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
 * vkCmdResolveImage.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdResolveImage
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdResolveImage
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jSrcImage, jobject jSrcImageLayout, jobject jDstImage, jobject jDstImageLayout, jobject jVkImageResolveCollection)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkImage_T *srcImage = (VkImage_T *)jvulkan::getHandleValue(env, jSrcImage);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jSrcImage handle");
        return;
    }

	jclass enumClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout");
		return;
	}

	jmethodID methodId = env->GetMethodID(enumClass, "valueOf", "()I");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id valueOf in class com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout");
		return;
	}

	jint enumValue = env->CallIntMethod(jSrcImageLayout, methodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod for valueOf");
		return;
	}

	VkImageLayout srcImageLayout = (VkImageLayout)enumValue;

    VkImage_T *dstImage = (VkImage_T *)jvulkan::getHandleValue(env, jDstImage);
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

    std::vector<void *> memoryToFree(5);
    int numberOfVkImageResolves = 0;
    VkImageResolve *vkImageResolves = nullptr;
	jvulkan::getVkImageResolveCollection(
			env,
			jVkImageResolveCollection,
			&vkImageResolves,
			&numberOfVkImageResolves,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkImageResolveCollection");
		return;
	}

	vkCmdResolveImage(
			commandBufferHandle,
			srcImage,
			srcImageLayout,
			dstImage,
			dstImageLayout,
			numberOfVkImageResolves,
			vkImageResolves);

    jvulkan::freeMemory(&memoryToFree);
}
