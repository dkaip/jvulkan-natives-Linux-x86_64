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
 * vkGetDeviceGroupSurfacePresentModesKHR.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetDeviceGroupSurfacePresentModesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkSurfaceKHR;Ljava/util/EnumSet;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetDeviceGroupSurfacePresentModesKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSurfaceKHR, jobject jVkDeviceGroupPresentModeFlagsKHR)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkSurfaceKHR_T *surfaceHandle = (VkSurfaceKHR_T *)jvulkan::getHandleValue(env, jVkSurfaceKHR);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkSurfaceKHR handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkDeviceGroupPresentModeFlagsKHR modes = 0;

	VkResult result = vkGetDeviceGroupSurfacePresentModesKHR(
			deviceHandle,
			surfaceHandle,
			&modes);

	jvulkan::populateVkDeviceGroupPresentModeFlagsKHR(env, jVkDeviceGroupPresentModeFlagsKHR, modes);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling populateVkDeviceGroupPresentModeFlagsKHR.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	return jvulkan::createVkResult(env, result);
}
