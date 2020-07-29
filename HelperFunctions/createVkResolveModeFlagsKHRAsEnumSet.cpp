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
 * getVkResolveModeFlagsKHRAsEnumSet.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkResolveModeFlagsAsEnumSet(JNIEnv *env, VkResolveModeFlags vkResolveModeFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/Enums/VkResolveModeFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResolveModeFlagBits;";

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
        	LOGERROR(env, "%s", "Could not find method id of noneOf in class java/util/EnumSet");
            return nullptr;
        }

        jclass enumClass = env->FindClass(enumClassString);

        jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod for method id of noneOf in class java/util/EnumSet");
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
        	LOGERROR(env, "%s", "Could not find method id of add in class java/util/Set");
            return nullptr;
        }

        /*
         * Make sure that flags does not have an unexpected value.  This would
         * indicate that this code is out of sync with the LunarG Vulkan SDK.
         */
        if ((vkResolveModeFlags &
             !(VK_RESOLVE_MODE_NONE |
			   VK_RESOLVE_MODE_SAMPLE_ZERO_BIT |
			   VK_RESOLVE_MODE_AVERAGE_BIT |
			   VK_RESOLVE_MODE_MIN_BIT |
			   VK_RESOLVE_MODE_MAX_BIT)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkResolveModeFlags...value is %x", vkResolveModeFlags);
            return nullptr;
        }

        if (vkResolveModeFlags & VK_RESOLVE_MODE_NONE)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_RESOLVE_MODE_NONE", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_RESOLVE_MODE_NONE to EnumSet");
                return nullptr;
            }
        }

        if (vkResolveModeFlags & VK_RESOLVE_MODE_SAMPLE_ZERO_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_RESOLVE_MODE_SAMPLE_ZERO_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_RESOLVE_MODE_SAMPLE_ZERO_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkResolveModeFlags & VK_RESOLVE_MODE_AVERAGE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_RESOLVE_MODE_AVERAGE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_RESOLVE_MODE_AVERAGE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkResolveModeFlags & VK_RESOLVE_MODE_MIN_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_RESOLVE_MODE_MIN_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_RESOLVE_MODE_MIN_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkResolveModeFlags & VK_RESOLVE_MODE_MAX_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_RESOLVE_MODE_MAX_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_RESOLVE_MODE_MAX_BIT to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
