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
 * populateVkExtensionProperties.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkExtensionProperties(
    		JNIEnv *env,
			jobject jVkExtensionPropertiesObject,
			const VkExtensionProperties *vkExtensionProperties)
    {
		if (jVkExtensionPropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkExtensionPropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkExtensionPropertiesObject == nullptr");
			return;
		}

		if (vkExtensionProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkExtensionProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkExtensionProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkExtensionPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtensionProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setExtensionName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExtensionName");
            return;
        }

        jstring layerNameString = env->NewStringUTF(vkExtensionProperties->extensionName);

        env->CallVoidMethod(jVkExtensionPropertiesObject, methodId, layerNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(layerNameString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSpecVersion", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSpecVersion");
            return;
        }

        env->CallVoidMethod(jVkExtensionPropertiesObject, methodId, vkExtensionProperties->specVersion);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        return;
    }
}
