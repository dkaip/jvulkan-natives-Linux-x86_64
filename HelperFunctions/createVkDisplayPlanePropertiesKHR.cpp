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

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlanePropertiesKHR",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
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

		jmethodID methodId = env->GetMethodID(theClass, "setCurrentDisplay", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCurrentDisplay");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkDisplayKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setCurrentStackIndex", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCurrentStackIndex");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkDisplayPlanePropertiesKHR->currentStackIndex);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
