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
 * vkCreateHeadlessSurfaceEXT.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCreateHeadlessSurfaceEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkHeadlessSurfaceCreateInfoEXT;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkSurfaceKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCreateHeadlessSurfaceEXT
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkHeadlessSurfaceCreateInfoEXT, jobject jAlternateAllocator, jobject jVkSurfaceKHR)
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

    std::vector<void *> memoryToFree(10);
    VkHeadlessSurfaceCreateInfoEXT vkHeadlessSurfaceCreateInfoEXT = {};
    jvulkan::getVkHeadlessSurfaceCreateInfoEXT(
    		env,
			jVkHeadlessSurfaceCreateInfoEXT,
			&vkHeadlessSurfaceCreateInfoEXT,
			&memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkHeadlessSurfaceCreateInfoEXT");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceKHR surface = nullptr;
    VkResult result = vkCreateHeadlessSurfaceEXT(
    		instanceHandle,
			&vkHeadlessSurfaceCreateInfoEXT,
			allocatorCallbacks,
			&surface);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    jvulkan::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    jvulkan::setHandleValue(env, jVkSurfaceKHR, surface);

    return jvulkan::createVkResult(env, result);
}
