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
 * createVkDisplayModeProperties2KHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkDisplayModeProperties2KHR(
			JNIEnv *env,
			VkDisplayModeProperties2KHR const *vkDisplayModeProperties2KHR)
	{
		if (vkDisplayModeProperties2KHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayModeProperties2KHR == nullptr");
			return nullptr;
		}

		jclass vkDisplayModeProperties2KHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeProperties2KHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeProperties2KHR");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkDisplayModeProperties2KHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkDisplayModeProperties2KHRObject =
				env->NewObject(vkDisplayModeProperties2KHRClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        jobject jVkDisplayModePropertiesKHRObject = createVkDisplayModePropertiesKHR(env, &vkDisplayModeProperties2KHR->displayModeProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkDisplayModePropertiesKHR");
            return nullptr;
        }

        methodId = env->GetMethodID(vkDisplayModeProperties2KHRClass, "setDisplayModeProperties", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModePropertiesKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDisplayModeProperties");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayModeProperties2KHRObject, methodId, jVkDisplayModePropertiesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkDisplayModeProperties2KHRObject;
	}
}
