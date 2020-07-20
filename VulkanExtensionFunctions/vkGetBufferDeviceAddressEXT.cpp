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
/*
 * vkGetBufferDeviceAddressEXT.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetBufferDeviceAddressEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkBufferDeviceAddressInfoEXT;)Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDeviceAddress;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetBufferDeviceAddressEXT
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkBufferDeviceAddressInfoEXT)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return nullptr;
	}

    std::vector<void *> memoryToFree(5);
    VkBufferDeviceAddressInfoEXT vkBufferDeviceAddressInfoEXT = {};
    jvulkan::getVkBufferDeviceAddressInfoEXT(
            env,
			jVkBufferDeviceAddressInfoEXT,
			&vkBufferDeviceAddressInfoEXT,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkBufferDeviceAddressInfoEXT.");
        return nullptr;
    }

    VkDeviceAddress deviceAddress = vkGetBufferDeviceAddressEXT(
    		deviceHandle,
			&vkBufferDeviceAddressInfoEXT);

    jvulkan::freeMemory(&memoryToFree);

    jobject jVkDeviceAddress = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDeviceAddress", (void *)deviceAddress);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }

    return jVkDeviceAddress;
}
