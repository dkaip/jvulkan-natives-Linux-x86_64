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
 * populateVkImageFormatPropertiesObject.cpp
 *
 *  Created on: Jun 3, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkImageFormatProperties(
			JNIEnv *env,
			jobject jVkImageFormatPropertiesObject,
			const VkImageFormatProperties *vkImageFormatProperties,
			std::vector<void *> *memoryToFree)
	{
		if (jVkImageFormatPropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkImageFormatPropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkImageFormatPropertiesObject == nullptr");
			return;
		}

		if (vkImageFormatProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkImageFormatProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkImageFormatProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkImageFormatPropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkImageFormatProperties");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setMaxExtent", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxExtent");
            return;
        }

	    jobject extent3DObject = createVkExtent3D(env, &(vkImageFormatProperties->maxExtent));
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return;
        }

        env->CallVoidMethod(jVkImageFormatPropertiesObject, methodId, extent3DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxMipLevels", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMipLevels");
            return;
        }

        env->CallVoidMethod(jVkImageFormatPropertiesObject, methodId, vkImageFormatProperties->maxMipLevels);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxArrayLayers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxArrayLayers");
            return;
        }

        env->CallVoidMethod(jVkImageFormatPropertiesObject, methodId, vkImageFormatProperties->maxArrayLayers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSampleCounts");
            return;
        }

        jobject vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, vkImageFormatProperties->sampleCounts);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSampleCountFlagBitsAsEnumSet");
            return;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createVkSampleCountFlagBitsAsEnumSet, vkSampleCountFlagBitsEnumSet was nullptr");
            return;
        }

        env->CallVoidMethod(jVkImageFormatPropertiesObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxResourceSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxResourceSize");
            return;
        }

        env->CallVoidMethod(jVkImageFormatPropertiesObject, methodId, vkImageFormatProperties->maxResourceSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
