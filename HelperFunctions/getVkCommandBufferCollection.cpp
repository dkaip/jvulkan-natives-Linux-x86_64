#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkCommandBufferCollection(
            JNIEnv *env,
            const jobject jVkCommandBufferCollectionObject,
            VkCommandBuffer **vkCommandBuffers,
            int *numberOfVkCommandBuffers,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCommandBufferCollectionClass = env->GetObjectClass(jVkCommandBufferCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkCommandBufferCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkCommandBufferCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkCommandBuffers = numberOfElements;
        *vkCommandBuffers = (VkCommandBuffer *)calloc(numberOfElements, sizeof(VkCommandBuffer *));
        memoryToFree->push_back(*vkCommandBuffers);

        jmethodID iteratorMethodId = env->GetMethodID(vkCommandBufferCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkCommandBufferCollectionObject, iteratorMethodId);
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

            jobject jVkCommandBufferHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkCommandBuffer_T *vkCommandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBufferHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkCommandBuffers)[i] = vkCommandBufferHandle;

            i++;
        } while(true);
    }
}
