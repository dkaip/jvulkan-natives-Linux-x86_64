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
#include <vector>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceSurfacePresentModesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkSurfaceKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceSurfacePresentModesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkSurfaceKHR, jobject jVkPresentModeKHRCollection)
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

    if (jVkPresentModeKHRCollection == nullptr)
    {
        cout << "ERROR: jVkPresentModeKHRCollection must be created before calling kGetPhysicalDeviceSurfacePresentModesKHR." << endl;
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    unsigned int numberOfPresentationModes = 0;

    VkResult result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDeviceHandle, surfaceKHRHandle, &numberOfPresentationModes, nullptr);
    if (result != VK_SUCCESS)
    {
        return jvulkan::createVkResult(env, result);
    }

    if (numberOfPresentationModes == 0)
    {
        return jvulkan::createVkResult(env, result);
    }

    std::vector<VkPresentModeKHR> presentationModes(numberOfPresentationModes);

    result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDeviceHandle, surfaceKHRHandle, &numberOfPresentationModes, presentationModes.data());
    if (result != VK_SUCCESS)
    {
        return jvulkan::createVkResult(env, result);
    }

    jclass collectionClass = env->GetObjectClass(jVkPresentModeKHRCollection);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = nullptr;

    for (const auto& presentationMode : presentationModes)
    {
        ///////////////////////////////////////////////////////////////////////////

        jclass vkPresentModeKHRClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPresentModeKHR");
        if (env->ExceptionOccurred())
        {
            cout << "vkGetPhysicalDeviceSurfacePresentModesKHR: could not find class " << "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPresentModeKHR" << endl;
            return nullptr;
        }

        methodId = env->GetStaticMethodID(vkPresentModeKHRClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPresentModeKHR;");
        if (env->ExceptionOccurred())
        {
            cout << "vkGetPhysicalDeviceSurfacePresentModesKHR: could not find static method " << "fromValue with signature (I)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPresentModeKHR;" << endl;
            return nullptr;
        }

        jobject formatEnum = env->CallStaticObjectMethod(vkPresentModeKHRClass, methodId, presentationMode);

        bool successfulAdd = false;
        successfulAdd = env->CallBooleanMethod(jVkPresentModeKHRCollection, addMethodId, formatEnum);
        if (successfulAdd == false)
        {
            cout << "ERROR:vkGetPhysicalDeviceSurfacePresentModesKHR the new VkPresentModeKHR element was not added to jVkPresentModeKHRCollection" << endl;
        }
    }

    return jvulkan::createVkResult(env, result);
}

