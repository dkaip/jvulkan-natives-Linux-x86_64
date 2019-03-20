#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkDescriptorBufferInfo(
            JNIEnv *env,
            const jobject jVkDescriptorBufferInfoObject,
            VkDescriptorBufferInfo *vkDescriptorBufferInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorBufferInfoClass = env->GetObjectClass(jVkDescriptorBufferInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorBufferInfoClass, "getBuffer", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBufferObject = env->CallObjectMethod(jVkDescriptorBufferInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *bufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jVkBufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorBufferInfoClass, "getOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong jOffset = env->CallLongMethod(jVkDescriptorBufferInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
         methodId = env->GetMethodID(vkDescriptorBufferInfoClass, "getRange", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong jRange = env->CallLongMethod(jVkDescriptorBufferInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkDescriptorBufferInfo->buffer = bufferHandle;
        vkDescriptorBufferInfo->offset = jOffset;
        vkDescriptorBufferInfo->range = jRange;
    }

    void getVkDescriptorBufferInfoCollection(
            JNIEnv *env,
            const jobject jVkDescriptorBufferInfoCollectionObject,
            VkDescriptorBufferInfo **vkDescriptorBufferInfos,
            int *numberOfVkDescriptorBufferInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorBufferInfoCollectionClass = env->GetObjectClass(jVkDescriptorBufferInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorBufferInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorBufferInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDescriptorBufferInfos = numberOfElements;
        *vkDescriptorBufferInfos = (VkDescriptorBufferInfo *)calloc(numberOfElements, sizeof(VkDescriptorBufferInfo));
        memoryToFree->push_back(*vkDescriptorBufferInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorBufferInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorBufferInfoCollectionObject, iteratorMethodId);
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

            jobject jVkDescriptorBufferInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkDescriptorBufferInfo(
                    env,
                    jVkDescriptorBufferInfoObject,
                    &((*vkDescriptorBufferInfos)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
