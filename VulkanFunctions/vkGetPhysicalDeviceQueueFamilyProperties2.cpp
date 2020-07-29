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
 * vkGetPhysicalDeviceQueueFamilyProperties2.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceQueueFamilyProperties2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceQueueFamilyProperties2
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkQueueFamilyProperties2Collection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return;
	}

	uint32_t queueFamilyPropertyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties2(
			physicalDeviceHandle,
			&queueFamilyPropertyCount,
			nullptr);

    std::vector<VkQueueFamilyProperties2> vkQueueFamilyProperties2s(queueFamilyPropertyCount);

    for(int i = 0; i < queueFamilyPropertyCount; i++)
	{
		vkQueueFamilyProperties2s.data()[i].sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2;
		vkQueueFamilyProperties2s.data()[i].pNext = nullptr;
	}

	vkGetPhysicalDeviceQueueFamilyProperties2(
			physicalDeviceHandle,
			&queueFamilyPropertyCount,
			vkQueueFamilyProperties2s.data());

	jvulkan::populateVkQueueFamilyProperties2Collection(
			env,
			jVkQueueFamilyProperties2Collection,
			vkQueueFamilyProperties2s.data(),
			queueFamilyPropertyCount);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling populateVkQueueFamilyProperties2Collection");
		return;
	}
}
