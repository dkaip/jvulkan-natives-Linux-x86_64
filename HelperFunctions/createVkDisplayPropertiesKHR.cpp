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

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPropertiesKHR",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor.");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jVkDisplayKHR = createVulkanHandle(
        		env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayKHR",
				vkDisplayPropertiesKHR->display);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
            return nullptr;
        }

		jmethodID methodId = env->GetMethodID(theClass, "setDisplay", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDisplay");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkDisplayKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setDisplayName", "(Ljava/lang/String;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setDisplayName");
			return nullptr;
		}

		jstring displayNameString = env->NewStringUTF(vkDisplayPropertiesKHR->displayName);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling NewStringUTF.");
            return nullptr;
        }

		env->CallVoidMethod(theObject, methodId, displayNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setDisplayName");
			return nullptr;
		}

		env->DeleteLocalRef(displayNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling DeleteLocalRef.");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayPropertiesKHR->physicalDimensions);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setPhysicalDimensions", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPhysicalDimensions");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkExtent2D);
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

		methodId = env->GetMethodID(theClass, "setPhysicalResolution", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPhysicalResolution");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSupportedTransforms", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(theObject, methodId, jsupportedTransforms);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setPlaneReorderPossible", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPlaneReorderPossible");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkDisplayPropertiesKHR->planeReorderPossible);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setPersistentContent", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPersistentContent");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkDisplayPropertiesKHR->persistentContent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
