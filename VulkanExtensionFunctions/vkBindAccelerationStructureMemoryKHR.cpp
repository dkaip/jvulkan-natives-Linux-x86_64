/*
 * Copyright 2020 Douglas Kaip
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
 * vkBindAccelerationStructureMemoryKHR.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkBindAccelerationStructureMemoryKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkBindAccelerationStructureMemoryKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkBindAccelerationStructureMemoryInfoKHRCollection)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    int numberOfBindAccelerationStructureMemoryInfos = 0;
    VkBindAccelerationStructureMemoryInfoNV *vkBindAccelerationStructureMemoryInfos = nullptr;

    jvulkan::getVkBindAccelerationStructureMemoryInfoKHRCollection(
            env,
            jVkBindAccelerationStructureMemoryInfoKHRCollection,
            &vkBindAccelerationStructureMemoryInfos,
            &numberOfBindAccelerationStructureMemoryInfos,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int result = vkBindAccelerationStructureMemoryKHR(
            logicalDeviceHandle,
            numberOfBindAccelerationStructureMemoryInfos,
            vkBindAccelerationStructureMemoryInfos);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
