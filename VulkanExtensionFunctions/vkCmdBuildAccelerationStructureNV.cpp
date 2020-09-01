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
 * Method:    vkCmdBuildAccelerationStructureNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkAccelerationStructureInfoNV;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;JZLcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkAccelerationStructureKHR;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkAccelerationStructureKHR;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;J)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdBuildAccelerationStructureNV
  ( JNIEnv *env,
    jobject,
	jobject jVkCommandBuffer,
	jobject jInfoObject,
	jobject jInstanceData,
	jlong jInstanceOffset,
	jboolean jUpdate,
	jobject jDst,
	jobject jSrc,
	jobject jScratchObject,
	jlong jScratchOffset)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkAccelerationStructureInfoNV info = {};

    jvulkan::getVkAccelerationStructureInfoNV(
            env,
			jInfoObject,
            &info,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkAccelerationStructureInfoNV.");
        return;
    }

    VkBuffer_T *instanceDataHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jInstanceData);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jInstanceData handle");
        return;
    }

    VkDeviceSize instanceOffset = (VkDeviceSize)jInstanceOffset;
    VkBool32 update = (VkBool32)jUpdate;

    VkAccelerationStructureKHR_T *dst = (VkAccelerationStructureKHR_T *)jvulkan::getHandleValue(env, jDst);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jDst handle");
        return;
    }

    VkAccelerationStructureKHR_T *src = (VkAccelerationStructureKHR_T *)jvulkan::getHandleValue(env, jSrc);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jSrc handle");
        return;
    }

    VkBuffer_T *scratchHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jScratchObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jScratchObject handle");
        return;
    }

    VkDeviceSize scratchOffset = (VkDeviceSize)jScratchOffset;

    vkCmdBuildAccelerationStructureNV(
    		commandBufferHandle,
			&info,
			instanceDataHandle,
			instanceOffset,
			update,
			dst,
			src,
			scratchHandle,
			scratchOffset);

    jvulkan::freeMemory(&memoryToFree);
}
