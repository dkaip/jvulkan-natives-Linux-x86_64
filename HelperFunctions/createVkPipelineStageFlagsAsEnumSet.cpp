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
 * createVkPipelineStageFlagsAsEnumSet.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkPipelineStageFlagsAsEnumSet(JNIEnv *env, VkPipelineStageFlags vkPipelineStageFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineStageFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineStageFlagBits;";

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
        if ((vkPipelineStageFlags &
             !(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT |
               VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT |
			   VK_PIPELINE_STAGE_VERTEX_INPUT_BIT |
			   VK_PIPELINE_STAGE_VERTEX_SHADER_BIT |
			   VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT |
			   VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT |
			   VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT |
			   VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT |
			   VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT |
			   VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT |
			   VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT |
			   VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT |
			   VK_PIPELINE_STAGE_TRANSFER_BIT |
			   VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT |
			   VK_PIPELINE_STAGE_HOST_BIT |
			   VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT |
			   VK_PIPELINE_STAGE_ALL_COMMANDS_BIT |
			   VK_PIPELINE_STAGE_COMMAND_PROCESS_BIT_NVX |
			   VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT |
			   VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV |
			   VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV |
			   VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_NV |
			   VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV |
			   VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT |
			   VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT |
			   VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_NV)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkPipelineStageFlags...value is %x", vkPipelineStageFlags);
            return nullptr;
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_VERTEX_INPUT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_VERTEX_INPUT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_VERTEX_INPUT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_VERTEX_SHADER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_VERTEX_SHADER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_VERTEX_SHADER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_TRANSFER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_TRANSFER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_TRANSFER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_HOST_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_HOST_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_HOST_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_ALL_COMMANDS_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_ALL_COMMANDS_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_ALL_COMMANDS_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_COMMAND_PROCESS_BIT_NVX)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_COMMAND_PROCESS_BIT_NVX", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_COMMAND_PROCESS_BIT_NVX to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        if (vkPipelineStageFlags & VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
