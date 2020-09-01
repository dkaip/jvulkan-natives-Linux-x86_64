/*
 * Copyright 2020 Douglas Kaip
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
 * populateVkCheckpointDataNVCollection.cpp
 *
 *  Created on: Sep 1, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkCheckpointDataNVCollection(
			JNIEnv *env,
			jobject jVkCheckpointDataNVCollectionObject,
			VkCheckpointDataNV const *vkCheckpointDataNVs,
			int numberOfVkCheckpointDataNVs)
	{
        jclass theClass = env->GetObjectClass(jVkCheckpointDataNVCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for a Collecion of com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkCheckpointDataNV");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(theClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return;
        }

        for(int i = 0; i < numberOfVkCheckpointDataNVs; i++)
        {
            jobject jVkCheckpointDataNVObject = createVkCheckpointDataNV(
        			env,
        			&vkCheckpointDataNVs[i]);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "Error calling createVkCheckpointDataNV for object %d.", i);
				return;
			}

			jboolean addResult = env->CallBooleanMethod(jVkCheckpointDataNVCollectionObject, addMethodId, jVkCheckpointDataNVObject);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling CallBooleanMethod");
				return;
			}

			if (addResult == 0)
			{
				LOGERROR(env, "%s", "Failed trying to add jVkCheckpointDataNVCollectionObject Object");
			}
        }
	}
}
