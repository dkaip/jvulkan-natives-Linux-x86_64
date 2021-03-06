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
 * vkGetPipelineExecutableInternalRepresentationsKHR.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPipelineExecutableInternalRepresentationsKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineExecutableInfoKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPipelineExecutableInternalRepresentationsKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPipelineExecutableInfoKHR, jobject jVkPipelineExecutableInternalRepresentationKHRCollection)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(20);

    VkPipelineExecutableInfoKHR vkPipelineExecutableInfoKHR = {};
    jvulkan::getVkPipelineExecutableInfoKHR(
            env,
			jVkPipelineExecutableInfoKHR,
			&vkPipelineExecutableInfoKHR,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getVkPhysicalDeviceSurfaceInfo2KHR.");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t count = 0;
    VkResult result = vkGetPipelineExecutableInternalRepresentationsKHR(
    		deviceHandle,
			&vkPipelineExecutableInfoKHR,
			&count,
			nullptr);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling vkGetPipelineExecutableInternalRepresentationsKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPipelineExecutableInternalRepresentationKHR *vkPipelineExecutableInternalRepresentationKHR = (VkPipelineExecutableInternalRepresentationKHR *)calloc(count, sizeof(VkPipelineExecutableInternalRepresentationKHR));
    if (vkPipelineExecutableInternalRepresentationKHR == nullptr)
    {
    	LOGERROR(env, "Ran out of memory trying to allocate %d VkPipelineExecutableInternalRepresentationKHR structures.", count);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    result = vkGetPipelineExecutableInternalRepresentationsKHR(
    		deviceHandle,
			&vkPipelineExecutableInfoKHR,
			&count,
			vkPipelineExecutableInternalRepresentationKHR);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling vkGetPipelineExecutableInternalRepresentationsKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jvulkan::populateVkPipelineExecutableInternalRepresentationKHRCollection(
			env,
			jVkPipelineExecutableInternalRepresentationKHRCollection,
			vkPipelineExecutableInternalRepresentationKHR,
			count);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling populateVkPipelineExecutableInternalRepresentationKHRCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    free(vkPipelineExecutableInternalRepresentationKHR);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
