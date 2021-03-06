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
 * vkGetPhysicalDeviceExternalFenceProperties.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceExternalFenceProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceExternalFenceInfo;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExternalFenceProperties;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceExternalFenceProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceExternalFenceInfo, jobject jVkExternalFenceProperties)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return;
	}

    std::vector<void *> memoryToFree(5);
    VkPhysicalDeviceExternalFenceInfo vkPhysicalDeviceExternalFenceInfo = {};
    jvulkan::getVkPhysicalDeviceExternalFenceInfo(
            env,
			jVkPhysicalDeviceExternalFenceInfo,
			&vkPhysicalDeviceExternalFenceInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkPhysicalDeviceExternalFenceInfo.");
        return;
    }

    VkExternalFenceProperties vkExternalFenceProperties = {};
    vkExternalFenceProperties.sType = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES;
    vkExternalFenceProperties.pNext = nullptr;

    vkGetPhysicalDeviceExternalFenceProperties(
    		physicalDeviceHandle,
			&vkPhysicalDeviceExternalFenceInfo,
			&vkExternalFenceProperties);

    jvulkan::populateVkExternalFenceProperties(
    		env,
			jVkExternalFenceProperties,
			&vkExternalFenceProperties);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkExternalFenceProperties.");
        return;
    }

    jvulkan::freeMemory(&memoryToFree);
}
