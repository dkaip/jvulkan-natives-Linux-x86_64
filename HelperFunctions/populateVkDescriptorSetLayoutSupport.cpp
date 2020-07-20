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
 * populateVkDescriptorSetLayoutSupport.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkDescriptorSetLayoutSupport(
    		JNIEnv *env,
			jobject jVkDescriptorSetLayoutSupportObject,
			const VkDescriptorSetLayoutSupport *vkDescriptorSetLayoutSupport)
    {
		if (jVkDescriptorSetLayoutSupportObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkDescriptorSetLayoutSupportObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkDescriptorSetLayoutSupportObject == nullptr");
			return;
		}

		if (vkDescriptorSetLayoutSupport == nullptr)
		{
			LOGERROR(env, "%s", "vkDescriptorSetLayoutSupport == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkDescriptorSetLayoutSupport == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkDescriptorSetLayoutSupportObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkDescriptorSetLayoutSupport");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setSupported", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupported");
            return;
        }

        env->CallVoidMethod(jVkDescriptorSetLayoutSupportObject, methodId, vkDescriptorSetLayoutSupport->supported);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
    }
}
