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
 * vkGetImageSubresourceLayout.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetImageSubresourceLayout
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkImage;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkImageSubresource;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSubresourceLayout;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetImageSubresourceLayout
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkImage, jobject jVkImageSubresource, jobject jVkSubresourceLayout)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return;
    }

    VkImage_T *imageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jVkImage);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkImage handle");
        return;
    }

    std::vector<void *> memoryToFree(20);

    VkImageSubresource vkImageSubresource = {};
    jvulkan::getVkImageSubresource(
            env,
			jVkImageSubresource,
			&vkImageSubresource,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getVkImageSubresource.");
        jvulkan::freeMemory(&memoryToFree);
        return;
    }

    VkSubresourceLayout vkSubresourceLayout = {};

    vkGetImageSubresourceLayout(
    		deviceHandle,
			imageHandle,
			&vkImageSubresource,
			&vkSubresourceLayout);

    jvulkan::populateVkSubresourceLayout(
    		env,
			jVkSubresourceLayout,
			&vkSubresourceLayout);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkSubresourceLayout.");
        return;
    }

    jvulkan::freeMemory(&memoryToFree);
}
