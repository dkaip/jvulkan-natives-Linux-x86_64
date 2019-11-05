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
 * populateVkSparseImageFormatProperties.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkSparseImageFormatProperties(
    		JNIEnv *env,
			jobject jVkSparseImageFormatPropertiesObject,
			const VkSparseImageFormatProperties *vkSparseImageFormatProperties)
    {
		if (jVkSparseImageFormatPropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkSparseImageFormatPropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkSparseImageFormatPropertiesObject == nullptr");
			return;
		}

		if (vkSparseImageFormatProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkSparseImageFormatProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkSparseImageFormatProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkSparseImageFormatPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSparseImageFormatProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setAspectMask", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setAspectMask");
            return;
        }

        jobject jAspectMask = createVkImageAspectFlagsAsEnumSet(env, vkSparseImageFormatProperties->aspectMask);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkImageAspectFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSparseImageFormatPropertiesObject, methodId, jAspectMask);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setImageGranularity", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent3D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageGranularity");
            return;
        }

        jobject extent2DObject = createVkExtent3D(env, &vkSparseImageFormatProperties->imageGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent3D.");
            return;
        }

        env->CallVoidMethod(jVkSparseImageFormatPropertiesObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFlags");
            return;
        }

        jobject jFlags = createVkSparseImageFormatFlagsAsEnumSet(env, vkSparseImageFormatProperties->flags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSparseImageFormatFlagBitsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkSparseImageFormatPropertiesObject, methodId, jFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
    }
}
