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
 * vkGetPhysicalDeviceSurfaceFormats2KHR.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include <vector>

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceSurfaceFormats2KHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceSurfaceInfo2KHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceSurfaceFormats2KHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceSurfaceInfo2KHR, jobject jVkSurfaceFormat2KHRCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    std::vector<void *> memoryToFree(5);
    VkPhysicalDeviceSurfaceInfo2KHR vkPhysicalDeviceSurfaceInfo2KHR = {};
    jvulkan::getVkPhysicalDeviceSurfaceInfo2KHR(
            env,
			jVkPhysicalDeviceSurfaceInfo2KHR,
			&vkPhysicalDeviceSurfaceInfo2KHR,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkPhysicalDeviceSurfaceInfo2KHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	uint32_t surfaceFormatCount = 0;
	VkResult result = vkGetPhysicalDeviceSurfaceFormats2KHR(
			physicalDeviceHandle,
			&vkPhysicalDeviceSurfaceInfo2KHR,
			&surfaceFormatCount,
			nullptr);
	if (result != VK_SUCCESS)
	{
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceSurfaceFormats2KHR.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatCount);

    result = vkGetPhysicalDeviceSurfaceFormats2KHR(
			physicalDeviceHandle,
			&vkPhysicalDeviceSurfaceInfo2KHR,
			&surfaceFormatCount,
			(VkSurfaceFormat2KHR *)surfaceFormats.data());
	if (result != VK_SUCCESS)
	{
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceSurfaceFormats2KHR.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	jvulkan::populateVkSurfaceFormat2KHRCollection(
			env,
			jVkSurfaceFormat2KHRCollection,
			(VkSurfaceFormat2KHR *)surfaceFormats.data(),
			surfaceFormatCount);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling populateVkSurfaceFormat2KHRCollection");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    jvulkan::freeMemory(&memoryToFree);

	return jvulkan::createVkResult(env, result);
}
