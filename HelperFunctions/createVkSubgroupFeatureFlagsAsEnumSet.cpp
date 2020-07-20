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
 * getVkSubgroupFeatureFlagsAsEnumSet.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkSubgroupFeatureFlagsAsEnumSet(JNIEnv *env, VkSubgroupFeatureFlags vkSubgroupFeatureFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/Enums/VkSubgroupFeatureFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSubgroupFeatureFlagBits;";

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
        if ((vkSubgroupFeatureFlags &
             !(VK_SUBGROUP_FEATURE_BASIC_BIT |
               VK_SUBGROUP_FEATURE_VOTE_BIT |
			   VK_SUBGROUP_FEATURE_ARITHMETIC_BIT |
			   VK_SUBGROUP_FEATURE_BALLOT_BIT |
			   VK_SUBGROUP_FEATURE_SHUFFLE_BIT |
			   VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT |
			   VK_SUBGROUP_FEATURE_CLUSTERED_BIT |
			   VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV |
			   VK_SHADER_STAGE_MESH_BIT_NV)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkSubgroupFeatureFlags...value is %x", vkSubgroupFeatureFlags);
            return nullptr;
        }

        if (vkSubgroupFeatureFlags & VK_SUBGROUP_FEATURE_BASIC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SUBGROUP_FEATURE_BASIC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SUBGROUP_FEATURE_BASIC_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSubgroupFeatureFlags & VK_SUBGROUP_FEATURE_VOTE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SUBGROUP_FEATURE_VOTE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SUBGROUP_FEATURE_VOTE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSubgroupFeatureFlags & VK_SUBGROUP_FEATURE_ARITHMETIC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SUBGROUP_FEATURE_ARITHMETIC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SUBGROUP_FEATURE_ARITHMETIC_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSubgroupFeatureFlags & VK_SUBGROUP_FEATURE_BALLOT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SUBGROUP_FEATURE_BALLOT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SUBGROUP_FEATURE_BALLOT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSubgroupFeatureFlags & VK_SUBGROUP_FEATURE_SHUFFLE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SUBGROUP_FEATURE_SHUFFLE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SUBGROUP_FEATURE_SHUFFLE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSubgroupFeatureFlags & VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSubgroupFeatureFlags & VK_SUBGROUP_FEATURE_CLUSTERED_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SUBGROUP_FEATURE_CLUSTERED_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SUBGROUP_FEATURE_CLUSTERED_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSubgroupFeatureFlags & VK_SUBGROUP_FEATURE_QUAD_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SUBGROUP_FEATURE_QUAD_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SUBGROUP_FEATURE_QUAD_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkSubgroupFeatureFlags & VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
