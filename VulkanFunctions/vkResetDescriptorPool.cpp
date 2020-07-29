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
 * vkResetDescriptorPool.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkResetDescriptorPool
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDescriptorPool;Ljava/util/EnumSet;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkResetDescriptorPool
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDescriptorPool, jobject jVkDescriptorPoolResetFlags)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDescriptorPool_T *descriptorPoolHandle = (VkDescriptorPool_T *)jvulkan::getHandleValue(env, jVkDescriptorPool);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDescriptorPool handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDescriptorPoolResetFlags flags = (VkDescriptorPoolResetFlags)jvulkan::getEnumSetValue(
            env,
			jVkDescriptorPoolResetFlags,
            "com/CIMthetics/jvulkan/VulkanCore/Enums/VkDescriptorPoolResetFlagBits");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getEnumSetValue");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	VkResult result = vkResetDescriptorPool(
			deviceHandle,
			descriptorPoolHandle,
			flags);

    return jvulkan::createVkResult(env, result);
}
