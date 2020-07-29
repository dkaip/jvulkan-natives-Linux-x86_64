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
 * vkGetDisplayPlaneCapabilitiesKHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetDisplayPlaneCapabilitiesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayModeKHR;ILcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlaneCapabilitiesKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetDisplayPlaneCapabilitiesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkDisplayModeKHR, jint planeIndex, jobject jVkDisplayPlaneCapabilitiesKHR)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDisplayModeKHR_T *displayModeHandle = (VkDisplayModeKHR_T *)jvulkan::getHandleValue(env, jVkDisplayModeKHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDisplayModeKHR handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDisplayPlaneCapabilitiesKHR vkDisplayPlaneCapabilitiesKHR = {};

    VkResult result = vkGetDisplayPlaneCapabilitiesKHR(
    		physicalDeviceHandle,
			displayModeHandle,
			planeIndex,
			&vkDisplayPlaneCapabilitiesKHR);

    jvulkan::populateVkDisplayPlaneCapabilitiesKHR(
    		env,
			jVkDisplayPlaneCapabilitiesKHR,
			&vkDisplayPlaneCapabilitiesKHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkDisplayPlaneCapabilitiesKHR.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    return jvulkan::createVkResult(env, result);
}
