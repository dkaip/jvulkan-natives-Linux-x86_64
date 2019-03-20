#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkSamplerCollection(
            JNIEnv *env,
            const jobject jVkSamplerCollectionObject,
            VkSampler **vkSamplers,
            int *numberOfVkSamplers,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSamplerCollectionClass = env->GetObjectClass(jVkSamplerCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSamplerCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSamplerCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkSamplers = numberOfElements;
        *vkSamplers = (VkSampler *)calloc(numberOfElements, sizeof(VkSampler *));
        memoryToFree->push_back(*vkSamplers);

        jmethodID iteratorMethodId = env->GetMethodID(vkSamplerCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSamplerCollectionObject, iteratorMethodId);
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

            jobject jVkSamplerHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkSampler_T *vkSamplerHandle = (VkSampler_T *)hwjvi::getHandleValue(env, jVkSamplerHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkSamplers)[i] = vkSamplerHandle;

            i++;
        } while(true);
    }
}
