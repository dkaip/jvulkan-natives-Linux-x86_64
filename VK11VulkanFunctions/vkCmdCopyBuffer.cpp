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
#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdCopyBuffer
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkBuffer;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdCopyBuffer
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jSrcVkBuffer, jobject jDstVkBuffer, jobject jVkBufferCopyCollectionObject)
{
    VkCommandBuffer_T *vkCommandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkBuffer_T *srcBufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jSrcVkBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkBuffer_T *dstBufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jDstVkBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkBufferCopies = 0;
    VkBufferCopy *vkBufferCopies = nullptr;

    if (jVkBufferCopyCollectionObject != nullptr)
    {
        hwjvi::getVkBufferCopyCollection(
                env,
                jVkBufferCopyCollectionObject,
                &vkBufferCopies,
                &numberOfVkBufferCopies,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    vkCmdCopyBuffer(vkCommandBufferHandle, srcBufferHandle, dstBufferHandle, numberOfVkBufferCopies, vkBufferCopies);

    hwjvi::freeMemory(&memoryToFree);
}
