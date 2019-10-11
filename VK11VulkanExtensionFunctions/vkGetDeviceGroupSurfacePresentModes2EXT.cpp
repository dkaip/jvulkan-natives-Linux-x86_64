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
 * vkGetDeviceGroupSurfacePresentModes2EXT.cpp
 *
 *  Created on: Sep 26, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetDeviceGroupSurfacePresentModes2EXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceSurfaceInfo2KHR;Ljava/util/EnumSet;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetDeviceGroupSurfacePresentModes2EXT
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPhysicalDeviceSurfaceInfo2KHR, jobject jVkDeviceGroupPresentModeFlagsKHR)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

//    std::vector<void *> memoryToFree(10);
//    VkPhysicalDeviceSurfaceInfo2KHR vkPhysicalDeviceSurfaceInfo2KHR = {};
//    jvulkan::getVkPhysicalDeviceSurfaceInfo2KHR(
//            env,
//			jVkPhysicalDeviceSurfaceInfo2KHR,
//			&vkPhysicalDeviceSurfaceInfo2KHR,
//            &memoryToFree);
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Error calling getVkPhysicalDeviceSurfaceInfo2KHR");
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }


	LOGERROR(env, "%s", "The function vkGetDeviceGroupSurfacePresentModes2EXT seems to have gotten lost from vulkan_core.h in 121");
    return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//
//    VkDeviceGroupPresentModeFlagsKHR vkDeviceGroupPresentModeFlagsKHR;
//    VkResult result = vkGetDeviceGroupSurfacePresentModes2EXT(
//    		deviceHandle,
//			&vkPhysicalDeviceSurfaceInfo2KHR,
//			&vkDeviceGroupPresentModeFlagsKHR);
//
//    jvulkan::freeMemory(&memoryToFree);
//
//    return jvulkan::createVkResult(env, result);
}
