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
 * getVkShaderStageFlagsAsEnumSet.cpp
 *
 *  Created on: May 13, 2019
 *      Author: Douglas KAip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject getVkShaderStageFlagsAsEnumSet(JNIEnv *env, VkShaderStageFlags vkShaderStageFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkShaderStageFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkShaderStageFlagBits;";

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
        if ((vkShaderStageFlags &
             !(VK_SHADER_STAGE_VERTEX_BIT |
			   VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT |
			   VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT |
			   VK_SHADER_STAGE_GEOMETRY_BIT |
			   VK_SHADER_STAGE_FRAGMENT_BIT |
			   VK_SHADER_STAGE_COMPUTE_BIT |
			   VK_SHADER_STAGE_ALL_GRAPHICS |
			   VK_SHADER_STAGE_ALL |
			   VK_SHADER_STAGE_RAYGEN_BIT_NV |
			   VK_SHADER_STAGE_ANY_HIT_BIT_NV |
			   VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV |
			   VK_SHADER_STAGE_MISS_BIT_NV |
			   VK_SHADER_STAGE_INTERSECTION_BIT_NV |
			   VK_SHADER_STAGE_CALLABLE_BIT_NV |
 			   VK_SHADER_STAGE_TASK_BIT_NV |
			   VK_SHADER_STAGE_MESH_BIT_NV)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkShaderStageFlags...value is %x", vkShaderStageFlags);
            return nullptr;
        }

        if (vkShaderStageFlags == VK_SHADER_STAGE_ALL)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_ALL", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_ALL to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_VERTEX_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_VERTEX_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_VERTEX_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_GEOMETRY_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_GEOMETRY_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_GEOMETRY_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_FRAGMENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_FRAGMENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_FRAGMENT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_COMPUTE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_COMPUTE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_COMPUTE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_ALL_GRAPHICS)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_ALL_GRAPHICS", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_ALL_GRAPHICS to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_RAYGEN_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_RAYGEN_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_RAYGEN_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_ANY_HIT_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_ANY_HIT_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_ANY_HIT_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_MISS_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_MISS_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_MISS_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_INTERSECTION_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_INTERSECTION_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_INTERSECTION_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_CALLABLE_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_CALLABLE_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_CALLABLE_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_TASK_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_TASK_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_TASK_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkShaderStageFlags & VK_SHADER_STAGE_MESH_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SHADER_STAGE_MESH_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SHADER_STAGE_MESH_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
