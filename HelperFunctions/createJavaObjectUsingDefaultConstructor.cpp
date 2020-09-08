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
 * createJavaObjectUsingDefaultConstructor.cpp
 *
 *  Created on: Sep 7, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void createJavaObjectUsingDefaultConstructor(
    		JNIEnv *env,
			const char *className,
			jclass *theClass,
			jobject *newJavaObject)
    {
    	if (className == nullptr)
    	{
        	LOGERROR(env, "%s.", "className argument must not be nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "className argument must not be nullptr");
    	}

    	if (theClass == nullptr)
    	{
        	LOGERROR(env, "%s.", "theClass argument must not be nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "theClass argument must not be nullptr");
    	}

    	if (newJavaObject == nullptr)
    	{
        	LOGERROR(env, "%s.", "newJavaObject argument must not be nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "newJavaObject argument must not be nullptr");
    	}

		*theClass = env->FindClass(className);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "Could not find class %s.", className);
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(*theClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
        }

		*newJavaObject = env->NewObject(*theClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
        }

        if (*newJavaObject == nullptr)
        {
        	LOGERROR(env, "New object for class %s did not seem to be created.", className);
        }
    }
}
