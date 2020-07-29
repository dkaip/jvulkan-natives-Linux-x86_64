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
 * vkCmdBindTransformFeedbackBuffersEXT.cpp
 *
 *  Created on: Oct 15, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdBindTransformFeedbackBuffersEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;ILjava/util/Collection;[J[J)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdBindTransformFeedbackBuffersEXT
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jint firstBinding, jobject jVkBufferCollection, jlongArray jOffsetsArray, jlongArray jSizesArray)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkBuffers = 0;
    VkBuffer *vkBufferHandles = nullptr;
    if (jVkBufferCollection != nullptr)
    {
        jvulkan::getVkBufferCollection(
                env,
				jVkBufferCollection,
                &vkBufferHandles,
                &numberOfVkBuffers,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {

            return;
        }
    }

    long *offsets = nullptr;
    jsize offsetsArrayLength = 0;
    if (jOffsetsArray != nullptr)
    {
    	offsetsArrayLength = env->GetArrayLength(jOffsetsArray);

        offsets = (long *)calloc(offsetsArrayLength, sizeof(long));

        env->GetLongArrayRegion(jOffsetsArray, 0, offsetsArrayLength, offsets);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    long *sizes = nullptr;
    jsize sizesArrayLength = 0;
    if (jSizesArray != nullptr)
    {
    	sizesArrayLength = env->GetArrayLength(jSizesArray);

    	sizes = (long *)calloc(sizesArrayLength, sizeof(long));

        env->GetLongArrayRegion(jSizesArray, 0, sizesArrayLength, sizes);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    if (numberOfVkBuffers != offsetsArrayLength)
    {
    	LOGERROR(env, "%s", "The number of elements in jVkBufferCollection, jOffsetsArray, and jSizesArray must be the same.");
        free(offsets);
        free(sizes);
        jvulkan::freeMemory(&memoryToFree);
    	return;
    }

    if (sizes != nullptr &&
    	sizesArrayLength != offsetsArrayLength)
    {
    	LOGERROR(env, "%s", "The number of elements in jVkBufferCollection, jOffsetsArray must be the same.");
        free(offsets);
        free(sizes);
        jvulkan::freeMemory(&memoryToFree);
    	return;
    }

    vkCmdBindTransformFeedbackBuffersEXT(
    		commandBufferHandle,
			firstBinding,
			numberOfVkBuffers,
			vkBufferHandles,
			(VkDeviceSize *)offsets,
			(VkDeviceSize *)sizes);

    free(offsets);
    free(sizes);

    jvulkan::freeMemory(&memoryToFree);
}
