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
 * vkGetBufferMemoryRequirements2.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetBufferMemoryRequirements2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkBufferMemoryRequirementsInfo2;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkMemoryRequirements2;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetBufferMemoryRequirements2
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkBufferMemoryRequirementsInfo2, jobject jVkMemoryRequirements2)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkBufferMemoryRequirementsInfo2 vkBufferMemoryRequirementsInfo2 = {};
    jvulkan::getVkBufferMemoryRequirementsInfo2(
            env,
			jVkBufferMemoryRequirementsInfo2,
			&vkBufferMemoryRequirementsInfo2,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkBufferMemoryRequirementsInfo2.");
        return;
    }

    VkMemoryRequirements2 vkMemoryRequirements2 = {};

    vkGetBufferMemoryRequirements2(
    		deviceHandle,
			&vkBufferMemoryRequirementsInfo2,
			&vkMemoryRequirements2);

    jvulkan::populateVkMemoryRequirements2(
    		env,
			jVkMemoryRequirements2,
			&vkMemoryRequirements2);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkMemoryRequirements2");
        return;
    }

    jvulkan::freeMemory(&memoryToFree);
}
