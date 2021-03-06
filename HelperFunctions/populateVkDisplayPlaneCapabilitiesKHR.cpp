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
 * populateVkDisplayPlaneCapabilitiesKHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkDisplayPlaneCapabilitiesKHR(
    		JNIEnv *env,
			jobject jVkDisplayPlaneCapabilitiesKHRObject,
			const VkDisplayPlaneCapabilitiesKHR *vkDisplayPlaneCapabilitiesKHR)
    {
		if (jVkDisplayPlaneCapabilitiesKHRObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkDisplayPlaneCapabilitiesKHRObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkDisplayPlaneCapabilitiesKHRObject == nullptr");
			return;
		}

		if (vkDisplayPlaneCapabilitiesKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkDisplayPlaneCapabilitiesKHR == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkDisplayPlaneCapabilitiesKHR == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass vkDisplayPlaneCapabilitiesKHRClass = env->GetObjectClass(jVkDisplayPlaneCapabilitiesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayPlaneCapabilitiesKHR");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject VkDisplayPlaneAlphaFlagBitsKHREnumSet = createVkDisplayPlaneAlphaFlagBitsKHRAsEnumSet(
        		env,
				vkDisplayPlaneCapabilitiesKHR->supportedAlpha);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkDisplayPlaneAlphaFlagBitsKHRAsEnumSet");
            return;
        }

		jmethodID methodId = env->GetMethodID(vkDisplayPlaneCapabilitiesKHRClass, "setSupportedAlpha", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedAlpha");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilitiesKHRObject, methodId, VkDisplayPlaneAlphaFlagBitsKHREnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jVkOffset2D = createVkOffset2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->minSrcPosition);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkOffset2D");
            return;
        }

		methodId = env->GetMethodID(vkDisplayPlaneCapabilitiesKHRClass, "setMinSrcPosition", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinSrcPosition");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilitiesKHRObject, methodId, jVkOffset2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkOffset2D = createVkOffset2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->maxSrcPosition);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkOffset2D");
            return;
        }

		methodId = env->GetMethodID(vkDisplayPlaneCapabilitiesKHRClass, "setMaxSrcPosition", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSrcPosition");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilitiesKHRObject, methodId, jVkOffset2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->minSrcExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return;
        }

		methodId = env->GetMethodID(vkDisplayPlaneCapabilitiesKHRClass, "setMinSrcExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinSrcExtent");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilitiesKHRObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->maxSrcExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return;
        }

		methodId = env->GetMethodID(vkDisplayPlaneCapabilitiesKHRClass, "setMaxSrcExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSrcExtent");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilitiesKHRObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkOffset2D = createVkOffset2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->minDstPosition);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkOffset2D");
            return;
        }

		methodId = env->GetMethodID(vkDisplayPlaneCapabilitiesKHRClass, "setMinDstPosition", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinDstPosition");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilitiesKHRObject, methodId, jVkOffset2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkOffset2D = createVkOffset2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->maxDstPosition);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkOffset2D");
            return;
        }

		methodId = env->GetMethodID(vkDisplayPlaneCapabilitiesKHRClass, "setMaxDstPosition", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDstPosition");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilitiesKHRObject, methodId, jVkOffset2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->minDstExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return;
        }

		methodId = env->GetMethodID(vkDisplayPlaneCapabilitiesKHRClass, "setMinDstExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinDstExtent");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilitiesKHRObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jVkExtent2D = createVkExtent2D(
        		env,
				&vkDisplayPlaneCapabilitiesKHR->maxDstExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return;
        }

		methodId = env->GetMethodID(vkDisplayPlaneCapabilitiesKHRClass, "setMaxDstExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDstExtent");
            return;
        }

        env->CallVoidMethod(jVkDisplayPlaneCapabilitiesKHRObject, methodId, jVkExtent2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
    }
}
