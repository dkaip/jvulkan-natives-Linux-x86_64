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

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateInstance
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkInstanceCreateInfo;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkInstance;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateInstance
  (JNIEnv *env, jobject, jobject jInstanceCreateInfo, jobject jAlternateAllocator, jobject jVkInstance)
{
    VkApplicationInfo applicationInfo = {};
    VkInstanceCreateInfo instanceCreateInfo = {};

    std::vector<void *> memoryToFree(30);

    hwjvi::getInstanceCreateInfo(env, jInstanceCreateInfo, &instanceCreateInfo, &applicationInfo, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        hwjvi::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    VkInstance instance;

    VkResult result = vkCreateInstance(&instanceCreateInfo, allocatorCallbacks, &instance);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;
    /*
     * Now transfer the VkInstance data to Java
     */
    hwjvi::setHandleValue(env, jVkInstance, instance);

    hwjvi::freeMemory(&memoryToFree);

    return hwjvi::createVkResult(env, result);
}

