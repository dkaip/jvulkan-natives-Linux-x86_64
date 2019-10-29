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
 * vkGetSemaphoreFdKHR.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetSemaphoreFdKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkSemaphoreGetFdInfoKHR;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/IntReturnValue;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetSemaphoreFdKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSemaphoreGetFdInfoKHR, jobject jFd)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    std::vector<void *> memoryToFree(5);
    VkSemaphoreGetFdInfoKHR vkSemaphoreGetFdInfoKHR = {};
    jvulkan::getVkSemaphoreGetFdInfoKHR(
            env,
			jVkSemaphoreGetFdInfoKHR,
			&vkSemaphoreGetFdInfoKHR,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkSemaphoreGetFdInfoKHR.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int theFd = -1;

    VkResult result = vkGetSemaphoreFdKHR(
    		deviceHandle,
			&vkSemaphoreGetFdInfoKHR,
			&theFd);

    jvulkan::setIntReturnValue(env, jFd, theFd);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
