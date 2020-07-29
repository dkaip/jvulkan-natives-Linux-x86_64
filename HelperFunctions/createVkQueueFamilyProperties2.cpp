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
 * createVkQueueFamilyProperties2.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkQueueFamilyProperties2(
			JNIEnv *env,
			VkQueueFamilyProperties2 const *vkQueueFamilyProperties2)
	{
		if (vkQueueFamilyProperties2 == nullptr)
		{
			LOGERROR(env, "%s", "vkQueueFamilyProperties2 == nullptr");
			return nullptr;
		}

		jclass vkQueueFamilyProperties2Class = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkQueueFamilyProperties2");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkQueueFamilyProperties2");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkQueueFamilyProperties2Class, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkQueueFamilyProperties2Object =
				env->NewObject(vkQueueFamilyProperties2Class, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        jobject jVkQueueFamilyProperties = createVkQueueFamilyProperties(
        		env,
				&vkQueueFamilyProperties2->queueFamilyProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkQueueFamilyProperties.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkQueueFamilyProperties2Class, "setQueueFamilyProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkQueueFamilyProperties;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setQueueFamilyProperties");
            return nullptr;
        }

        env->CallVoidMethod(jVkQueueFamilyProperties2Object, methodId, jVkQueueFamilyProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkQueueFamilyProperties2Object;
	}
}
