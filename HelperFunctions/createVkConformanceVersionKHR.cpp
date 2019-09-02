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
 * createVkConformanceVersionKHR.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkConformanceVersionKHR(JNIEnv *env, const VkConformanceVersionKHR *vkConformanceVersionKHR)
	{
		// Locate the VkConformanceVersionKHR class
		jclass vkConformanceVersionKHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkConformanceVersionKHR");

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkConformanceVersionKHRClass, "<init>", "()V");

		// Create the Java vkDebugUtilsObjectNameInfoEXTObject object
		jobject jVkConformanceVersionKHRObject =
				env->NewObject(vkConformanceVersionKHRClass, methodId);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkConformanceVersionKHRClass, "setMajor", "(B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMajor");
            return nullptr;
        }

        env->CallVoidMethod(jVkConformanceVersionKHRObject, methodId, vkConformanceVersionKHR->major);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkConformanceVersionKHRClass, "setMinor", "(B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinor");
            return nullptr;
        }

        env->CallVoidMethod(jVkConformanceVersionKHRObject, methodId, vkConformanceVersionKHR->minor);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkConformanceVersionKHRClass, "setSubminor", "(B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubminor");
            return nullptr;
        }

        env->CallVoidMethod(jVkConformanceVersionKHRObject, methodId, vkConformanceVersionKHR->subminor);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkConformanceVersionKHRClass, "setPatch", "(B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPatch");
            return nullptr;
        }

        env->CallVoidMethod(jVkConformanceVersionKHRObject, methodId, vkConformanceVersionKHR->patch);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		return jVkConformanceVersionKHRObject;
	}
}
