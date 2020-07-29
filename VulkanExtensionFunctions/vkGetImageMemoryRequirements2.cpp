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
 * vkGetImageMemoryRequirements2.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetImageMemoryRequirements2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageMemoryRequirementsInfo2;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkMemoryRequirements2;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetImageMemoryRequirements2
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkImageMemoryRequirementsInfo2, jobject jVkMemoryRequirements2)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return;
    }

    if (jVkMemoryRequirements2 == nullptr)
    {
    	LOGERROR(env, "%s", "jVkMemoryRequirements2 must be created before calling vkGetImageMemoryRequirements2.");
        return;
    }

    std::vector<void *> memoryToFree(20);

    VkImageMemoryRequirementsInfo2 vkImageMemoryRequirementsInfo2 = {};
    jvulkan::getVkImageMemoryRequirementsInfo2(
            env,
			jVkImageMemoryRequirementsInfo2,
			&vkImageMemoryRequirementsInfo2,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getVkImageMemoryRequirementsInfo2.");
        jvulkan::freeMemory(&memoryToFree);
        return;
    }

    /*
     * For "output" data we need to crawl the pNext chain "first" so that all of
     * the pNext structures are already in place before the API call.  For "input"
     * items their pNext has already been crawled in the "get" functions (in this
     * case getVkImageMemoryRequirementsInfo2) before the API call.
     */
    void *headOfpNextChain = nullptr;
    ////////////////////////////////////////////////////////////////////////
    jobject jpNextObject = jvulkan::getpNextObject(env, jVkMemoryRequirements2);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getpNext failed.");
        return;
    }

    if (jpNextObject != nullptr)
    {
		/*
		 * Crawl the pNext chain and identify / create any needed elements.
		 */
		jvulkan::getpNextChain(
				env,
				jpNextObject,
				&headOfpNextChain,
				&memoryToFree);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error trying to crawl the pNext chain.");
			return;
		}
    }

    VkMemoryRequirements2 vkMemoryRequirements2 = {};
    vkMemoryRequirements2.sType = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2;
    vkMemoryRequirements2.pNext = headOfpNextChain;

    vkGetImageMemoryRequirements2(
    		deviceHandle,
			&vkImageMemoryRequirementsInfo2,
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
