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
 * vkCmdUpdateBuffer.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdUpdateBuffer
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;J[B)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdUpdateBuffer
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkBuffer, jlong dstOffset, jbyteArray jData)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkBuffer handle");
        return;
    }

    uint8_t *data = nullptr;
    jsize arrayLength = 0;
	arrayLength = env->GetArrayLength(jData);

	data = (uint8_t *)calloc(arrayLength, sizeof(uint8_t));

	env->GetByteArrayRegion(jData, 0, arrayLength, (signed char *)data);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling GetByteArrayRegion");
		return;
	}

	vkCmdUpdateBuffer(
			commandBufferHandle,
			bufferHandle,
			dstOffset,
			arrayLength,
			data);

	free(data);
}
