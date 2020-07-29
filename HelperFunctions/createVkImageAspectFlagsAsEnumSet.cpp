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
 * createVkImageAspectFlagsAsEnumSet.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkImageAspectFlagsAsEnumSet(JNIEnv *env, VkImageAspectFlags vkImageAspectFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageAspectFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageAspectFlagBits;";

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
        if ((vkImageAspectFlags &
             !(VK_IMAGE_ASPECT_COLOR_BIT |
               VK_IMAGE_ASPECT_DEPTH_BIT |
			   VK_IMAGE_ASPECT_STENCIL_BIT |
			   VK_IMAGE_ASPECT_METADATA_BIT |
			   VK_IMAGE_ASPECT_PLANE_0_BIT |
			   VK_IMAGE_ASPECT_PLANE_1_BIT |
			   VK_IMAGE_ASPECT_PLANE_2_BIT |
			   VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT |
			   VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT |
			   VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT |
			   VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkImageAspectFlags...value is %x", vkImageAspectFlags);
            return nullptr;
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_COLOR_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_COLOR_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_COLOR_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_DEPTH_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_DEPTH_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_DEPTH_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_STENCIL_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_STENCIL_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_STENCIL_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_METADATA_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_METADATA_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_METADATA_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_PLANE_0_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_PLANE_0_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_PLANE_0_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_PLANE_1_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_PLANE_1_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_PLANE_1_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_PLANE_2_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_PLANE_2_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_PLANE_2_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        if (vkImageAspectFlags & VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
