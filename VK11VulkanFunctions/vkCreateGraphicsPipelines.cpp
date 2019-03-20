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
 * Method:    vkCreateGraphicsPipelines
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPipelineCache;Ljava/util/Collection;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateGraphicsPipelines
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPipelineCache, jobject jVkGraphicsPipelineCreateInfoCollection, jobject jAlternateAllocator, jobject jVkPipelineCollection)
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

    VkPipelineCache_T *pipelineCacheHandle = nullptr;
    if (jVkPipelineCache != nullptr)
    {
        pipelineCacheHandle = (VkPipelineCache_T *)jvulkan::getHandleValue(env, jVkPipelineCache);
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    std::vector<void *> memoryToFree(5);
    int numberOfCreateInfos = 0;
    VkGraphicsPipelineCreateInfo *vkGraphicsPipelineCreateInfo = nullptr;

    jvulkan::getCollectionOfVkGraphicsPipelineCreateInfo(
            env,
            jVkGraphicsPipelineCreateInfoCollection,
            &vkGraphicsPipelineCreateInfo,
            &numberOfCreateInfos,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPipeline *pipelines = (VkPipeline *)calloc(numberOfCreateInfos, sizeof(VkPipeline *));

    int result = vkCreateGraphicsPipelines(
            logicalDeviceHandle,
            pipelineCacheHandle,
            numberOfCreateInfos,
            vkGraphicsPipelineCreateInfo,
            allocatorCallbacks,
            pipelines);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    jvulkan::freeMemory(&memoryToFree);

    jclass vkPipelineCollectionClass = env->GetObjectClass(jVkPipelineCollection);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkPipelineCollectionClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jint numberOfElements = env->CallIntMethod(jVkPipelineCollection, methodId);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (numberOfCreateInfos != numberOfElements)
    {
        std::cerr << "ERROR: The collection size for resulting pipeline collection must be the same as jVkGraphicsPipelineCreateInfoCollection." << std::endl;
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID iteratorMethodId = env->GetMethodID(vkPipelineCollectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject iteratorObject = env->CallObjectMethod(jVkPipelineCollection, iteratorMethodId);
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

        jobject jVkPipelineObject = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
            break;
        }

        /*
         * Now transfer the VkDevice data to Java
         */
        jvulkan::setHandleValue(env, jVkPipelineObject, pipelines[i]);

        i++;
    } while(true);

    free(pipelines);

    return jvulkan::createVkResult(env, result);
}
