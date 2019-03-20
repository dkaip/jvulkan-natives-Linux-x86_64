#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkBufferMemoryBarrier(
            JNIEnv *env,
            const jobject jVkBufferMemoryBarrierObject,
            VkBufferMemoryBarrier *vkBufferMemoryBarrier,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferMemoryBarrierClass = env->GetObjectClass(jVkBufferMemoryBarrierObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkBufferMemoryBarrierObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getSrcAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkBufferMemoryBarrierObject, methodId);
        VkAccessFlags srcAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAccessFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getDstAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkBufferMemoryBarrierObject, methodId);
        VkAccessFlags dstAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAccessFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getSrcQueueFamilyIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint srcQueueFamilyIndex = env->CallIntMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getDstQueueFamilyIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint dstQueueFamilyIndex = env->CallIntMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getBuffer", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBufferObject = env->CallObjectMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *vkBufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jVkBufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong offset = env->CallLongMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getSize", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong size = env->CallLongMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkBufferMemoryBarrier->sType = (VkStructureType)sTypeValue;
        vkBufferMemoryBarrier->pNext = (void *)pNext;
        vkBufferMemoryBarrier->srcAccessMask = srcAccessMask;
        vkBufferMemoryBarrier->dstAccessMask = dstAccessMask;
        vkBufferMemoryBarrier->srcQueueFamilyIndex = srcQueueFamilyIndex;
        vkBufferMemoryBarrier->dstQueueFamilyIndex = dstQueueFamilyIndex;
        vkBufferMemoryBarrier->buffer = vkBufferHandle;
        vkBufferMemoryBarrier->offset = offset;
        vkBufferMemoryBarrier->size = size;
    }

    void getVkBufferMemoryBarrierCollection(
            JNIEnv *env,
            const jobject jVkBufferMemoryBarrierCollectionObject,
            VkBufferMemoryBarrier **vkBufferMemoryBarriers,
            int *numberOfVkBufferMemoryBarriers,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferMemoryBarrierCollectionClass = env->GetObjectClass(jVkBufferMemoryBarrierCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBufferMemoryBarrierCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBufferMemoryBarrierCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkBufferMemoryBarriers = numberOfElements;
        *vkBufferMemoryBarriers = (VkBufferMemoryBarrier *)calloc(numberOfElements, sizeof(VkBufferMemoryBarrier));
        memoryToFree->push_back(*vkBufferMemoryBarriers);

        jmethodID iteratorMethodId = env->GetMethodID(vkBufferMemoryBarrierCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkBufferMemoryBarrierCollectionObject, iteratorMethodId);
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

            jobject jVkBufferMemoryBarrierObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkBufferMemoryBarrier(
                    env,
                    jVkBufferMemoryBarrierObject,
                    &((*vkBufferMemoryBarriers)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
