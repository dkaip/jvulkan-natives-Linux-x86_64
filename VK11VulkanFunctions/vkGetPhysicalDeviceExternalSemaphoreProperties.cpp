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
 * vkGetPhysicalDeviceExternalSemaphoreProperties.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceExternalSemaphoreProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceExternalSemaphoreInfo;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExternalSemaphoreProperties;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceExternalSemaphoreProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceExternalSemaphoreInfo, jobject jVkExternalSemaphoreProperties)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return;
	}

    std::vector<void *> memoryToFree(5);
    VkPhysicalDeviceExternalSemaphoreInfo vkPhysicalDeviceExternalSemaphoreInfo = {};
    jvulkan::getVkPhysicalDeviceExternalSemaphoreInfo(
            env,
			jVkPhysicalDeviceExternalSemaphoreInfo,
			&vkPhysicalDeviceExternalSemaphoreInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkPhysicalDeviceExternalSemaphoreInfo.");
        return;
    }

    VkExternalSemaphoreProperties vkExternalSemaphoreProperties = {};
    vkExternalSemaphoreProperties.sType = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES;
    vkExternalSemaphoreProperties.pNext = nullptr;

    vkGetPhysicalDeviceExternalSemaphoreProperties(
    		physicalDeviceHandle,
			&vkPhysicalDeviceExternalSemaphoreInfo,
			&vkExternalSemaphoreProperties);

    jvulkan::populateVkExternalSemaphoreProperties(
    		env,
			jVkExternalSemaphoreProperties,
			&vkExternalSemaphoreProperties);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkExternalSemaphoreProperties.");
        return;
    }

    jvulkan::freeMemory(&memoryToFree);
}
