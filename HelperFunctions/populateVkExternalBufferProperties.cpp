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
 * populateVkExternalBufferProperties.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkExternalBufferProperties(
    		JNIEnv *env,
			jobject jVkExternalBufferPropertiesObject,
			const VkExternalBufferProperties *vkExternalBufferProperties)
    {
		if (jVkExternalBufferPropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkExternalBufferPropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkExternalBufferPropertiesObject == nullptr");
			return;
		}

		if (vkExternalBufferProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkExternalBufferProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkExternalBufferProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass vkExternalBufferPropertiesClass = env->GetObjectClass(jVkExternalBufferPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkExternalBufferProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkExternalMemoryProperties",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor.");
            return;
        }

        populateVkExternalMemoryProperties(
        		env,
				theObject,
    			&vkExternalBufferProperties->externalMemoryProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling populateVkExternalMemoryProperties.");
            return;
        }


        jmethodID methodId = env->GetMethodID(vkExternalBufferPropertiesClass, "setExternalMemoryProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExternalMemoryProperties;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExternalMemoryProperties");
            return;
        }

        env->CallVoidMethod(jVkExternalBufferPropertiesObject, methodId, theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        return;
    }
}
