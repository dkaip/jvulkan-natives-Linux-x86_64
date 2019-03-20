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
 * Method:    vkAllocateCommandBuffers
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkCommandBufferAllocateInfo;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkAllocateCommandBuffers
  (JNIEnv *env , jobject, jobject jVkDevice, jobject jVkCommandBufferAllocateInfo, jobject jVkCommandBufferCollection)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkCommandBufferAllocateInfo vkCommandBufferAllocateInfo = {};
    std::vector<void *> memoryToFree(5);

    jvulkan::getVkCommandBufferAllocateInfo(env, jVkCommandBufferAllocateInfo, &vkCommandBufferAllocateInfo, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkCommandBuffer *commandBuffers = (VkCommandBuffer *)calloc(vkCommandBufferAllocateInfo.commandBufferCount, sizeof(VkCommandBuffer *));

    int result = vkAllocateCommandBuffers(
            logicalDeviceHandle,
            &vkCommandBufferAllocateInfo,
            commandBuffers);


    jvulkan::freeMemory(&memoryToFree);

    jclass vkCommandBuffeCollectionClass = env->GetObjectClass(jVkCommandBufferCollection);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkCommandBuffeCollectionClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jint numberOfElements = env->CallIntMethod(jVkCommandBufferCollection, methodId);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (vkCommandBufferAllocateInfo.commandBufferCount != (uint32_t)numberOfElements)
    {
        std::cerr << "ERROR: The collection size for resulting pipeline collection must be the same as jVkGraphicsPipelineCreateInfoCollection." << std::endl;
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID iteratorMethodId = env->GetMethodID(vkCommandBuffeCollectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject iteratorObject = env->CallObjectMethod(jVkCommandBufferCollection, iteratorMethodId);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass iteratorClass = env->GetObjectClass(iteratorObject);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int i = 0;
    do
    {
        jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
        if (env->ExceptionOccurred())
        {
            break;
        }

        if (hasNext == false)
        {
            break;
        }

        jobject jVkCommandBufferObject = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
            break;
        }

        /*
         * Now transfer the VkDevice data to Java
         */
        jvulkan::setHandleValue(env, jVkCommandBufferObject, commandBuffers[i]);

        i++;
    } while(true);

    free(commandBuffers);

    return jvulkan::createVkResult(env, result);
}
