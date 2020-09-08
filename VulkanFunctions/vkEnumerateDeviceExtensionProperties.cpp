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
#include <vector>

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkEnumerateDeviceExtensionProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Ljava/lang/String;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkEnumerateDeviceExtensionProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jstring jlayerName, jobject jEnumerateDeviceExtensionPropertiesCollection)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t numberOfPhysicalDeviceExtensionProperties = 0;

    const char *layerName = nullptr;
    if (jlayerName != nullptr)
    {
        layerName = env->GetStringUTFChars(jlayerName, 0);
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    VkResult result = vkEnumerateDeviceExtensionProperties(
            vkPhysicalDeviceHandle,
            layerName,
            &numberOfPhysicalDeviceExtensionProperties,
            nullptr);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, result);
    }

    if (numberOfPhysicalDeviceExtensionProperties != 0)
    {
        std::vector<VkExtensionProperties> extensionList(numberOfPhysicalDeviceExtensionProperties);

        result = vkEnumerateDeviceExtensionProperties(
                vkPhysicalDeviceHandle,
                layerName,
                &numberOfPhysicalDeviceExtensionProperties,
                extensionList.data());
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, result);
        }

        jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Structures/VkExtensionProperties");
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID constructor = env->GetMethodID(javaClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jclass collectionClass = env->GetObjectClass(jEnumerateDeviceExtensionPropertiesCollection);
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        for (const auto& extension : extensionList)
        {
            jobject newObject = env->NewObject(javaClass, constructor);
            if (env->ExceptionOccurred())
            {
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            jmethodID methodId = env->GetMethodID(javaClass, "setExtensionName", "(Ljava/lang/String;)V");
            if (env->ExceptionOccurred())
            {
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            jstring extensionName = env->NewStringUTF(extension.extensionName);
            env->CallVoidMethod(newObject, methodId, extensionName);
            if (env->ExceptionOccurred())
            {
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            methodId = env->GetMethodID(javaClass, "setSpecVersion", "(I)V");
            if (env->ExceptionOccurred())
            {
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            env->CallVoidMethod(newObject, methodId, extension.specVersion);
            if (env->ExceptionOccurred())
            {
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            bool addResult = env->CallBooleanMethod(jEnumerateDeviceExtensionPropertiesCollection, addMethodId, newObject);
            if (env->ExceptionOccurred())
            {
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            if (addResult == false)
            {
                cout << "Error VkPhysicalDevice element did not get added." << endl;
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }
        }
    }

    if (jlayerName != nullptr)
    {
        env->ReleaseStringUTFChars(jlayerName, layerName);
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    return jvulkan::createVkResult(env, result);
}
