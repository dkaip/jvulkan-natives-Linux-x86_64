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
 * vkGetPhysicalDeviceDisplayPlaneProperties2KHR.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceDisplayPlaneProperties2KHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceDisplayPlaneProperties2KHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkDisplayPlaneProperties2KHRCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	uint32_t propertyCount = 0;
	VkResult result = vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
			physicalDeviceHandle,
			&propertyCount,
			nullptr);
	if (result != VK_SUCCESS)
	{
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceDisplayPlaneProperties2KHR.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkDisplayPlaneProperties2KHR *vkDisplayPlaneProperties2KHRs =
			(VkDisplayPlaneProperties2KHR *)calloc(propertyCount, sizeof(VkDisplayPlaneProperties2KHR));
	if (vkDisplayPlaneProperties2KHRs == nullptr)
	{
		LOGERROR(env, "Error trying to allocate memory for %d VkDisplayPlaneProperties2KHRs.", propertyCount);
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	result = vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
			physicalDeviceHandle,
			&propertyCount,
			vkDisplayPlaneProperties2KHRs);
	if (result != VK_SUCCESS)
	{
		free(vkDisplayPlaneProperties2KHRs);
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceDisplayPlaneProperties2KHR.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	jvulkan::populateVkDisplayPlaneProperties2KHRCollection(
			env,
			jVkDisplayPlaneProperties2KHRCollection,
			vkDisplayPlaneProperties2KHRs,
			propertyCount);
	if (env->ExceptionOccurred())
	{
		free(vkDisplayPlaneProperties2KHRs);
		LOGERROR(env, "%s", "Error calling populateVkDisplayPlaneProperties2KHRCollection");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	free(vkDisplayPlaneProperties2KHRs);

	return jvulkan::createVkResult(env, result);
}
