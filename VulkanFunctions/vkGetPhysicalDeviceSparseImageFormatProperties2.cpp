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
 * vkGetPhysicalDeviceSparseImageFormatProperties2.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceSparseImageFormatProperties2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceSparseImageFormatInfo2;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceSparseImageFormatProperties2
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceSparseImageFormatInfo2, jobject jVkSparseImageFormatProperties2Collection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return;
	}

    std::vector<void *> memoryToFree(5);
    VkPhysicalDeviceSparseImageFormatInfo2 vkPhysicalDeviceSparseImageFormatInfo2 = {};
	jvulkan::getVkPhysicalDeviceSparseImageFormatInfo2(
			env,
			jVkPhysicalDeviceSparseImageFormatInfo2,
			&vkPhysicalDeviceSparseImageFormatInfo2,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkPhysicalDeviceSparseImageFormatInfo2");
		return;
	}

	uint32_t propertyCount = 0;
	vkGetPhysicalDeviceSparseImageFormatProperties2(
			physicalDeviceHandle,
			&vkPhysicalDeviceSparseImageFormatInfo2,
			&propertyCount,
			nullptr);

	VkSparseImageFormatProperties2 *vkSparseImageFormatProperties2s =
			(VkSparseImageFormatProperties2 *)calloc(propertyCount, sizeof(VkSparseImageFormatProperties2));
	if (vkSparseImageFormatProperties2s == nullptr)
	{
		LOGERROR(env, "Error trying to allocate memory for %d VkSparseImageFormatProperties2.", propertyCount);
		return;
	}

	vkGetPhysicalDeviceSparseImageFormatProperties2(
			physicalDeviceHandle,
			&vkPhysicalDeviceSparseImageFormatInfo2,
			&propertyCount,
			vkSparseImageFormatProperties2s);

	jvulkan::populateVkSparseImageFormatProperties2Collection(
			env,
			jVkSparseImageFormatProperties2Collection,
			vkSparseImageFormatProperties2s,
			propertyCount);
	if (env->ExceptionOccurred())
	{
		free(vkSparseImageFormatProperties2s);
		LOGERROR(env, "%s", "Error calling populateVkSparseImageFormatProperties2Collection");
		return;
	}

    free(vkSparseImageFormatProperties2s);

    jvulkan::freeMemory(&memoryToFree);
}
