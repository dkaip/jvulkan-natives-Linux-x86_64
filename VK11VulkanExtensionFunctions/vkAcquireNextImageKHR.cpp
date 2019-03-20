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

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkAcquireNextImageKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkSwapchainKHR;JLcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkSemaphore;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkFence;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/IntReturnValue;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkAcquireNextImageKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSwapchainKHR, jlong jTimeout, jobject jVkSemaphore, jobject jVkFence, jobject jImageIndex)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSwapchainKHR_T *swapchainHandle = nullptr;
    if (jVkSwapchainKHR != nullptr)
    {
        swapchainHandle = (VkSwapchainKHR_T *)hwjvi::getHandleValue(env, jVkSwapchainKHR);
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    VkSemaphore_T *semaphoreHandle = nullptr;
    if (jVkSemaphore != nullptr)
    {
        semaphoreHandle = (VkSemaphore_T *)hwjvi::getHandleValue(env, jVkSemaphore);
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    VkFence_T *fenceHandle = nullptr;
    if (jVkFence != nullptr)
    {
        fenceHandle = (VkFence_T *)hwjvi::getHandleValue(env, jVkFence);
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }


    uint32_t imageIndex = 0xFFFFFFFF;
    int result = vkAcquireNextImageKHR(
            logicalDeviceHandle,
            swapchainHandle,
            jTimeout,
            semaphoreHandle,
            fenceHandle,
            &imageIndex);

    hwjvi::setIntReturnValue(env, jImageIndex, imageIndex);

    return hwjvi::createVkResult(env, result);
}
