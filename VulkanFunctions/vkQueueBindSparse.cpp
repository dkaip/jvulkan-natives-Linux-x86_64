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
 * vkQueueBindSparse.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkQueueBindSparse
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkQueue;Ljava/util/Collection;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkFence;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkQueueBindSparse
  (JNIEnv *env, jobject, jobject jVkQueue, jobject jVkBindSparseInfoCollection, jobject jVkFence)
{
	VkQueue_T *queueHandle = (VkQueue_T *)jvulkan::getHandleValue(env, jVkQueue);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkQueue handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkBindSparseInfos = 0;
    VkBindSparseInfo *vkBindSparseInfos = nullptr;
	jvulkan::getVkBindSparseInfoCollection(
			env,
			jVkBindSparseInfoCollection,
			&vkBindSparseInfos,
			&numberOfVkBindSparseInfos,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkBindSparseInfoCollection");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkFence fence = nullptr;
	if (jVkFence != nullptr)
	{
		fence = (VkFence_T *)jvulkan::getHandleValue(env, jVkFence);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not retrieve VkFence handle");
			return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
		}
	}

	VkResult result = vkQueueBindSparse(
			queueHandle,
			numberOfVkBindSparseInfos,
			vkBindSparseInfos,
			fence);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
