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
 * populateVkPhysicalDeviceDepthStencilResolveProperties.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceDepthStencilResolveProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceDepthStencilResolvePropertiesObject,
			const VkPhysicalDeviceDepthStencilResolveProperties* vkPhysicalDeviceDepthStencilResolveProperties,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceDepthStencilResolvePropertiesClass = env->GetObjectClass(
				jVkPhysicalDeviceDepthStencilResolvePropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceDepthStencilResolvePropertiesObject.");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceDepthStencilResolvePropertiesClass, "setSupportedDepthResolveModes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedDepthResolveModes");
            return;
        }

        jobject jSupportedDepthResolveModes = createVkResolveModeFlagsAsEnumSet(env, vkPhysicalDeviceDepthStencilResolveProperties->supportedDepthResolveModes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkResolveModeFlagsKHRAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDepthStencilResolvePropertiesObject, methodId, jSupportedDepthResolveModes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceDepthStencilResolvePropertiesClass, "setSupportedStencilResolveModes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedStencilResolveModes");
            return;
        }

        jobject jSupportedStencilResolveMode = createVkResolveModeFlagsAsEnumSet(env, vkPhysicalDeviceDepthStencilResolveProperties->supportedStencilResolveModes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkResolveModeFlagsKHRAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDepthStencilResolvePropertiesObject, methodId, jSupportedStencilResolveMode);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceDepthStencilResolvePropertiesClass, "setIndependentResolveNone", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setIndependentResolveNone");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDepthStencilResolvePropertiesObject, methodId, vkPhysicalDeviceDepthStencilResolveProperties->independentResolveNone);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceDepthStencilResolvePropertiesClass, "setIndependentResolve", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setIndependentResolve");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDepthStencilResolvePropertiesObject, methodId, vkPhysicalDeviceDepthStencilResolveProperties->independentResolve);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
