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
 * createVkSurfaceFormatKHR.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkSurfaceFormatKHR(
			JNIEnv *env,
			VkSurfaceFormatKHR const *vkSurfaceFormatKHR)
	{
		if (vkSurfaceFormatKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkSurfaceFormatKHR == nullptr");
			return nullptr;
		}

        ///////////////////////////////////////////////////////////////////////////
        jclass vkFormatClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat");
            return nullptr;
        }

        jmethodID methodId = env->GetStaticMethodID(vkFormatClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find static method id fromValue");
            return nullptr;
        }

        jobject formatEnum = env->CallStaticObjectMethod(vkFormatClass, methodId, vkSurfaceFormatKHR->format);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        jclass vkColorSpaceKHRClass = env->FindClass("com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR");
            return nullptr;
        }

        methodId = env->GetStaticMethodID(vkColorSpaceKHRClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find static method id fromValue");
            return nullptr;
        }

        jobject colorspaceEnum = env->CallStaticObjectMethod(vkColorSpaceKHRClass, methodId, vkSurfaceFormatKHR->colorSpace);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
            return nullptr;
        }


		jclass vkSurfaceFormatKHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSurfaceFormatKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSurfaceFormatKHR");
            return nullptr;
        }

		// Locate the constructor
		methodId = env->GetMethodID(vkSurfaceFormatKHRClass, "<init>", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR;)V");
            return nullptr;
        }

        jobject jVkSurfaceFormatKHRObject =
				env->NewObject(vkSurfaceFormatKHRClass, methodId, formatEnum, colorspaceEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        return jVkSurfaceFormatKHRObject;
	}
}
