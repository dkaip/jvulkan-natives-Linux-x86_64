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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImageCreateInfo(
            JNIEnv *env,
            jobject jVkImageCreateInfoObject,
            VkImageCreateInfo *vkImageCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkImageCreateInfoClass = env->GetObjectClass(jVkImageCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkImageCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImageCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkImageCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        VkImageCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getImageType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageType;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageTypeObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageTypeEnumClass = env->GetObjectClass(jVkImageTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkImageTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageType vkImageTypeEnumValue = (VkImageType)env->CallIntMethod(jVkImageTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFormatObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFormatEnumClass = env->GetObjectClass(jVkFormatObject);

        valueOfMethodId = env->GetMethodID(vkFormatEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFormat vkFormatEnumValue = (VkFormat)env->CallIntMethod(jVkFormatObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getExtent", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkExtent3DObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkExtent3D vkExtent3D = {};
        getVkExtent3D(env,
                jVkExtent3DObject,
                &vkExtent3D,
                memoryToFree);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getMipLevels", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint mipLevels = env->CallIntMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getArrayLayers", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint arrayLayers = env->CallIntMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getSamples", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSampleCountFlagBitsObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkSampleCountFlagBitsEnumClass = env->GetObjectClass(jVkSampleCountFlagBitsObject);

        valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSampleCountFlagBits vkSampleCountFlagBitsEnumValue = (VkSampleCountFlagBits)env->CallIntMethod(jVkSampleCountFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getTiling", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageTiling;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageTilingObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageTilingEnumClass = env->GetObjectClass(jVkImageTilingObject);

        valueOfMethodId = env->GetMethodID(vkImageTilingEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageTiling vkImageTilingEnumValue = (VkImageTiling)env->CallIntMethod(jVkImageTilingObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getUsage", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject usageFlagsObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        VkImageUsageFlags imageUsageFlags = getEnumSetValue(
                env,
                usageFlagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageUsageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getSharingMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSharingMode;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSharingModeObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkSharingModeEnumClass = env->GetObjectClass(jVkSharingModeObject);

        valueOfMethodId = env->GetMethodID(vkSharingModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSharingMode vkSharingModeEnumValue = (VkSharingMode)env->CallIntMethod(jVkSharingModeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getQueueFamilyIndices", "()[I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jQueueFamilyIndices = (jintArray)env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int *queueFamilyIndicesArray = nullptr;
        jsize arrayLength = 0;
        if (jQueueFamilyIndices != nullptr)
        {
            arrayLength = env->GetArrayLength(jQueueFamilyIndices);

            queueFamilyIndicesArray = (int *)calloc(arrayLength, sizeof(int));
            memoryToFree->push_back(queueFamilyIndicesArray);

            env->GetIntArrayRegion(jQueueFamilyIndices, 0, arrayLength, queueFamilyIndicesArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getInitialLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageLayoutObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageLayoutEnumClass = env->GetObjectClass(jVkImageLayoutObject);

        valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageLayout vkImageLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkImageCreateInfo->sType = (VkStructureType)sTypeValue;
        vkImageCreateInfo->pNext = (void *)pNext;
        vkImageCreateInfo->flags = flags;
        vkImageCreateInfo->imageType = vkImageTypeEnumValue;
        vkImageCreateInfo->format = vkFormatEnumValue;

        vkImageCreateInfo->extent.width  = vkExtent3D.width;
        vkImageCreateInfo->extent.height = vkExtent3D.height;
        vkImageCreateInfo->extent.depth  = vkExtent3D.depth;

        vkImageCreateInfo->mipLevels = mipLevels;
        vkImageCreateInfo->arrayLayers = arrayLayers;
        vkImageCreateInfo->samples = vkSampleCountFlagBitsEnumValue;
        vkImageCreateInfo->tiling = vkImageTilingEnumValue;
        vkImageCreateInfo->usage = imageUsageFlags;
        vkImageCreateInfo->sharingMode = vkSharingModeEnumValue;
        vkImageCreateInfo->queueFamilyIndexCount = arrayLength;
        vkImageCreateInfo->pQueueFamilyIndices = (uint32_t *)queueFamilyIndicesArray;
        vkImageCreateInfo->initialLayout = vkImageLayoutEnumValue;
    }
}
