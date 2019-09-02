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
 * populateVkSurfaceCapabilitiesKHR.cpp
 *
 *  Created on: May 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkSurfaceCapabilitiesKHR(
			JNIEnv *env,
			jobject jVkSurfaceCapabilitiesKHRObject,
			const VkSurfaceCapabilitiesKHR *vkSurfaceCapabilitiesKHR,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkSurfaceCapabilitiesKHRObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSurfaceCapabilitiesKHR");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setMinImageCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinImageCount");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, vkSurfaceCapabilitiesKHR->minImageCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxImageCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageCount");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, vkSurfaceCapabilitiesKHR->maxImageCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setCurrentImageExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCurrentImageExtent");
            return;
        }

        jobject extent2DObject = createVkExtent2D(env, &vkSurfaceCapabilitiesKHR->currentExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D.");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinImageExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinImageExtent");
            return;
        }

        extent2DObject = createVkExtent2D(env, &vkSurfaceCapabilitiesKHR->minImageExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D.");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxImageExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageExtent");
            return;
        }

        extent2DObject = createVkExtent2D(env, &vkSurfaceCapabilitiesKHR->maxImageExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D.");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxImageArrayLayers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageArrayLayers");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, vkSurfaceCapabilitiesKHR->maxImageArrayLayers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSupportedTransforms", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedTransforms");
            return;
        }

        jobject jsupportedTransforms = createVkSurfaceTransformFlagsKHRAsEnumSet(env, vkSurfaceCapabilitiesKHR->supportedTransforms);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkSurfaceTransformFlagsKHRAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, jsupportedTransforms);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jclass vkSurfaceTransformFlagBitsKHRClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR");
            return;
        }

        methodId = env->GetStaticMethodID(vkSurfaceTransformFlagBitsKHRClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find static method id fromValue");
            return;
        }

        jobject jCurrentTransformEnum = env->CallStaticObjectMethod(vkSurfaceTransformFlagBitsKHRClass, methodId, vkSurfaceCapabilitiesKHR->currentTransform);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setCurrentTransform", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCurrentTransform");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, jCurrentTransformEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSupportedCompositeAlpha", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedCompositeAlpha");
            return;
        }

        jobject jsupportedCompositeAlpha = createVkCompositeAlphaFlagsKHRAsEnumSet(env, vkSurfaceCapabilitiesKHR->supportedCompositeAlpha);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkSurfaceTransformFlagsKHRAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, jsupportedCompositeAlpha);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSupportedUsageFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedUsageFlags");
            return;
        }

        jobject jsupportedUsageFlags = createVkImageUsageFlagsAsEnumSet(env, vkSurfaceCapabilitiesKHR->supportedUsageFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkSurfaceTransformFlagsKHRAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilitiesKHRObject, methodId, jsupportedUsageFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
