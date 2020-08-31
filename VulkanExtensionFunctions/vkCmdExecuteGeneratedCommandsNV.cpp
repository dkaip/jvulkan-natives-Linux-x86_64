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
 * vkCmdExecuteGeneratedCommandsNV.cpp
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
 * Method:    vkCmdExecuteGeneratedCommandsNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;ZLcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkGeneratedCommandsInfoNV;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdExecuteGeneratedCommandsNV
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jboolean jIsPreprocessed, jobject jVkGeneratedCommandsInfoNVObject)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkBool32 isPreprocessed = (VkBool32) jIsPreprocessed;

    std::vector<void *> memoryToFree(5);
    VkGeneratedCommandsInfoNV vkGeneratedCommandsInfoNV = {};

    jvulkan::getVkGeneratedCommandsInfoNV(
            env,
			jVkGeneratedCommandsInfoNVObject,
            &vkGeneratedCommandsInfoNV,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkGeneratedCommandsInfoNV.");
        return;
    }

    vkCmdExecuteGeneratedCommandsNV(
    		commandBufferHandle,
			isPreprocessed,
			&vkGeneratedCommandsInfoNV);

    jvulkan::freeMemory(&memoryToFree);
}
