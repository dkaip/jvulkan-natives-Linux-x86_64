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

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdPipelineBarrier
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;Ljava/util/EnumSet;Ljava/util/EnumSet;Ljava/util/EnumSet;Ljava/util/Collection;Ljava/util/Collection;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdPipelineBarrier
  (JNIEnv *env,
   jobject,
   jobject jVkCommandBuffer,
   jobject jSrcStageMaskObject,
   jobject jDstStageMaskObject,
   jobject jDependencyFlagsObject,
   jobject jVkMemoryBarriersCollectionObject,
   jobject jVkBufferMemoryBarriersCollectionObject,
   jobject jVkImageMemoryBarriersCollectionObject)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ////////////////////////////////////////////////////////////////////////
    VkPipelineStageFlags srcStageMask = jvulkan::getEnumSetValue(
            env,
            jSrcStageMaskObject,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

    ////////////////////////////////////////////////////////////////////////
    VkPipelineStageFlags dstStageMask = jvulkan::getEnumSetValue(
            env,
            jDstStageMaskObject,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

    ////////////////////////////////////////////////////////////////////////
    VkDependencyFlags dependencyFlags = jvulkan::getEnumSetValue(
            env,
            jDependencyFlagsObject,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkDependencyFlagBits");

    ////////////////////////////////////////////////////////////////////////
    std::vector<void *> memoryToFree(5);
    int numberOfVkMemoryBarriers = 0;
    VkMemoryBarrier *vkMemoryBarriers = nullptr;

    if (jVkMemoryBarriersCollectionObject != nullptr)
    {
        jvulkan::getVkMemoryBarrierCollection(
                env,
                jVkMemoryBarriersCollectionObject,
                &vkMemoryBarriers,
                &numberOfVkMemoryBarriers,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    ////////////////////////////////////////////////////////////////////////
    int numberOfVkBufferMemoryBarriers = 0;
    VkBufferMemoryBarrier *vkBufferMemoryBarriers = nullptr;

    if (jVkBufferMemoryBarriersCollectionObject != nullptr)
    {
        jvulkan::getVkBufferMemoryBarrierCollection(
                env,
                jVkBufferMemoryBarriersCollectionObject,
                &vkBufferMemoryBarriers,
                &numberOfVkBufferMemoryBarriers,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    ////////////////////////////////////////////////////////////////////////
    int numberOfVkImageMemoryBarriers = 0;
    VkImageMemoryBarrier *vkImageMemoryBarriers = nullptr;

    if (jVkImageMemoryBarriersCollectionObject != nullptr)
    {
        jvulkan::getVkImageMemoryBarrierCollection(
                env,
                jVkImageMemoryBarriersCollectionObject,
                &vkImageMemoryBarriers,
                &numberOfVkImageMemoryBarriers,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    vkCmdPipelineBarrier(
            commandBufferHandle,
            srcStageMask,
            dstStageMask,
            dependencyFlags,
            numberOfVkMemoryBarriers,
            vkMemoryBarriers,
            numberOfVkBufferMemoryBarriers,
            vkBufferMemoryBarriers,
            numberOfVkImageMemoryBarriers,
            vkImageMemoryBarriers);

    jvulkan::freeMemory(&memoryToFree);
}
