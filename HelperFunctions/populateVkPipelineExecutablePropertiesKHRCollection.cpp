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
 * populateVkPipelineExecutablePropertiesKHRCollection.cpp
 *
 *  Created on: Sep 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkPipelineExecutablePropertiesKHRCollection(
			JNIEnv *env,
			jobject jVkPipelineExecutablePropertiesKHRCollectionObject,
			VkPipelineExecutablePropertiesKHR const *vkPipelineExecutablePropertiesKHR,
			int numberOfVkPipelineExecutablePropertiesKHR)
	{
        jclass theClass = env->GetObjectClass(jVkPipelineExecutablePropertiesKHRCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for a Collecion of com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineExecutablePropertiesKHR");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(theClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return;
        }

        jclass vkPipelineExecutablePropertiesKHRClass = env->FindClass("Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineExecutablePropertiesKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineExecutablePropertiesKHR");
            return;
        }

        jmethodID constructorMethodId = env->GetMethodID(vkPipelineExecutablePropertiesKHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            return;
        }

        for(int i = 0; i < numberOfVkPipelineExecutablePropertiesKHR; i++)
        {
        	jobject jVkPipelineExecutablePropertiesKHRObject = env->NewObject(
        			vkPipelineExecutablePropertiesKHRClass,
					constructorMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling constructor for VkPipelineExecutablePropertiesKHR object.");
                return;
            }


        	jvulkan::populateVkPipelineExecutablePropertiesKHR(
        			env,
        			jVkPipelineExecutablePropertiesKHRObject,
        			&vkPipelineExecutablePropertiesKHR[i]);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "Error calling populateVkPipelineExecutablePropertiesKHR for object %d.", i);
				return;
			}

			jboolean addResult = env->CallBooleanMethod(jVkPipelineExecutablePropertiesKHRCollectionObject, addMethodId, jVkPipelineExecutablePropertiesKHRObject);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling CallBooleanMethod");
				return;
			}

			if (addResult == 0)
			{
				LOGERROR(env, "%s", "Failed trying to add jVkPipelineExecutablePropertiesKHRObject Object");
			}
        }
	}
}
