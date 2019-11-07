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
 * vkGetPhysicalDeviceSparseImageFormatProperties.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceSparseImageFormatProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageType;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits;Ljava/util/EnumSet;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageTiling;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceSparseImageFormatProperties
  (JNIEnv *env, jobject,
		  jobject jVkPhysicalDevice,
		  jobject jVkFormat,
		  jobject jVkImageType,
		  jobject jVkSampleCountFlagBits,
		  jobject jVkImageUsageFlags,
		  jobject jVkImageTiling,
		  jobject jVkSparseImageFormatPropertiesCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return;
	}

    std::vector<void *> memoryToFree(5);
    VkFormat vkFormat = (VkFormat)0;
    jvulkan::getVkFormat(
            env,
			jVkFormat,
			&vkFormat,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling method getVkFormat");
    	return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkImageTypeClass = env->GetObjectClass(jVkImageType);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get class for jVkImageType");
    	return;
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkImageTypeClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id valueOf.");
    	return;
    }

    VkImageType vkImageTypeEnumValue = (VkImageType)env->CallIntMethod(jVkImageType, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
    	return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkSampleCountFlagBitsClass = env->GetObjectClass(jVkSampleCountFlagBits);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get class for jVkSampleCountFlagBits");
    	return;
    }

    valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id valueOf.");
    	return;
    }

    VkSampleCountFlagBits samplesEnumValue = (VkSampleCountFlagBits)env->CallIntMethod(jVkSampleCountFlagBits, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
    	return;
    }

	////////////////////////////////////////////////////////////////////////
    VkImageUsageFlags vkImageUsageFlags = (VkImageUsageFlags)jvulkan::getEnumSetValue(
			env,
			jVkImageUsageFlags,
			"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageUsageFlagBits");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getEnumSetValue");
    	return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkImageTilingClass = env->GetObjectClass(jVkImageTiling);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get class for jVkImageTilingObject");
    	return;
    }

    valueOfMethodId = env->GetMethodID(vkImageTypeClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id valueOf.");
    	return;
    }

    VkImageTiling vkImageTilingEnumValue = (VkImageTiling)env->CallIntMethod(jVkImageTiling, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
    	return;
    }

    uint32_t propertyCount = 0;
    vkGetPhysicalDeviceSparseImageFormatProperties(
    		physicalDeviceHandle,
			vkFormat,
			vkImageTypeEnumValue,
			samplesEnumValue,
			vkImageUsageFlags,
			vkImageTilingEnumValue,
			&propertyCount,
			nullptr);

    VkSparseImageFormatProperties *properties =
			(VkSparseImageFormatProperties *)calloc(propertyCount, sizeof(VkSparseImageFormatProperties));
	if (properties == nullptr)
	{
		LOGERROR(env, "Error trying to allocate memory for %d VkSparseImageFormatPropertiess.", propertyCount);
		return;
	}

    vkGetPhysicalDeviceSparseImageFormatProperties(
    		physicalDeviceHandle,
			vkFormat,
			vkImageTypeEnumValue,
			samplesEnumValue,
			vkImageUsageFlags,
			vkImageTilingEnumValue,
			&propertyCount,
			properties);

	jvulkan::populateVkSparseImageFormatPropertiesCollection(
			env,
			jVkSparseImageFormatPropertiesCollection,
			properties,
			propertyCount);
	if (env->ExceptionOccurred())
	{
		free(properties);
		LOGERROR(env, "%s", "Error calling populateVkSparseImageFormatPropertiesCollection");
		return;
	}

	free(properties);
}
