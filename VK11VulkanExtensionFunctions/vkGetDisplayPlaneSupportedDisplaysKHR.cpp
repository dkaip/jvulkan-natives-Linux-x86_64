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
 * vkGetDisplayPlaneSupportedDisplaysKHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetDisplayPlaneSupportedDisplaysKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;ILjava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetDisplayPlaneSupportedDisplaysKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jint planeIndex, jobject jVkDisplayKHRCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t numberOfVkDisplayKHRs = 0;
    VkDisplayKHR *vkDisplayKHRs = nullptr;

    VkResult result = vkGetDisplayPlaneSupportedDisplaysKHR(
    		physicalDeviceHandle,
			planeIndex,
			&numberOfVkDisplayKHRs,
			vkDisplayKHRs);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "Error calling vkGetDisplayPlaneSupportedDisplaysKHR %d", result);
        return jvulkan::createVkResult(env, result);
    }

    vkDisplayKHRs = (VkDisplayKHR *)calloc(numberOfVkDisplayKHRs, sizeof(VkDisplayKHR));
    if ( vkDisplayKHRs == nullptr)
    {
    	LOGERROR(env, "Error trying to allocate memory for %d vkDisplayKHRs structures.", numberOfVkDisplayKHRs);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    result = vkGetDisplayPlaneSupportedDisplaysKHR(
    		physicalDeviceHandle,
			planeIndex,
			&numberOfVkDisplayKHRs,
			vkDisplayKHRs);
    if (result != VK_SUCCESS)
    {
    	free(vkDisplayKHRs);
    	LOGERROR(env, "Error calling vkGetDisplayPlaneSupportedDisplaysKHR %d", result);
        return jvulkan::createVkResult(env, result);
    }

    jvulkan::populateVulkanHandleCollection(
    		env,
			"com/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkDisplayKHR",
			jVkDisplayKHRCollection,
			numberOfVkDisplayKHRs,
			(const void**)vkDisplayKHRs);
    if (env->ExceptionOccurred())
    {
    	free(vkDisplayKHRs);
    	LOGERROR(env, "%s", "Error calling populateVulkanHandleCollection.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	free(vkDisplayKHRs);

	return jvulkan::createVkResult(env, result);

}
