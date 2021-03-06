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
 * Method:    vkCmdNextSubpass2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkSubpassBeginInfo;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkSubpassEndInfo;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdNextSubpass2
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkSubpassBeginInfoObject, jobject jVkSubpassEndInfoObject)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
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

    VkSubpassEndInfo vkSubpassEndInfo = {};
    jvulkan::getVkSubpassEndInfo(
            env,
			jVkSubpassEndInfoObject,
			&vkSubpassEndInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkSubpassEndInfo.");
        return;
    }

    vkCmdNextSubpass2(
    		commandBufferHandle,
			&vkSubpassBeginInfo,
			&vkSubpassEndInfo);

    jvulkan::freeMemory(&memoryToFree);
}
