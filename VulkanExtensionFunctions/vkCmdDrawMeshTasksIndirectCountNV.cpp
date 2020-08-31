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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdDrawMeshTasksIndirectCountNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;JLcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;JII)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdDrawMeshTasksIndirectCountNV
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkBuffer, jlong jOffset, jobject jCountBuffer, jlong jCountBufferOffset, jint jMaxDrawCount, jint jStride)
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

    VkDeviceSize offset = (VkDeviceSize)jOffset;

    VkBuffer_T *countBufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jCountBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jCountBuffer handle");
        return;
    }

    VkDeviceSize countBufferOffset = (VkDeviceSize)jCountBufferOffset;
    uint32_t maxDrawCount = (uint32_t)jMaxDrawCount;
    uint32_t stride = (uint32_t)jStride;

    vkCmdDrawMeshTasksIndirectCountNV(
    		commandBufferHandle,
			bufferHandle,
			offset,
			countBufferHandle,
			countBufferOffset,
			maxDrawCount,
			stride);
}
