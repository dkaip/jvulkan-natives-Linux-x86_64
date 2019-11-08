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
 * populateVkMemoryFdPropertiesKHR.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkMemoryFdPropertiesKHR(
			JNIEnv *env,
			jobject jVkMemoryFdPropertiesKHRObject,
			const VkMemoryFdPropertiesKHR *vkMemoryFdPropertiesKHR)
	{
		if (jVkMemoryFdPropertiesKHRObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkMemoryFdPropertiesKHRObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkMemoryFdPropertiesKHRObject == nullptr");
			return;
		}

		if (vkMemoryFdPropertiesKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkMemoryFdPropertiesKHR == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkMemoryFdPropertiesKHR == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkMemoryFdPropertiesKHRObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkMemoryFdPropertiesKHR");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "setMemoryTypeBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMemoryTypeBits");
            return;
        }

        env->CallVoidMethod(jVkMemoryFdPropertiesKHRObject, methodId, vkMemoryFdPropertiesKHR->memoryTypeBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}