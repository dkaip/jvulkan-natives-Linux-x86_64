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
 * vkAcquirePerformanceConfigurationINTEL.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkAcquirePerformanceConfigurationINTEL
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPerformanceConfigurationAcquireInfoINTEL;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkPerformanceConfigurationINTEL;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkAcquirePerformanceConfigurationINTEL
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPerformanceConfigurationAcquireInfoINTEL, jobject jVkPerformanceConfigurationINTEL)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    VkPerformanceConfigurationAcquireInfoINTEL vkPerformanceConfigurationAcquireInfoINTEL = {};

    jvulkan::getVkPerformanceConfigurationAcquireInfoINTEL(
            env,
			jVkPerformanceConfigurationAcquireInfoINTEL,
            &vkPerformanceConfigurationAcquireInfoINTEL,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkPerformanceConfigurationAcquireInfoINTEL.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPerformanceConfigurationINTEL_T *configurationHandle = nullptr;

    VkResult result = vkAcquirePerformanceConfigurationINTEL(
    		deviceHandle,
			&vkPerformanceConfigurationAcquireInfoINTEL,
			&configurationHandle);

    jvulkan::setHandleValue(env, jVkPerformanceConfigurationINTEL, configurationHandle);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
