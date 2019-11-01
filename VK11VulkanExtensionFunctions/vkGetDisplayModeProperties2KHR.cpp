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
 * vkGetDisplayModeProperties2KHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetDisplayModeProperties2KHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkDisplayKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetDisplayModeProperties2KHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkDisplayKHR, jobject jVkDisplayModeProperties2KHRCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDisplayKHR_T *displayHandle = (VkDisplayKHR_T *)jvulkan::getHandleValue(env, jVkDisplayKHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDisplayKHR handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t numberOfVkDisplayModeProperties2KHRs = 0;
    VkDisplayModeProperties2KHR *vkDisplayModeProperties2KHRs = nullptr;

    VkResult result = vkGetDisplayModeProperties2KHR(
    		physicalDeviceHandle,
			displayHandle,
			&numberOfVkDisplayModeProperties2KHRs,
			nullptr);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "Error calling vkGetDisplayModeProperties2KHR %d", result);
        return jvulkan::createVkResult(env, result);
    }

    vkDisplayModeProperties2KHRs = (VkDisplayModeProperties2KHR *)calloc(numberOfVkDisplayModeProperties2KHRs, sizeof(VkDisplayModeProperties2KHR));
    if ( vkDisplayModeProperties2KHRs == nullptr)
    {
    	LOGERROR(env, "Error trying to allocate memory for %d vkDisplayModeProperties2KHR structures.", numberOfVkDisplayModeProperties2KHRs);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    for(int i = 0; i < numberOfVkDisplayModeProperties2KHRs; i++)
    {
    	vkDisplayModeProperties2KHRs[i].sType = VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR;
    	vkDisplayModeProperties2KHRs[i].pNext = nullptr;  // This line is not really needed because of the calloc above
    }

    result = vkGetDisplayModeProperties2KHR(
    		physicalDeviceHandle,
			displayHandle,
			&numberOfVkDisplayModeProperties2KHRs,
			vkDisplayModeProperties2KHRs);

    if (result != VK_SUCCESS)
    {
    	free(vkDisplayModeProperties2KHRs);
    	LOGERROR(env, "Error calling vkGetDisplayModeProperties2KHR %d", result);
        return jvulkan::createVkResult(env, result);
    }

    jvulkan::populateVkDisplayModeProperties2KHRCollection(
			env,
			jVkDisplayModeProperties2KHRCollection,
			vkDisplayModeProperties2KHRs,
			numberOfVkDisplayModeProperties2KHRs);

	free(vkDisplayModeProperties2KHRs);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling populateVkPipelineExecutableStatisticKHRCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    return jvulkan::createVkResult(env, result);
}
