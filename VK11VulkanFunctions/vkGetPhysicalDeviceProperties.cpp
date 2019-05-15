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
#include <cstring>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceProperties;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDevicePropertiesObject)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkPhysicalDeviceProperties vkPhysicalDeviceProperties = {};
    vkGetPhysicalDeviceProperties(vkPhysicalDeviceHandle, &vkPhysicalDeviceProperties);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jvulkan::createVkPhysicalDeviceProperties(
    		env,
			jVkPhysicalDevicePropertiesObject,
			&vkPhysicalDeviceProperties);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVkPhysicalDeviceProperties");
        return;
    }
}

