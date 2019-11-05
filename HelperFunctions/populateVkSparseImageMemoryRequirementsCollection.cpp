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
 * populateVkSparseImageMemoryRequirementsCollection.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkSparseImageMemoryRequirementsCollection(
			JNIEnv *env,
			jobject jVkSparseImageMemoryRequirementsCollectionObject,
			VkSparseImageMemoryRequirements const *vkSparseImageMemoryRequirements,
			int numberOfVkSparseImageMemoryRequirements)
	{
        jclass theClass = env->GetObjectClass(jVkSparseImageMemoryRequirementsCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for a Collecion of com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSparseImageMemoryRequirements");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(theClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return;
        }

        jclass vkSparseImageMemoryRequirementsClass = env->FindClass("Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSparseImageMemoryRequirements;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSparseImageMemoryRequirements");
            return;
        }

        jmethodID constructorMethodId = env->GetMethodID(vkSparseImageMemoryRequirementsClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            return;
        }

        for(int i = 0; i < numberOfVkSparseImageMemoryRequirements; i++)
        {
        	jobject jVkSparseImageMemoryRequirementsObject = createVkSparseImageMemoryRequirements(
        			env,
					&vkSparseImageMemoryRequirements[i]);

			jboolean addResult = env->CallBooleanMethod(jVkSparseImageMemoryRequirementsCollectionObject, addMethodId, jVkSparseImageMemoryRequirementsObject);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling CallBooleanMethod");
				return;
			}

			if (addResult == 0)
			{
				LOGERROR(env, "%s", "Failed trying to add jVkSparseImageMemoryRequirementsObject Object");
			}
        }
	}
}
