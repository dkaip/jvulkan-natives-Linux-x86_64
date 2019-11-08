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
 * vkGetSemaphoreCounterValueKHR.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetSemaphoreCounterValueKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkSemaphore;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/LongReturnValue;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetSemaphoreCounterValueKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSemaphore, jobject jLongReturnValue)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkSemaphore_T *semaphoreHandle = (VkSemaphore_T *)jvulkan::getHandleValue(env, jVkSemaphore);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkSemaphore handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	uint64_t value = 0;
	VkResult result = vkGetSemaphoreCounterValueKHR(
			deviceHandle,
			semaphoreHandle,
			&value);

    jvulkan::setLongReturnValue(env, jLongReturnValue, value);

	return jvulkan::createVkResult(env, result);
}
