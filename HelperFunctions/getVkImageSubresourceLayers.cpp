#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkImageSubresourceLayers(
            JNIEnv *env,
            const jobject jVkImageSubresourceLayersObject,
            VkImageSubresourceLayers *vkImageSubresourceLayers,
            std::vector<void *> *memoryToFree)
    {
        jclass vkImageSubresourceLayersClass = env->GetObjectClass(jVkImageSubresourceLayersObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkImageSubresourceLayersClass, "getAspectMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkImageSubresourceLayersObject, methodId);
        VkImageAspectFlags aspectMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageAspectFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageSubresourceLayersClass, "getMipLevel", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint mipLevel = env->CallIntMethod(jVkImageSubresourceLayersObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageSubresourceLayersClass, "getBaseArrayLayer", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint baseArrayLayer = env->CallIntMethod(jVkImageSubresourceLayersObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageSubresourceLayersClass, "getLayerCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint layerCount = env->CallIntMethod(jVkImageSubresourceLayersObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkImageSubresourceLayers->aspectMask = aspectMask;
        vkImageSubresourceLayers->mipLevel = mipLevel;
        vkImageSubresourceLayers->baseArrayLayer = baseArrayLayer;
        vkImageSubresourceLayers->layerCount = layerCount;
    }
}
