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
 * vkCmdClearAttachments.cpp
 *
 *  Created on: Oct 15, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdClearAttachments
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Ljava/util/Collection;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdClearAttachments
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkClearAttachmentCollection, jobject jVkClearRectCollection)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkClearAttachments = 0;
    VkClearAttachment *vkClearAttachments = nullptr;
    if (vkClearAttachments != nullptr)
    {
        jvulkan::getVkClearAttachmentCollection(
                env,
				jVkClearAttachmentCollection,
                &vkClearAttachments,
                &numberOfVkClearAttachments,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkClearAttachmentCollection");
            return;
        }
    }

    int numberOfVkClearRects = 0;
    VkClearRect *vkClearRects = nullptr;
    if (vkClearRects != nullptr)
    {
        jvulkan::getVkClearRectCollection(
                env,
				jVkClearRectCollection,
                &vkClearRects,
                &numberOfVkClearRects,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkClearRectCollection");
            return;
        }
    }


    vkCmdClearAttachments(
    		commandBufferHandle,
			numberOfVkClearAttachments,
			vkClearAttachments,
			numberOfVkClearRects,
			vkClearRects);

    jvulkan::freeMemory(&memoryToFree);
}
