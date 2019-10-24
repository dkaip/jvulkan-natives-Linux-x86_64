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
 * vkCmdDrawIndirectByteCountEXT.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdDrawIndirectByteCountEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;IILcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkBuffer;JII)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdDrawIndirectByteCountEXT
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jint instanceCount, jint firstInstance, jobject jVkBuffer, jlong counterBufferOffset, jint counterOffset, jint vertexStride)
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

    vkCmdDrawIndirectByteCountEXT(
    		commandBufferHandle,
			instanceCount,
			firstInstance,
			bufferHandle,
			counterBufferOffset,
			counterOffset,
			vertexStride);
}
