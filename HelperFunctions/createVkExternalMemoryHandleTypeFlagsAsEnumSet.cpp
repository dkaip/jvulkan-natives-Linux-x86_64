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
 * createVkExternalMemoryHandleTypeFlagsAsEnumSet.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkExternalMemoryHandleTypeFlagsAsEnumSet(JNIEnv *env, VkExternalMemoryHandleTypeFlags vkExternalMemoryHandleTypeFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkExternalMemoryHandleTypeFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkExternalMemoryHandleTypeFlagBits;";

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
        if ((vkExternalMemoryHandleTypeFlags &
             !(VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT |
               VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT |
			   VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT |
			   VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT |
			   VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT |
			   VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT |
			   VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT |
			   VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT |
			   VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID |
			   VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT |
			   VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT)) != 0)
        {
        	LOGERROR(env, "Unhandled case for vkExternalMemoryHandleTypeFlags...value is %x", vkExternalMemoryHandleTypeFlags);
            return nullptr;
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        if (vkExternalMemoryHandleTypeFlags & VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Could not add VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT to EnumSet");
                return nullptr;
            }
        }

        return enumSetObject;
    }
}
