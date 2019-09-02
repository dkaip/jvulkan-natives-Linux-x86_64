/*
 * Copyright 2019 Douglas Kaip
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "JVulkanHelperFunctions.hh"

namespace jvulkan
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
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageAspectFlagBits");

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
