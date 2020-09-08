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
 * populateVkMemoryRequirements.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkMemoryRequirements(
			JNIEnv *env,
			jobject jVkMemoryRequirementsObject,
			const VkMemoryRequirements *vkMemoryRequirements)
	{
		if (jVkMemoryRequirementsObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkMemoryRequirementsObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkMemoryRequirementsObject == nullptr");
			return;
		}

		if (vkMemoryRequirements == nullptr)
		{
			LOGERROR(env, "%s", "vkMemoryRequirements == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkMemoryRequirements == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkMemoryRequirementsObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/jVkMemoryRequirementsObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSize");
            return;
        }

        env->CallVoidMethod(jVkMemoryRequirementsObject, methodId, vkMemoryRequirements->size);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setAlignment");
            return;
        }

        env->CallVoidMethod(jVkMemoryRequirementsObject, methodId, vkMemoryRequirements->alignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ////////////////////////////////////////////////////////////////////////////
        jclass bitSetClass = env->FindClass("java/util/BitSet");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for java/util/BitSet.");
            return;
        }

        methodId = env->GetMethodID(bitSetClass, "<init>", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init>");
            return;
        }

        jobject bitSetObject = env->NewObject(bitSetClass, methodId, 32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling NewObject.");
            return;
        }

        methodId = env->GetMethodID(bitSetClass, "set", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id set");
            return;
        }

        for (uint32_t i = 0; i < 32; i++)
        {
            if ((1 << i) & vkMemoryRequirements->memoryTypeBits)
            {
                env->CallVoidMethod(bitSetObject, methodId, i);
                if (env->ExceptionOccurred())
                {
                	LOGERROR(env, "%s", "Error calling CallVoidMethod.");
                    return;
                }
            }
        }

        methodId = env->GetMethodID(theClass, "setMemoryTypeBits", "(Ljava/util/BitSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMemoryTypeBits");
            return;
        }

        env->CallVoidMethod(jVkMemoryRequirementsObject, methodId, bitSetObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallVoidMethod.");
            return;
        }
	}
}
