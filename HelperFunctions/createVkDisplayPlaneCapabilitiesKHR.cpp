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
 * createVkDisplayPlaneCapabilitiesKHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkDisplayPlaneCapabilitiesKHR(
			JNIEnv *env,
			VkDisplayPlaneCapabilitiesKHR const *vkDisplayPlaneCapabilitiesKHR)
	{
		if (vkDisplayPlaneCapabilitiesKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayPlaneCapabilitiesKHR == nullptr");
			return nullptr;
		}

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlaneCapabilitiesKHR",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject VkDisplayPlaneAlphaFlagBitsKHREnumSet = createVkDisplayPlaneAlphaFlagBitsKHRAsEnumSet(
        		env,
				vkDisplayPlaneCapabilitiesKHR->supportedAlpha);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkDisplayPlaneAlphaFlagBitsKHRAsEnumSet");
            return nullptr;
        }

		jmethodID methodId = env->GetMethodID(theClass, "setSupportedAlpha", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedAlpha");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, VkDisplayPlaneAlphaFlagBitsKHREnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jVkOffset2D = createVkOffset2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->minSrcPosition);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkOffset2D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setMinSrcPosition", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinSrcPosition");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkOffset2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkOffset2D = createVkOffset2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->maxSrcPosition);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkOffset2D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setMaxSrcPosition", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSrcPosition");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkOffset2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->minSrcExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setMinSrcExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinSrcExtent");
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
				&vkDisplayPlaneCapabilitiesKHR->maxSrcExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setMaxSrcExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSrcExtent");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkOffset2D = createVkOffset2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->minDstPosition);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkOffset2D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setMinDstPosition", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinDstPosition");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkOffset2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkOffset2D = createVkOffset2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->maxDstPosition);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkOffset2D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setMaxDstPosition", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDstPosition");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkOffset2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->minDstExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setMinDstExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinDstExtent");
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
				&vkDisplayPlaneCapabilitiesKHR->maxDstExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setMaxDstExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDstExtent");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
