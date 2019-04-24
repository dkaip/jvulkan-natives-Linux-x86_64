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
 * getEnumSetValue.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: dkaip
 */


#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"


using namespace std;

namespace jvulkan
{
	int32_t getEnumSetValue(
			JNIEnv *env,
			const jobject enumSetObject,
			const char *enumClassName)
	{
		jclass setClass = env->FindClass("java/util/Set");
		if (env->ExceptionOccurred())
		{
			cout << "Error finding EnumSet class ... returning" << endl;
			return -1;
		}

		jmethodID iteratorMethodId = env->GetMethodID(setClass, "iterator", "()Ljava/util/Iterator;");
		if (env->ExceptionOccurred())
		{
			return -1;
		}

		jobject iteratorObject = env->CallObjectMethod(enumSetObject, iteratorMethodId);
		if (env->ExceptionOccurred())
		{
			return -1;
		}

		jclass iteratorClass = env->GetObjectClass(iteratorObject);
		if (env->ExceptionOccurred())
		{
			return -1;
		}

		jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
		if (env->ExceptionOccurred())
		{
			return -1;
		}

		jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
		if (env->ExceptionOccurred())
		{
			return -1;
		}

		jclass enumClass = env->FindClass(enumClassName);
		if (env->ExceptionOccurred())
		{
			cout << "Error finding Enum class name " << enumClassName << " ... returning" << endl;
			return -1;
		}

		jmethodID valueOfMethod = env->GetMethodID(enumClass, "valueOf", "()I");
		if (env->ExceptionOccurred())
		{
			cout << "ERROR finding valueOf method with signature " << "()I" << endl;
			return -1;
		}

		int32_t result = 0;
		do
		{
			jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
			if (env->ExceptionOccurred())
			{
				result = -1;
				break;
			}

			if (hasNext == false)
			{
				break;
			}

			jobject enumObject = env->CallObjectMethod(iteratorObject, nextMethod);
			if (env->ExceptionOccurred())
			{
				result = -1;
				break;
			}

			jint value = env->CallIntMethod(enumObject, valueOfMethod);
			if (env->ExceptionOccurred())
			{
				result = -1;
				break;
			}

			result |= value;
		} while(true);

		return result;
	}
}



