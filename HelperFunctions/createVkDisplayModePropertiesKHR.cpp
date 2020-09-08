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

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModePropertiesKHR",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
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

		jmethodID methodId = env->GetMethodID(theClass, "setDisplayMode", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayModeKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDisplayMode");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkDisplayModeKHR);
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

		methodId = env->GetMethodID(theClass, "setParameters", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeParametersKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setParameters");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkDisplayModeParametersKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
