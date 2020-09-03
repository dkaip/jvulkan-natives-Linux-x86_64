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
 * getRenderPassCreateInfo.cpp
 *
 *  Created on: May 20, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getRenderPassCreateInfo(
		JNIEnv *env,
		const jobject jVkRenderPassCreateInfoObject,
		VkRenderPassCreateInfo *renderPassCreateInfo,
		std::vector<void *> *memoryToFree)
	{
		jclass vkRenderPassCreateInfoClass = env->GetObjectClass(jVkRenderPassCreateInfoObject);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find class for jVkRenderPassCreateInfoObject");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		VkStructureType sTypeValue = getSType(env, jVkRenderPassCreateInfoObject);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Call to getSType failed.");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		jobject jpNextObject = getpNextObject(env, jVkRenderPassCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getpNext failed.");
			return;
		}

		void *pNext = nullptr;
		if (jpNextObject != nullptr)
		{
			getpNextChain(
					env,
					jpNextObject,
					&pNext,
					memoryToFree);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Call to getpNextChain failed.");
				return;
			}
		}

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(vkRenderPassCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getFlags");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkRenderPassCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		int32_t flags = getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkRenderPassCreateFlagBits");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkRenderPassCreateInfoClass, "getAttachments", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getAttachments");
			return;
		}

		jobject jAttachmentDescriptionCollection = env->CallObjectMethod(jVkRenderPassCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		int numberOfAttachmentDescriptions = 0;
		VkAttachmentDescription *vkAttachmentDescriptions = nullptr;

		getVkAttachmentDescriptionCollection(
				env,
				jAttachmentDescriptionCollection,
				&vkAttachmentDescriptions,
				&numberOfAttachmentDescriptions,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getVkAttachmentDescriptions");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkRenderPassCreateInfoClass, "getSubpasses", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getSubpasses");
			return;
		}

		jobject subpassDescriptionCollection = env->CallObjectMethod(jVkRenderPassCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		int numberOfSubpassDescriptions = 0;
		VkSubpassDescription *vkSubpassDescription = nullptr;

		getVkSubpassDescriptionCollection(
				env,
				subpassDescriptionCollection,
				&vkSubpassDescription,
				&numberOfSubpassDescriptions,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getVkSubpassDescriptionCollection");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkRenderPassCreateInfoClass, "getDependencies", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getDependencies");
			return;
		}

		jobject subpassDependencCollection = env->CallObjectMethod(jVkRenderPassCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		int numberOfSubpassDependencies = 0;
		VkSubpassDependency *vkSubpassDependency = nullptr;

		getVkSubpassDependencyCollection(
				env,
				subpassDependencCollection,
				&vkSubpassDependency,
				&numberOfSubpassDependencies,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getCollectionOfVkSubpassDependency");
			return;
		}

		renderPassCreateInfo->sType = sTypeValue;
		renderPassCreateInfo->pNext = pNext;
		renderPassCreateInfo->flags = flags;
		renderPassCreateInfo->attachmentCount = numberOfAttachmentDescriptions;
		renderPassCreateInfo->pAttachments = vkAttachmentDescriptions;
		renderPassCreateInfo->subpassCount = (uint32_t)numberOfSubpassDescriptions;
		renderPassCreateInfo->pSubpasses = vkSubpassDescription;
		renderPassCreateInfo->dependencyCount = (uint32_t)numberOfSubpassDependencies;
		renderPassCreateInfo->pDependencies = vkSubpassDependency;
	}
}
