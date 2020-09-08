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

using namespace std;

#include <vector>

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceSurfacePresentModesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkSurfaceKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceSurfacePresentModesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkSurfaceKHR, jobject jVkPresentModeKHRCollection)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceKHR_T *surfaceKHRHandle = (VkSurfaceKHR_T *)jvulkan::getHandleValue(env, jVkSurfaceKHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkSurfaceKHR handle.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (jVkPresentModeKHRCollection == nullptr)
    {
    	LOGERROR(env, "%s", "jVkPresentModeKHRCollection must be created before calling kGetPhysicalDeviceSurfacePresentModesKHR.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    unsigned int numberOfPresentationModes = 0;

    VkResult result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDeviceHandle, surfaceKHRHandle, &numberOfPresentationModes, nullptr);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "Error calling vkGetPhysicalDeviceSurfacePresentModesKHR, result is %d.", result);
        return jvulkan::createVkResult(env, result);
    }

    if (numberOfPresentationModes == 0)
    {
    	LOGWARN(env, "%s", "numberOfPresentationModes == 0.");
        return jvulkan::createVkResult(env, result);
    }

    std::vector<VkPresentModeKHR> presentationModes(numberOfPresentationModes);

    result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDeviceHandle, surfaceKHRHandle, &numberOfPresentationModes, presentationModes.data());
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "Error calling vkGetPhysicalDeviceSurfacePresentModesKHR, result is %d.", result);
        return jvulkan::createVkResult(env, result);
    }

    jclass collectionClass = env->GetObjectClass(jVkPresentModeKHRCollection);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could get class for jVkPresentModeKHRCollection.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id for add.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = nullptr;

    for (const auto& presentationMode : presentationModes)
    {
        ///////////////////////////////////////////////////////////////////////////
    	jobject vkPresentModeKHREnum = jvulkan::createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkPresentModeKHR",
				presentationMode);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        bool successfulAdd = false;
        successfulAdd = env->CallBooleanMethod(jVkPresentModeKHRCollection, addMethodId, vkPresentModeKHREnum);
        if (successfulAdd == false)
        {
        	LOGERROR(env, "%s", "vkGetPhysicalDeviceSurfacePresentModesKHR the new VkPresentModeKHR element was not added to jVkPresentModeKHRCollection");
        }
    }

    return jvulkan::createVkResult(env, result);
}

