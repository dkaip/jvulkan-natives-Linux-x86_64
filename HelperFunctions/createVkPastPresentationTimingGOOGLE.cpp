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
 * createVkPastPresentationTimingGOOGLE.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkPastPresentationTimingGOOGLE(JNIEnv *env, const VkPastPresentationTimingGOOGLE *vkPastPresentationTimingGOOGLE)
	{
		if (vkPastPresentationTimingGOOGLE)
		{
			LOGERROR(env, "%s", "vkPastPresentationTimingGOOGLE == nullptr");
			return nullptr;
		}

		jclass vkPastPresentationTimingGOOGLEClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPastPresentationTimingGOOGLE");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPastPresentationTimingGOOGLE");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkPastPresentationTimingGOOGLEClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkPastPresentationTimingGOOGLEObject =
				env->NewObject(vkPastPresentationTimingGOOGLEClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPastPresentationTimingGOOGLEClass, "setPresentID", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPresentID");
            return nullptr;
        }

        env->CallVoidMethod(jVkPastPresentationTimingGOOGLEObject, methodId, vkPastPresentationTimingGOOGLE->presentMargin);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPastPresentationTimingGOOGLEClass, "setDesiredPresentTime", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDesiredPresentTime");
            return nullptr;
        }

        env->CallVoidMethod(jVkPastPresentationTimingGOOGLEObject, methodId, vkPastPresentationTimingGOOGLE->desiredPresentTime);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPastPresentationTimingGOOGLEClass, "setActualPresentTime", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setActualPresentTime");
            return nullptr;
        }

        env->CallVoidMethod(jVkPastPresentationTimingGOOGLEObject, methodId, vkPastPresentationTimingGOOGLE->actualPresentTime);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPastPresentationTimingGOOGLEClass, "setEarliestPresentTime", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setEarliestPresentTime");
            return nullptr;
        }

        env->CallVoidMethod(jVkPastPresentationTimingGOOGLEObject, methodId, vkPastPresentationTimingGOOGLE->earliestPresentTime);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPastPresentationTimingGOOGLEClass, "setPresentMargin", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPresentMargin");
            return nullptr;
        }

        env->CallVoidMethod(jVkPastPresentationTimingGOOGLEObject, methodId, vkPastPresentationTimingGOOGLE->presentMargin);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		return jVkPastPresentationTimingGOOGLEObject;
	}
}
