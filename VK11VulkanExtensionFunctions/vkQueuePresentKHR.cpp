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
 * Method:    vkQueuePresentKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkQueue;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPresentInfoKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkQueuePresentKHR
  (JNIEnv *env, jobject, jobject jVkQueue, jobject jVkPresentInfoKHR)
{
    VkQueue_T *vkQueueHandle = (VkQueue_T *)jvulkan::getHandleValue(env, jVkQueue);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    VkPresentInfoKHR vkPresentInfoKHR = {};
    jobject jVkResultsCollectionObject = nullptr;

    jvulkan::getVkPresentInfoKHR(
            env,
            jVkPresentInfoKHR,
            &vkPresentInfoKHR,
            &jVkResultsCollectionObject,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int result = vkQueuePresentKHR(
            vkQueueHandle,
            &vkPresentInfoKHR);

    if (jVkResultsCollectionObject != nullptr)
    {
        jclass vkResultsCollectionClass = env->GetObjectClass(jVkResultsCollectionObject);
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID addMethodId = env->GetMethodID(vkResultsCollectionClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        for (uint32_t i = 0; i < vkPresentInfoKHR.swapchainCount; i++)
        {
            jobject jVkResultObject = jvulkan::createVkResult(env, vkPresentInfoKHR.pResults[i]);
            if (env->ExceptionOccurred())
            {
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            jboolean added = env->CallBooleanMethod(jVkResultsCollectionObject, addMethodId, jVkResultObject);
            if (env->ExceptionOccurred())
            {
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            if (added == 0)
            {
                std::cerr << "Could not add VkResult to output collection." << std::endl;
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }
        }
    }

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
