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
 * getVkSampleCountFlagsAsEnumSet.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkSampleCountFlagsAsEnumSet(JNIEnv *env, VkSampleCountFlags vkSampleCountFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits;";

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
        if ((vkSampleCountFlags &
             !(VK_SAMPLE_COUNT_1_BIT |
			   VK_SAMPLE_COUNT_2_BIT |
			   VK_SAMPLE_COUNT_4_BIT |
			   VK_SAMPLE_COUNT_8_BIT |
			   VK_SAMPLE_COUNT_16_BIT |
			   VK_SAMPLE_COUNT_32_BIT |
			   VK_SAMPLE_COUNT_64_BIT)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkSampleCountFlags...value is %x", vkSampleCountFlags);
            return nullptr;
        }

        if (vkSampleCountFlags == VK_SAMPLE_COUNT_1_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_1_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SAMPLE_COUNT_1_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSampleCountFlags == VK_SAMPLE_COUNT_2_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_2_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SAMPLE_COUNT_2_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSampleCountFlags == VK_SAMPLE_COUNT_4_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_4_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SAMPLE_COUNT_4_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSampleCountFlags == VK_SAMPLE_COUNT_8_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_8_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SAMPLE_COUNT_8_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSampleCountFlags == VK_SAMPLE_COUNT_16_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_16_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SAMPLE_COUNT_16_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSampleCountFlags == VK_SAMPLE_COUNT_32_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_32_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SAMPLE_COUNT_32_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSampleCountFlags == VK_SAMPLE_COUNT_64_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_64_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SAMPLE_COUNT_64_BIT to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
