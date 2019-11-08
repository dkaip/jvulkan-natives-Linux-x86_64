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
 * populateVkQueueFamilyCheckpointPropertiesNV.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkQueueFamilyCheckpointPropertiesNV(
			JNIEnv *env,
			jobject jVkQueueFamilyCheckpointPropertiesNVObject,
			const VkQueueFamilyCheckpointPropertiesNV *vkQueueFamilyCheckpointPropertiesNV)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkQueueFamilyCheckpointPropertiesNVObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkQueueFamilyCheckpointPropertiesNV");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setCheckpointExecutionStageMask", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCheckpointExecutionStageMask");
            return;
        }

        jobject jflags = createVkPipelineStageFlagsAsEnumSet(env, vkQueueFamilyCheckpointPropertiesNV->checkpointExecutionStageMask);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkPipelineStageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkQueueFamilyCheckpointPropertiesNVObject, methodId, jflags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}