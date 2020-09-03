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
/*
 * getImageViewCreateInfo.cpp
 *
 *  Created on: May 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getImageViewCreateInfo(
        JNIEnv *env,
        const jobject jVkImageViewCreateInfo,
        VkImageViewCreateInfo *imageViewCreateInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass vkImageViewCreateInfoClass = env->GetObjectClass(jVkImageViewCreateInfo);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkImageViewCreateInfo);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImageViewCreateInfo);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageViewCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getImage", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jImageHandle = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImage_T *imageHandle = (VkImage_T *)getHandleValue(env, jImageHandle);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getViewType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageViewType;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject imageViewTypeEnumObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass imageViewTypeEnumClass = env->GetObjectClass(imageViewTypeEnumObject);

        jmethodID valueOfMethodId = env->GetMethodID(imageViewTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint imageViewTypeEnumClassValue = env->CallIntMethod(imageViewTypeEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject vkFormatEnumObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFormatEnumEnumClass = env->GetObjectClass(vkFormatEnumObject);

        valueOfMethodId = env->GetMethodID(vkFormatEnumEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkFormatEnumEnumClassValue = env->CallIntMethod(vkFormatEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getComponents", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkComponentMapping;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject componentsObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint componentRValue = 0;
        jint componentGValue = 0;
        jint componentBValue = 0;
        jint componentAValue = 0;

        if (componentsObject != nullptr)
        {
            jclass componentsObjectClass = env->GetObjectClass(componentsObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(componentsObjectClass, "getR", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkComponentSwizzle;");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jobject vkComponentSwizzleEnumObject = env->CallObjectMethod(componentsObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            jclass vkComponentSwizzleEnumClass = env->GetObjectClass(vkComponentSwizzleEnumObject);

            valueOfMethodId = env->GetMethodID(vkComponentSwizzleEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            componentRValue = env->CallIntMethod(vkComponentSwizzleEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(componentsObjectClass, "getG", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkComponentSwizzle;");
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkComponentSwizzleEnumObject = env->CallObjectMethod(componentsObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            componentGValue = env->CallIntMethod(vkComponentSwizzleEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(componentsObjectClass, "getB", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkComponentSwizzle;");
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkComponentSwizzleEnumObject = env->CallObjectMethod(componentsObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            componentBValue = env->CallIntMethod(vkComponentSwizzleEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(componentsObjectClass, "getA", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkComponentSwizzle;");
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkComponentSwizzleEnumObject = env->CallObjectMethod(componentsObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            componentAValue = env->CallIntMethod(vkComponentSwizzleEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getSubresourceRange", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageSubresourceRange;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject subresourceRangeObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass subresourceRangeObjectClass = env->GetObjectClass(subresourceRangeObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getAspectMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject aspectMaskObject = env->CallObjectMethod(subresourceRangeObject, methodId);
        int32_t aspectMaskFlags = getEnumSetValue(
                env,
                aspectMaskObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageAspectFlagBits");

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getBaseMipLevel", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint baseMipLevel = env->CallIntMethod(subresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getLevelCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint levelCount = env->CallIntMethod(subresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getBaseArrayLayer", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint baseArrayLayer = env->CallIntMethod(subresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getLayerCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint layerCount = env->CallIntMethod(subresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }


        imageViewCreateInfo->sType = sTypeValue;
        imageViewCreateInfo->pNext = (void *)pNext;
        imageViewCreateInfo->flags = flags;
        imageViewCreateInfo->image = imageHandle;
        imageViewCreateInfo->viewType = (VkImageViewType)imageViewTypeEnumClassValue;
        imageViewCreateInfo->format = (VkFormat)vkFormatEnumEnumClassValue;
        imageViewCreateInfo->components.r = (VkComponentSwizzle)componentRValue;
        imageViewCreateInfo->components.g = (VkComponentSwizzle)componentGValue;
        imageViewCreateInfo->components.b = (VkComponentSwizzle)componentBValue;
        imageViewCreateInfo->components.a = (VkComponentSwizzle)componentAValue;
        imageViewCreateInfo->subresourceRange.aspectMask = (VkImageAspectFlags)aspectMaskFlags;
        imageViewCreateInfo->subresourceRange.baseArrayLayer = baseArrayLayer;
        imageViewCreateInfo->subresourceRange.baseMipLevel = baseMipLevel;
        imageViewCreateInfo->subresourceRange.layerCount = layerCount;
        imageViewCreateInfo->subresourceRange.levelCount = levelCount;
    }
}
