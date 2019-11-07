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
 * populateVkSparseImageFormatPropertiesCollection.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkSparseImageFormatPropertiesCollection(
			JNIEnv *env,
			jobject jVkSparseImageFormatPropertiesCollectionObject,
			VkSparseImageFormatProperties const *vkSparseImageFormatProperties,
			int numberOfVkSparseImageFormatProperties)
	{
        jclass theClass = env->GetObjectClass(jVkSparseImageFormatPropertiesCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for a Collecion of com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSparseImageFormatProperties");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(theClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return;
        }

        for(int i = 0; i < numberOfVkSparseImageFormatProperties; i++)
        {
        	jobject jVkSparseImageFormatPropertiesObject = createVkSparseImageFormatProperties(
        			env,
					&vkSparseImageFormatProperties[i]);

			jboolean addResult = env->CallBooleanMethod(jVkSparseImageFormatPropertiesCollectionObject, addMethodId, jVkSparseImageFormatPropertiesObject);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling CallBooleanMethod");
				return;
			}

			if (addResult == 0)
			{
				LOGERROR(env, "%s", "Failed trying to add jVkSparseImageFormatPropertiesCollectionObject Object");
			}
        }
	}
}
