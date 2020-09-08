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
 * Method:    vkGetBufferMemoryRequirements
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkMemoryRequirements;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetBufferMemoryRequirements
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkBuffer, jobject jVkMemoryRequirements)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkMemoryRequirements vkMemoryRequirements = {};

    vkGetBufferMemoryRequirements(logicalDeviceHandle, bufferHandle, &vkMemoryRequirements);

    jvulkan::populateVkMemoryRequirements(
    		env,
			jVkMemoryRequirements,
			&vkMemoryRequirements);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkMemoryRequirements");
        return;
    }

    return;
}
