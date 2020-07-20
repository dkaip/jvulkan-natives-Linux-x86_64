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
 * setVkPeerMemoryFeatureFlagsEnumSet.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void setVkPeerMemoryFeatureFlagsEnumSet(JNIEnv *env, jobject jVkPeerMemoryFeatureFlagsObject, VkPeerMemoryFeatureFlags vkPeerMemoryFeatureFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPeerMemoryFeatureFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPeerMemoryFeatureFlagBits;";

        /*
         * Create the EnumSet for the flags.
         */
        jclass enumSetClass = env->FindClass("java/util/EnumSet");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class java/util/EnumSet");
            return;
        }

        jclass enumClass = env->FindClass(enumClassString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "Could not find class %s", enumClassString);
            return;
        }

        jclass setClass = env->FindClass("java/util/Set");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class java/util/Set");
            return;
        }

        jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id of add in class java/util/Set");
            return;
        }

        /*
         * Make sure that flags does not have an unexpected value.  This would
         * indicate that this code is out of sync with the LunarG Vulkan SDK.
         */
        if ((vkPeerMemoryFeatureFlags &
             !(VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT |
			   VK_PEER_MEMORY_FEATURE_COPY_DST_BIT |
			   VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT |
			   VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkPeerMemoryFeatureFlags...value is %x", vkPeerMemoryFeatureFlags);
            return;
        }

        if (vkPeerMemoryFeatureFlags == VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(jVkPeerMemoryFeatureFlagsObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT to EnumSet");
                return;
            }
        }

        if (vkPeerMemoryFeatureFlags & VK_PEER_MEMORY_FEATURE_COPY_DST_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PEER_MEMORY_FEATURE_COPY_DST_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(jVkPeerMemoryFeatureFlagsObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PEER_MEMORY_FEATURE_COPY_DST_BIT to EnumSet");
                return;
            }
        }

        if (vkPeerMemoryFeatureFlags & VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(jVkPeerMemoryFeatureFlagsObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT to EnumSet");
                return;
            }
        }

        if (vkPeerMemoryFeatureFlags & VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(jVkPeerMemoryFeatureFlagsObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT to EnumSet");
                return;
            }
        }
    }
}
