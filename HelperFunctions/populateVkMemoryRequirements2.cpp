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
 * populateVkMemoryRequirements2.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkMemoryRequirements2(
    		JNIEnv *env,
			jobject jVkMemoryRequirements2Object,
			const VkMemoryRequirements2 *vkMemoryRequirements2)
    {
		if (jVkMemoryRequirements2Object == nullptr)
		{
			LOGERROR(env, "%s", "jVkMemoryRequirements2Object == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkMemoryRequirements2Object == nullptr");
			return;
		}

		if (vkMemoryRequirements2 == nullptr)
		{
			LOGERROR(env, "%s", "vkMemoryRequirements2 == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkMemoryRequirements2 == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkMemoryRequirements2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkMemoryRequirements2");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jclass vkMemoryRequirementsClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkMemoryRequirements");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkMemoryRequirements");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init>");
            return;
        }

        jobject jVkMemoryRequirementsObject = env->NewObject(vkMemoryRequirementsClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could construct VkMemoryRequirements");
            return;
        }

        populateVkMemoryRequirements(
        		env,
				jVkMemoryRequirementsObject,
    			&vkMemoryRequirements2->memoryRequirements);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling populateVkMemoryRequirements");
            return;
        }

        methodId =env->GetMethodID(theClass, "setMemoryRequirements", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkMemoryRequirements;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMemoryRequirements");
            return;
        }

        env->CallVoidMethod(jVkMemoryRequirementsObject, methodId, jVkMemoryRequirementsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
    }
}
