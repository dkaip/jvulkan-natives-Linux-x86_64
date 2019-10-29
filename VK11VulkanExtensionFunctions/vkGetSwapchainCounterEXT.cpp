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
 * vkGetSwapchainCounterEXT.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetSwapchainCounterEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkSwapchainKHR;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkSurfaceCounterFlagBitsEXT;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/LongReturnValue;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetSwapchainCounterEXT
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSwapchainKHR, jobject jVkSurfaceCounterFlagBitsEXT, jobject jCounterValue)
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

    jclass vkSurfaceCounterFlagBitsEXTEnumClass = env->GetObjectClass(jVkSurfaceCounterFlagBitsEXT);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get class for jVkSurfaceCounterFlagBitsEXT");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkSurfaceCounterFlagBitsEXTEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceCounterFlagBitsEXT vkSurfaceCounterFlagBitsEXTEnumValue = (VkSurfaceCounterFlagBitsEXT)env->CallIntMethod(jVkSurfaceCounterFlagBitsEXT, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	uint64_t counterValue = 0;

	VkResult result = vkGetSwapchainCounterEXT(
			deviceHandle,
			swapchainHandle,
			vkSurfaceCounterFlagBitsEXTEnumValue,
			&counterValue);

    jvulkan::setLongReturnValue(env, jCounterValue, counterValue);

    return jvulkan::createVkResult(env, result);
}
