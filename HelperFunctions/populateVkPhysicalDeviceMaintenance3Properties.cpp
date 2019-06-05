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
 * populateVkPhysicalDeviceMaintenance3Properties.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceMaintenance3Properties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceMaintenance3PropertiesObject,
			const VkPhysicalDeviceMaintenance3Properties *vkPhysicalDeviceMaintenance3Properties,
			std::vector<void *> *memoryToFree)
	{
		if (jVkPhysicalDeviceMaintenance3PropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkPhysicalDeviceMaintenance3PropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceMaintenance3PropertiesObject == nullptr");
			return;
		}

		if (vkPhysicalDeviceMaintenance3Properties == nullptr)
		{
			LOGERROR(env, "%s", "vkPhysicalDeviceMaintenance3Properties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceMaintenance3Properties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceMaintenance3PropertiesClass = env->GetObjectClass(
				jVkPhysicalDeviceMaintenance3PropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceMaintenance3Properties");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceMaintenance3PropertiesClass, "setMaxPerSetDescriptors", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerSetDescriptors");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMaintenance3PropertiesObject, methodId, vkPhysicalDeviceMaintenance3Properties->maxPerSetDescriptors);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceMaintenance3PropertiesClass, "setMaxMemoryAllocationSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMemoryAllocationSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMaintenance3PropertiesObject, methodId, vkPhysicalDeviceMaintenance3Properties->maxMemoryAllocationSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}
