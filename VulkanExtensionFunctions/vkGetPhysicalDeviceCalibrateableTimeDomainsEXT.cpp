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
 * vkGetPhysicalDeviceCalibrateableTimeDomainsEXT.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceCalibrateableTimeDomainsEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkTimeDomainEXTCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	uint32_t timeDomainCount = 0;
	VkResult result = vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
			physicalDeviceHandle,
			&timeDomainCount,
			nullptr);
	if (result != VK_SUCCESS)
	{
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceCalibrateableTimeDomainsEXT.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkTimeDomainEXT *vkTimeDomainEXTs =
			(VkTimeDomainEXT *)calloc(timeDomainCount, sizeof(VkTimeDomainEXT));
	if (vkTimeDomainEXTs == nullptr)
	{
		LOGERROR(env, "Error trying to allocate memory for %d VkTimeDomainEXTs.", timeDomainCount);
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	result = vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
			physicalDeviceHandle,
			&timeDomainCount,
			vkTimeDomainEXTs);
	if (result != VK_SUCCESS)
	{
		free(vkTimeDomainEXTs);
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceCalibrateableTimeDomainsEXT.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	jvulkan::populateVkTimeDomainEXTCollection(
			env,
			jVkTimeDomainEXTCollection,
			vkTimeDomainEXTs,
			timeDomainCount);
	if (env->ExceptionOccurred())
	{
		free(vkTimeDomainEXTs);
		LOGERROR(env, "%s", "Error calling populateVkTimeDomainEXTCollection");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	free(vkTimeDomainEXTs);

	return jvulkan::createVkResult(env, result);
}
