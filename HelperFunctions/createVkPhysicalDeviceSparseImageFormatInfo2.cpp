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
 * createVkPhysicalDeviceSparseImageFormatInfo2.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkPhysicalDeviceSparseImageFormatInfo2(
			JNIEnv *env,
			VkPhysicalDeviceSparseImageFormatInfo2 const *vkPhysicalDeviceSparseImageFormatInfo2)
	{
		if (vkPhysicalDeviceSparseImageFormatInfo2 == nullptr)
		{
			LOGERROR(env, "%s", "vkPhysicalDeviceSparseImageFormatInfo2 == nullptr");
			return nullptr;
		}

		jclass vkPhysicalDeviceSparseImageFormatInfo2Class = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceSparseImageFormatInfo2");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceSparseImageFormatInfo2");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkPhysicalDeviceSparseImageFormatInfo2Class, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkPhysicalDeviceSparseImageFormatInfo2Object =
				env->NewObject(vkPhysicalDeviceSparseImageFormatInfo2Class, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkFormat = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat",
				vkPhysicalDeviceSparseImageFormatInfo2->format);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkPhysicalDeviceSparseImageFormatInfo2Class, "setFormat", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFormat");
            return nullptr;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId, jVkFormat);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkImageType = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageType",
				vkPhysicalDeviceSparseImageFormatInfo2->type);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkPhysicalDeviceSparseImageFormatInfo2Class, "setType", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageType;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setType");
            return nullptr;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId, jVkImageType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkSampleCountFlagBits = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits",
				vkPhysicalDeviceSparseImageFormatInfo2->samples);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkPhysicalDeviceSparseImageFormatInfo2Class, "setSamples", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSamples");
            return nullptr;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId, jVkSampleCountFlagBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jUsage = createVkImageUsageFlagsAsEnumSet(
    			env,
				vkPhysicalDeviceSparseImageFormatInfo2->usage);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkPhysicalDeviceSparseImageFormatInfo2Class, "setUsage", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setUsage");
            return nullptr;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId, jUsage);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkImageTiling = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageTiling",
				vkPhysicalDeviceSparseImageFormatInfo2->tiling);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkPhysicalDeviceSparseImageFormatInfo2Class, "setTiling", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageTiling;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTiling");
            return nullptr;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId, jVkImageTiling);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }


        return jVkPhysicalDeviceSparseImageFormatInfo2Object;
	}
}
