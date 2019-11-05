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
 * createVkDisplayPropertiesKHR.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkDisplayPropertiesKHR(
			JNIEnv *env,
			VkDisplayPropertiesKHR const *vkDisplayPropertiesKHR)
	{
		if (vkDisplayPropertiesKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayPropertiesKHR == nullptr");
			return nullptr;
		}

		jclass vkDisplayPropertiesKHRClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkDisplayPropertiesKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkDisplayPropertiesKHR");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkDisplayPropertiesKHRClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkDisplayPropertiesKHRObject =
				env->NewObject(vkDisplayPropertiesKHRClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jVkDisplayKHR = createVulkanHandle(
        		env,
				"com/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkDisplayKHR",
				vkDisplayPropertiesKHR->display);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle");
            return nullptr;
        }

		methodId = env->GetMethodID(vkDisplayPropertiesKHRClass, "setDisplay", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkDisplayKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDisplay");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayPropertiesKHRObject, methodId, jVkDisplayKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkDisplayPropertiesKHRClass, "setDisplayName", "(Ljava/lang/String;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setDisplayName");
			return nullptr;
		}

		jstring displayNameString = env->NewStringUTF(vkDisplayPropertiesKHR->displayName);

		env->CallVoidMethod(jVkDisplayPropertiesKHRObject, methodId, displayNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setDisplayName");
			return nullptr;
		}

		env->DeleteLocalRef(displayNameString);

        ////////////////////////////////////////////////////////////////////////
        jobject jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayPropertiesKHR->physicalDimensions);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return nullptr;
        }

		methodId = env->GetMethodID(vkDisplayPropertiesKHRClass, "setPhysicalDimensions", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPhysicalDimensions");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayPropertiesKHRObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayPropertiesKHR->physicalResolution);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return nullptr;
        }

		methodId = env->GetMethodID(vkDisplayPropertiesKHRClass, "setPhysicalResolution", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPhysicalResolution");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayPropertiesKHRObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplayPropertiesKHRClass, "setSupportedTransforms", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedTransforms");
            return nullptr;
        }

        jobject jsupportedTransforms = createVkSurfaceTransformFlagsKHRAsEnumSet(env, vkDisplayPropertiesKHR->supportedTransforms);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSurfaceTransformFlagsKHRAsEnumSet");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayPropertiesKHRObject, methodId, jsupportedTransforms);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkDisplayPropertiesKHRClass, "setPlaneReorderPossible", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPlaneReorderPossible");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayPropertiesKHRObject, methodId, vkDisplayPropertiesKHR->planeReorderPossible);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkDisplayPropertiesKHRClass, "setPersistentContent", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPersistentContent");
            return nullptr;
        }

        env->CallVoidMethod(jVkDisplayPropertiesKHRObject, methodId, vkDisplayPropertiesKHR->persistentContent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkDisplayPropertiesKHRObject;
	}
}
