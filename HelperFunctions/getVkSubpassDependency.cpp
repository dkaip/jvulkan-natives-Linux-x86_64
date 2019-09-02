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
 * getVkSubpassDependency.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSubpassDependency(
			JNIEnv *env,
			const jobject jVkSubpassDependencyObject,
			VkSubpassDependency *subpassDependency,
			std::vector<void *> *memoryToFree)
	{
		jclass vkSubpassDependencyClass = env->GetObjectClass(jVkSubpassDependencyObject);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(vkSubpassDependencyClass, "getSrcSubpass", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint srcSubpass = env->CallIntMethod(jVkSubpassDependencyObject, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSubpassDependencyClass, "getDstSubpass", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint dstSubpass = env->CallIntMethod(jVkSubpassDependencyObject, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSubpassDependencyClass, "getSrcStageMask", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
		int32_t srcStageMask = getEnumSetValue(
				env,
				enumSetObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSubpassDependencyClass, "getDstStageMask", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
		int32_t dstStageMask = getEnumSetValue(
				env,
				enumSetObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSubpassDependencyClass, "getSrcAccessMask", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
		int32_t srcAccessMask = getEnumSetValue(
				env,
				enumSetObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAccessFlagBits");

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSubpassDependencyClass, "getDstAccessMask", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
		int32_t dstAccessMask = getEnumSetValue(
				env,
				enumSetObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAccessFlagBits");

		methodId = env->GetMethodID(vkSubpassDependencyClass, "getDependencyFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
		int32_t dependencyFlags = getEnumSetValue(
				env,
				enumSetObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkDependencyFlagBits");

		subpassDependency->srcSubpass = (uint32_t)srcSubpass;
		subpassDependency->dstSubpass = (uint32_t)dstSubpass;
		subpassDependency->srcStageMask = srcStageMask;
		subpassDependency->dstStageMask = dstStageMask;
		subpassDependency->srcAccessMask = srcAccessMask;
		subpassDependency->dstAccessMask = dstAccessMask;
		subpassDependency->dependencyFlags = dependencyFlags;
	}
}
