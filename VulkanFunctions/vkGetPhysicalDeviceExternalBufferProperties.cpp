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
 * vkGetPhysicalDeviceExternalBufferProperties.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceExternalBufferProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceExternalBufferInfo;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExternalBufferProperties;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceExternalBufferProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceExternalBufferInfo, jobject jVkExternalBufferProperties)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return;
	}

    std::vector<void *> memoryToFree(5);
    VkPhysicalDeviceExternalBufferInfo vkPhysicalDeviceExternalBufferInfo = {};
    jvulkan::getVkPhysicalDeviceExternalBufferInfo(
            env,
			jVkPhysicalDeviceExternalBufferInfo,
			&vkPhysicalDeviceExternalBufferInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkPhysicalDeviceExternalBufferInfo.");
        return;
    }

    VkExternalBufferProperties vkExternalBufferProperties = {};
    vkExternalBufferProperties.sType = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES;
    vkExternalBufferProperties.pNext = nullptr;

    vkGetPhysicalDeviceExternalBufferProperties(
    		physicalDeviceHandle,
			&vkPhysicalDeviceExternalBufferInfo,
			&vkExternalBufferProperties);

    jvulkan::populateVkExternalBufferProperties(
    		env,
			jVkExternalBufferProperties,
			&vkExternalBufferProperties);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkExternalBufferProperties.");
        return;
    }

    jvulkan::freeMemory(&memoryToFree);
}
