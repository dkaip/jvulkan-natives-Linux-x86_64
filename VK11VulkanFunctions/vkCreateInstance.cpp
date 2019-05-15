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
#include <iostream>
#include <vector>

using namespace std;

const char *voidMethodErrorText = "Error Calling CallVoidMethod";

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateInstance
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkInstanceCreateInfo;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkInstance;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateInstance
  (JNIEnv *env, jobject, jobject jVkInstanceCreateInfoObject, jobject jAlternateAllocator, jobject jVkInstance)
{
	LOGTRACE(env, "%s", "vkCreateInstance called"); // This line is mainly here so that the logging stuff gets initialized before any errors.

    VkInstanceCreateInfo vkInstanceCreateInfo = {};

    std::vector<void *> memoryToFree(30);

	jvulkan::getVkInstanceCreateInfo(
        env,
        jVkInstanceCreateInfoObject,
		&vkInstanceCreateInfo,
        &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed on call to getVkInstanceCreateInfo");

        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    VkInstance instance = nullptr;

    VkResult result = vkCreateInstance(&vkInstanceCreateInfo, allocatorCallbacks, &instance);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;
    /*
     * Now transfer the VkInstance data to Java
     */
    jvulkan::setHandleValue(env, jVkInstance, instance);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}

