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
 * populateVkDeviceGroupPresentModeFlagsKHR.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkDeviceGroupPresentModeFlagsKHR(JNIEnv *env, jobject jVkDeviceGroupPresentModeFlagsKHR, VkDeviceGroupPresentModeFlagsKHR modes)
	{
		char const *enumClassString = "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDeviceGroupPresentModeFlagBitsKHR";
		char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDeviceGroupPresentModeFlagBitsKHR;";
		/*
		 * Create the EnumSet for the flags.
		 */
		jclass enumSetClass = env->FindClass("java/util/EnumSet");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class java/util/EnumSet");
			return;
		}

		jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
		if (env->ExceptionOccurred() != 0)
		{
			LOGERROR(env, "%s", "Could not find static method noneOf");
			return;
		}

		jclass enumClass = env->FindClass(enumClassString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "Could not find class %s", enumClassString);
			return;
		}

		jclass setClass = env->FindClass("java/util/Set");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "Could not find class %s", "java/util/Set");
			return;
		}

		jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id add");
			return;
		}

		/*
		 * Make sure that flags does not have an unexpected value.  This would
		 * indicate that this code is out of sync with the LunarG Vulkan SDK.
		 */
		if ((modes &
			 !(VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR |
			   VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR |
			   VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR |
			   VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR)) != 0)
		{
			LOGERROR(env, "ERROR: Unhandled case for modes...value is %d", modes);
			return;
		}

		if (modes & VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR", enumObjectString);
			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

			bool addResult = env->CallBooleanMethod(jVkDeviceGroupPresentModeFlagsKHR, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "ERROR: could not add VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR to EnumSet");
				return;
			}
		}

		if (modes & VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR", enumObjectString);
			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

			bool addResult = env->CallBooleanMethod(jVkDeviceGroupPresentModeFlagsKHR, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "ERROR: could not add VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR to EnumSet");
				return;
			}
		}

		if (modes & VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR", enumObjectString);
			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

			bool addResult = env->CallBooleanMethod(jVkDeviceGroupPresentModeFlagsKHR, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "ERROR: could not add VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR to EnumSet");
				return;
			}
		}

		if (modes & VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR)
		{
			jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR", enumObjectString);
			jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

			bool addResult = env->CallBooleanMethod(jVkDeviceGroupPresentModeFlagsKHR, setAddMethod, theEnum);
			if (addResult == false)
			{
				LOGERROR(env, "%s", "ERROR: could not add VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR to EnumSet");
				return;
			}
		}
	}
}
