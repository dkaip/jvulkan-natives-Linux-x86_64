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
 * createVkQueueFamilyProperties.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkQueueFamilyProperties(JNIEnv *env, const VkQueueFamilyProperties *vkQueueFamilyProperties)
	{
		if (vkQueueFamilyProperties)
		{
			LOGERROR(env, "%s", "vkQueueFamilyProperties == nullptr");
			return nullptr;
		}

		jclass vkQueueFamilyPropertiesClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkQueueFamilyProperties");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkQueueFamilyProperties");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkQueueFamilyPropertiesClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkQueueFamilyPropertiesObject =
				env->NewObject(vkQueueFamilyPropertiesClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkQueueFamilyPropertiesClass, "setQueueFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setQueueFlags");
            return nullptr;
        }

        jobject jqueueFlags = createVkQueueFlagsKHRAsEnumSet(env, vkQueueFamilyProperties->queueFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkQueueFlagsKHRAsEnumSet");
            return nullptr;
        }

        env->CallVoidMethod(jVkQueueFamilyPropertiesObject, methodId, jqueueFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkQueueFamilyPropertiesClass, "setQueueCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setQueueCount");
            return nullptr;
        }

        env->CallVoidMethod(jVkQueueFamilyPropertiesObject, methodId, vkQueueFamilyProperties->queueCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkQueueFamilyPropertiesClass, "setTimestampValidBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTimestampValidBits");
            return nullptr;
        }

        env->CallVoidMethod(jVkQueueFamilyPropertiesObject, methodId, vkQueueFamilyProperties->timestampValidBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject vkExtent3D = createVkExtent3D(env, &vkQueueFamilyProperties->minImageTransferGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent3D.");
            return nullptr;
        }

        methodId = env->GetMethodID(vkQueueFamilyPropertiesClass, "setMinImageTransferGranularity", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent3D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinImageTransferGranularity");
            return nullptr;
        }

        env->CallVoidMethod(jVkQueueFamilyPropertiesObject, methodId, vkExtent3D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		return jVkQueueFamilyPropertiesObject;
	}
}
