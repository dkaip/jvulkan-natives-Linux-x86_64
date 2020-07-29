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
 * getVkSubpassDescriptionCollection.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSubpassDescriptionCollection(
			JNIEnv *env,
			const jobject jVkSubpassDescriptionCollectionObject,
			VkSubpassDescription **subpassDescriptions,
			int *numberOfDescriptions,
			std::vector<void *> *memoryToFree)
	{
		jclass vkSubpassDescriptionCollectionClass = env->GetObjectClass(jVkSubpassDescriptionCollectionObject);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jmethodID methodId = env->GetMethodID(vkSubpassDescriptionCollectionClass, "size", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint numberOfElements = env->CallIntMethod(jVkSubpassDescriptionCollectionObject, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		*numberOfDescriptions = numberOfElements;
		*subpassDescriptions = (VkSubpassDescription *)calloc(numberOfElements, sizeof(VkSubpassDescription));
		memoryToFree->push_back(*subpassDescriptions);

		jmethodID iteratorMethodId = env->GetMethodID(vkSubpassDescriptionCollectionClass, "iterator", "()Ljava/util/Iterator;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject iteratorObject = env->CallObjectMethod(jVkSubpassDescriptionCollectionObject, iteratorMethodId);
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

		int i = 0;
		jclass vkSubpassDescriptionClass = nullptr;
		jmethodID getFlagsMethodId;
		jmethodID getPipelineBindPointMethodId;
		jmethodID getInputAttachmentsMethodId;
		jmethodID getColorAttachmentsMethodId;
		jmethodID getResolveAttachmentsMethodId;
		jmethodID getDepthStencilAttachmentMethodId;
		jmethodID getPreserveAttachmentsMethodId;

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

			jobject jVkSubpassDescriptionObject = env->CallObjectMethod(iteratorObject, nextMethod);
			if (env->ExceptionOccurred())
			{
				break;
			}

			if (i == 0)
			{
				/*
				 * This "setup" only needs to be done in the first iteration.
				 */
				vkSubpassDescriptionClass = env->GetObjectClass(jVkSubpassDescriptionObject);
				if (env->ExceptionOccurred())
				{
					return;
				}

				getFlagsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getFlags", "()Ljava/util/EnumSet;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getPipelineBindPointMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getPipelineBindPoint", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineBindPoint;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getInputAttachmentsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getInputAttachments", "()Ljava/util/Collection;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getColorAttachmentsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getColorAttachments", "()Ljava/util/Collection;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getResolveAttachmentsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getResolveAttachments", "()Ljava/util/Collection;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getDepthStencilAttachmentMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getDepthStencilAttachment", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAttachmentReference;");
				if (env->ExceptionOccurred())
				{
					return;
				}

				getPreserveAttachmentsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getPreserveAttachments", "()[I");
				if (env->ExceptionOccurred())
				{
					return;
				}
			}

			////////////////////////////////////////////////////////////////////////
			jobject flagsObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getFlagsMethodId);
			int32_t flags = getEnumSetValue(
					env,
					flagsObject,
					"com/CIMthetics/jvulkan/VulkanCore/Enums/VkSubpassDescriptionFlagBits");

			////////////////////////////////////////////////////////////////////////
			jobject vkPipelineBindPointEnumObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getPipelineBindPointMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			jclass vkPipelineBindPointEnumClass = env->GetObjectClass(vkPipelineBindPointEnumObject);

			jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointEnumClass, "valueOf", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint vkPipelineBindPointEnumValue = env->CallIntMethod(vkPipelineBindPointEnumObject, valueOfMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			////////////////////////////////////////////////////////////////////////
			jobject vkAttachmentReferenceCollectionObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getInputAttachmentsMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			int numberOfInputAttachments = 0;
			VkAttachmentReference *inputAttachements = nullptr;

			getVkAttachmentReferenceCollection(
					env,
					vkAttachmentReferenceCollectionObject,
					&inputAttachements,
					&numberOfInputAttachments,
					memoryToFree);

			////////////////////////////////////////////////////////////////////////
			vkAttachmentReferenceCollectionObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getColorAttachmentsMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			int numberOfColorAttachments = 0;
			VkAttachmentReference *colorAttachements = nullptr;

			getVkAttachmentReferenceCollection(
					env,
					vkAttachmentReferenceCollectionObject,
					&colorAttachements,
					&numberOfColorAttachments,
					memoryToFree);

			////////////////////////////////////////////////////////////////////////
			vkAttachmentReferenceCollectionObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getResolveAttachmentsMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			int numberOfResolveAttachments = 0;
			VkAttachmentReference *resolveAttachements = nullptr;

			getVkAttachmentReferenceCollection(
					env,
					vkAttachmentReferenceCollectionObject,
					&resolveAttachements,
					&numberOfResolveAttachments,
					memoryToFree);

			////////////////////////////////////////////////////////////////////////
			jobject jVkAttachmentReferenceObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getDepthStencilAttachmentMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			VkAttachmentReference *depthStencilAttachment = nullptr;
			if (jVkAttachmentReferenceObject != nullptr)
			{
				depthStencilAttachment = (VkAttachmentReference *)calloc(1, sizeof(VkAttachmentReference));
				memoryToFree->push_back(depthStencilAttachment);

				getVkAttachmentReference(
					env,
					jVkAttachmentReferenceObject,
					depthStencilAttachment,
					memoryToFree);
			}

			////////////////////////////////////////////////////////////////////////
			jintArray jPreserveAttachmentArray = (jintArray)env->CallObjectMethod(jVkSubpassDescriptionObject, getPreserveAttachmentsMethodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			uint32_t *preserveAttachmentArray = nullptr;
			jsize arrayLength = 0;
			if (jPreserveAttachmentArray != nullptr)
			{
				arrayLength = env->GetArrayLength(jPreserveAttachmentArray);

				preserveAttachmentArray = (uint32_t *)calloc(arrayLength, sizeof(uint32_t));
				memoryToFree->push_back(preserveAttachmentArray);

				env->GetIntArrayRegion(jPreserveAttachmentArray, 0, arrayLength, (int *)preserveAttachmentArray);
				if (env->ExceptionOccurred())
				{
					return;
				}
			}

			(*subpassDescriptions)[i].flags         = (VkSubpassDescriptionFlags)flags;
			(*subpassDescriptions)[i].pipelineBindPoint = (VkPipelineBindPoint)vkPipelineBindPointEnumValue;
			(*subpassDescriptions)[i].inputAttachmentCount = numberOfInputAttachments;
			(*subpassDescriptions)[i].pInputAttachments = inputAttachements;
			(*subpassDescriptions)[i].colorAttachmentCount = numberOfColorAttachments;
			(*subpassDescriptions)[i].pColorAttachments = colorAttachements;
			(*subpassDescriptions)[i].pResolveAttachments = resolveAttachements;
			(*subpassDescriptions)[i].pDepthStencilAttachment = depthStencilAttachment;
			(*subpassDescriptions)[i].preserveAttachmentCount = (uint32_t)arrayLength;
			(*subpassDescriptions)[i].pPreserveAttachments = preserveAttachmentArray;

			i++;
		} while(true);
	}
}
