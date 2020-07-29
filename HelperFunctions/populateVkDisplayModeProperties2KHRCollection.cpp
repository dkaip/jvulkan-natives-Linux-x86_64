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
 * populateVkDisplayModeProperties2KHRCollection.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkDisplayModeProperties2KHRCollection(
			JNIEnv *env,
			jobject jVkDisplayModeProperties2KHRCollectionObject,
			VkDisplayModeProperties2KHR const *vkDisplayModeProperties2KHRs,
			int numberOfVkDisplayModeProperties2KHRs)
	{
        jclass theClass = env->GetObjectClass(jVkDisplayModeProperties2KHRCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for a Collecion of com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeProperties2KHR");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(theClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return;
        }

        jclass vkDisplayModeProperties2KHRClass = env->FindClass("Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeProperties2KHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeProperties2KHR");
            return;
        }

        jmethodID constructorMethodId = env->GetMethodID(vkDisplayModeProperties2KHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            return;
        }

        for(int i = 0; i < numberOfVkDisplayModeProperties2KHRs; i++)
        {
            jobject jVkDisplayModeProperties2KHRObject = createVkDisplayModeProperties2KHR(
        			env,
        			&vkDisplayModeProperties2KHRs[i]);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "Error calling createVkDisplayModeProperties2KHR for object %d.", i);
				return;
			}

			jboolean addResult = env->CallBooleanMethod(jVkDisplayModeProperties2KHRCollectionObject, addMethodId, jVkDisplayModeProperties2KHRObject);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling CallBooleanMethod");
				return;
			}

			if (addResult == 0)
			{
				LOGERROR(env, "%s", "Failed trying to add jVkDisplayModeProperties2KHRObject Object");
			}
        }
	}
}
