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
 * Method:    vkGetSwapchainImagesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkSwapchainKHR;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetSwapchainImagesKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSwapchainKHR, jobject jswapchainImageCollection)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSwapchainKHR_T *swapchainHandle = (VkSwapchainKHR_T *)jvulkan::getHandleValue(env, jVkSwapchainKHR);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }


    uint32_t numberOfImages = 0;

    int result = vkGetSwapchainImagesKHR(logicalDeviceHandle, swapchainHandle, &numberOfImages, nullptr);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, result);
    }

    VkImage_T **swapchainImageHandles = (VkImage_T **)calloc(numberOfImages, sizeof(VkImage *));

    result = vkGetSwapchainImagesKHR(logicalDeviceHandle, swapchainHandle, &numberOfImages, swapchainImageHandles);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, result);
    }

    jclass collectionClass = env->GetObjectClass(jswapchainImageCollection);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    for (uint32_t i = 0; i < numberOfImages; i++)
    {
        jobject vkImageHandle = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkImage", swapchainImageHandles[i]);
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jboolean addResult = env->CallBooleanMethod(jswapchainImageCollection, addMethodId, vkImageHandle);
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        if (addResult == false)
        {
            cerr << "Warning did not add VkImage to output collection." << endl;
        }
    }

    free(swapchainImageHandles);
    return jvulkan::createVkResult(env, result);
}

