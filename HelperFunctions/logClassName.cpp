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
 * logClassName.cpp
 *
 *  Created on: Apr 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void logClassName(JNIEnv *env, const jobject theObject)
	{
		jclass theClass = env->GetObjectClass(theObject);
		jmethodID methodId = env->GetMethodID(theClass, "getClass", "()Ljava/lang/Class;");
		jobject classClassObject = env->CallObjectMethod(theObject, methodId);

		theClass = env->GetObjectClass(classClassObject);
		methodId = env->GetMethodID(theClass, "getName", "()Ljava/lang/String;");
		jstring stringObject = (jstring)env->CallObjectMethod(classClassObject, methodId);

		const char *className = env->GetStringUTFChars(stringObject, NULL);

		LOGINFO(env, "The class name is:%s", className);

		env->ReleaseStringUTFChars(stringObject, className);
	}
}
