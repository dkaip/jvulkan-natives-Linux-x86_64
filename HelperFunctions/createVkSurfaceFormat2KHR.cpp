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
 * createVkSurfaceFormat2KHR.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkSurfaceFormat2KHR(
			JNIEnv *env,
			VkSurfaceFormat2KHR const *vkSurfaceFormat2KHR)
	{
		if (vkSurfaceFormat2KHR == nullptr)
		{
			LOGERROR(env, "%s", "vkSurfaceFormat2KHR == nullptr");
			return nullptr;
		}

		jclass vkSurfaceFormat2KHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkSurfaceFormat2KHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkSurfaceFormat2KHR");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkSurfaceFormat2KHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkSurfaceFormat2KHRObject =
				env->NewObject(vkSurfaceFormat2KHRClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        jobject jVkSurfaceFormatKHRObject = createVkSurfaceFormatKHR(env, &vkSurfaceFormat2KHR->surfaceFormat);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkDisplayPlanePropertiesKHR");
            return nullptr;
        }

        methodId = env->GetMethodID(vkSurfaceFormat2KHRClass, "setSurfaceFormat", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkSurfaceFormatKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSurfaceFormat");
            return nullptr;
        }

        env->CallVoidMethod(jVkSurfaceFormat2KHRObject, methodId, jVkSurfaceFormatKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkSurfaceFormat2KHRObject;
	}
}
