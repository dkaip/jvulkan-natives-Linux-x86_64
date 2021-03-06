/*
 * Copyright 2020 Douglas Kaip
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
 * vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkQueryPoolPerformanceCreateInfoKHR;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/IntReturnValue;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkQueryPoolPerformanceCreateInfoKHR, jobject jNumPasses)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
        return;
	}

    std::vector<void *> memoryToFree(5);
	VkQueryPoolPerformanceCreateInfoKHR vkQueryPoolPerformanceCreateInfoKHR = {};
    jvulkan::getVkQueryPoolPerformanceCreateInfoKHR(
            env,
			jVkQueryPoolPerformanceCreateInfoKHR,
			&vkQueryPoolPerformanceCreateInfoKHR,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkQueryPoolPerformanceCreateInfoKHR.");
        return;
    }

	uint32_t numPasses = -1;

	vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
			physicalDeviceHandle,
			&vkQueryPoolPerformanceCreateInfoKHR,
			&numPasses);

    jvulkan::freeMemory(&memoryToFree);

	jvulkan::setIntReturnValue(env, jNumPasses, numPasses);

}
