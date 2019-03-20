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
 * Method:    vkQueueSubmit
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkQueue;Ljava/util/Collection;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkFence;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkQueueSubmit
  (JNIEnv *env, jobject, jobject jVkQueue, jobject jVkSubmitInfoCollection, jobject jVkFence)
{
    VkQueue_T *vkQueueHandle = (VkQueue_T *)hwjvi::getHandleValue(env, jVkQueue);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkFence_T *vkFenceHandle = nullptr;
    if (jVkFence != nullptr)
    {
        vkFenceHandle = (VkFence_T *)hwjvi::getHandleValue(env, jVkFence);
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkSubmitInfos = 0;
    VkSubmitInfo *vkSubmitInfos = nullptr;

    hwjvi::getVkSubmitInfoCollection(
            env,
            jVkSubmitInfoCollection,
            &vkSubmitInfos,
            &numberOfVkSubmitInfos,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int result = vkQueueSubmit(
            vkQueueHandle,
            numberOfVkSubmitInfos,
            vkSubmitInfos,
            vkFenceHandle);

    hwjvi::freeMemory(&memoryToFree);

    return hwjvi::createVkResult(env, result);
}
