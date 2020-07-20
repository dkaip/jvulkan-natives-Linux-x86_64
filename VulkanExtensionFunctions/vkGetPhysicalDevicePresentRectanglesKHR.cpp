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
 * vkGetPhysicalDevicePresentRectanglesKHR.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDevicePresentRectanglesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkSurfaceKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDevicePresentRectanglesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkSurfaceKHR, jobject jVkRect2DCollection)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get handle for jVkPhysicalDevice");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceKHR_T *surfaceHandle = (VkSurfaceKHR_T *)jvulkan::getHandleValue(env, jVkSurfaceKHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get handle for VkSurfaceKHR");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t numberOfVkRect2Ds = 0;
    VkRect2D *vkRect2Ds = nullptr;

    VkResult result = vkGetPhysicalDevicePresentRectanglesKHR(
    		physicalDeviceHandle,
			surfaceHandle,
			&numberOfVkRect2Ds,
			nullptr);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "Error calling vkGetPhysicalDevicePresentRectanglesKHR %d", result);
        return jvulkan::createVkResult(env, result);
    }

    vkRect2Ds = (VkRect2D *)calloc(numberOfVkRect2Ds, sizeof(VkRect2D));
    if ( vkRect2Ds == nullptr)
    {
    	LOGERROR(env, "Error trying to allocate memory for %d VkRect2D structures.", numberOfVkRect2Ds);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    result = vkGetPhysicalDevicePresentRectanglesKHR(
    		physicalDeviceHandle,
			surfaceHandle,
			&numberOfVkRect2Ds,
			vkRect2Ds);

    if (result != VK_SUCCESS)
    {
    	free(vkRect2Ds);
    	LOGERROR(env, "Error calling vkGetPhysicalDevicePresentRectanglesKHR %d", result);
        return jvulkan::createVkResult(env, result);
    }

    jvulkan::populateVkRect2DCollection(
			env,
			jVkRect2DCollection,
			vkRect2Ds,
			numberOfVkRect2Ds);

	free(vkRect2Ds);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling populateVkRect2DCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    return jvulkan::createVkResult(env, result);

}
