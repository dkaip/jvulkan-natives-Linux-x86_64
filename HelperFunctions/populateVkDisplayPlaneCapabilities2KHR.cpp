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
 * populateVkDisplayPlaneCapabilities2KHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkDisplayPlaneCapabilities2KHR(
    		JNIEnv *env,
			jobject jVkDisplayPlaneCapabilities2KHRObject,
			const VkDisplayPlaneCapabilities2KHR *vkDisplayPlaneCapabilities2KHR)
    {
		if (jVkDisplayPlaneCapabilities2KHRObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkDisplayPlaneCapabilities2KHRObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkDisplayPlaneCapabilities2KHRObject == nullptr");
			return;
		}

		if (vkDisplayPlaneCapabilities2KHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayPlaneCapabilities2KHR == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkDisplayPlaneCapabilities2KHR == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkDisplayPlaneCapabilities2KHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlaneCapabilities2KHR");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject jVkDisplayPlaneCapabilitiesKHRObject = createVkDisplayPlaneCapabilitiesKHR(
        		env,
				&vkDisplayPlaneCapabilities2KHR->capabilities);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkDisplayPlaneCapabilitiesKHR.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setCapabilities", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlaneCapabilitiesKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCapabilities");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilities2KHRObject, methodId, jVkDisplayPlaneCapabilitiesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
    }
}
