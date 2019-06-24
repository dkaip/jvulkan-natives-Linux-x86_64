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
 * createWlSeatCapabilityAsEnumSet.cpp
 *
 *  Created on: Jun 20, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jwayland
{
	jobject createWlSeatCapabilityAsEnumSet(JNIEnv *env, int flags)
	{
		char const *enumClassString = "com/CIMthetics/jvulkan/Wayland/Enums/WlSeatCapability";
		char const *enumObjectString = "Lcom/CIMthetics/jvulkan/Wayland/Enums/WlSeatCapability;";
		/*
		 * Create the EnumSet for the flags.
		 */
		jclass enumSetClass = env->FindClass("java/util/EnumSet");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for java/util/EnumSet.");
			return nullptr;
		}

		jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
		if (env->ExceptionOccurred() != 0)
		{
			LOGERROR(env, "%s", "Error getting noneOf ... returning");
			return nullptr;
		}

		jclass enumClass = env->FindClass(enumClassString);
		if (env->ExceptionOccurred() != 0)
		{
			LOGERROR(env, "Could not find class for %s", enumClassString);
			return nullptr;
		}

		jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling CallStaticObjectMethod for noneOf method.");
			return nullptr;
		}

		jclass setClass = env->FindClass("java/util/Set");
		if (env->ExceptionOccurred() != 0)
		{
			LOGERROR(env, "Could not find class for %s", "java/util/Set");
			return nullptr;
		}

		jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id add");
			return nullptr;
		}

		/*
		 * Make sure that flags does not have an unexpected value.  This would
		 * indicate that this code is out of sync with the LunarG Vulkan SDK.
		 */
		if ((flags &
			 !(1 |
			   2 |
			   4)) != 0)
		{
			LOGERROR(env, "ERROR: Unhandled case for flags...value is %d.", flags);
			return nullptr;
		}

		if (flags & 1)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "POINTER", enumObjectString);
			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				std::cout << "ERROR: could not add POINTER to EnumSet" << std::endl;
				return nullptr;
			}
		}

		if (flags & 2)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "KEYBOARD", enumObjectString);
			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				std::cout << "ERROR: could not add KEYBOARD to EnumSet" << std::endl;
				return nullptr;
			}
		}

		if (flags & 4)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "TOUCH", enumObjectString);
			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				std::cout << "ERROR: could not add TOUCH to EnumSet" << std::endl;
				return nullptr;
			}
		}

		return enumSetObject;
	}
}
