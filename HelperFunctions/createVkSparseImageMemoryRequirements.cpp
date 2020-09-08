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

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageMemoryRequirements",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
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

		jmethodID methodId = env->GetMethodID(theClass, "setFormatProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageFormatProperties;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFormatProperties");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkSparseImageFormatProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setImageMipTailFirstLod", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageMipTailFirstLod");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSparseImageMemoryRequirements->imageMipTailFirstLod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setImageMipTailSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageMipTailSize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSparseImageMemoryRequirements->imageMipTailSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setImageMipTailOffset", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageMipTailOffset");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSparseImageMemoryRequirements->imageMipTailOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setImageMipTailStride", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageMipTailStride");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSparseImageMemoryRequirements->imageMipTailStride);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
