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
 * populateVkPhysicalDeviceDepthStencilResolvePropertiesKHR.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceDepthStencilResolvePropertiesKHR(
			JNIEnv *env,
			jobject jVkPhysicalDeviceDepthStencilResolvePropertiesKHRObject,
			const VkPhysicalDeviceDepthStencilResolvePropertiesKHR* vkPhysicalDeviceDepthStencilResolvePropertiesKHR,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceDepthStencilResolvePropertiesKHRClass = env->GetObjectClass(
				jVkPhysicalDeviceDepthStencilResolvePropertiesKHRObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceDepthStencilResolvePropertiesKHR");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceDepthStencilResolvePropertiesKHRClass, "setSupportedDepthResolveModes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedDepthResolveModes");
            return;
        }

        jobject jSupportedDepthResolveModes = createVkResolveModeFlagsKHRAsEnumSet(env, vkPhysicalDeviceDepthStencilResolvePropertiesKHR->supportedDepthResolveModes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkResolveModeFlagsKHRAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDepthStencilResolvePropertiesKHRObject, methodId, jSupportedDepthResolveModes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceDepthStencilResolvePropertiesKHRClass, "setSupportedStencilResolveModes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedStencilResolveModes");
            return;
        }

        jobject jSupportedStencilResolveMode = createVkResolveModeFlagsKHRAsEnumSet(env, vkPhysicalDeviceDepthStencilResolvePropertiesKHR->supportedStencilResolveModes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkResolveModeFlagsKHRAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDepthStencilResolvePropertiesKHRObject, methodId, jSupportedStencilResolveMode);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceDepthStencilResolvePropertiesKHRClass, "setIndependentResolveNone", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setIndependentResolveNone");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDepthStencilResolvePropertiesKHRObject, methodId, vkPhysicalDeviceDepthStencilResolvePropertiesKHR->independentResolveNone);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceDepthStencilResolvePropertiesKHRClass, "setIndependentResolve", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setIndependentResolve");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDepthStencilResolvePropertiesKHRObject, methodId, vkPhysicalDeviceDepthStencilResolvePropertiesKHR->independentResolve);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
