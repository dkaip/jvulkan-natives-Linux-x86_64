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
 * vkGetShaderInfoAMD.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetShaderInfoAMD
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPipeline;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkShaderStageFlagBits;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkShaderInfoTypeAMD;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/ByteArrayReturnValue;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetShaderInfoAMD
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPipeline, jobject jVkShaderStageFlagBits, jobject jVkShaderInfoTypeAMD, jobject jByteArrayReturnValue)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkPipeline_T *pipelineHandle = (VkPipeline_T *)jvulkan::getHandleValue(env, jVkPipeline);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPipeline handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    jclass vkShaderStageFlagBitsEnumClass = env->GetObjectClass(jVkShaderStageFlagBits);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error getting class for jVkShaderStageFlagBits");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkShaderStageFlagBitsEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id for valueOf");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkShaderStageFlagBits shaderStageEnumValue = (VkShaderStageFlagBits)env->CallIntMethod(jVkShaderStageFlagBits, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass vkShaderInfoTypeAMDEnumClass = env->GetObjectClass(jVkShaderInfoTypeAMD);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error getting class for jVkShaderInfoTypeAMD");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    valueOfMethodId = env->GetMethodID(vkShaderInfoTypeAMDEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id for valueOf");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkShaderInfoTypeAMD infoTypeEnumValue = (VkShaderInfoTypeAMD)env->CallIntMethod(jVkShaderInfoTypeAMD, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	size_t dataSize = 0;
	void   *data = nullptr;

	VkResult result = vkGetShaderInfoAMD(
			deviceHandle,
			pipelineHandle,
			shaderStageEnumValue,
			infoTypeEnumValue,
			&dataSize,
			nullptr);
	if (result != VK_SUCCESS)
	{
		LOGERROR(env, "vkGetShaderInfoAMD returned %d.", result);
		return jvulkan::createVkResult(env, result);
	}

	data = calloc(dataSize, 1);
	if (data == nullptr)
	{
		LOGERROR(env, "Error trying to allocate %ld bytes of memory for data", dataSize);
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	result = vkGetShaderInfoAMD(
			deviceHandle,
			pipelineHandle,
			shaderStageEnumValue,
			infoTypeEnumValue,
			&dataSize,
			data);
	if (result != VK_SUCCESS)
	{
		free(data);
		LOGERROR(env, "vkGetShaderInfoAMD returned %d.", result);
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
