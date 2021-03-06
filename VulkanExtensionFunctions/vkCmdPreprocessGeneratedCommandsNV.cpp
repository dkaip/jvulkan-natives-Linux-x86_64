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
 * vkCmdPreprocessGeneratedCommandsNV.cpp
 *
 *  Created on: Aug 29, 2020
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdPreprocessGeneratedCommandsNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkGeneratedCommandsInfoNV;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdPreprocessGeneratedCommandsNV
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jGeneratedCommandsInfoObject)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkGeneratedCommandsInfoNV generatedCommandsInfo = {};

    jvulkan::getVkGeneratedCommandsInfoNV(
            env,
			jGeneratedCommandsInfoObject,
            &generatedCommandsInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkGeneratedCommandsInfoNV.");
        return;
    }

    vkCmdPreprocessGeneratedCommandsNV(
    		commandBufferHandle,
			&generatedCommandsInfo);

    jvulkan::freeMemory(&memoryToFree);
}
