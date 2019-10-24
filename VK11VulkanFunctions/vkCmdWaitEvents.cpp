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
 * vkCmdWaitEvents.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdWaitEvents
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;Ljava/util/Collection;Ljava/util/EnumSet;Ljava/util/EnumSet;Ljava/util/Collection;Ljava/util/Collection;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdWaitEvents
  (JNIEnv *env,
		  jobject,
		  jobject jVkCommandBuffer,
		  jobject jVkEventCollection,
		  jobject jSrcStageMask,
		  jobject jDstStageMask,
		  jobject jVkMemoryBarrierCollection,
		  jobject jVkBufferMemoryBarrierCollection,
		  jobject jVkImageMemoryBarrierCollection)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkEvents = 0;
    VkEvent *vkEvents = nullptr;
	jvulkan::getVulkanHandleCollection(
			env,
			jVkEventCollection,
			(void **)&vkEvents,
			&numberOfVkEvents,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVulkanHandleCollection");
		return;
	}

    VkPipelineStageFlags srcStageMask = jvulkan::getEnumSetValue(
            env,
			jSrcStageMask,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getEnumSetValue");
		return;
	}

    VkPipelineStageFlags dstStageMask = jvulkan::getEnumSetValue(
            env,
			jDstStageMask,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getEnumSetValue");
		return;
	}

    int numberOfVkMemoryBarriers = 0;
    VkMemoryBarrier *vkMemoryBarriers = nullptr;
	jvulkan::getVkMemoryBarrierCollection(
			env,
			jVkMemoryBarrierCollection,
			&vkMemoryBarriers,
			&numberOfVkMemoryBarriers,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkMemoryBarrierCollection");
		return;
	}

    int numberOfVkBufferMemoryBarriers = 0;
    VkBufferMemoryBarrier *vkBufferMemoryBarriers = nullptr;
	jvulkan::getVkBufferMemoryBarrierCollection(
			env,
			jVkBufferMemoryBarrierCollection,
			&vkBufferMemoryBarriers,
			&numberOfVkBufferMemoryBarriers,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkBufferMemoryBarrierCollection");
		return;
	}

    int numberOfVkImageMemoryBarriers = 0;
    VkImageMemoryBarrier *vkImageMemoryBarriers = nullptr;
	jvulkan::getVkImageMemoryBarrierCollection(
			env,
			jVkImageMemoryBarrierCollection,
			&vkImageMemoryBarriers,
			&numberOfVkImageMemoryBarriers,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkImageMemoryBarrierCollection");
		return;
	}

	vkCmdWaitEvents(
			commandBufferHandle,
			numberOfVkEvents,
			vkEvents,
			srcStageMask,
			dstStageMask,
			numberOfVkMemoryBarriers,
			vkMemoryBarriers,
			numberOfVkBufferMemoryBarriers,
			vkBufferMemoryBarriers,
			numberOfVkImageMemoryBarriers,
			vkImageMemoryBarriers);

    jvulkan::freeMemory(&memoryToFree);
}
