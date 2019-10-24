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
 * vkCmdEndTransformFeedbackEXT.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdEndTransformFeedbackEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;ILjava/util/Collection;[J)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdEndTransformFeedbackEXT
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jint firstCounterBuffer, jobject jVkBufferCollectionObject, jlongArray jCounterBufferOffsetsArray)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkBuffers = 0;
    VkBuffer *vkBuffers = nullptr;
    jvulkan::getVkBufferCollection(
            env,
            jVkBufferCollectionObject,
			&vkBuffers,
            &numberOfVkBuffers,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkBufferCollection");
        return;
    }

    long *counterBufferOffsets = nullptr;
    jsize arrayLength = 0;
    if (jCounterBufferOffsetsArray != nullptr)
    {
        arrayLength = env->GetArrayLength(jCounterBufferOffsetsArray);

        counterBufferOffsets = (long *)calloc(arrayLength, sizeof(long));

        env->GetLongArrayRegion(jCounterBufferOffsetsArray, 0, arrayLength, counterBufferOffsets);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetLongArrayRegion");
            return;
        }
    }

    if (numberOfVkBuffers != arrayLength)
    {
    	LOGERROR(env, "%s", "The number of elements in jVkBufferCollectionObject and jCounterBufferOffsetsArray must be the same.");
        jvulkan::freeMemory(&memoryToFree);
    	free(counterBufferOffsets);
    	return;
    }


    vkCmdEndTransformFeedbackEXT(
    		commandBufferHandle,
			firstCounterBuffer,
			numberOfVkBuffers,
			vkBuffers,
			(unsigned long int *)counterBufferOffsets);

    free(counterBufferOffsets);
    jvulkan::freeMemory(&memoryToFree);
}
