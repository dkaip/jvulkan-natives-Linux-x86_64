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
 * vkCmdCopyImage.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdCopyImage
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdCopyImage
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jSrcImage, jobject jSrcImageLayout, jobject jDstImage, jobject jDstImageLayout, jobject jVkImageCopyCollection)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkImage_T *srcImageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jSrcImage);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jSrcImage handle");
        return;
    }

	jclass vkImageLayoutEnumClass = env->GetObjectClass(jSrcImageLayout);

	jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id valueOf");
		return;
	}

	VkImageLayout srcImageLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jSrcImageLayout, valueOfMethodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod");
		return;
	}

    VkImage_T *dstImageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jDstImage);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jDstImage handle");
        return;
    }

	VkImageLayout dstImageLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jDstImageLayout, valueOfMethodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod");
		return;
	}

    std::vector<void *> memoryToFree(5);
    int numberOfVkImageCopies = 0;
    VkImageCopy *vkImageCopies = nullptr;
	jvulkan::getVkImageCopyCollection(
			env,
			jVkImageCopyCollection,
			&vkImageCopies,
			&numberOfVkImageCopies,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkImageCopyCollection");
		return;
	}

	vkCmdCopyImage(
			commandBufferHandle,
			srcImageHandle,
			srcImageLayoutEnumValue,
			dstImageHandle,
			dstImageLayoutEnumValue,
			numberOfVkImageCopies,
			vkImageCopies);

    jvulkan::freeMemory(&memoryToFree);
}
