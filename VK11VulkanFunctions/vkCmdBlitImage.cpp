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
 * vkCmdBlitImage.cpp
 *
 *  Created on: Oct 15, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdBlitImage
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkImage;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkImage;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout;Ljava/util/Collection;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFilter;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdBlitImage
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jSrcImage, jobject jSrcImageLayout, jobject jDstImage, jobject jDstImageLayout, jobject jRegionCollection, jobject jFilter)
{
    ///////////////////////////////////////////////////////////////////////////
	VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
		return;
	}

    ///////////////////////////////////////////////////////////////////////////
	VkImage_T *sourceImageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jSrcImage);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve jSrcImage handle");
		return;
	}

    ///////////////////////////////////////////////////////////////////////////
	jclass enumClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout");
		return;
	}

	jmethodID methodId = env->GetMethodID(enumClass, "valueOf", "()I");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id valueOf in class com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout");
		return;
	}

	jint enumValue = env->CallIntMethod(jSrcImageLayout, methodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod for valueOf");
		return;
	}

	VkImageLayout srcImageLayout = (VkImageLayout)enumValue;

    ///////////////////////////////////////////////////////////////////////////
	VkImage_T *destImageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jDstImage);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve jDstImage handle");
		return;
	}

	enumValue = env->CallIntMethod(jDstImageLayout, methodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod for valueOf");
		return;
	}

	VkImageLayout dstImageLayout = (VkImageLayout)enumValue;

    ///////////////////////////////////////////////////////////////////////////
	std::vector<void *> memoryToFree(5);
	int numberOfVkImageBlits = 0;
	VkImageBlit *vkImageBlits = nullptr;
	if (jRegionCollection != nullptr)
	{
		jvulkan::getVkImageBlitCollection(
				env,
				jRegionCollection,
                &vkImageBlits,
				&numberOfVkImageBlits,
				&memoryToFree);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling CallIntMethod for valueOf");
			return;
		}
	}

    ///////////////////////////////////////////////////////////////////////////

	enumClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFilter");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFilter");
		return;
	}

	methodId = env->GetMethodID(enumClass, "valueOf", "()I");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id valueOf in class com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout");
        return;
	}

	enumValue = env->CallIntMethod(jFilter, methodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod for valueOf");
		return;
	}

	VkFilter filter = (VkFilter)enumValue;

	vkCmdBlitImage(
			commandBufferHandle,
			sourceImageHandle,
			srcImageLayout,
			destImageHandle,
			dstImageLayout,
			numberOfVkImageBlits,
			vkImageBlits,
			filter);

    jvulkan::freeMemory(&memoryToFree);
}
