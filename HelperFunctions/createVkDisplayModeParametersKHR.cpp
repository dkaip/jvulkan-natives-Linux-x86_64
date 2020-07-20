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
 * createVkDisplayModeParametersKHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkDisplayModeParametersKHR(
			JNIEnv *env,
			VkDisplayModeParametersKHR const *vkDisplayModeParametersKHR)
	{
		if (vkDisplayModeParametersKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayModeParametersKHR == nullptr");
			return nullptr;
		}

		jclass vkDisplayModeParametersKHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeParametersKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeParametersKHR");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkDisplayModeParametersKHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkDisplayModeParametersKHRObject =
				env->NewObject(vkDisplayModeParametersKHRClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        jobject jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayModeParametersKHR->visibleRegion);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return nullptr;
        }

		methodId = env->GetMethodID(vkDisplayModeParametersKHRClass, "setVisibleRegion", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setVisibleRegion");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayModeParametersKHRObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(vkDisplayModeParametersKHRClass, "setRefreshRate", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRefreshRate");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayModeParametersKHRObject, methodId, vkDisplayModeParametersKHR->refreshRate);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkDisplayModeParametersKHRObject;
	}
}
