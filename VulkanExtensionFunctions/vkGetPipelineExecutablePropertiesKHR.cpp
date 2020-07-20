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
 * vkGetPipelineExecutablePropertiesKHR.cpp
 *
 *  Created on: Sep 29, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPipelineExecutablePropertiesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineInfoKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPipelineExecutablePropertiesKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPipelineInfoKHR, jobject jVkPipelineExecutablePropertiesKHRCollection)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(10);
    VkPipelineInfoKHR vkPipelineInfoKHR = {};
    jvulkan::getVkPipelineInfoKHR(
    		env,
			jVkPipelineInfoKHR,
			&vkPipelineInfoKHR,
			&memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkPipelineInfoKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t propertiesCount = 0;
    VkResult result = vkGetPipelineExecutablePropertiesKHR(
    		deviceHandle,
			&vkPipelineInfoKHR,
			&propertiesCount,
			nullptr);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling vkGetPipelineExecutablePropertiesKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPipelineExecutablePropertiesKHR *vkPipelineExecutablePropertiesKHR = (VkPipelineExecutablePropertiesKHR *)calloc(propertiesCount, sizeof(VkPipelineExecutablePropertiesKHR));
    if (vkPipelineExecutablePropertiesKHR == nullptr)
    {
    	LOGERROR(env, "Ran out of memory trying to allocate %d VkPipelineExecutablePropertiesKHR structures.", propertiesCount);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    result = vkGetPipelineExecutablePropertiesKHR(
    		deviceHandle,
			&vkPipelineInfoKHR,
			&propertiesCount,
			vkPipelineExecutablePropertiesKHR);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling vkGetPipelineExecutablePropertiesKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jvulkan::populateVkPipelineExecutablePropertiesKHRCollection(
			env,
			jVkPipelineExecutablePropertiesKHRCollection,
			vkPipelineExecutablePropertiesKHR,
			propertiesCount);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling populateVkPipelineExecutablePropertiesKHRCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    free(vkPipelineExecutablePropertiesKHR);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
