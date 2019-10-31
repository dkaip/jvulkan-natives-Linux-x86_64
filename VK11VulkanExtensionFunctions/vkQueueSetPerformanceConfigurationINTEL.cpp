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
 * vkQueueSetPerformanceConfigurationINTEL.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkQueueSetPerformanceConfigurationINTEL
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkQueue;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkPerformanceConfigurationINTEL;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkQueueSetPerformanceConfigurationINTEL
  (JNIEnv *env, jobject, jobject jVkQueue, jobject jVkPerformanceConfigurationINTEL)
{
	VkQueue_T *queueHandle = (VkQueue_T *)jvulkan::getHandleValue(env, jVkQueue);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkQueue");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	LOGERROR(env, "%s", "Not Implemented Yet.");
    return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
}