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
 * vkQueueBeginDebugUtilsLabelEXT.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"
#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkQueueBeginDebugUtilsLabelEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkQueue;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDebugUtilsLabelEXTlabelInfo;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkQueueBeginDebugUtilsLabelEXT
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

    vkQueueBeginDebugUtilsLabelEXT(vkQueueHandle, &vkDebugUtilsLabelEXT);

    jvulkan::freeMemory(&memoryToFree);

    return;
}
