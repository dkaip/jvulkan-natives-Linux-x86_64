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
 * vkGetDeviceGroupPresentCapabilitiesKHR.cpp
 *
 *  Created on: Sep 26, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetDeviceGroupPresentCapabilitiesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDeviceGroupPresentCapabilitiesKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetDeviceGroupPresentCapabilitiesKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDeviceGroupPresentCapabilitiesKHR)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(10);
    VkDeviceGroupPresentCapabilitiesKHR vkDeviceGroupPresentCapabilitiesKHR = {};
    vkDeviceGroupPresentCapabilitiesKHR.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR;
    vkDeviceGroupPresentCapabilitiesKHR.pNext = nullptr;

    VkResult result = vkGetDeviceGroupPresentCapabilitiesKHR(
    		deviceHandle,
			&vkDeviceGroupPresentCapabilitiesKHR);

    jvulkan::populateVkDeviceGroupPresentCapabilitiesKHR(
    		env,
			jVkDeviceGroupPresentCapabilitiesKHR,
			&vkDeviceGroupPresentCapabilitiesKHR,
			&memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkDeviceGroupPresentCapabilitiesKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
