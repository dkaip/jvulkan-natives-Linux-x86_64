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
 * getVkAcquireNextImageInfoKHR.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace jvulkan
{
    void getVkAcquireNextImageInfoKHR(
            JNIEnv *env,
            jobject jVkAcquireNextImageInfoKHRObject,
            VkAcquireNextImageInfoKHR *vkAcquireNextImageInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAcquireNextImageInfoKHRClass = env->GetObjectClass(jVkAcquireNextImageInfoKHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkAcquireNextImageInfoKHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkAcquireNextImageInfoKHRClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkAcquireNextImageInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAcquireNextImageInfoKHRClass, "getSwapchain", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkSwapchainKHR;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSwapchainKHRHandleObject = env->CallObjectMethod(jVkAcquireNextImageInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSwapchainKHR_T *vkSwapchainKHRHandle = (VkSwapchainKHR_T *)jvulkan::getHandleValue(env, jVkSwapchainKHRHandleObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAcquireNextImageInfoKHRClass, "getTimeout", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong timeout = env->CallLongMethod(jVkAcquireNextImageInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAcquireNextImageInfoKHRClass, "getSemaphore", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkSemaphore;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSemaphoreHandleObject = env->CallObjectMethod(jVkAcquireNextImageInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSemaphore_T *vkSemaphoreHandle = (VkSemaphore_T *)jvulkan::getHandleValue(env, jVkSemaphoreHandleObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAcquireNextImageInfoKHRClass, "getFence", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkFence;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFenceHandleObject = env->CallObjectMethod(jVkAcquireNextImageInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFence_T *vkFenceHandle = (VkFence_T *)jvulkan::getHandleValue(env, jVkFenceHandleObject);
        if (env->ExceptionOccurred())
        {
            return;
        }


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAcquireNextImageInfoKHRClass, "getDeviceMask", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint deviceMask = env->CallIntMethod(jVkAcquireNextImageInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkAcquireNextImageInfoKHR->sType = (VkStructureType)sTypeValue;
        vkAcquireNextImageInfoKHR->pNext = (void *)pNext;
        vkAcquireNextImageInfoKHR->swapchain = vkSwapchainKHRHandle;
        vkAcquireNextImageInfoKHR->timeout = timeout;
        vkAcquireNextImageInfoKHR->semaphore = vkSemaphoreHandle;
        vkAcquireNextImageInfoKHR->fence = vkFenceHandle;
        vkAcquireNextImageInfoKHR->deviceMask = deviceMask;
    }
}

