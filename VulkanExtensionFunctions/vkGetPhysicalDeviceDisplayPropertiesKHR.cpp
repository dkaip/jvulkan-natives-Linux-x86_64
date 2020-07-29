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
 * vkGetPhysicalDeviceDisplayPropertiesKHR.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceDisplayPropertiesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPropertiesKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceDisplayPropertiesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkDisplayPropertiesKHRCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	uint32_t propertyCount = 0;
	VkResult result = vkGetPhysicalDeviceDisplayPropertiesKHR(
			physicalDeviceHandle,
			&propertyCount,
			nullptr);
	if (result != VK_SUCCESS)
	{
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceDisplayPropertiesKHR.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkDisplayPropertiesKHR *vkDisplayPropertiesKHRs =
			(VkDisplayPropertiesKHR *)calloc(propertyCount, sizeof(VkDisplayPropertiesKHR));
	if (vkDisplayPropertiesKHRs == nullptr)
	{
		LOGERROR(env, "Error trying to allocate memory for %d VkDisplayPropertiesKHRs.", propertyCount);
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	result = vkGetPhysicalDeviceDisplayPropertiesKHR(
			physicalDeviceHandle,
			&propertyCount,
			vkDisplayPropertiesKHRs);
	if (result != VK_SUCCESS)
	{
		free(vkDisplayPropertiesKHRs);
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceDisplayPropertiesKHR.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	jvulkan::populateVkDisplayPropertiesKHRCollection(
			env,
			jVkDisplayPropertiesKHRCollection,
			vkDisplayPropertiesKHRs,
			propertyCount);
	if (env->ExceptionOccurred())
	{
		free(vkDisplayPropertiesKHRs);
		LOGERROR(env, "%s", "Error calling populateVkDisplayPropertiesKHRCollection");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	free(vkDisplayPropertiesKHRs);

	return jvulkan::createVkResult(env, result);

}
