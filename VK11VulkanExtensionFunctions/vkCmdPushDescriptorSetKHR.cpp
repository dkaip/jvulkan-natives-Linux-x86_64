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
 * vkCmdPushDescriptorSetKHR.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern PFN_vkCmdPushDescriptorSetKHR 	vkCmdPushDescriptorSetKHRFunc;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdPushDescriptorSetKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineBindPoint;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPipelineLayout;ILjava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdPushDescriptorSetKHR
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkPipelineBindPointEnum, jobject jVkPipelineLayout, jint set, jobject jVkWriteDescriptorSetCollection)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

	jclass vkPipelineBindPointEnumClass = env->GetObjectClass(jVkPipelineBindPointEnum);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find class for jVkPipelineBindPointEnum");
		return;
	}

	jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointEnumClass, "valueOf", "()I");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id for valueOf.");
		return;
	}

	VkPipelineBindPoint vkPipelineBindPointEnumValue = (VkPipelineBindPoint)env->CallIntMethod(jVkPipelineBindPointEnum, valueOfMethodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod");
		return;
	}

    VkPipelineLayout_T *pipelineLayoutHandle = (VkPipelineLayout_T *)jvulkan::getHandleValue(env, jVkPipelineLayout);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkPipelineLayout handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkWriteDescriptorSets = 0;
    VkWriteDescriptorSet *vkWriteDescriptorSets = nullptr;
	jvulkan::getVkWriteDescriptorSetCollection(
			env,
			jVkWriteDescriptorSetCollection,
			&vkWriteDescriptorSets,
			&numberOfVkWriteDescriptorSets,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkWriteDescriptorSetCollection");
		return;
	}

	vkCmdPushDescriptorSetKHRFunc(
    		commandBufferHandle,
			vkPipelineBindPointEnumValue,
			pipelineLayoutHandle,
			set,
			numberOfVkWriteDescriptorSets,
			vkWriteDescriptorSets);

    jvulkan::freeMemory(&memoryToFree);
}
