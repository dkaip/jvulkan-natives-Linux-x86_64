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
 * createVkSparseImageMemoryRequirements2.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkSparseImageMemoryRequirements2(
			JNIEnv *env,
			VkSparseImageMemoryRequirements2 const *vkSparseImageMemoryRequirements2)
	{
		if (vkSparseImageMemoryRequirements2 == nullptr)
		{
			LOGERROR(env, "%s", "vkSparseImageMemoryRequirements2 == nullptr");
			return nullptr;
		}

		jclass vkSparseImageMemoryRequirements2Class = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements2");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements2");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkSparseImageMemoryRequirements2Class, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkSparseImageMemoryRequirements2Object =
				env->NewObject(vkSparseImageMemoryRequirements2Class, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        jobject jVkSparseImageMemoryRequirements = createVkSparseImageMemoryRequirements(
        		env,
				&vkSparseImageMemoryRequirements2->memoryRequirements);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSparseImageMemoryRequirements.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkSparseImageMemoryRequirements2Class, "setMemoryRequirements", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMemoryRequirements");
            return nullptr;
        }

        env->CallVoidMethod(jVkSparseImageMemoryRequirements2Object, methodId, jVkSparseImageMemoryRequirements);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkSparseImageMemoryRequirements2Object;
	}
}
