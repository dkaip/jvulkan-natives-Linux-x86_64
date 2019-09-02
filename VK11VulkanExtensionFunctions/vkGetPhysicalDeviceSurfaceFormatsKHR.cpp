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
 * Method:    vkGetPhysicalDeviceSurfaceFormatsKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkSurfaceKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceSurfaceFormatsKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkSurfaceKHR, jobject jVkSurfaceFormatKHRCollection)
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

    if (jVkSurfaceFormatKHRCollection == nullptr)
    {
        cout << "ERROR: jVkSurfaceFormatKHRCollection must be created before calling vkGetPhysicalDeviceSurfaceFormatsKHR." << endl;
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    unsigned int numberOfSurfaceFormats = 0;

    VkResult result = vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDeviceHandle, surfaceKHRHandle, &numberOfSurfaceFormats, nullptr);
    if (result != VK_SUCCESS)
    {
        return jvulkan::createVkResult(env, result);
    }

    if (numberOfSurfaceFormats == 0)
    {
        return jvulkan::createVkResult(env, result);
    }

    std::vector<VkSurfaceFormatKHR> surfaceFormats(numberOfSurfaceFormats);

    result = vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDeviceHandle, surfaceKHRHandle, &numberOfSurfaceFormats, surfaceFormats.data());
    if (result != VK_SUCCESS)
    {
        return jvulkan::createVkResult(env, result);
    }

    jclass vkSurfaceFormatKHRClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSurfaceFormatKHR");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID vkSurfaceFormatKHRConstructor = env->GetMethodID(
            vkSurfaceFormatKHRClass,
            "<init>",
            "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR;)V");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass collectionClass = env->GetObjectClass(jVkSurfaceFormatKHRCollection);
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

    for (const auto& surfaceFormat : surfaceFormats)
    {
        ///////////////////////////////////////////////////////////////////////////

        jclass vkFormatClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat");
        if (env->ExceptionOccurred())
        {
            cout << "vkGetPhysicalDeviceSurfaceFormatsKHR: could not find class " << "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat" << endl;
            return nullptr;
        }

        methodId = env->GetStaticMethodID(vkFormatClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            cout << "vkGetPhysicalDeviceSurfaceFormatsKHR: could not find static method " << "fromValue with signature (I)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;" << endl;
            return nullptr;
        }

        jobject formatEnum = env->CallStaticObjectMethod(vkFormatClass, methodId, surfaceFormat.format);

        ///////////////////////////////////////////////////////////////////////////

        jclass vkColorSpaceKHRClass = env->FindClass("com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR");
        if (env->ExceptionOccurred())
        {
            cout << "vkGetPhysicalDeviceSurfaceFormatsKHR: could not find class " << "ccom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR" << endl;
            return nullptr;
        }

        methodId = env->GetStaticMethodID(vkColorSpaceKHRClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR;");
        if (env->ExceptionOccurred())
        {
            cout << "vkGetPhysicalDeviceSurfaceFormatsKHR: could not find static method " << "fromValue with signature (I)Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR;" << endl;
            return nullptr;
        }

        jobject colorspaceEnum = env->CallStaticObjectMethod(vkColorSpaceKHRClass, methodId, surfaceFormat.colorSpace);

        ///////////////////////////////////////////////////////////////////////////

        jobject newVkSurfaceFormatKHR = env->NewObject(vkSurfaceFormatKHRClass, vkSurfaceFormatKHRConstructor, formatEnum, colorspaceEnum);
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        bool successfulAdd = false;
        successfulAdd = env->CallBooleanMethod(jVkSurfaceFormatKHRCollection, addMethodId, newVkSurfaceFormatKHR);
        if (successfulAdd == false)
        {
            cout << "ERROR:vkGetPhysicalDeviceSurfaceFormatsKHR the new VkSurfaceFormatKHR element was not added to jVkSurfaceFormatKHRCollection" << endl;
        }
    }

    return jvulkan::createVkResult(env, result);
}

