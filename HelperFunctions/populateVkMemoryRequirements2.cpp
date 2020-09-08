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

        jclass vkMemoryRequirements2Class = env->GetObjectClass(jVkMemoryRequirements2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkMemoryRequirements2");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		jclass vkMemoryRequirementsClass = nullptr;
		jobject vkMemoryRequirementsObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkMemoryRequirements",
				&vkMemoryRequirementsClass,
				&vkMemoryRequirementsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor.");
            return;
        }

        populateVkMemoryRequirements(
        		env,
				vkMemoryRequirementsObject,
    			&vkMemoryRequirements2->memoryRequirements);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling populateVkMemoryRequirements");
            return;
        }

        jmethodID methodId =env->GetMethodID(vkMemoryRequirements2Class, "setMemoryRequirements", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkMemoryRequirements;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMemoryRequirements");
            return;
        }

        env->CallVoidMethod(jVkMemoryRequirements2Object, methodId, vkMemoryRequirementsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
    }
}
