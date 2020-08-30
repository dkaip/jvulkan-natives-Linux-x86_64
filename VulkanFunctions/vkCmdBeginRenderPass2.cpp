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
 * Method:    vkCmdBeginRenderPass2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkRenderPassBeginInfo;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkSubpassBeginInfo;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdBeginRenderPass2
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkRenderPassBeginInfoObject, jobject jVkSubpassBeginInfoObject)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkRenderPassBeginInfo vkRenderPassBeginInfo = {};
    jvulkan::getVkRenderPassBeginInfo(
            env,
			jVkRenderPassBeginInfoObject,
			&vkRenderPassBeginInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkRenderPassBeginInfo.");
        return;
    }

    VkSubpassBeginInfo vkSubpassBeginInfo = {};
    jvulkan::getVkSubpassBeginInfo(
            env,
			jVkSubpassBeginInfoObject,
			&vkSubpassBeginInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkSubpassBeginInfo.");
        return;
    }

    vkCmdBeginRenderPass2(
    		commandBufferHandle,
			&vkRenderPassBeginInfo,
			&vkSubpassBeginInfo);

    jvulkan::freeMemory(&memoryToFree);
}
