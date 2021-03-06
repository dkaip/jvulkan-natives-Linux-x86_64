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
 * createVkDisplayProperties2KHR.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkDisplayProperties2KHR(
			JNIEnv *env,
			VkDisplayProperties2KHR const *vkDisplayProperties2KHR)
	{
		if (vkDisplayProperties2KHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayProperties2KHR == nullptr");
			return nullptr;
		}

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayProperties2KHR",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        jobject jVkDisplayPropertiesKHRObject = createVkDisplayPropertiesKHR(env, &vkDisplayProperties2KHR->displayProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkDisplayPropertiesKHR");
            return nullptr;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setDisplayProperties", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPropertiesKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDisplayProperties");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkDisplayPropertiesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
