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
 * vkCmdSetViewportWScalingNV.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdSetViewportWScalingNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;ILjava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdSetViewportWScalingNV
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jint jFirstViewport, jobject jVkViewportWScalingNVCollection)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    uint32_t firstViewport = (uint32_t)jFirstViewport;

    std::vector<void *> memoryToFree(5);
    int numberOfVkViewportWScalingNVs = 0;
    VkViewportWScalingNV *vkViewportWScalingNVs = nullptr;
	jvulkan::getVkViewportWScalingNVCollection(
			env,
			jVkViewportWScalingNVCollection,
			&vkViewportWScalingNVs,
			&numberOfVkViewportWScalingNVs,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkViewportWScalingNVCollection");
		return;
	}

	vkCmdSetViewportWScalingNV(
			commandBufferHandle,
			firstViewport,
			numberOfVkViewportWScalingNVs,
			vkViewportWScalingNVs);

	jvulkan::freeMemory(&memoryToFree);
}
