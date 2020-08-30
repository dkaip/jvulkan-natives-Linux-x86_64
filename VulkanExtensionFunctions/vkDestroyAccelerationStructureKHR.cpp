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
 * vkDestroyAccelerationStructureKHR.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkDestroyAccelerationStructureKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkAccelerationStructureKHR;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAllocationCallbacks;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkDestroyAccelerationStructureKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkAccelerationStructureKHRObject, jobject jAlternateAllocator)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get jVkDevice.");
        return;
    }

    VkAccelerationStructureKHR_T *accelerationStructureHandle = (VkAccelerationStructureKHR_T *)jvulkan::getHandleValue(env, jVkAccelerationStructureKHRObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get jVkAccelerationStructureKHRObject.");
        return;
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    vkDestroyAccelerationStructureKHR(
    		logicalDeviceHandle,
			accelerationStructureHandle,
			allocatorCallbacks);
}
