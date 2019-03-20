#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkImageSubresourceRange(
            JNIEnv *env,
            const jobject jVkImageSubresourceRangeObject,
            VkImageSubresourceRange *vkImageSubresourceRange,
            std::vector<void *> *memoryToFree)
    {
        jclass vkImageSubresourceRangeClass = env->GetObjectClass(jVkImageSubresourceRangeObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkImageSubresourceRangeClass, "getAspectMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkImageSubresourceRangeObject, methodId);
        VkImageAspectFlags aspectMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageAspectFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageSubresourceRangeClass, "getBaseMipLevel", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint baseMipLevel = env->CallIntMethod(jVkImageSubresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageSubresourceRangeClass, "getLevelCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint levelCount = env->CallIntMethod(jVkImageSubresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageSubresourceRangeClass, "getBaseArrayLayer", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint baseArrayLayer = env->CallIntMethod(jVkImageSubresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageSubresourceRangeClass, "getLayerCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint layerCount = env->CallIntMethod(jVkImageSubresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkImageSubresourceRange->aspectMask = aspectMask;
        vkImageSubresourceRange->baseMipLevel = baseMipLevel;
        vkImageSubresourceRange->levelCount = levelCount;
        vkImageSubresourceRange->baseArrayLayer = baseArrayLayer;
        vkImageSubresourceRange->layerCount = layerCount;
    }
}
