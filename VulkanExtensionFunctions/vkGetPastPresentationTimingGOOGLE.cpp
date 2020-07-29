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
 * vkGetPastPresentationTimingGOOGLE.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPastPresentationTimingGOOGLE
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkSwapchainKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPastPresentationTimingGOOGLE
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSwapchainKHR, jobject jVkPastPresentationTimingGOOGLECollection)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkSwapchainKHR_T *swapchainHandle = (VkSwapchainKHR_T *)jvulkan::getHandleValue(env, jVkSwapchainKHR);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkSwapchainKHR handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	uint32_t presentationTimingCount = 0;
	VkResult result = vkGetPastPresentationTimingGOOGLE(
			deviceHandle,
			swapchainHandle,
			&presentationTimingCount,
			nullptr);
	if (result != VK_SUCCESS)
	{
		LOGERROR(env, "%s", "Error calling vkGetPastPresentationTimingGOOGLE.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkPastPresentationTimingGOOGLE *vkPastPresentationTimingGOOGLEs =
			(VkPastPresentationTimingGOOGLE *)calloc(presentationTimingCount, sizeof(VkPastPresentationTimingGOOGLE));
	if (vkPastPresentationTimingGOOGLEs == nullptr)
	{
		LOGERROR(env, "Could not allocate memory for %d vkPastPresentationTimingGOOGLEs.", presentationTimingCount);
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	result = vkGetPastPresentationTimingGOOGLE(
			deviceHandle,
			swapchainHandle,
			&presentationTimingCount,
			vkPastPresentationTimingGOOGLEs);
	if (result != VK_SUCCESS)
	{
		free(vkPastPresentationTimingGOOGLEs);
		LOGERROR(env, "%s", "Error calling vkGetPastPresentationTimingGOOGLE.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	jvulkan::populateVkPastPresentationTimingGOOGLECollection(
			env,
			jVkPastPresentationTimingGOOGLECollection,
			vkPastPresentationTimingGOOGLEs,
			presentationTimingCount);
	if (env->ExceptionOccurred())
	{
		free(vkPastPresentationTimingGOOGLEs);
		LOGERROR(env, "%s", "Error calling populateVkPastPresentationTimingGOOGLECollection.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	free(vkPastPresentationTimingGOOGLEs);

    return jvulkan::createVkResult(env, result);
}
