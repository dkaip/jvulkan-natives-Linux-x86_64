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
 * createVkDisplayPlanePropertiesKHR.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkDisplayPlanePropertiesKHR(
			JNIEnv *env,
			VkDisplayPlanePropertiesKHR const *vkDisplayPlanePropertiesKHR)
	{
		if (vkDisplayPlanePropertiesKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayPlanePropertiesKHR == nullptr");
			return nullptr;
		}

		jclass vkDisplayPlanePropertiesKHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlanePropertiesKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlanePropertiesKHR");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkDisplayPlanePropertiesKHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkDisplayPlanePropertiesKHRObject =
				env->NewObject(vkDisplayPlanePropertiesKHRClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jVkDisplayKHR = createVulkanHandle(
        		env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayKHR",
				vkDisplayPlanePropertiesKHR->currentDisplay);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle");
            return nullptr;
        }

		methodId = env->GetMethodID(vkDisplayPlanePropertiesKHRClass, "setCurrentDisplay", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCurrentDisplay");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayPlanePropertiesKHRObject, methodId, jVkDisplayKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkDisplayPlanePropertiesKHRClass, "setCurrentStackIndex", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCurrentStackIndex");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayPlanePropertiesKHRObject, methodId, vkDisplayPlanePropertiesKHR->currentStackIndex);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkDisplayPlanePropertiesKHRObject;
	}
}
