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
 * vkBindImageMemory2.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: Douglas Kaip
 */
/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkBindImageMemory2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkBindImageMemory2
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkBindImageMemoryInfoCollection)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    int numberOfBindImageMemoryInfos = 0;
    VkBindImageMemoryInfo *vkBindImageMemoryInfos = nullptr;

    jvulkan::getVkBindImageMemoryInfoCollection(
            env,
            jVkBindImageMemoryInfoCollection,
            &vkBindImageMemoryInfos,
            &numberOfBindImageMemoryInfos,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int result = vkBindImageMemory2(
            logicalDeviceHandle,
            numberOfBindImageMemoryInfos,
            vkBindImageMemoryInfos);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}


