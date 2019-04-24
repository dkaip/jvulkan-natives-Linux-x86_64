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
 * createVulkanHandle.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: Douglas Kaip
 */

//#include <cstring>
//#include <iostream>
#include <stdlib.h>

#include "../headers/slf4j.hh"
#include "HelperFunctions.hh"

using namespace std;

namespace jvulkan
{
    jobject createVulkanHandle(JNIEnv *env, const char *className, void *value)
    {
        jclass handleClass = env->FindClass(className);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "Could not find class \"%s\"", className);
            return nullptr;
        }

        jmethodID methodId = env->GetMethodID(handleClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "Could not find constructor for class \"%s\"", className);
            return nullptr;
        }

        jobject handleObject = env->NewObject(handleClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "Failed to create object for class \"%s\"", className);
            return nullptr;
        }

        setHandleValue(env, handleObject, value);

        return handleObject;
    }
}
