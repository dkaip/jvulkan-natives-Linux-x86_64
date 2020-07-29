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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCreateGraphicsPipelines
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineCache;Ljava/util/Collection;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAllocationCallbacks;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCreateGraphicsPipelines
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPipelineCache, jobject jVkGraphicsPipelineCreateInfoCollection, jobject jAlternateAllocator, jobject jVkPipelineCollection)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
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
        	LOGERROR(env, "%s", "Could not retrieve VkPipelineCache handle");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    std::vector<void *> memoryToFree(5);
    int numberOfCreateInfos = 0;
    VkGraphicsPipelineCreateInfo *vkGraphicsPipelineCreateInfo = nullptr;

    jvulkan::getVkGraphicsPipelineCreateInfoCollection(
            env,
            jVkGraphicsPipelineCreateInfoCollection,
            &vkGraphicsPipelineCreateInfo,
            &numberOfCreateInfos,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkGraphicsPipelineCreateInfoCollection.");
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

    jvulkan::populatepNextChainCollection(
            env,
			jVkGraphicsPipelineCreateInfoCollection,
			(jvulkan::InfoStructure *)vkGraphicsPipelineCreateInfo,
			&memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to crawl the pNext chain.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);;
    }

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    jvulkan::freeMemory(&memoryToFree);

    jclass vkPipelineCollectionClass = env->GetObjectClass(jVkPipelineCollection);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to class for jVkPipelineCollection.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkPipelineCollectionClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get method id for size.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jint numberOfElements = env->CallIntMethod(jVkPipelineCollection, methodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (numberOfCreateInfos != numberOfElements)
    {
    	LOGERROR(env, "%s", "The collection size for resulting pipeline collection must be the same as jVkGraphicsPipelineCreateInfoCollection.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID iteratorMethodId = env->GetMethodID(vkPipelineCollectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get method id for iterator.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject iteratorObject = env->CallObjectMethod(jVkPipelineCollection, iteratorMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass iteratorClass = env->GetObjectClass(iteratorObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to class for iteratorObject.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get method id for hasNext.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get method id for next.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int i = 0;
    do
    {
        jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            break;
        }

        if (hasNext == false)
        {
            break;
        }

        jobject jVkPipelineObject = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            break;
        }

        /*
         * Now transfer the VkDevice data to Java
         */
        jvulkan::setHandleValue(env, jVkPipelineObject, pipelines[i]);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling setHandleValue.");
            break;
        }

        i++;
    } while(true);

    free(pipelines);

    return jvulkan::createVkResult(env, result);
}
