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
 * vkCmdCopyQueryPoolResults.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdCopyQueryPoolResults
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkQueryPool;IILcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;JJLjava/util/EnumSet;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdCopyQueryPoolResults
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkQueryPool, jint firstQuery, jint queryCount, jobject jVkBuffer, jlong dstOffset, jlong stride, jobject jVkQueryResultFlags)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkQueryPool_T *queryPoolHandle = (VkQueryPool_T *)jvulkan::getHandleValue(env, jVkQueryPool);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jVkQueryPool handle");
        return;
    }

    VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkBuffer handle");
        return;
    }

    VkQueryResultFlags flags = (VkQueryResultFlags)jvulkan::getEnumSetValue(
            env,
			jVkQueryResultFlags,
            "com/CIMthetics/jvulkan/VulkanCore/Enums/VkQueryResultFlagBits");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getEnumSetValue");
        return;
    }

    vkCmdCopyQueryPoolResults(
    		commandBufferHandle,
			queryPoolHandle,
			(unsigned int)firstQuery,
			(unsigned int)queryCount,
			bufferHandle,
			(unsigned long int)dstOffset,
			(unsigned long int)stride,
			flags);
}
