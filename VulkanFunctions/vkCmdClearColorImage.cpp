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
 * vkCmdClearColorImage.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdClearColorImage
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkClearColorValue;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdClearColorImage
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkImage, jobject jVkImageLayoutEnumObject, jobject jVkClearColorValue, jobject jVkImageSubresourceRangeCollection)
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
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find class for jVkImageLayoutEnumObject");
		return;
	}

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

    std::vector<void *> memoryToFree(5);
    VkClearColorValue vkClearColorValue = {};
    jvulkan::getVkClearColorValue(
            env,
			jVkClearColorValue,
			&vkClearColorValue,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkClearColorValue.");
        return;
    }

    int numberOfVkImageSubresourceRanges = 0;
    VkImageSubresourceRange *vkImageSubresourceRanges = nullptr;
    if (vkImageSubresourceRanges != nullptr)
    {
        jvulkan::getVkImageSubresourceRangeCollection(
                env,
				jVkImageSubresourceRangeCollection,
                &vkImageSubresourceRanges,
                &numberOfVkImageSubresourceRanges,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageSubresourceRangeCollection");
            return;
        }
    }

    vkCmdClearColorImage(
    		commandBufferHandle,
			imageHandle,
			vkImageLayoutEnumValue,
			&vkClearColorValue,
			(unsigned int)numberOfVkImageSubresourceRanges,
			vkImageSubresourceRanges);

    jvulkan::freeMemory(&memoryToFree);
}
