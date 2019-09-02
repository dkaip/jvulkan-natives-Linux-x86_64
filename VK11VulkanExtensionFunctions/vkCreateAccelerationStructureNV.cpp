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
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateAccelerationStructureNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/CreateInfos/VkAccelerationStructureCreateInfoNV;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkAccelerationStructureNV;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateAccelerationStructureNV
  (JNIEnv *env, jobject,
          jobject jVkDevice,
          jobject jVkAccelerationStructureCreateInfoNVObject,
          jobject jAlternateAllocator,
          jobject jVkAccelerationStructureNVObject)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAccelerationStructureCreateInfoNV vkAccelerationStructureCreateInfoNVObject = {};
    std::vector<void *> memoryToFree(5);

    jvulkan::getVkAccelerationStructureCreateInfoNV(env, jVkAccelerationStructureCreateInfoNVObject, &vkAccelerationStructureCreateInfoNVObject, &memoryToFree);
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

    VkAccelerationStructureNV vkAccelerationStructureNV = nullptr;

    int result = vkCreateAccelerationStructureNV(
            logicalDeviceHandle,
            &vkAccelerationStructureCreateInfoNVObject,
            allocatorCallbacks,
            &vkAccelerationStructureNV);
    /*
     * Now transfer the VkDevice data to Java
     */
    jvulkan::setHandleValue(env, jVkAccelerationStructureNVObject, vkAccelerationStructureNV);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
