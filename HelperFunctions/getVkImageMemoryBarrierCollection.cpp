#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkImageMemoryBarrier(
            JNIEnv *env,
            const jobject jVkImageMemoryBarrierObject,
            VkImageMemoryBarrier *vkImageMemoryBarrier,
            std::vector<void *> *memoryToFree)
    {
        jclass vkImageMemoryBarrierClass = env->GetObjectClass(jVkImageMemoryBarrierObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkImageMemoryBarrierObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkImageMemoryBarrierClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkImageMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageMemoryBarrierClass, "getSrcAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkImageMemoryBarrierObject, methodId);
        VkAccessFlags srcAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAccessFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageMemoryBarrierClass, "getDstAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkImageMemoryBarrierObject, methodId);
        VkAccessFlags dstAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAccessFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageMemoryBarrierClass, "getOldLayout", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageLayoutObject = env->CallObjectMethod(jVkImageMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageLayoutEnumClass = env->GetObjectClass(jVkImageLayoutObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageLayout oldLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageMemoryBarrierClass, "getNewLayout", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkImageLayoutObject = env->CallObjectMethod(jVkImageMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageLayout newLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageMemoryBarrierClass, "getSrcQueueFamilyIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint srcQueueFamilyIndex = env->CallIntMethod(jVkImageMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageMemoryBarrierClass, "getDstQueueFamilyIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint dstQueueFamilyIndex = env->CallIntMethod(jVkImageMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageMemoryBarrierClass, "getImage", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkImage;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageObject = env->CallObjectMethod(jVkImageMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImage_T *vkImageHandle = (VkImage_T *)hwjvi::getHandleValue(env, jVkImageObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageMemoryBarrierClass, "getSubresourceRange", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkImageSubresourceRange;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageSubresourceRangeObject = env->CallObjectMethod(jVkImageMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        getVkImageSubresourceRange(
                env,
                jVkImageSubresourceRangeObject,
                &(vkImageMemoryBarrier->subresourceRange),
                memoryToFree);

        vkImageMemoryBarrier->sType = (VkStructureType)sTypeValue;
        vkImageMemoryBarrier->pNext = (void *)pNext;
        vkImageMemoryBarrier->srcAccessMask = srcAccessMask;
        vkImageMemoryBarrier->dstAccessMask = dstAccessMask;
        vkImageMemoryBarrier->oldLayout = oldLayoutEnumValue;
        vkImageMemoryBarrier->newLayout = newLayoutEnumValue;
        vkImageMemoryBarrier->srcQueueFamilyIndex = srcQueueFamilyIndex;
        vkImageMemoryBarrier->dstQueueFamilyIndex = dstQueueFamilyIndex;
        vkImageMemoryBarrier->image = vkImageHandle;
    }

    void getVkImageMemoryBarrierCollection(
            JNIEnv *env,
            const jobject jVkImageMemoryBarrierCollectionObject,
            VkImageMemoryBarrier **vkImageMemoryBarriers,
            int *numberOfVkImageMemoryBarriers,
            std::vector<void *> *memoryToFree)
    {
        jclass vkImageMemoryBarrierCollectionClass = env->GetObjectClass(jVkImageMemoryBarrierCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkImageMemoryBarrierCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkImageMemoryBarrierCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkImageMemoryBarriers = numberOfElements;
        *vkImageMemoryBarriers = (VkImageMemoryBarrier *)calloc(numberOfElements, sizeof(VkImageMemoryBarrier));
        memoryToFree->push_back(*vkImageMemoryBarriers);

        jmethodID iteratorMethodId = env->GetMethodID(vkImageMemoryBarrierCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkImageMemoryBarrierCollectionObject, iteratorMethodId);
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

            jobject jVkImageMemoryBarrierObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkImageMemoryBarrier(
                    env,
                    jVkImageMemoryBarrierObject,
                    &((*vkImageMemoryBarriers)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
