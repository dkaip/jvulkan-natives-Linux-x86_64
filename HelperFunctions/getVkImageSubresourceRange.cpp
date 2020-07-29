/*
 * Copyright 2019-2020 Douglas Kaip
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
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageAspectFlagBits");

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
