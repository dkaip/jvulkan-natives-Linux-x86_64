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
 * createVkFormatFeatureFlagsAsEnumSet.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkFormatFeatureFlagsAsEnumSet(JNIEnv *env, VkFormatFeatureFlags vkFormatFeatureFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/Enums/VkFormatFeatureFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormatFeatureFlagBits;";

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
        if ((vkFormatFeatureFlags &
             !(VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT |
               VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT |
			   VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT |
			   VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT |
			   VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT |
			   VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT |
			   VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT |
			   VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT |
			   VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT |
			   VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT |
			   VK_FORMAT_FEATURE_BLIT_SRC_BIT |
			   VK_FORMAT_FEATURE_BLIT_DST_BIT |
			   VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT |
			   VK_FORMAT_FEATURE_TRANSFER_SRC_BIT |
			   VK_FORMAT_FEATURE_TRANSFER_DST_BIT |
			   VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT |
			   VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT |
			   VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT |
			   VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT |
			   VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT |
			   VK_FORMAT_FEATURE_DISJOINT_BIT |
			   VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT |
			   VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG |
			   VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT |
			   VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkFormatFeatureFlags...value is %x", vkFormatFeatureFlags);
            return nullptr;
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_BLIT_SRC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_BLIT_SRC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_BLIT_SRC_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_BLIT_DST_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_BLIT_DST_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_BLIT_DST_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_TRANSFER_SRC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_TRANSFER_SRC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_TRANSFER_SRC_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_TRANSFER_DST_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_TRANSFER_DST_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_TRANSFER_DST_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_DISJOINT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_DISJOINT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_DISJOINT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        if (vkFormatFeatureFlags & VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
