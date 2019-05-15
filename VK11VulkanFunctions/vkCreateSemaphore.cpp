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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateSemaphore
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkSemaphoreCreateInfo;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkSemaphore;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateSemaphore
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSemaphoreCreateInfoObject, jobject jAlternateAllocator, jobject jVkSemaphore)
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

    jclass vkSemaphoreCreateInfoClass = env->GetObjectClass(jVkSemaphoreCreateInfoObject);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    int sTypeValue = jvulkan::getSTypeAsInt(env, jVkSemaphoreCreateInfoObject);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    jobject pNextObject = jvulkan::getpNextObject(env, jVkSemaphoreCreateInfoObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getpNext failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (pNextObject != nullptr)
    {
    	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    void *pNext = nullptr;

    ////////////////////////////////////////////////////////////////////////
    jmethodID methodId = env->GetMethodID(vkSemaphoreCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject flagsObject = env->CallObjectMethod(jVkSemaphoreCreateInfoObject, methodId);
    VkSemaphoreCreateFlags flags = jvulkan::getEnumSetValue(
            env,
            flagsObject,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSemaphoreCreateFlagBits");

    VkSemaphoreCreateInfo vkSemaphoreCreateInfo = {};
    vkSemaphoreCreateInfo.sType = (VkStructureType)sTypeValue;
    vkSemaphoreCreateInfo.pNext = (void *)pNext;
    vkSemaphoreCreateInfo.flags = flags;

    VkSemaphore_T *semaphoreHandle = nullptr;
    int result = vkCreateSemaphore(logicalDeviceHandle, &vkSemaphoreCreateInfo, allocatorCallbacks, &semaphoreHandle);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    /*
     * Now transfer the VkDevice data to Java
     */
    jvulkan::setHandleValue(env, jVkSemaphore, semaphoreHandle);

    return jvulkan::createVkResult(env, result);
}

