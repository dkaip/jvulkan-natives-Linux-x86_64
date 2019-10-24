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
 * vkCmdCopyImageToBuffer.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: dkaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdCopyImageToBuffer
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkImage;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkBuffer;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdCopyImageToBuffer
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkImage, jobject jVkImageLayoutEnumObject, jobject jVkBuffer, jobject jVkBufferImageCopyCollection)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkImage_T *imageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jVkImage);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jVkImage handle");
        return;
    }

	jclass vkImageLayoutEnumClass = env->GetObjectClass(jVkImageLayoutEnumObject);

	jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id valueOf");
		return;
	}

	VkImageLayout vkImageLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutEnumObject, valueOfMethodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod");
		return;
	}

	VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jVkBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkBufferImageCopies = 0;
    VkBufferImageCopy *vkBufferImageCopies = nullptr;
	jvulkan::getVkBufferImageCopyCollection(
			env,
			jVkBufferImageCopyCollection,
			&vkBufferImageCopies,
			&numberOfVkBufferImageCopies,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkBufferImageCopyCollection");
		return;
	}

	vkCmdCopyImageToBuffer(
			commandBufferHandle,
			imageHandle,
			vkImageLayoutEnumValue,
			bufferHandle,
			(unsigned int)numberOfVkBufferImageCopies,
			vkBufferImageCopies);

    jvulkan::freeMemory(&memoryToFree);
}
