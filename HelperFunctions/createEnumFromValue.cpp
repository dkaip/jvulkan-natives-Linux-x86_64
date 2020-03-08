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
 * createEnumFromValue.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

namespace jvulkan
{
	jobject createEnumFromValue(JNIEnv *env, const char *enumClassString, jint value)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "Clearing an exception.");
			env->ExceptionClear();
		}

        int signatureLength = strlen(enumClassString) + 5 + 1;
        char *fromValueSignature = (char *)calloc(signatureLength, sizeof(char));
        fromValueSignature[0] = '(';
        fromValueSignature[1] = 'I';
        fromValueSignature[2] = ')';
        fromValueSignature[3] = 'L';
        strcat(&fromValueSignature[4], enumClassString);
        fromValueSignature[signatureLength-2] = ';';

		jclass vkResultClass = env->FindClass(enumClassString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "Could not find class %s.", enumClassString);
			free(fromValueSignature);
			return nullptr;
		}

		jmethodID methodId = env->GetStaticMethodID(vkResultClass, "fromValue", fromValueSignature);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "Could not find static method fromValue with signature %s", fromValueSignature);
			free(fromValueSignature);
			return nullptr;
		}

		free(fromValueSignature);

		return env->CallStaticObjectMethod(vkResultClass, methodId, value);
	}
}
