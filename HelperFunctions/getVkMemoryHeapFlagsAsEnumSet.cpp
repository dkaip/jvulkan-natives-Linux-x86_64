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
#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace jvulkan
{
    jobject getVkMemoryHeapFlagsAsEnumSet(JNIEnv *env, VkMemoryHeapFlags memoryHeapFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkMemoryHeapFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkMemoryHeapFlagBits;";
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
        if ((memoryHeapFlags &
             !(VK_MEMORY_HEAP_DEVICE_LOCAL_BIT |
               VK_MEMORY_HEAP_MULTI_INSTANCE_BIT |
               VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR)) != 0)
        {
            std::cout << "ERROR: Unhandled case for memoryHeapFlags...value is " << memoryHeapFlags << std::endl;
            return nullptr;
        }

        if (memoryHeapFlags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_MEMORY_HEAP_DEVICE_LOCAL_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                std::cout << "ERROR: could not add VK_MEMORY_HEAP_DEVICE_LOCAL_BIT to EnumSet" << std::endl;
                return nullptr;
            }
        }

        if (memoryHeapFlags & VK_MEMORY_HEAP_MULTI_INSTANCE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_MEMORY_HEAP_MULTI_INSTANCE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                std::cout << "ERROR: could not add VK_MEMORY_HEAP_MULTI_INSTANCE_BIT to EnumSet" << std::endl;
                return nullptr;
            }
        }

        if (memoryHeapFlags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_MEMORY_PROPERTY_HOST_COHERENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                std::cout << "ERROR: could not add VK_MEMORY_PROPERTY_HOST_COHERENT_BIT to EnumSet" << std::endl;
                return nullptr;
            }
        }

        if (memoryHeapFlags & VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                std::cout << "ERROR: could not add VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR to EnumSet" << std::endl;
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
