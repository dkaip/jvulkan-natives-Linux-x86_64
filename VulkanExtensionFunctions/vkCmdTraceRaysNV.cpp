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
 * Method:    vkCmdTraceRaysNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;JLcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;JJLcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;JJLcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;JJIII)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdTraceRaysNV
  ( JNIEnv *env,
    jobject,
	jobject jVkCommandBuffer,
	jobject jRaygenShaderBindingTableBuffer,
	jlong   jRaygenShaderBindingOffset,
	jobject jMissShaderBindingTableBuffer,
	jlong   jMissShaderBindingOffset,
	jlong   jMissShaderBindingStride,
	jobject jHitShaderBindingTableBuffer,
	jlong   jHitShaderBindingOffset,
	jlong   jHitShaderBindingStride,
	jobject jCallableShaderBindingTableBuffer,
	jlong   jCallableShaderBindingOffset,
	jlong   jCallableShaderBindingStride,
	jint    jWidth,
	jint    jHeight,
	jint    jDepth)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkBuffer_T *raygenShaderBindingTableBuffer = (VkBuffer_T *)jvulkan::getHandleValue(env, jRaygenShaderBindingTableBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jRaygenShaderBindingTableBuffer handle");
        return;
    }

    VkDeviceSize raygenShaderBindingOffset = (VkDeviceSize)jRaygenShaderBindingOffset;

    VkBuffer_T *missShaderBindingTableBuffer = (VkBuffer_T *)jvulkan::getHandleValue(env, jMissShaderBindingTableBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jMissShaderBindingTableBuffer handle");
        return;
    }

    VkDeviceSize missShaderBindingOffset = (VkDeviceSize)jMissShaderBindingOffset;
    VkDeviceSize missShaderBindingStride = (VkDeviceSize)jMissShaderBindingStride;

    VkBuffer_T *hitShaderBindingTableBuffer = (VkBuffer_T *)jvulkan::getHandleValue(env, jHitShaderBindingTableBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jHitShaderBindingTableBuffer handle");
        return;
    }

    VkDeviceSize hitShaderBindingOffset = (VkDeviceSize)jHitShaderBindingOffset;
    VkDeviceSize hitShaderBindingStride = (VkDeviceSize)jHitShaderBindingStride;

    VkBuffer_T *callableShaderBindingTableBuffer = (VkBuffer_T *)jvulkan::getHandleValue(env, jCallableShaderBindingTableBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jCallableShaderBindingTableBuffer handle");
        return;
    }

    VkDeviceSize callableShaderBindingOffset = (VkDeviceSize)jCallableShaderBindingOffset;
    VkDeviceSize callableShaderBindingStride = (VkDeviceSize)jCallableShaderBindingStride;

    uint32_t width  = (uint32_t)jWidth;
    uint32_t height = (uint32_t)jHeight;
    uint32_t depth  = (uint32_t)jDepth;

    vkCmdTraceRaysNV(
    		commandBufferHandle,
			raygenShaderBindingTableBuffer,
			raygenShaderBindingOffset,
			missShaderBindingTableBuffer,
			missShaderBindingOffset,
			missShaderBindingStride,
			hitShaderBindingTableBuffer,
			hitShaderBindingOffset,
			hitShaderBindingStride,
			callableShaderBindingTableBuffer,
			callableShaderBindingOffset,
			callableShaderBindingStride,
			width,
			height,
			depth);
}
