#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkDescriptorSetCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetCollectionObject,
            VkDescriptorSet **vkDescriptorSets,
            int *numberOfVkDescriptorSets,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetCollectionClass = env->GetObjectClass(jVkDescriptorSetCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorSetCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorSetCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDescriptorSets = numberOfElements;
        *vkDescriptorSets = (VkDescriptorSet *)calloc(numberOfElements, sizeof(VkDescriptorSet *));
        memoryToFree->push_back(*vkDescriptorSets);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorSetCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorSetCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkDescriptorSetHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkDescriptorSet_T *vkDescriptorSetHandle = (VkDescriptorSet_T *)hwjvi::getHandleValue(env, jVkDescriptorSetHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkDescriptorSets)[i] = vkDescriptorSetHandle;

            i++;
        } while(true);
    }
}
