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
 * createVkDisplayPlaneAlphaFlagBitsKHRAsEnumSet.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkDisplayPlaneAlphaFlagBitsKHRAsEnumSet(JNIEnv *env, VkDisplayPlaneAlphaFlagsKHR vkDisplayPlaneAlphaFlagsKHR)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDisplayPlaneAlphaFlagBitsKHR";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDisplayPlaneAlphaFlagBitsKHR;";

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
        if ((vkDisplayPlaneAlphaFlagsKHR &
             !(VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR |
               VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR |
			   VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR |
			   VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkDisplayPlaneAlphaFlagsKHR...value is %x", vkDisplayPlaneAlphaFlagsKHR);
            return nullptr;
        }

        if (vkDisplayPlaneAlphaFlagsKHR & VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR to EnumSet");
                return nullptr;
            }
        }

        if (vkDisplayPlaneAlphaFlagsKHR & VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR to EnumSet");
                return nullptr;
            }
        }

        if (vkDisplayPlaneAlphaFlagsKHR & VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR to EnumSet");
                return nullptr;
            }
        }

        if (vkDisplayPlaneAlphaFlagsKHR & VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
