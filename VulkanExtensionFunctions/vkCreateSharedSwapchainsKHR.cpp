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
/*
 * vkCreateSharedSwapchainsKHR.cpp
 *
 *  Created on: Oct 25, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCreateSharedSwapchainsKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Ljava/util/Collection;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAllocationCallbacks;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCreateSharedSwapchainsKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSwapchainCreateInfoKHRCollection, jobject jAlternateAllocator, jobject jVkSwapchainKHRCollection)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkSwapchainCreateInfoKHRs = 0;
    VkSwapchainCreateInfoKHR *vkSwapchainCreateInfoKHRs = nullptr;
	jvulkan::getVkSwapchainCreateInfoKHRCollection(
			env,
			jVkSwapchainCreateInfoKHRCollection,
			&vkSwapchainCreateInfoKHRs,
			&numberOfVkSwapchainCreateInfoKHRs,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkSwapchainCreateInfoKHRCollection");
		return  jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    VkSwapchainKHR swapchains[numberOfVkSwapchainCreateInfoKHRs];

    VkResult result = vkCreateSharedSwapchainsKHR(
    		deviceHandle,
			numberOfVkSwapchainCreateInfoKHRs,
			vkSwapchainCreateInfoKHRs,
			allocatorCallbacks,
			swapchains);

    jvulkan::freeMemory(&memoryToFree);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    jclass vkSwapchainKHRCollectionClass = env->GetObjectClass(jVkSwapchainKHRCollection);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find class for jVkSwapchainKHRCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkSwapchainKHRCollectionClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find method id for size");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jint numberOfElements = env->CallIntMethod(jVkSwapchainKHRCollection, methodId);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Error calling CallIntMethod");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (numberOfVkSwapchainCreateInfoKHRs != numberOfElements)
    {
		LOGERROR(env, "%s", "The collection size for resulting swapchain collection must be the same as jVkSwapchainCreateInfoKHRCollection.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID iteratorMethodId = env->GetMethodID(vkSwapchainKHRCollectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find method id for iterator");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject iteratorObject = env->CallObjectMethod(jVkSwapchainKHRCollection, iteratorMethodId);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Error calling CallObjectMethod");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass iteratorClass = env->GetObjectClass(iteratorObject);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find class for iteratorObject");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find method id for hasNext");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find method id for next");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int i = 0;
    do
    {
        jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            break;
        }

        if (hasNext == false)
        {
            break;
        }

        jobject jVkSwapchainKHRObject = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling CallObjectMethod");
            break;
        }

        /*
         * Now transfer the VkPipeline data to Java
         */
        jvulkan::setHandleValue(env, jVkSwapchainKHRObject, swapchains[i]);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling setHandleValue");
            break;
        }

        i++;
    } while(true);

    return jvulkan::createVkResult(env, result);
}
