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
 * vkCmdSetViewport.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdSetViewport
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;ILjava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdSetViewport
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jint firstViewport, jobject jVkViewportCollection)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkViewports = 0;
    VkViewport *vkViewports = nullptr;
	jvulkan::getVkViewportCollection(
			env,
			jVkViewportCollection,
			&vkViewports,
			&numberOfVkViewports,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkViewportCollection");
		return;
	}

	vkCmdSetViewport(
			commandBufferHandle,
			firstViewport,
			numberOfVkViewports,
			vkViewports);

    jvulkan::freeMemory(&memoryToFree);
}
