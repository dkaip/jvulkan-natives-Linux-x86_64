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
 * vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkFramebufferMixedSamplesCombinationNVCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkPhysicalDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t count = 0;
    VkResult result = vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    		physicalDeviceHandle,
			&count,
			nullptr);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkFramebufferMixedSamplesCombinationNV *vkFramebufferMixedSamplesCombinationNV = (VkFramebufferMixedSamplesCombinationNV *)calloc(count, sizeof(VkFramebufferMixedSamplesCombinationNV));
    if (vkFramebufferMixedSamplesCombinationNV == nullptr)
    {
    	LOGERROR(env, "Ran out of memory trying to allocate %d VkFramebufferMixedSamplesCombinationNV structures.", count);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    result = vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    		physicalDeviceHandle,
			&count,
			vkFramebufferMixedSamplesCombinationNV);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jvulkan::populateVkFramebufferMixedSamplesCombinationNVCollection(
			env,
			jVkFramebufferMixedSamplesCombinationNVCollection,
			vkFramebufferMixedSamplesCombinationNV,
			count);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling populateVkFramebufferMixedSamplesCombinationNVCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    free(vkFramebufferMixedSamplesCombinationNV);

    return jvulkan::createVkResult(env, result);
}
