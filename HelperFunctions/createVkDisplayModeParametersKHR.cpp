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

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeParametersKHR",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
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

		jmethodID methodId = env->GetMethodID(theClass, "setVisibleRegion", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setVisibleRegion");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setRefreshRate", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRefreshRate");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkDisplayModeParametersKHR->refreshRate);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
