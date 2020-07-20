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
 * vkGetDeviceQueue2.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetDeviceQueue2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkDeviceQueueInfo2;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkQueue;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetDeviceQueue2
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDeviceQueueInfo2, jobject jVkQueue)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkDeviceQueueInfo2 vkDeviceQueueInfo2 = {};
    jvulkan::getVkDeviceQueueInfo2(
            env,
			jVkDeviceQueueInfo2,
			&vkDeviceQueueInfo2,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkDeviceQueueInfo2.");
        return;
    }

    VkQueue vkQueue = nullptr;
    vkGetDeviceQueue2(
    		deviceHandle,
			&vkDeviceQueueInfo2,
			&vkQueue);

    /*
     * Now transfer the VkQueue data to Java
     */
    jvulkan::setHandleValue(env, jVkQueue, vkQueue);

    jvulkan::freeMemory(&memoryToFree);
}
