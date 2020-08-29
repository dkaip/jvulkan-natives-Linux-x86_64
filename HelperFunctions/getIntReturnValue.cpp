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
 * getIntReturnValue.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

namespace jvulkan
{
    int getIntReturnValue(JNIEnv *env, jobject jIntReturnValueObject)
    {
    	if (jIntReturnValueObject == nullptr)
    	{
        	LOGERROR(env, "%s", "IntReturnValueObject must not be null.");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jIntReturnValue == nullptr");
			return -1;
    	}

        jclass handleClass = env->GetObjectClass(jIntReturnValueObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for IntReturnValue.");
            return -1;
        }

        jmethodID methodId = env->GetMethodID(handleClass, "getValue", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getValue.");
            return -1;
        }

        jint jIntReturnValue = 0;
        env->CallIntMethod(jIntReturnValueObject, methodId, &jIntReturnValue);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return -1;
        }

        return (int)jIntReturnValue;
    }
}
