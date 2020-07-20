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
 * createVkDisplayModePropertiesKHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkDisplayModePropertiesKHR(
			JNIEnv *env,
			VkDisplayModePropertiesKHR const *vkDisplayModePropertiesKHR)
	{
		if (vkDisplayModePropertiesKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayModePropertiesKHR == nullptr");
			return nullptr;
		}

		jclass vkDisplayModePropertiesKHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModePropertiesKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModePropertiesKHR");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkDisplayModePropertiesKHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkDisplayModePropertiesKHRObject =
				env->NewObject(vkDisplayModePropertiesKHRClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        jobject jVkDisplayModeKHR = createVulkanHandle(
        		env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayModeKHR",
				vkDisplayModePropertiesKHR->displayMode);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle");
            return nullptr;
        }

		methodId = env->GetMethodID(vkDisplayModePropertiesKHRClass, "setDisplayMode", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayModeKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDisplayMode");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayModePropertiesKHRObject, methodId, jVkDisplayModeKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        jobject jVkDisplayModeParametersKHR = createVkDisplayModeParametersKHR(
        		env,
				&vkDisplayModePropertiesKHR->parameters);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkDisplayModeParametersKHR");
            return nullptr;
        }

		methodId = env->GetMethodID(vkDisplayModePropertiesKHRClass, "setParameters", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeParametersKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setParameters");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayModePropertiesKHRObject, methodId, jVkDisplayModeParametersKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkDisplayModePropertiesKHRObject;
	}
}
