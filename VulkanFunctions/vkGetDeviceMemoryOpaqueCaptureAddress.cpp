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
 * vkGetDeviceMemoryOpaqueCaptureAddress.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetDeviceMemoryOpaqueCaptureAddress
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkDeviceMemoryOpaqueCaptureAddressInfo;)Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VulkanHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetDeviceMemoryOpaqueCaptureAddress
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDeviceMemoryOpaqueCaptureAddressInfo)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return nullptr;
	}

    std::vector<void *> memoryToFree(5);
    VkDeviceMemoryOpaqueCaptureAddressInfo vkDeviceMemoryOpaqueCaptureAddressInfo = {};
    jvulkan::getVkDeviceMemoryOpaqueCaptureAddressInfo(
            env,
			jVkDeviceMemoryOpaqueCaptureAddressInfo,
			&vkDeviceMemoryOpaqueCaptureAddressInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkDeviceMemoryOpaqueCaptureAddressInfo.");
        return nullptr;
    }

    VkDeviceAddress opaqueCaptureAddress = vkGetDeviceMemoryOpaqueCaptureAddress(
    		deviceHandle,
			&vkDeviceMemoryOpaqueCaptureAddressInfo);

    jvulkan::freeMemory(&memoryToFree);

    jobject opaqueAddress = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/VulkanExtensions/Handles/VulkanHandle", (void *)opaqueCaptureAddress);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }

    return opaqueAddress;
}
