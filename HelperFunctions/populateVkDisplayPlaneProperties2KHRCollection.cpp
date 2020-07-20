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
 * populateVkDisplayPlaneProperties2KHRCollection.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkDisplayPlaneProperties2KHRCollection(
			JNIEnv *env,
			jobject jVkDisplayPlaneProperties2KHRCollectionObject,
			VkDisplayPlaneProperties2KHR const *vkDisplayPlaneProperties2KHRs,
			int numberOfVkDisplayPlaneProperties2KHRs)
	{
        jclass theClass = env->GetObjectClass(jVkDisplayPlaneProperties2KHRCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for a Collecion of com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlaneProperties2KHR");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(theClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return;
        }

        for(int i = 0; i < numberOfVkDisplayPlaneProperties2KHRs; i++)
        {
            jobject jVkDisplayPlaneProperties2KHRObject = createVkDisplayPlaneProperties2KHR(
        			env,
        			&vkDisplayPlaneProperties2KHRs[i]);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "Error calling createVkDisplayPlaneProperties2KHR for object %d.", i);
				return;
			}

			jboolean addResult = env->CallBooleanMethod(jVkDisplayPlaneProperties2KHRCollectionObject, addMethodId, jVkDisplayPlaneProperties2KHRObject);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling CallBooleanMethod");
				return;
			}

			if (addResult == 0)
			{
				LOGERROR(env, "%s", "Failed trying to add jVkDisplayPlaneProperties2KHRObject Object");
			}
        }
	}
}
