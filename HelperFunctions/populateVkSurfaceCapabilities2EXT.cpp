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
 * populateVkSurfaceCapabilities2EXT.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkSurfaceCapabilities2EXT(
			JNIEnv *env,
			jobject jVkSurfaceCapabilities2EXTObject,
			const VkSurfaceCapabilities2EXT *vkSurfaceCapabilities2EXT)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkSurfaceCapabilities2EXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkSurfaceCapabilities2EXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setMinImageCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinImageCount");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, vkSurfaceCapabilities2EXT->minImageCount);
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

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, vkSurfaceCapabilities2EXT->maxImageCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setCurrentImageExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCurrentImageExtent");
            return;
        }

        jobject extent2DObject = createVkExtent2D(env, &vkSurfaceCapabilities2EXT->currentExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D.");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinImageExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinImageExtent");
            return;
        }

        extent2DObject = createVkExtent2D(env, &vkSurfaceCapabilities2EXT->minImageExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D.");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxImageExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageExtent");
            return;
        }

        extent2DObject = createVkExtent2D(env, &vkSurfaceCapabilities2EXT->maxImageExtent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D.");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, extent2DObject);
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

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, vkSurfaceCapabilities2EXT->maxImageArrayLayers);
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

        jobject jsupportedTransforms = createVkSurfaceTransformFlagsKHRAsEnumSet(env, vkSurfaceCapabilities2EXT->supportedTransforms);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSurfaceTransformFlagsKHRAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, jsupportedTransforms);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject jCurrentTransformEnum = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkSurfaceTransformFlagBitsKHR",
				vkSurfaceCapabilities2EXT->currentTransform);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setCurrentTransform", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSurfaceTransformFlagBitsKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCurrentTransform");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, jCurrentTransformEnum);
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

        jobject jsupportedCompositeAlpha = createVkCompositeAlphaFlagsKHRAsEnumSet(env, vkSurfaceCapabilities2EXT->supportedCompositeAlpha);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkCompositeAlphaFlagsKHRAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, jsupportedCompositeAlpha);
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

        jobject jsupportedUsageFlags = createVkImageUsageFlagsAsEnumSet(env, vkSurfaceCapabilities2EXT->supportedUsageFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkImageUsageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, jsupportedUsageFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSupportedSurfaceCounters", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedSurfaceCounters");
            return;
        }

        jobject jsupportedCounters = createVkSurfaceCounterFlagsEXTAsEnumSet(env, vkSurfaceCapabilities2EXT->supportedSurfaceCounters);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSurfaceCounterFlagsEXTAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSurfaceCapabilities2EXTObject, methodId, jsupportedCounters);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
