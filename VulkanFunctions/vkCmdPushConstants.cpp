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
 * vkCmdPushConstants.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdPushConstants
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineLayout;Ljava/util/EnumSet;I[B)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdPushConstants
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkPipelineLayout, jobject jVkShaderStageFlags, jint offset, jbyteArray jValues)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkPipelineLayout_T *pipelineLayoutHandle = (VkPipelineLayout_T *)jvulkan::getHandleValue(env, jVkPipelineLayout);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkBuffer handle");
        return;
    }

    VkShaderStageFlags stageFlags = jvulkan::getEnumSetValue(
            env,
			jVkShaderStageFlags,
            "com/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderStageFlagBits");

    uint8_t *values = nullptr;
    jsize arrayLength = 0;
	arrayLength = env->GetArrayLength(jValues);

	values = (uint8_t *)calloc(arrayLength, sizeof(uint8_t));

	env->GetByteArrayRegion(jValues, 0, arrayLength, (signed char *)values);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling GetByteArrayRegion");
		return;
	}

	vkCmdPushConstants(
			commandBufferHandle,
			pipelineLayoutHandle,
			stageFlags,
			(unsigned int)offset,
			(unsigned int)arrayLength,
			(void *)values);

	free(values);
}

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdPushConstants
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineLayout;Ljava/util/EnumSet;I[F)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdPushConstants__Lcom_CIMthetics_jvulkan_VulkanCore_Handles_VkCommandBuffer_2Lcom_CIMthetics_jvulkan_VulkanCore_Handles_VkPipelineLayout_2Ljava_util_EnumSet_2I_3F
(JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkPipelineLayout, jobject jVkShaderStageFlags, jint offset, jfloatArray jValues)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkPipelineLayout_T *pipelineLayoutHandle = (VkPipelineLayout_T *)jvulkan::getHandleValue(env, jVkPipelineLayout);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkBuffer handle");
        return;
    }

    VkShaderStageFlags stageFlags = jvulkan::getEnumSetValue(
            env,
			jVkShaderStageFlags,
            "com/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderStageFlagBits");

    float *values = nullptr;
    jsize arrayLength = 0;
	arrayLength = env->GetArrayLength(jValues);

	values = (float *)calloc(arrayLength, sizeof(float));

	env->GetFloatArrayRegion(jValues, 0, arrayLength, (float *)values);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling GetFloatArrayRegion");
		return;
	}

	vkCmdPushConstants(
			commandBufferHandle,
			pipelineLayoutHandle,
			stageFlags,
			(unsigned int)offset,
			(unsigned int)arrayLength * sizeof(float),
			(void *)values);

	free(values);
}

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdPushConstants
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineLayout;Ljava/util/EnumSet;I[I)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdPushConstants__Lcom_CIMthetics_jvulkan_VulkanCore_Handles_VkCommandBuffer_2Lcom_CIMthetics_jvulkan_VulkanCore_Handles_VkPipelineLayout_2Ljava_util_EnumSet_2I_3I
(JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkPipelineLayout, jobject jVkShaderStageFlags, jint offset, jintArray jValues)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkPipelineLayout_T *pipelineLayoutHandle = (VkPipelineLayout_T *)jvulkan::getHandleValue(env, jVkPipelineLayout);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkBuffer handle");
        return;
    }

    VkShaderStageFlags stageFlags = jvulkan::getEnumSetValue(
            env,
			jVkShaderStageFlags,
            "com/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderStageFlagBits");

    uint32_t *values = nullptr;
    jsize arrayLength = 0;
	arrayLength = env->GetArrayLength(jValues);

	values = (uint32_t *)calloc(arrayLength, sizeof(uint32_t));

	env->GetIntArrayRegion(jValues, 0, arrayLength, (int *)values);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling GetIntArrayRegion");
		return;
	}

	vkCmdPushConstants(
			commandBufferHandle,
			pipelineLayoutHandle,
			stageFlags,
			(unsigned int)offset,
			(unsigned int)arrayLength * sizeof(uint32_t),
			(void *)values);

	free(values);
}


