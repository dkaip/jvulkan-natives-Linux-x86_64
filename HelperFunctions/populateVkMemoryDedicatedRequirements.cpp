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
 * populateVkMemoryDedicatedRequirements.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkMemoryDedicatedRequirements(
			JNIEnv *env,
			jobject jVkMemoryDedicatedRequirementsObject,
			const VkMemoryDedicatedRequirements *vkMemoryDedicatedRequirements,
			std::vector<void *> *memoryToFree)
	{
		if (jVkMemoryDedicatedRequirementsObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkMemoryDedicatedRequirementsObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkMemoryDedicatedRequirementsObject == nullptr");
			return;
		}

		if (vkMemoryDedicatedRequirements == nullptr)
		{
			LOGERROR(env, "%s", "vkMemoryDedicatedRequirements == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkMemoryDedicatedRequirements == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkMemoryDedicatedRequirementsObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkMemoryDedicatedRequirements");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setPrefersDedicatedAllocation", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPrefersDedicatedAllocation");
            return;
        }

        env->CallVoidMethod(jVkMemoryDedicatedRequirementsObject, methodId, vkMemoryDedicatedRequirements->prefersDedicatedAllocation);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setRequiresDedicatedAllocation", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRequiresDedicatedAllocation");
            return;
        }

        env->CallVoidMethod(jVkMemoryDedicatedRequirementsObject, methodId, vkMemoryDedicatedRequirements->requiresDedicatedAllocation);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
