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
 * populateVkImageViewHandleInfoNVX.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkImageViewHandleInfoNVX(
			JNIEnv *env,
			jobject jVkImageViewHandleInfoNVXObject,
			VkImageViewHandleInfoNVX const *vkImageViewHandleInfoNVX)
	{
        jclass theClass = env->GetObjectClass(jVkImageViewHandleInfoNVXObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/jVkImageViewHandleInfoNVXObject");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setImageView", "(Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImageView;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageView");
            return;
        }

        jobject jVkImageView = createVulkanHandle(env, "com/CIMthetics/jvulkan/VulkanCore/Handles/VkImageView", (void *)vkImageViewHandleInfoNVX->imageView);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
            return;
        }

        env->CallVoidMethod(jVkImageViewHandleInfoNVXObject, methodId, jVkImageView);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDescriptorType", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkDescriptorType;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDescriptorType");
            return;
        }


    	jobject jVkDescriptorType = createEnumFromValue(env, "com/CIMthetics/jvulkan/VulkanCore/Enums/VkDescriptorType", (int)vkImageViewHandleInfoNVX->descriptorType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return;
        }

        env->CallVoidMethod(jVkImageViewHandleInfoNVXObject, methodId, jVkDescriptorType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSampler", "(Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkSampler;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSampler");
            return;
        }

        jobject jVkSampler = createVulkanHandle(env, "com/CIMthetics/jvulkan/VulkanCore/Handles/VkSampler", (void *)vkImageViewHandleInfoNVX->sampler);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
            return;
        }

        env->CallVoidMethod(jVkImageViewHandleInfoNVXObject, methodId, jVkSampler);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
