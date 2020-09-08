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
		if (vkPerformanceCounterDescriptionKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkPerformanceCounterDescriptionKHR == nullptr");
			return nullptr;
		}

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPerformanceCounterDescriptionKHR",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
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

        jmethodID methodId = env->GetMethodID(theClass, "setFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFlags");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkPerformanceCounterDescriptionFlagsKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setName", "(Ljava/lang/String;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setName");
			return nullptr;
		}

		jstring objectNameString = env->NewStringUTF(vkPerformanceCounterDescriptionKHR->name);

		env->CallVoidMethod(theObject, methodId, objectNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setName");
			return nullptr;
		}

		env->DeleteLocalRef(objectNameString);

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setCategory", "(Ljava/lang/String;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setCategory");
			return nullptr;
		}

		objectNameString = env->NewStringUTF(vkPerformanceCounterDescriptionKHR->category);

		env->CallVoidMethod(theObject, methodId, objectNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setCategory");
			return nullptr;
		}

		env->DeleteLocalRef(objectNameString);

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setDescription", "(Ljava/lang/String;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setDescription");
			return nullptr;
		}

		objectNameString = env->NewStringUTF(vkPerformanceCounterDescriptionKHR->description);

		env->CallVoidMethod(theObject, methodId, objectNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setDescription");
			return nullptr;
		}

		env->DeleteLocalRef(objectNameString);


		return theObject;
	}
}
