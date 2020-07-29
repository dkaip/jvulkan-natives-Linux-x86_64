/*
 * Copyright 2019-2020 Douglas Kaip
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

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceFeatures
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceFeatures;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceFeatures
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jPhysicalDeviceFeaturesObject)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Error calling getHandleValue for vkPhysicalDeviceHandle.");
        return;
    }

    VkPhysicalDeviceFeatures vkPhysicalDeviceFeatures = {};
    vkGetPhysicalDeviceFeatures(vkPhysicalDeviceHandle, &vkPhysicalDeviceFeatures);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Error calling vkGetPhysicalDeviceFeatures.");
        return;
    }

    jvulkan::populateVkPhysicalDeviceFeatures(
			env,
			jPhysicalDeviceFeaturesObject,
			&vkPhysicalDeviceFeatures,
			nullptr);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceFeatures.");
		return;
	}
}
