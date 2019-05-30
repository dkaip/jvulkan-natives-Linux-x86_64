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
 * populateVkSharedPresentSurfaceCapabilitiesKHR.cpp
 *
 *  Created on: May 29, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkSharedPresentSurfaceCapabilitiesKHR(
			JNIEnv *env,
			jobject jVkSharedPresentSurfaceCapabilitiesKHRObject,
			const VkSharedPresentSurfaceCapabilitiesKHR *vkSharedPresentSurfaceCapabilitiesKHR,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkSharedPresentSurfaceCapabilitiesKHRObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkSharedPresentSurfaceCapabilitiesKHR");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setSharedPresentSupportedUsageFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSharedPresentSupportedUsageFlags");
            return;
        }

        jobject sharedPresentSupportedUsageFlags = getVkImageUsageFlagsAsEnumSet(env, vkSharedPresentSurfaceCapabilitiesKHR->sharedPresentSupportedUsageFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageUsageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSharedPresentSurfaceCapabilitiesKHRObject, methodId, sharedPresentSupportedUsageFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
