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
 * vkGetQueryPoolResults.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetQueryPoolResults
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkQueryPool;II[BJLjava/util/EnumSet;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetQueryPoolResults
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkQueryPool, jint firstQuery, jint queryCount, jbyteArray jData, jlong stride, jobject jVkQueryResultFlags)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkQueryPool_T *queryPoolHandle = (VkQueryPool_T *)jvulkan::getHandleValue(env, jVkQueryPool);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkQueryPool handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	size_t dataSize = env->GetArrayLength(jData);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling GetArrayLength.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    VkQueryResultFlags flags = (VkQueryResultFlags)jvulkan::getEnumSetValue(
            env,
			jVkQueryResultFlags,
            "com/CIMthetics/jvulkan/VulkanCore/Enums/VkQueryResultFlagBits");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getEnumSetValue");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	uint8_t data[dataSize];

	VkResult result = vkGetQueryPoolResults(
			deviceHandle,
			queryPoolHandle,
			firstQuery,
			queryCount,
			dataSize,
			data,
			stride,
			flags);

	env->SetByteArrayRegion(jData, 0, dataSize, (const signed char *)data);
	if (env->ExceptionOccurred())
	{
		free(data);
		LOGERROR(env, "%s", "Error calling SetByteArrayRegion.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    return jvulkan::createVkResult(env, result);
}
