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
/*
 * vkGetPhysicalDeviceExternalImageFormatPropertiesNV.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceExternalImageFormatPropertiesNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageType;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageTiling;Ljava/util/EnumSet;Ljava/util/EnumSet;Ljava/util/EnumSet;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkExternalImageFormatPropertiesNV;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceExternalImageFormatPropertiesNV
  (JNIEnv *env, jobject,
		  jobject jVkPhysicalDevice,
		  jobject jVkFormat,
		  jobject jVkImageType,
		  jobject jVkImageTiling,
		  jobject jVkImageUsageFlags,
		  jobject jVkImageCreateFlags,
		  jobject jVkExternalMemoryHandleTypeFlagsNV,
		  jobject jVkExternalImageFormatPropertiesNV)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    ////////////////////////////////////////////////////////////////////////
    jclass theClass = env->GetObjectClass(jVkFormat);

    jmethodID valueOfMethodId = env->GetMethodID(theClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkFormat vkFormatEnumValue = (VkFormat)env->CallIntMethod(jVkFormat, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    theClass = env->GetObjectClass(jVkImageType);

    valueOfMethodId = env->GetMethodID(theClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkImageType vkImageTypeEnumValue = (VkImageType)env->CallIntMethod(jVkImageType, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    theClass = env->GetObjectClass(jVkImageTiling);

    valueOfMethodId = env->GetMethodID(theClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkImageTiling vkImageTilingEnumValue = (VkImageTiling)env->CallIntMethod(jVkImageTiling, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    VkImageUsageFlags imageUsageFlags = (VkImageUsageFlags)jvulkan::getEnumSetValue(
            env,
			jVkImageUsageFlags,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageUsageFlagBits");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getEnumSetValue");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    VkImageCreateFlags imageCreateFlags = (VkImageCreateFlags)jvulkan::getEnumSetValue(
            env,
			jVkImageCreateFlags,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageCreateFlags");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getEnumSetValue");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    VkExternalMemoryHandleTypeFlagsNV vkExternalMemoryHandleTypeFlagsNVFlags = (VkExternalMemoryHandleTypeFlagsNV)jvulkan::getEnumSetValue(
            env,
			jVkExternalMemoryHandleTypeFlagsNV,
            "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkExternalMemoryHandleTypeFlagBitsNV");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getEnumSetValue");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkExternalImageFormatPropertiesNV vkExternalImageFormatPropertiesNV = {};

	VkResult result = vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
			physicalDeviceHandle,
			vkFormatEnumValue,
			vkImageTypeEnumValue,
			vkImageTilingEnumValue,
			imageUsageFlags,
			imageCreateFlags,
			vkExternalMemoryHandleTypeFlagsNVFlags,
			&vkExternalImageFormatPropertiesNV);


    jvulkan::populateVkExternalImageFormatPropertiesNV(
			env,
			jVkExternalImageFormatPropertiesNV,
			&vkExternalImageFormatPropertiesNV);
	if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkExternalImageFormatPropertiesNV");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	return jvulkan::createVkResult(env, result);
}
