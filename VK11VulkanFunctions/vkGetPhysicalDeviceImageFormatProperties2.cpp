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
 * vkGetPhysicalDeviceImageFormatProperties2.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceImageFormatProperties2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceImageFormatInfo2;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkImageFormatProperties2;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceImageFormatProperties2
  (JNIEnv *env, jobject, jobject jVkPhysicalDeviceObject, jobject jVkPhysicalDeviceImageFormatInfo2Object, jobject jVkImageFormatProperties2Object)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDeviceObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getHandleValue.");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);

    VkPhysicalDeviceImageFormatInfo2 vkPhysicalDeviceImageFormatInfo2 = {};
    jvulkan::getVkPhysicalDeviceImageFormatInfo2(
            env,
			jVkPhysicalDeviceImageFormatInfo2Object,
			&vkPhysicalDeviceImageFormatInfo2,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling method getVkFormat");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkImageFormatProperties2 vkImageFormatProperties2 = {};
    jvulkan::getVkImageFormatProperties2(
            env,
			jVkImageFormatProperties2Object,
			&vkImageFormatProperties2,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling method getVkFormat");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }


    VkResult result = vkGetPhysicalDeviceImageFormatProperties2(
    		physicalDeviceHandle,
			&vkPhysicalDeviceImageFormatInfo2,
			&vkImageFormatProperties2);

    if (result == VK_SUCCESS)
    {
		jvulkan::populateVkImageFormatProperties2(
				env,
				jVkImageFormatProperties2Object,
				&vkImageFormatProperties2,
				&memoryToFree);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling jvulkan::populateVkImageFormatProperties2");
			return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
		}
    }

    jvulkan::freeMemory(&memoryToFree);


    return jvulkan::createVkResult(env, result);
}
