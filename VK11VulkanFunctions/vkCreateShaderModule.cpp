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
 * Method:    vkCreateShaderModule
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkShaderModuleCreateInfo;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkShaderModule;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateShaderModule
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkShaderModuleCreateInfo, jobject jAlternateAllocator, jobject jVkShaderModule)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
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

    VkShaderModuleCreateInfo vkShaderModuleCreateInfo = {};
    std::vector<void *> memoryToFree(5);

    hwjvi::getVkShaderModuleCreateInfo(env, jVkShaderModuleCreateInfo, &vkShaderModuleCreateInfo, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkShaderModule shaderModule;
    int result = vkCreateShaderModule(logicalDeviceHandle, &vkShaderModuleCreateInfo, allocatorCallbacks, &shaderModule);
    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    hwjvi::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVkShaderModule, shaderModule);

    return hwjvi::createVkResult(env, result);
}
