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
 * populateVkSparseImageMemoryRequirements2Collection.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkSparseImageMemoryRequirements2Collection(
			JNIEnv *env,
			jobject jVkSparseImageMemoryRequirements2CollectionObject,
			VkSparseImageMemoryRequirements2 const *VkSparseImageMemoryRequirements2s,
			int numberOfVkSparseImageMemoryRequirements2s)
	{
        jclass theClass = env->GetObjectClass(jVkSparseImageMemoryRequirements2CollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for a Collecion of com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements2");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(theClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return;
        }

        jclass vkSparseImageMemoryRequirements2Class = env->FindClass("Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements2;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements2");
            return;
        }

        jmethodID constructorMethodId = env->GetMethodID(vkSparseImageMemoryRequirements2Class, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            return;
        }

        for(int i = 0; i < numberOfVkSparseImageMemoryRequirements2s; i++)
        {
        	jobject jVkSparseImageMemoryRequirements2Object = createVkSparseImageMemoryRequirements2(
        			env,
					&VkSparseImageMemoryRequirements2s[i]);

			jboolean addResult = env->CallBooleanMethod(jVkSparseImageMemoryRequirements2CollectionObject, addMethodId, jVkSparseImageMemoryRequirements2Object);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling CallBooleanMethod");
				return;
			}

			if (addResult == 0)
			{
				LOGERROR(env, "%s", "Failed trying to add jVkSparseImageMemoryRequirements2CollectionObject Object");
			}
        }
	}
}
