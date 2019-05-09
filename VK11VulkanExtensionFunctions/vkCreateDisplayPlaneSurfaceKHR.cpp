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
 * vkCreateDisplayPlaneSurfaceKHR.cpp
 *
 *  Created on: May 9, 2019
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateDisplayPlaneSurfaceKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/CreateInfos/VkDisplaySurfaceCreateInfoKHR;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkSurfaceKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateDisplayPlaneSurfaceKHR
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkDisplaySurfaceCreateInfoKHR, jobject jAlternateAllocator, jobject jVkSurfaceKHRHandle)
{
	VkInstance_T *instanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkInstance");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    VkDisplaySurfaceCreateInfoKHR vkDisplaySurfaceCreateInfoKHR = {};
    std::vector<void *> memoryToFree(10);

    jvulkan::getVkDisplaySurfaceCreateInfoKHR(env, jVkDisplaySurfaceCreateInfoKHR, &vkDisplaySurfaceCreateInfoKHR, &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getVkDisplaySurfaceCreateInfoKHR failed for jVkDisplaySurfaceCreateInfoKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceKHR vkSurfaceKHRHandle = nullptr;
    int result = vkCreateDisplayPlaneSurfaceKHR(
    		instanceHandle,
			&vkDisplaySurfaceCreateInfoKHR,
			allocatorCallbacks,
			&vkSurfaceKHRHandle);


    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    jvulkan::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    jvulkan::setHandleValue(env, jVkSurfaceKHRHandle, vkSurfaceKHRHandle);

    return jvulkan::createVkResult(env, result);
}
