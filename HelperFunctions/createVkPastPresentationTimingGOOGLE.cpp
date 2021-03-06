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

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPastPresentationTimingGOOGLE",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "setPresentID", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPresentID");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkPastPresentationTimingGOOGLE->presentMargin);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setDesiredPresentTime", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDesiredPresentTime");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkPastPresentationTimingGOOGLE->desiredPresentTime);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setActualPresentTime", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setActualPresentTime");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkPastPresentationTimingGOOGLE->actualPresentTime);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setEarliestPresentTime", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setEarliestPresentTime");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkPastPresentationTimingGOOGLE->earliestPresentTime);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setPresentMargin", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPresentMargin");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkPastPresentationTimingGOOGLE->presentMargin);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		return theObject;
	}
}
