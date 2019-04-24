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
 * vkQueueInsertDebugUtilsLabelEXT.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: Douglas Kaip
 */

#include "../headers/slf4j.hh"
#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkQueueInsertDebugUtilsLabelEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkQueue;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkDebugUtilsLabelEXT;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkQueueInsertDebugUtilsLabelEXT
  (JNIEnv *env, jobject, jobject jVkQueue, jobject jVkDebugUtilsLabelEXT)
{
	VkQueue_T *vkQueueHandle = (VkQueue_T *)jvulkan::getHandleValue(env, jVkQueue);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to extract vkQueueHandle");
        return;
    }

    VkDebugUtilsLabelEXT vkDebugUtilsLabelEXT = {};
    std::vector<void *> memoryToFree(5);

    jvulkan::getVkDebugUtilsLabelEXT(env, jVkDebugUtilsLabelEXT, &vkDebugUtilsLabelEXT, &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to extract jVkDebugUtilsLabelEXT");
        return;
    }

    vkQueueInsertDebugUtilsLabelEXT(vkQueueHandle, &vkDebugUtilsLabelEXT);

    jvulkan::freeMemory(&memoryToFree);

    return;
}