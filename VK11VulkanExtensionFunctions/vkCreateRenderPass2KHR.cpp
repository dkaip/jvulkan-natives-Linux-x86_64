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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateRenderPass2KHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkRenderPassCreateInfo2KHR;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkRenderPass;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateRenderPass2KHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkRenderPassCreateInfo2KHR, jobject jAlternateAllocator, jobject jVkRenderPass)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }



    VkRenderPassCreateInfo2KHR vkRenderPassCreateInfo2KHR = {};
    std::vector<void *> memoryToFree(10);

    jvulkan::getVkRenderPassCreateInfo2KHR(env, jVkRenderPassCreateInfo2KHR, &vkRenderPassCreateInfo2KHR, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }



    VkRenderPass renderPassHandle = nullptr;
    int result = vkCreateRenderPass2KHR(logicalDeviceHandle, &vkRenderPassCreateInfo2KHR, allocatorCallbacks, &renderPassHandle);


    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    jvulkan::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    jvulkan::setHandleValue(env, jVkRenderPass, renderPassHandle);

    return jvulkan::createVkResult(env, result);
}

