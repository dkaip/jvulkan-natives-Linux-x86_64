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
 * getVkDebugUtilsMessengerCallbackDataFlagsEXTAsEnumSet.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: Douglas Kaip
 */


#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "../headers/slf4j.hh"
#include "HelperFunctions.hh"

namespace jvulkan
{
    jobject getVkDebugUtilsMessengerCallbackDataFlagsEXTAsEnumSet(JNIEnv *env, VkDebugUtilsMessengerCallbackDataFlagsEXT flags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessengerCallbackDataFlagsEXT";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessengerCallbackDataFlagsEXT;";
        /*
         * Create the EnumSet for the flags.
         */
        jclass enumSetClass = env->FindClass("java/util/EnumSet");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class \"java/util/EnumSet\"");
            return nullptr;
        }

        jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
        if (env->ExceptionOccurred() != 0)
        {
        	LOGERROR(env, "%s", "Could not find static method noneOf");
            return nullptr;
        }

        jclass enumClass = env->FindClass(enumClassString);

        jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling static method noneOf");
            return nullptr;
        }

        // Currently there are no values for this Enum so we are returning an empty set.



//        jclass setClass = env->FindClass("java/util/Set");
//        jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
//        if (env->ExceptionOccurred())
//        {
//            std::cout << "Error getting add method on EnumSet ... returning" << std::endl;
//            return nullptr;
//        }
//
//        /*
//         * Make sure that flags does not have an unexpected value.  This would
//         * indicate that this code is out of sync with the LunarG Vulkan SDK.
//         */
//        if ((flags &
//             !(RESERVED_FOR_FUTURE_USE)) != 0)
//        {
//            std::cout << "ERROR: Unhandled case for memoryHeapFlags...value is " << flags << std::endl;
//            return nullptr;
//        }
//
//        if (messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                std::cout << "ERROR: could not add VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT to EnumSet" << std::endl;
//                return nullptr;
//            }
//        }
//
//        if (messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                std::cout << "ERROR: could not add VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT to EnumSet" << std::endl;
//                return nullptr;
//            }
//        }
//
//        if (messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                std::cout << "ERROR: could not add VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT to EnumSet" << std::endl;
//                return nullptr;
//            }
//        }
//
//        if (messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                std::cout << "ERROR: could not add VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT to EnumSet" << std::endl;
//                return nullptr;
//            }
//        }
//
        return enumSetObject;
    }
}
