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
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateFence
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkFenceCreateInfo;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkFence;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateFence
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkFenceCreateInfoObject, jobject jAlternateAllocator, jobject jVkFence)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    jclass vkFenceCreateInfoClass = env->GetObjectClass(jVkFenceCreateInfoObject);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    int sTypeValue = jvulkan::getSTypeAsInt(env, jVkFenceCreateInfoObject);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    jmethodID methodId = env->GetMethodID(vkFenceCreateInfoClass, "getpNext", "()J");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jlong pNext = env->CallLongMethod(jVkFenceCreateInfoObject, methodId);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    methodId = env->GetMethodID(vkFenceCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject flagsObject = env->CallObjectMethod(jVkFenceCreateInfoObject, methodId);
    VkFenceCreateFlags flags = jvulkan::getEnumSetValue(
            env,
            flagsObject,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSemaphoreCreateFlagBits");

    VkFenceCreateInfo vkFenceCreateInfo = {};
    vkFenceCreateInfo.sType = (VkStructureType)sTypeValue;
    vkFenceCreateInfo.pNext = (void *)pNext;
    vkFenceCreateInfo.flags = flags;

    VkFence_T *fenceHandle = nullptr;
    int result = vkCreateFence(logicalDeviceHandle, &vkFenceCreateInfo, allocatorCallbacks, &fenceHandle);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    /*
     * Now transfer the VkDevice data to Java
     */
    jvulkan::setHandleValue(env, jVkFence, fenceHandle);

    return jvulkan::createVkResult(env, result);
}

