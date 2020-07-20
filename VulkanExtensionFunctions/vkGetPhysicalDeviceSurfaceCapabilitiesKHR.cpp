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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceSurfaceCapabilitiesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkSurfaceKHR;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkSurfaceCapabilitiesKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceSurfaceCapabilitiesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkSurfaceKHR, jobject jVkSurfaceCapabilitiesKHR)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceKHR_T *surfaceKHRHandle = (VkSurfaceKHR_T *)jvulkan::getHandleValue(env, jVkSurfaceKHR);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (jVkSurfaceCapabilitiesKHR == nullptr)
    {
        cout << "ERROR: jVkSurfaceCapabilitiesKHR must be created before calling vkGetPhysicalDeviceSurfaceCapabilitiesKHR." << endl;
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceCapabilitiesKHR surfaceCapabilities = {};

    VkResult result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDeviceHandle, surfaceKHRHandle, &surfaceCapabilities);
    if (result != VK_SUCCESS)
    {
        return jvulkan::createVkResult(env, result);
    }

    std::vector<void *> memoryToFree(5);

	jvulkan::populateVkSurfaceCapabilitiesKHR(
			env,
			jVkSurfaceCapabilitiesKHR,
			&surfaceCapabilities,
			&memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkSurfaceCapabilitiesKHR");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }


//    jclass surfaceCapabilitiesClass = env->GetObjectClass(jVkSurfaceCapabilitiesKHR);
//    ////////////////////////////////////////////////////////////////////////////
//    jmethodID methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMinImageCount", "(I)V");
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, surfaceCapabilities.minImageCount);
//
//    ////////////////////////////////////////////////////////////////////////////
//    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMaxImageCount", "(I)V");
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, surfaceCapabilities.maxImageCount);
//
//    ////////////////////////////////////////////////////////////////////////////
//    jobject extent2DObject = jvulkan::createVkExtent2D(env, &surfaceCapabilities.currentExtent);
//
//    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setCurrentImageExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, extent2DObject);
//
//    ////////////////////////////////////////////////////////////////////////////
//    extent2DObject = jvulkan::createVkExtent2D(env, &surfaceCapabilities.minImageExtent);
//
//    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMinImageExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, extent2DObject);
//
//    ////////////////////////////////////////////////////////////////////////////
//    extent2DObject = jvulkan::createVkExtent2D(env, &surfaceCapabilities.maxImageExtent);
//
//    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMaxImageExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, extent2DObject);
//
//    ////////////////////////////////////////////////////////////////////////////
//    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMaxImageArrayLayers", "(I)V");
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, surfaceCapabilities.maxImageArrayLayers);
//
//    ///////////////////////////////////////////////////////////////////////////
//    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setSupportedTransforms", "(Ljava/util/EnumSet;)V");
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    jobject supportedTransformsEnumSet = jvulkan::getVkSurfaceTransformFlagsKHRAsEnumSet(env, surfaceCapabilities.supportedTransforms);
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    if (supportedTransformsEnumSet == nullptr)
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, supportedTransformsEnumSet);
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    ///////////////////////////////////////////////////////////////////////////
//    jclass vkSurfaceTransformFlagBitsKHRClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Enums/VkSurfaceTransformFlagBitsKHR");
//    if (env->ExceptionOccurred())
//    {
//        cout << "vkGetPhysicalDeviceSurfaceCapabilitiesKHR: could not find class " << "com/CIMthetics/jvulkan/VulkanCore/Enums/VkSurfaceTransformFlagBitsKHR" << endl;
//        return nullptr;
//    }
//
//    methodId = env->GetStaticMethodID(vkSurfaceTransformFlagBitsKHRClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSurfaceTransformFlagBitsKHR;");
//    if (env->ExceptionOccurred())
//    {
//        cout << "vkGetPhysicalDeviceSurfaceCapabilitiesKHR: could not find static method " << "fromValue with signature (I)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSurfaceTransformFlagBitsKHR;" << endl;
//        return nullptr;
//    }
//
//    jobject jCurrentTransformEnum = env->CallStaticObjectMethod(vkSurfaceTransformFlagBitsKHRClass, methodId, surfaceCapabilities.currentTransform);
//
//    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setCurrentTransform", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSurfaceTransformFlagBitsKHR;)V");
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, jCurrentTransformEnum);
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    ///////////////////////////////////////////////////////////////////////////
//    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setSupportedCompositeAlpha", "(Ljava/util/EnumSet;)V");
//    if (env->ExceptionOccurred())
//    {
//        return nullptr;
//    }
//
//    jobject supportedCompositeAlphaEnumSet = jvulkan::getVkCompositeAlphaFlagsKHRAsEnumSet(env, surfaceCapabilities.supportedCompositeAlpha);
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    if (supportedCompositeAlphaEnumSet == nullptr)
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, supportedCompositeAlphaEnumSet);
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    ///////////////////////////////////////////////////////////////////////////
//    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setSupportedUsageFlags", "(Ljava/util/EnumSet;)V");
//    if (env->ExceptionOccurred())
//    {
//        return nullptr;
//    }
//
//    jobject supportedImageUsageFlagsEnumSet = jvulkan::getVkImageUsageFlagsAsEnumSet(env, surfaceCapabilities.supportedUsageFlags);
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    if (supportedImageUsageFlagsEnumSet == nullptr)
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, supportedImageUsageFlagsEnumSet);
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
