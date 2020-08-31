/*
 * Copyright 2020 Douglas Kaip
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
 * populateVkImageViewAddressPropertiesNVX.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkImageViewAddressPropertiesNVX(
    		JNIEnv *env,
			jobject jVkImageViewAddressPropertiesNVXObject,
			const VkImageViewAddressPropertiesNVX *vkImageViewAddressPropertiesNVX)
    {
		if (jVkImageViewAddressPropertiesNVXObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkImageViewAddressPropertiesNVXObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkImageViewAddressPropertiesNVXObject == nullptr");
			return;
		}

		if (vkImageViewAddressPropertiesNVX == nullptr)
		{
			LOGERROR(env, "%s", "vkImageViewAddressPropertiesNVX == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkImageViewAddressPropertiesNVX == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkImageViewAddressPropertiesNVXObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/jVkImageViewAddressPropertiesNVXObject");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setDeviceAddress", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDeviceAddress;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceAddress");
            return;
        }

        jobject jVkDeviceAddress = createVulkanHandle(env, "com/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDeviceAddress", (void *)vkImageViewAddressPropertiesNVX->deviceAddress);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
            return;
        }

        env->CallVoidMethod(jVkImageViewAddressPropertiesNVXObject, methodId, jVkDeviceAddress);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSize");
            return;
        }

        env->CallVoidMethod(jVkImageViewAddressPropertiesNVXObject, methodId, vkImageViewAddressPropertiesNVX->size);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        return;
    }
}
