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
 * populateVkPhysicalDeviceMultiviewProperties.cpp
 *
 *  Created on: May 13, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceMultiviewProperties(
		JNIEnv *env,
		jobject jVkPhysicalDeviceMultiviewPropertiesObject,
		const VkPhysicalDeviceMultiviewProperties* vkPhysicalDeviceMultiviewProperties,
		std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceMultiviewPropertiesClass = env->GetObjectClass(
				jVkPhysicalDeviceMultiviewPropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceMultiviewProperties");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceMultiviewPropertiesClass, "setMaxMultiviewViewCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMultiviewViewCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMultiviewPropertiesObject, methodId, vkPhysicalDeviceMultiviewProperties->maxMultiviewViewCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceMultiviewPropertiesClass, "setMaxMultiviewInstanceIndex", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMultiviewInstanceIndex");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMultiviewPropertiesObject, methodId, vkPhysicalDeviceMultiviewProperties->maxMultiviewInstanceIndex);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
