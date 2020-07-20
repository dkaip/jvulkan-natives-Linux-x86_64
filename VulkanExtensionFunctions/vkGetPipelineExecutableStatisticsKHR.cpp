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
 * vkGetPipelineExecutableStatisticsKHR.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPipelineExecutableStatisticsKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineExecutableInfoKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPipelineExecutableStatisticsKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPipelineExecutableInfoKHR, jobject jVkPipelineExecutableStatisticKHRCollection)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(10);
    VkPipelineExecutableInfoKHR vkPipelineExecutableInfoKHR = {};
    jvulkan::getVkPipelineExecutableInfoKHR(
    		env,
			jVkPipelineExecutableInfoKHR,
			&vkPipelineExecutableInfoKHR,
			&memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkPipelineExecutableInfoKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t statisticCount = 0;
    VkResult result = vkGetPipelineExecutableStatisticsKHR(
    		deviceHandle,
			&vkPipelineExecutableInfoKHR,
			&statisticCount,
			nullptr);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling vkGetPipelineExecutableStatisticsKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPipelineExecutableStatisticKHR *vkPipelineExecutableStatisticKHR = (VkPipelineExecutableStatisticKHR *)calloc(statisticCount, sizeof(VkPipelineExecutableStatisticKHR));
    if (vkPipelineExecutableStatisticKHR == nullptr)
    {
    	LOGERROR(env, "Ran out of memory trying to allocate %d VkPipelineExecutableStatisticKHR structures.", statisticCount);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    result = vkGetPipelineExecutableStatisticsKHR(
    		deviceHandle,
			&vkPipelineExecutableInfoKHR,
			&statisticCount,
			vkPipelineExecutableStatisticKHR);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling vkGetPipelineExecutableStatisticsKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jvulkan::populateVkPipelineExecutableStatisticKHRCollection(
			env,
			jVkPipelineExecutableStatisticKHRCollection,
			vkPipelineExecutableStatisticKHR,
			statisticCount);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling populateVkPipelineExecutableStatisticKHRCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    free(vkPipelineExecutableStatisticKHR);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
