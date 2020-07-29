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
 * vkGetPipelineCacheData.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPipelineCacheData
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineCache;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/ByteArrayReturnValue;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPipelineCacheData
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPipelineCache, jobject jByteArrayReturnValue)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkPipelineCache_T *pipelineCacheHandle = (VkPipelineCache_T *)jvulkan::getHandleValue(env, jVkPipelineCache);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPipelineCache handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	size_t dataSize = 0;
	void   *data = nullptr;

	VkResult result = vkGetPipelineCacheData(
			deviceHandle,
			pipelineCacheHandle,
			&dataSize,
			nullptr);
	if (result != VK_SUCCESS)
	{
		LOGERROR(env, "vkGetPipelineCacheData returned %d.", result);
		return jvulkan::createVkResult(env, result);
	}

	data = calloc(dataSize, 1);
	if (data == nullptr)
	{
		LOGERROR(env, "Error trying to allocate %ld bytes of memory for data", dataSize);
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	result = vkGetPipelineCacheData(
			deviceHandle,
			pipelineCacheHandle,
			&dataSize,
			data);
	if (result != VK_SUCCESS)
	{
		free(data);
		LOGERROR(env, "vkGetPipelineCacheData returned %d.", result);
		return jvulkan::createVkResult(env, result);
	}

	jclass byteArrayReturnValueClass = env->GetObjectClass(jByteArrayReturnValue);
	if (env->ExceptionOccurred())
	{
		free(data);
		LOGERROR(env, "%s", "Error trying to get class for jByteArrayReturnValue");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	jmethodID methodId = env->GetMethodID(byteArrayReturnValueClass, "setValue", "([B)V" );
	if (env->ExceptionOccurred())
	{
		free(data);
		LOGERROR(env, "%s", "Could not find method id for setValue");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	jbyteArray returnData = env->NewByteArray(dataSize);
	if (env->ExceptionOccurred())
	{
		free(data);
		LOGERROR(env, "%s", "Error calling NewByteArray.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	env->SetByteArrayRegion(returnData, 0, dataSize, (const signed char *)data);
	if (env->ExceptionOccurred())
	{
		free(data);
		LOGERROR(env, "%s", "Error calling SetByteArrayRegion.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	free(data);

	env->CallVoidMethod(jByteArrayReturnValue, methodId, returnData);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", voidMethodErrorText);
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    return jvulkan::createVkResult(env, result);
}
