/*
 * Copyright 2020 Douglas Kaip
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
 * createVkPerformanceCounterDescriptionKHR.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkPerformanceCounterDescriptionKHR(JNIEnv *env, const VkPerformanceCounterDescriptionKHR *vkPerformanceCounterDescriptionKHR)
	{
		if (vkPerformanceCounterDescriptionKHR)
		{
			LOGERROR(env, "%s", "vkPerformanceCounterDescriptionKHR == nullptr");
			return nullptr;
		}

		jclass vkPerformanceCounterDescriptionKHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPerformanceCounterDescriptionKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPerformanceCounterDescriptionKHR");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkPerformanceCounterDescriptionKHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> (II)V");
            return nullptr;
        }

		jobject jVkPerformanceCounterDescriptionKHRObject =
				env->NewObject(vkPerformanceCounterDescriptionKHRClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject jVkPerformanceCounterDescriptionFlagsKHR = createVkPerformanceCounterDescriptionFlagsKHRAsEnumSet(
        		env,
				vkPerformanceCounterDescriptionKHR->flags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkPerformanceCounterDescriptionFlagsKHRAsEnumSet.");
            return nullptr;
        }

        methodId = env->GetMethodID(vkPerformanceCounterDescriptionKHRClass, "setFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFlags");
            return nullptr;
        }

        env->CallVoidMethod(jVkPerformanceCounterDescriptionKHRObject, methodId, jVkPerformanceCounterDescriptionFlagsKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPerformanceCounterDescriptionKHRClass, "setName", "(Ljava/lang/String;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setName");
			return nullptr;
		}

		jstring objectNameString = env->NewStringUTF(vkPerformanceCounterDescriptionKHR->name);

		env->CallVoidMethod(jVkPerformanceCounterDescriptionKHRObject, methodId, objectNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setName");
			return nullptr;
		}

		env->DeleteLocalRef(objectNameString);

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPerformanceCounterDescriptionKHRClass, "setCategory", "(Ljava/lang/String;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setCategory");
			return nullptr;
		}

		objectNameString = env->NewStringUTF(vkPerformanceCounterDescriptionKHR->category);

		env->CallVoidMethod(jVkPerformanceCounterDescriptionKHRObject, methodId, objectNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setCategory");
			return nullptr;
		}

		env->DeleteLocalRef(objectNameString);

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPerformanceCounterDescriptionKHRClass, "setDescription", "(Ljava/lang/String;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setDescription");
			return nullptr;
		}

		objectNameString = env->NewStringUTF(vkPerformanceCounterDescriptionKHR->description);

		env->CallVoidMethod(jVkPerformanceCounterDescriptionKHRObject, methodId, objectNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setDescription");
			return nullptr;
		}

		env->DeleteLocalRef(objectNameString);


		return jVkPerformanceCounterDescriptionKHRObject;
	}
}
