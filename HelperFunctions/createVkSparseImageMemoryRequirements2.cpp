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
 * createVkSparseImageMemoryRequirements2.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkSparseImageMemoryRequirements2(
			JNIEnv *env,
			VkSparseImageMemoryRequirements2 const *vkSparseImageMemoryRequirements2)
	{
		if (vkSparseImageMemoryRequirements2 == nullptr)
		{
			LOGERROR(env, "%s", "vkSparseImageMemoryRequirements2 == nullptr");
			return nullptr;
		}

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements2",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        jobject jVkSparseImageMemoryRequirements = createVkSparseImageMemoryRequirements(
        		env,
				&vkSparseImageMemoryRequirements2->memoryRequirements);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSparseImageMemoryRequirements.");
            return nullptr;
        }

		jmethodID methodId = env->GetMethodID(theClass, "setMemoryRequirements", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMemoryRequirements");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkSparseImageMemoryRequirements);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
