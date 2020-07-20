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
 * vkCreateDisplayModeKHR.cpp
 *
 *  Created on: May 8, 2019
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCreateDisplayModeKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayKHR;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkDisplayModeCreateInfoKHR;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayModeKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCreateDisplayModeKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkDisplayKHR, jobject jVkDisplayModeCreateInfoKHR, jobject jAlternateAllocator, jobject jVkDisplayModeKHRHandle)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkPhysicalDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDisplayKHR_T *vkDisplayKHRHandle = (VkDisplayKHR_T *)jvulkan::getHandleValue(env, jVkDisplayKHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkDisplayKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    VkDisplayModeCreateInfoKHR vkDisplayModeCreateInfoKHR = {};
    std::vector<void *> memoryToFree(10);

    jvulkan::getVkDisplayModeCreateInfoKHR(env, jVkDisplayModeCreateInfoKHR, &vkDisplayModeCreateInfoKHR, &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getVkDisplayModeCreateInfoKHR failed for jVkDisplayModeCreateInfoKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDisplayModeKHR vkDisplayModeKHRHandle = nullptr;
    int result = vkCreateDisplayModeKHR(
    		physicalDeviceHandle,
			vkDisplayKHRHandle,
			&vkDisplayModeCreateInfoKHR,
			allocatorCallbacks,
			&vkDisplayModeKHRHandle);


    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    jvulkan::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    jvulkan::setHandleValue(env, jVkDisplayModeKHRHandle, vkDisplayModeKHRHandle);

    return jvulkan::createVkResult(env, result);
}
