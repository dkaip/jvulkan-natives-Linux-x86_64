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

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdBeginRenderPass
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkRenderPassBeginInfo;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSubpassContents;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdBeginRenderPass
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkRenderPassBeginInfo, jobject jVkSubpassContents)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get jVkCommandBuffer.");
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkRenderPassBeginInfo vkRenderPassBeginInfo = {};

    jvulkan::getVkRenderPassBeginInfo(env, jVkRenderPassBeginInfo, &vkRenderPassBeginInfo, &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkRenderPassBeginInfo.");
        return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass subpassContentsEnumClass = env->GetObjectClass(jVkSubpassContents);

    jmethodID valueOfMethodId = env->GetMethodID(subpassContentsEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to methodId for valueOf.");
        return;
    }

    jint subpassContentsEnumValue = env->CallIntMethod(jVkSubpassContents, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }

    vkCmdBeginRenderPass(commandBufferHandle, &vkRenderPassBeginInfo, (enum VkSubpassContents)subpassContentsEnumValue);

    jvulkan::freeMemory(&memoryToFree);
}

