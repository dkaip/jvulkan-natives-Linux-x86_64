/*
 * Copyright 2020 Douglas Kaip
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
 * vkCmdBindVertexBuffers2EXT.cpp
 *
 *  Created on: Aug 29, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdBindVertexBuffers2EXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;ILjava/util/Collection;[J[J[J)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdBindVertexBuffers2EXT
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jint jFirstBinding, jobject jVkBufferCollectionObject, jlongArray jOffsetsArray, jlongArray jSizesArray, jlongArray jStridesArray)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    uint32_t firstBinding = (uint32_t)jFirstBinding;

    std::vector<void *> memoryToFree(5);
    int numberOfVkBuffers = 0;
    VkBuffer *vkBufferHandles = nullptr;
	jvulkan::getVkBufferCollection(
			env,
			jVkBufferCollectionObject,
			&vkBufferHandles,
			&numberOfVkBuffers,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkBufferCollection.");
		return;
	}

    long *offsets = nullptr;
    jsize arrayLength = 0;
    if (jOffsetsArray != nullptr)
    {
        arrayLength = env->GetArrayLength(jOffsetsArray);

        offsets = (long *)calloc(arrayLength, sizeof(long));

        env->GetLongArrayRegion(jOffsetsArray, 0, arrayLength, offsets);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetLongArrayRegion");
            return;
        }
    }

    if (numberOfVkBuffers != arrayLength)
    {
    	LOGERROR(env, "%s", "The number of elements in jVkBufferCollection and jOffsetsArray must be the same.");
        jvulkan::freeMemory(&memoryToFree);
    	free(offsets);
    	return;
    }

    long *sizes = nullptr;
    arrayLength = 0;
    if (jSizesArray != nullptr)
    {
        arrayLength = env->GetArrayLength(jSizesArray);

        sizes = (long *)calloc(arrayLength, sizeof(long));

        env->GetLongArrayRegion(jSizesArray, 0, arrayLength, sizes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetLongArrayRegion");
            return;
        }
    }

    if (jSizesArray != nullptr && numberOfVkBuffers != arrayLength)
    {
    	LOGERROR(env, "%s", "The number of elements in jVkBufferCollection and jSizesArray (if present) must be the same.");
        jvulkan::freeMemory(&memoryToFree);
    	free(offsets);
    	free(sizes);
    	return;
    }

    long *strides = nullptr;
    arrayLength = 0;
    if (jStridesArray != nullptr)
    {
        arrayLength = env->GetArrayLength(jStridesArray);

        strides = (long *)calloc(arrayLength, sizeof(long));

        env->GetLongArrayRegion(jStridesArray, 0, arrayLength, strides);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetLongArrayRegion");
            return;
        }
    }

    if (jStridesArray != nullptr && numberOfVkBuffers != arrayLength)
    {
    	LOGERROR(env, "%s", "The number of elements in jVkBufferCollection and jStridesArray (if present) must be the same.");
        jvulkan::freeMemory(&memoryToFree);
    	free(offsets);
    	free(sizes);
    	free(strides);
    	return;
    }

    vkCmdBindVertexBuffers2EXT(
    		commandBufferHandle,
			firstBinding,
			numberOfVkBuffers,
			vkBufferHandles,
			(VkDeviceSize *)offsets,
			(VkDeviceSize *)sizes,
			(VkDeviceSize *)strides);

    free(offsets);
    free(sizes);
    free(strides);

    jvulkan::freeMemory(&memoryToFree);
}
