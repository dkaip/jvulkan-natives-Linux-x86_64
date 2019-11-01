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
 * vkGetDisplayPlaneCapabilities2KHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetDisplayPlaneCapabilities2KHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkDisplayPlaneInfo2KHR;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkDisplayPlaneCapabilities2KHR;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetDisplayPlaneCapabilities2KHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject VkDisplayPlaneInfo2KHR, jobject jVkDisplayPlaneCapabilities2KHR)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    struct VkDisplayPlaneInfo2KHR vkDisplayPlaneInfo2KHR = {};
    jvulkan::getVkDisplayPlaneInfo2KHR(
            env,
			VkDisplayPlaneInfo2KHR,
			&vkDisplayPlaneInfo2KHR,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkDisplayPlaneInfo2KHR.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDisplayPlaneCapabilities2KHR vkDisplayPlaneCapabilities2KHR = {};
    vkDisplayPlaneCapabilities2KHR.sType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR;
    vkDisplayPlaneCapabilities2KHR.pNext = nullptr;

    VkResult result = vkGetDisplayPlaneCapabilities2KHR(
    		physicalDeviceHandle,
			&vkDisplayPlaneInfo2KHR,
			&vkDisplayPlaneCapabilities2KHR);

    jvulkan::populateVkDisplayPlaneCapabilities2KHR(
    		env,
			jVkDisplayPlaneCapabilities2KHR,
			&vkDisplayPlaneCapabilities2KHR);

    jvulkan::freeMemory(&memoryToFree);

    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkDisplayPlaneCapabilities2KHR.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    return jvulkan::createVkResult(env, result);
}
