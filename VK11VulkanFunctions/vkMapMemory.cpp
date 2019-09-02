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

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkMapMemory
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDeviceMemory;JJLjava/util/EnumSet;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/MappedMemoryPointer;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkMapMemory
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDeviceMemory, jlong jOffset, jlong jSize, jobject jVkMemoryMapFlags, jobject jVoidPointer)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDeviceMemory_T *deviceMemoryHandle = (VkDeviceMemory_T *)jvulkan::getHandleValue(env, jVkDeviceMemory);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkMemoryMapFlags flags = 0;
    if (jVkMemoryMapFlags != nullptr)
    {
        flags = jvulkan::getEnumSetValue(
                env,
                jVkMemoryMapFlags,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkMemoryMapFlagBits");
    }

    void *dataPointer = nullptr;
    int result = vkMapMemory(
            logicalDeviceHandle,
            deviceMemoryHandle,
            (VkDeviceSize)jOffset,
            (VkDeviceSize)jSize,
            flags,
            &dataPointer);

    /*
     * Now transfer the VkDevice data to Java
     */
    jvulkan::setHandleValue(env, jVoidPointer, dataPointer);

    return jvulkan::createVkResult(env, result);
}
