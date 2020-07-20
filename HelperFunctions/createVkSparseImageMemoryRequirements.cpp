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
 * createVkSparseImageMemoryRequirements.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkSparseImageMemoryRequirements(
			JNIEnv *env,
			VkSparseImageMemoryRequirements const *vkSparseImageMemoryRequirements)
	{
		if (vkSparseImageMemoryRequirements == nullptr)
		{
			LOGERROR(env, "%s", "vkSparseImageMemoryRequirements == nullptr");
			return nullptr;
		}

		jclass vkSparseImageMemoryRequirementsClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkSparseImageMemoryRequirementsClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkSparseImageMemoryRequirementsObject =
				env->NewObject(vkSparseImageMemoryRequirementsClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        jclass vkSparseImageFormatPropertiesClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageFormatProperties");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageFormatProperties");
            return nullptr;
        }

        jmethodID constructorMethod = env->GetMethodID(vkSparseImageFormatPropertiesClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            return nullptr;
        }

        jobject jVkSparseImageFormatProperties = env->NewObject(vkSparseImageFormatPropertiesClass, constructorMethod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not create a new VkSparseImageFormatProperties.");
            return nullptr;
        }

        populateVkSparseImageFormatProperties(
        		env,
				jVkSparseImageFormatProperties,
				&vkSparseImageMemoryRequirements->formatProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling populateVkSparseImageFormatProperties");
            return nullptr;
        }

		methodId = env->GetMethodID(vkSparseImageMemoryRequirementsClass, "setFormatProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageFormatProperties;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFormatProperties");
            return nullptr;
        }

        env->CallVoidMethod(jVkSparseImageMemoryRequirementsObject, methodId, jVkSparseImageFormatProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(vkSparseImageMemoryRequirementsClass, "setImageMipTailFirstLod", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageMipTailFirstLod");
            return nullptr;
        }

        env->CallVoidMethod(jVkSparseImageMemoryRequirementsObject, methodId, vkSparseImageMemoryRequirements->imageMipTailFirstLod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(vkSparseImageMemoryRequirementsClass, "setImageMipTailSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageMipTailSize");
            return nullptr;
        }

        env->CallVoidMethod(jVkSparseImageMemoryRequirementsObject, methodId, vkSparseImageMemoryRequirements->imageMipTailSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(vkSparseImageMemoryRequirementsClass, "setImageMipTailOffset", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageMipTailOffset");
            return nullptr;
        }

        env->CallVoidMethod(jVkSparseImageMemoryRequirementsObject, methodId, vkSparseImageMemoryRequirements->imageMipTailOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(vkSparseImageMemoryRequirementsClass, "setImageMipTailStride", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageMipTailStride");
            return nullptr;
        }

        env->CallVoidMethod(jVkSparseImageMemoryRequirementsObject, methodId, vkSparseImageMemoryRequirements->imageMipTailStride);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkSparseImageMemoryRequirementsObject;
	}
}
