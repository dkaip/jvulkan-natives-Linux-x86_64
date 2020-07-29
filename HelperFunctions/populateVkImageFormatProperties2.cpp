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
 * populateVkImageFormatProperties2.cpp
 *
 *  Created on: Jun 3, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkImageFormatProperties2(
			JNIEnv *env,
			jobject jVkImageFormatProperties2Object,
			const VkImageFormatProperties2 *vkImageFormatProperties2)
	{
		if (jVkImageFormatProperties2Object == nullptr)
		{
			LOGERROR(env, "%s", "jVkImageFormatProperties2Object == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkImageFormatProperties2Object == nullptr");
			return;
		}

		if (vkImageFormatProperties2 == nullptr)
		{
			LOGERROR(env, "%s", "vkImageFormatProperties2 == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkImageFormatProperties2 == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkImageFormatProperties2Object);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkImageFormatProperties2");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setImageFormatProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageFormatProperties;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageFormatProperties");
            return;
        }

    	jobject jVkImageFormatPropertiesObject = createVkImageFormatProperties(
    			env,
    			&(vkImageFormatProperties2->imageFormatProperties));
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkImageFormatProperties");
        	return;
        }

        env->CallVoidMethod(jVkImageFormatProperties2Object, methodId, jVkImageFormatPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
