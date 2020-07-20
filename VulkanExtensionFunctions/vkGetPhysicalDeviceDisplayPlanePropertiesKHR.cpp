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
 * vkGetPhysicalDeviceDisplayPlanePropertiesKHR.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceDisplayPlanePropertiesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceDisplayPlanePropertiesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkDisplayPlanePropertiesKHRCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	uint32_t propertyCount = 0;
	VkResult result = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
			physicalDeviceHandle,
			&propertyCount,
			nullptr);
	if (result != VK_SUCCESS)
	{
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceDisplayPlanePropertiesKHR.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkDisplayPlanePropertiesKHR *vkDisplayPlanePropertiesKHRs =
			(VkDisplayPlanePropertiesKHR *)calloc(propertyCount, sizeof(VkDisplayPlanePropertiesKHR));
	if (vkDisplayPlanePropertiesKHRs == nullptr)
	{
		LOGERROR(env, "Error trying to allocate memory for %d VkDisplayPlanePropertiesKHRs.", propertyCount);
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	result = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
			physicalDeviceHandle,
			&propertyCount,
			vkDisplayPlanePropertiesKHRs);
	if (result != VK_SUCCESS)
	{
		free(vkDisplayPlanePropertiesKHRs);
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceDisplayPlanePropertiesKHR.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	jvulkan::populateVkDisplayPlanePropertiesKHRCollection(
			env,
			jVkDisplayPlanePropertiesKHRCollection,
			vkDisplayPlanePropertiesKHRs,
			propertyCount);
	if (env->ExceptionOccurred())
	{
		free(vkDisplayPlanePropertiesKHRs);
		LOGERROR(env, "%s", "Error calling populateVkDisplayPlanePropertiesKHRCollection");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	free(vkDisplayPlanePropertiesKHRs);

	return jvulkan::createVkResult(env, result);
}
