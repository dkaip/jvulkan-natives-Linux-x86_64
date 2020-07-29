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
 * createVkExternalFenceHandleTypeFlagsAsEnumSet.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkExternalFenceHandleTypeFlagsAsEnumSet(JNIEnv *env, VkExternalFenceHandleTypeFlags vkExternalFenceHandleTypeFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalFenceHandleTypeFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalFenceHandleTypeFlagBits;";

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
        if ((vkExternalFenceHandleTypeFlags &
             !(VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT |
               VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT |
			   VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT |
			   VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkExternalFenceHandleTypeFlags...value is %x", vkExternalFenceHandleTypeFlags);
            return nullptr;
        }

        if (vkExternalFenceHandleTypeFlags & VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalFenceHandleTypeFlags & VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalFenceHandleTypeFlags & VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalFenceHandleTypeFlags & VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
