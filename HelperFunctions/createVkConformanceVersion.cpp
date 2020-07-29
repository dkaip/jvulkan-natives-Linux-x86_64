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
 * createVkConformanceVersion.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkConformanceVersion(JNIEnv *env, const VkConformanceVersion *vkConformanceVersion)
	{
		// Locate the VkConformanceVersion class
		jclass vkConformanceVersionClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkConformanceVersion");

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkConformanceVersionClass, "<init>", "()V");

		// Create the Java jVkConformanceVersionObject object
		jobject jVkConformanceVersionObject =
				env->NewObject(vkConformanceVersionClass, methodId);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkConformanceVersionClass, "setMajor", "(B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMajor");
            return nullptr;
        }

        env->CallVoidMethod(jVkConformanceVersionObject, methodId, vkConformanceVersion->major);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkConformanceVersionClass, "setMinor", "(B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinor");
            return nullptr;
        }

        env->CallVoidMethod(jVkConformanceVersionObject, methodId, vkConformanceVersion->minor);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkConformanceVersionClass, "setSubminor", "(B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubminor");
            return nullptr;
        }

        env->CallVoidMethod(jVkConformanceVersionObject, methodId, vkConformanceVersion->subminor);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkConformanceVersionClass, "setPatch", "(B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPatch");
            return nullptr;
        }

        env->CallVoidMethod(jVkConformanceVersionObject, methodId, vkConformanceVersion->patch);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		return jVkConformanceVersionObject;
	}
}
