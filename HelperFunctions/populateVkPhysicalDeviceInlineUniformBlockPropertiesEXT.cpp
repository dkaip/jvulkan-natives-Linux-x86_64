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
 * populateVkPhysicalDeviceInlineUniformBlockPropertiesEXT.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceInlineUniformBlockPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceInlineUniformBlockPropertiesEXTObject,
			const VkPhysicalDeviceInlineUniformBlockPropertiesEXT *vkPhysicalDeviceInlineUniformBlockPropertiesEXT,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceInlineUniformBlockPropertiesEXTClass = env->GetObjectClass(
				jVkPhysicalDeviceInlineUniformBlockPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/jVkPhysicalDeviceInlineUniformBlockPropertiesEXTObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceInlineUniformBlockPropertiesEXTClass, "setMaxInlineUniformBlockSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxInlineUniformBlockSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceInlineUniformBlockPropertiesEXTObject, methodId, vkPhysicalDeviceInlineUniformBlockPropertiesEXT->maxInlineUniformBlockSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceInlineUniformBlockPropertiesEXTClass, "setMaxPerStageDescriptorInlineUniformBlocks", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorInlineUniformBlocks");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceInlineUniformBlockPropertiesEXTObject, methodId, vkPhysicalDeviceInlineUniformBlockPropertiesEXT->maxPerStageDescriptorInlineUniformBlocks);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceInlineUniformBlockPropertiesEXTClass, "setMaxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorUpdateAfterBindInlineUniformBlocks");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceInlineUniformBlockPropertiesEXTObject, methodId, vkPhysicalDeviceInlineUniformBlockPropertiesEXT->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceInlineUniformBlockPropertiesEXTClass, "setMaxDescriptorSetInlineUniformBlocks", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetInlineUniformBlocks");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceInlineUniformBlockPropertiesEXTObject, methodId, vkPhysicalDeviceInlineUniformBlockPropertiesEXT->maxDescriptorSetInlineUniformBlocks);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceInlineUniformBlockPropertiesEXTClass, "setMaxDescriptorSetUpdateAfterBindInlineUniformBlocks", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUpdateAfterBindInlineUniformBlocks");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceInlineUniformBlockPropertiesEXTObject, methodId, vkPhysicalDeviceInlineUniformBlockPropertiesEXT->maxDescriptorSetUpdateAfterBindInlineUniformBlocks);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}
