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
 * vkGetDisplayModePropertiesKHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetDisplayModePropertiesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkDisplayKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetDisplayModePropertiesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkDisplayKHR, jobject jVkDisplayModePropertiesKHRCollection)
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

    uint32_t numberOfVkDisplayModePropertiesKHRs = 0;
    VkDisplayModePropertiesKHR *vkDisplayModePropertiesKHRs = nullptr;

    VkResult result = vkGetDisplayModePropertiesKHR(
    		physicalDeviceHandle,
			displayHandle,
			&numberOfVkDisplayModePropertiesKHRs,
			nullptr);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "Error calling vkGetDisplayModePropertiesKHR %d", result);
        return jvulkan::createVkResult(env, result);
    }

    vkDisplayModePropertiesKHRs = (VkDisplayModePropertiesKHR *)calloc(numberOfVkDisplayModePropertiesKHRs, sizeof(VkDisplayModePropertiesKHR));
    if ( vkDisplayModePropertiesKHRs == nullptr)
    {
    	LOGERROR(env, "Error trying to allocate memory for %d vkDisplayModePropertiesKHRs structures.", numberOfVkDisplayModePropertiesKHRs);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    result = vkGetDisplayModePropertiesKHR(
    		physicalDeviceHandle,
			displayHandle,
			&numberOfVkDisplayModePropertiesKHRs,
			vkDisplayModePropertiesKHRs);

    if (result != VK_SUCCESS)
    {
    	free(vkDisplayModePropertiesKHRs);
    	LOGERROR(env, "Error calling vkGetDisplayModePropertiesKHR %d", result);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    // TODO we may need to do pNext chain processing here
    jvulkan::populateVkDisplayModePropertiesKHRCollection(
			env,
			jVkDisplayModePropertiesKHRCollection,
			vkDisplayModePropertiesKHRs,
			numberOfVkDisplayModePropertiesKHRs);

	free(vkDisplayModePropertiesKHRs);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling populateVkDisplayModePropertiesKHRCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    return jvulkan::createVkResult(env, result);
}
