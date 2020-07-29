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
 * getVkAttachmentDescriptions.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkAttachmentDescriptionCollection(
			JNIEnv *env,
			const jobject jVkAttachmentDescriptionCollectionObject,
			VkAttachmentDescription **attachmentDescriptions,
			int *numberOfAttachments,
			std::vector<void *> *memoryToFree)
	{
		jclass vkAttachmentDescriptionCollectionClass = env->GetObjectClass(jVkAttachmentDescriptionCollectionObject);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jmethodID methodId = env->GetMethodID(vkAttachmentDescriptionCollectionClass, "size", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint numberOfElements = env->CallIntMethod(jVkAttachmentDescriptionCollectionObject, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		*numberOfAttachments = numberOfElements;
		*attachmentDescriptions = (VkAttachmentDescription *)calloc(numberOfElements, sizeof(VkAttachmentDescription));
		memoryToFree->push_back(*attachmentDescriptions);

		jmethodID iteratorMethodId = env->GetMethodID(vkAttachmentDescriptionCollectionClass, "iterator", "()Ljava/util/Iterator;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject iteratorObject = env->CallObjectMethod(jVkAttachmentDescriptionCollectionObject, iteratorMethodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jclass iteratorClass = env->GetObjectClass(iteratorObject);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jclass vkAttachmentDescriptionClass = nullptr;
		jmethodID getFlagsMethodId;
		jmethodID getFormatMethodId;
		jmethodID getSamplesMethodId;
		jmethodID getLoadOpMethodId;
		jmethodID getStoreOpMethodId;
		jmethodID getStencilLoadOpMethodId;
		jmethodID getStencilStoreOpMethodId;
		jmethodID getInitialLayoutMethodId;
		jmethodID getFinalLayoutMethodId;
		int i = 0;
		do
		{
			jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
			if (env->ExceptionOccurred())
			{
				break;
			}

			if (hasNext == false)
			{
				break;
			}

			jobject jVkAttachmentDescriptionObject = env->CallObjectMethod(iteratorObject, nextMethod);
			if (env->ExceptionOccurred())
			{
				break;
			}

			if (i == 0)
			{
				/*
				 * This "setup" only needs to be done in the first iteration.
				 */
				vkAttachmentDescriptionClass = env->GetObjectClass(jVkAttachmentDescriptionObject);
				if (env->ExceptionOccurred())
				{
					return;
				}

				getFlagsMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getFlags", "()Ljava/util/EnumSet;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getFormatMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getSamplesMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getSamples", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getLoadOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getLoadOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentLoadOp;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getStoreOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getStoreOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentStoreOp;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getStencilLoadOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getStencilLoadOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentLoadOp;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getStencilStoreOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getStencilStoreOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentStoreOp;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getInitialLayoutMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getInitialLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getFinalLayoutMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getFinalLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;");
				if (env->ExceptionOccurred())
				{
					return;
				}

			}

			////////////////////////////////////////////////////////////////////////
			jobject flagsObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getFlagsMethodId);
			int32_t flags = getEnumSetValue(
					env,
					flagsObject,
					"com/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentDescriptionFlagBits");

			////////////////////////////////////////////////////////////////////////
			jobject vkFormatEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getFormatMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			jclass vkFormatEnumEnumClass = env->GetObjectClass(vkFormatEnumObject);

			jmethodID valueOfMethodId = env->GetMethodID(vkFormatEnumEnumClass, "valueOf", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint vkFormatEnumEnumValue = env->CallIntMethod(vkFormatEnumObject, valueOfMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			////////////////////////////////////////////////////////////////////////
			jobject vkSampleCountFlagBitsEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getSamplesMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			jclass vkSampleCountFlagBitsEnumClass = env->GetObjectClass(vkSampleCountFlagBitsEnumObject);

			valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsEnumClass, "valueOf", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint vkSampleCountFlagBitsEnumValue = env->CallIntMethod(vkSampleCountFlagBitsEnumObject, valueOfMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			////////////////////////////////////////////////////////////////////////
			jobject vkAttachmentLoadOpEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getLoadOpMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			jclass vkAttachmentLoadOpEnumClass = env->GetObjectClass(vkAttachmentLoadOpEnumObject);

			valueOfMethodId = env->GetMethodID(vkAttachmentLoadOpEnumClass, "valueOf", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint vkAttachmentLoadOpEnumValue = env->CallIntMethod(vkAttachmentLoadOpEnumObject, valueOfMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			////////////////////////////////////////////////////////////////////////
			jobject vkAttachmentStoreOpEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getStoreOpMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			jclass vkAttachmentStoreOpEnumClass = env->GetObjectClass(vkAttachmentStoreOpEnumObject);

			valueOfMethodId = env->GetMethodID(vkAttachmentStoreOpEnumClass, "valueOf", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint vkAttachmentStoreOpEnumValue = env->CallIntMethod(vkAttachmentStoreOpEnumObject, valueOfMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			////////////////////////////////////////////////////////////////////////
			vkAttachmentLoadOpEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getStencilLoadOpMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			vkAttachmentLoadOpEnumClass = env->GetObjectClass(vkAttachmentLoadOpEnumObject);

			valueOfMethodId = env->GetMethodID(vkAttachmentLoadOpEnumClass, "valueOf", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint stencilLoadOpEnumValue = env->CallIntMethod(vkAttachmentLoadOpEnumObject, valueOfMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			////////////////////////////////////////////////////////////////////////
			vkAttachmentStoreOpEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getStencilStoreOpMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			vkAttachmentStoreOpEnumClass = env->GetObjectClass(vkAttachmentStoreOpEnumObject);

			valueOfMethodId = env->GetMethodID(vkAttachmentStoreOpEnumClass, "valueOf", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint stencilStoreOpEnumValue = env->CallIntMethod(vkAttachmentStoreOpEnumObject, valueOfMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			////////////////////////////////////////////////////////////////////////
			jobject vkImageLayoutEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getInitialLayoutMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			jclass vkImageLayoutEnumClass = env->GetObjectClass(vkImageLayoutEnumObject);

			valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint initialLayoutEnumValue = env->CallIntMethod(vkImageLayoutEnumObject, valueOfMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			////////////////////////////////////////////////////////////////////////
			vkImageLayoutEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getFinalLayoutMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			vkImageLayoutEnumClass = env->GetObjectClass(vkImageLayoutEnumObject);

			valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint finalLayoutEnumValue = env->CallIntMethod(vkImageLayoutEnumObject, valueOfMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			(*attachmentDescriptions)[i].flags    = (VkAttachmentDescriptionFlags)flags;
			(*attachmentDescriptions)[i].format   = (VkFormat)vkFormatEnumEnumValue;
			(*attachmentDescriptions)[i].samples  = (VkSampleCountFlagBits)vkSampleCountFlagBitsEnumValue;
			(*attachmentDescriptions)[i].loadOp   = (VkAttachmentLoadOp)vkAttachmentLoadOpEnumValue;
			(*attachmentDescriptions)[i].storeOp  = (VkAttachmentStoreOp)vkAttachmentStoreOpEnumValue;
			(*attachmentDescriptions)[i].stencilLoadOp  = (VkAttachmentLoadOp)stencilLoadOpEnumValue;
			(*attachmentDescriptions)[i].stencilStoreOp = (VkAttachmentStoreOp)stencilStoreOpEnumValue;
			(*attachmentDescriptions)[i].initialLayout  = (VkImageLayout)initialLayoutEnumValue;
			(*attachmentDescriptions)[i].finalLayout    = (VkImageLayout)finalLayoutEnumValue;

			i++;
		} while(true);
	}
}
