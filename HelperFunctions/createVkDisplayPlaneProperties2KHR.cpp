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
 * createVkDisplayPlaneProperties2KHR.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkDisplayPlaneProperties2KHR(
			JNIEnv *env,
			VkDisplayPlaneProperties2KHR const *vkDisplayPlaneProperties2KHR)
	{
		if (vkDisplayPlaneProperties2KHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayPlaneProperties2KHR == nullptr");
			return nullptr;
		}

		jclass vkDisplayPlaneProperties2KHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlaneProperties2KHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlaneProperties2KHR");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkDisplayPlaneProperties2KHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkDisplayPlaneProperties2KHRObject =
				env->NewObject(vkDisplayPlaneProperties2KHRClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        jobject jVkDisplayPlanePropertiesKHRObject = createVkDisplayPlanePropertiesKHR(env, &vkDisplayPlaneProperties2KHR->displayPlaneProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkDisplayPlanePropertiesKHR");
            return nullptr;
        }

        methodId = env->GetMethodID(vkDisplayPlaneProperties2KHRClass, "setDisplayPlaneProperties", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlanePropertiesKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDisplayPlaneProperties");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayPlaneProperties2KHRObject, methodId, jVkDisplayPlanePropertiesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkDisplayPlaneProperties2KHRObject;
	}
}
