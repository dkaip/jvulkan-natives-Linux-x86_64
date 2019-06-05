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
 * populateVkPhysicalDeviceExternalImageFormatInfo.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceExternalImageFormatInfo(
			JNIEnv *env,
			jobject jVkPhysicalDeviceExternalImageFormatInfoObject,
			const VkPhysicalDeviceExternalImageFormatInfo *vkPhysicalDeviceExternalImageFormatInfo,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceExternalImageFormatInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkImageFormatProperties2");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jclass vkExternalMemoryHandleTypeFlagBitsClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkExternalMemoryHandleTypeFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkExternalMemoryHandleTypeFlagBits");
            return;
        }

        jmethodID methodId = env->GetStaticMethodID(vkExternalMemoryHandleTypeFlagBitsClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkExternalMemoryHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find static method id fromValue");
            return;
        }

        jobject jhandleTypeEnumObject = env->CallStaticObjectMethod(vkExternalMemoryHandleTypeFlagBitsClass, methodId, vkPhysicalDeviceExternalImageFormatInfo->handleType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setHandleType", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkExternalMemoryHandleTypeFlagBits;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setHandleType");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceExternalImageFormatInfoObject, methodId, jhandleTypeEnumObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}
