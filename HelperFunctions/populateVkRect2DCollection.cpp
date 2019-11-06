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
 * populateVkRect2DCollection.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkRect2DCollection(
			JNIEnv *env,
			jobject jVkRect2DCollectionObject,
			VkRect2D const *VkRect2Ds,
			int numberOfVkRect2Ds)
	{
        jclass theClass = env->GetObjectClass(jVkRect2DCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for a Collecion of com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkRect2D");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(theClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return;
        }

        for(int i = 0; i < numberOfVkRect2Ds; i++)
        {
        	jobject jVkRect2DObject = createVkRect2D(
        			env,
					&VkRect2Ds[i]);

			jboolean addResult = env->CallBooleanMethod(jVkRect2DCollectionObject, addMethodId, jVkRect2DObject);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling CallBooleanMethod");
				return;
			}

			if (addResult == 0)
			{
				LOGERROR(env, "%s", "Failed trying to add jVkRect2DObject Object");
			}
        }
	}
}
