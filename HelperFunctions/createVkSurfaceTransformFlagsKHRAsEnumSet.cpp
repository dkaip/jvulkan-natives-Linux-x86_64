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
 * getVkSurfaceTransformFlagsKHRAsEnumSet.cpp
 *
 *  Created on: May 29, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	jobject createVkSurfaceTransformFlagsKHRAsEnumSet(JNIEnv *env, VkSurfaceTransformFlagsKHR transformFlags)
	{
		char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR";
		char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;";
		/*
		 * Create the EnumSet for the flags.
		 */
		jclass enumSetClass = env->FindClass("java/util/EnumSet");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class java/util/EnumSet");
			return nullptr;
		}

		jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
		if (env->ExceptionOccurred() != 0)
		{
			LOGERROR(env, "%s", "Could not find static method id noneOf");
			return nullptr;
		}

		jclass enumClass = env->FindClass(enumClassString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "Could not find class %s", enumClassString);
			return nullptr;
		}

		jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
			return nullptr;
		}

		jclass setClass = env->FindClass("java/util/Set");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class java/util/Set");
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
		if ((transformFlags &
			 !(VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR |
			   VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR |
			   VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR |
			   VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR |
			   VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR |
			   VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR |
			   VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR |
			   VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR |
			   VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR)) != 0)
		{
			LOGERROR(env, "Unhandled case for transformFlags...value is %d", transformFlags);
			return nullptr;
		}

		if (transformFlags & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR", enumObjectString);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Could not find static field id VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR");
				return nullptr;
			}

			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling GetStaticObjectField.");
				return nullptr;
			}

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "Could not add VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR to EnumSet");
				return nullptr;
			}
		}

		if (transformFlags & VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR", enumObjectString);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Could not find static field id VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR");
				return nullptr;
			}

			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling GetStaticObjectField.");
				return nullptr;
			}

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "Could not add VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR to EnumSet");
				return nullptr;
			}
		}

		if (transformFlags & VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR", enumObjectString);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Could not find static field id VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR");
				return nullptr;
			}

			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling GetStaticObjectField.");
				return nullptr;
			}

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "Could not add VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR to EnumSet");
				return nullptr;
			}
		}

		if (transformFlags & VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR", enumObjectString);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Could not find static field id VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR");
				return nullptr;
			}

			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling GetStaticObjectField.");
				return nullptr;
			}

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "Could not add VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR to EnumSet");
				return nullptr;
			}
		}

		if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR", enumObjectString);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Could not find static field id VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR");
				return nullptr;
			}

			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling GetStaticObjectField.");
				return nullptr;
			}

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "Could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR to EnumSet");
				return nullptr;
			}
		}

		if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR", enumObjectString);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Could not find static field id VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR");
				return nullptr;
			}

			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling GetStaticObjectField.");
				return nullptr;
			}

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "Could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR to EnumSet");
				return nullptr;
			}
		}

		if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR", enumObjectString);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Could not find static field id VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR");
				return nullptr;
			}

			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling GetStaticObjectField.");
				return nullptr;
			}

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "Could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR to EnumSet");
				return nullptr;
			}
		}

		if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR", enumObjectString);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Could not find static field id VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR");
				return nullptr;
			}

			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling GetStaticObjectField.");
				return nullptr;
			}

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "Could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR to EnumSet");
				return nullptr;
			}
		}

		if (transformFlags & VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR", enumObjectString);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Could not find static field id VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR");
				return nullptr;
			}

			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling GetStaticObjectField.");
				return nullptr;
			}

			bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "Could not add VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR to EnumSet");
				return nullptr;
			}
		}

		return enumSetObject;
	}

}
