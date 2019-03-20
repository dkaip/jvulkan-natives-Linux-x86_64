#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkDescriptorSetLayoutCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetLayoutCollectionObject,
            VkDescriptorSetLayout **vkDescriptorSetLayout,
            int *numberOfVkDescriptorSetLayouts,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetLayoutCollectionClass = env->GetObjectClass(jVkDescriptorSetLayoutCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorSetLayoutCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorSetLayoutCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDescriptorSetLayouts = numberOfElements;
        *vkDescriptorSetLayout = (VkDescriptorSetLayout *)calloc(numberOfElements, sizeof(VkDescriptorSetLayout *));
        memoryToFree->push_back(*vkDescriptorSetLayout);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorSetLayoutCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorSetLayoutCollectionObject, iteratorMethodId);
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

            jobject jVkDescriptorSetLayoutHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkDescriptorSetLayout_T *vkDescriptorSetLayoutHandle = (VkDescriptorSetLayout_T *)hwjvi::getHandleValue(env, jVkDescriptorSetLayoutHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkDescriptorSetLayout)[i] = vkDescriptorSetLayoutHandle;

            i++;
        } while(true);
    }
}
