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
 * createVulkanHandleCollection.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVulkanHandleCollection(JNIEnv *env, const char *className, int handlesCount, const void **handles)
    {
    	jclass linkedListClass = env->FindClass("java/util/LinkedList");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class \"java/util/LinkedList\"");
            return nullptr;
        }

    	jmethodID linkedListConstructor = env->GetMethodID(linkedListClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find constructor for \"java/util/LinkedList\"");
            return nullptr;
        }

    	jobject jLinkedList = env->NewObject(linkedListClass, linkedListConstructor);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not create a Java LinkedList");
            return nullptr;
        }

        jmethodID addMethodId = env->GetMethodID(linkedListClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find add method for Java LinkedList class");
            return nullptr;
        }

    	for(int i = 0; i < handlesCount; i++)
    	{
    		jobject vulkanHandleObject =
    				createVulkanHandle(env, className, &handles[i]);

    		env->CallVoidMethod(jLinkedList, addMethodId, vulkanHandleObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Failed trying to add a VulkanHandle object to a Java LinkedList");
                return nullptr;
            }
    	}

    	return jLinkedList;
    }
}