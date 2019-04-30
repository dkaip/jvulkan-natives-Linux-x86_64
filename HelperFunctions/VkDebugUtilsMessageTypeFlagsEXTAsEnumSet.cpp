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
 * VkDebugUtilsMessageTypeFlagsEXTAsEnumSet.cpp
 *
 *  Created on: Apr 21, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject getVkDebugUtilsMessageTypeFlagsEXTAsEnumSet(JNIEnv *env, VkDebugUtilsMessageTypeFlagsEXT messageTypes)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessageTypeFlagBitsEXT";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessageTypeFlagBitsEXT;";
        /*
         * Create the EnumSet for the flags.
         */
        jclass enumSetClass = env->FindClass("java/util/EnumSet");
        if (env->ExceptionOccurred())
        {
            std::cout << "Error finding EnumSet class ... returning" << std::endl;
            return nullptr;
        }
    //    cout << "Found EnumSet class" << endl;

        jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
        if (env->ExceptionOccurred() != 0)
        {
            std::cout << "Error getting noneOf ... returning" << std::endl;
            return nullptr;
        }

    //    cout << "Got noneOfMethod" << endl;

        jclass enumClass = env->FindClass(enumClassString);

        jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
        if (env->ExceptionOccurred())
        {
            std::cout << "Error CallStaticObjectMethod on enumset object class ... returning" << std::endl;
            return nullptr;
        }

    //    cout << "Made the empty EnumSet flags is " << vkSampleCountFlags << endl;

        jclass setClass = env->FindClass("java/util/Set");
        jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
            std::cout << "Error getting add method on EnumSet ... returning" << std::endl;
            return nullptr;
        }

        /*
         * Make sure that flags does not have an unexpected value.  This would
         * indicate that this code is out of sync with the LunarG Vulkan SDK.
         */
        if ((messageTypes &
             !(VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
               VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
			   VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT |
			   VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT)) != 0)
        {
            std::cout << "ERROR: Unhandled case for memoryHeapFlags...value is " << messageTypes << std::endl;
            return nullptr;
        }

        if (messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                std::cout << "ERROR: could not add VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT to EnumSet" << std::endl;
                return nullptr;
            }
        }

        if (messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                std::cout << "ERROR: could not add VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT to EnumSet" << std::endl;
                return nullptr;
            }
        }

        if (messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                std::cout << "ERROR: could not add VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT to EnumSet" << std::endl;
                return nullptr;
            }
        }

        return enumSetObject;
    }
}



