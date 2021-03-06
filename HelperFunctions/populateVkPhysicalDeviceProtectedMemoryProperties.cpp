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
 * populateVkPhysicalDeviceProtectedMemoryProperties.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceProtectedMemoryProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceProtectedMemoryPropertiesObject,
			const VkPhysicalDeviceProtectedMemoryProperties *vkPhysicalDeviceProtectedMemoryProperties,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDeviceProtectedMemoryPropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceProtectedMemoryProperties");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setProtectedNoFault", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setProtectedNoFault");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceProtectedMemoryPropertiesObject, methodId, vkPhysicalDeviceProtectedMemoryProperties->protectedNoFault);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
