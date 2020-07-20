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
 * populateVkPhysicalDeviceImageDrmFormatModifierInfoEXT.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceImageDrmFormatModifierInfoEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject,
			const VkPhysicalDeviceImageDrmFormatModifierInfoEXT *vkPhysicalDeviceImageDrmFormatModifierInfoEXT,
			std::vector<void *> *memoryToFree)
	{
		if (jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject == nullptr");
			return;
		}

		if (vkPhysicalDeviceImageDrmFormatModifierInfoEXT == nullptr)
		{
			LOGERROR(env, "%s", "vkPhysicalDeviceImageDrmFormatModifierInfoEXT == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceImageDrmFormatModifierInfoEXT == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceImageDrmFormatModifierInfoEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setDrmFormatModifier", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDrmFormatModifier");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject, methodId, vkPhysicalDeviceImageDrmFormatModifierInfoEXT->drmFormatModifier);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jclass vkSharingModeClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Enums/VkSharingMode");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Enums/VkSharingMode");
            return;
        }

        methodId = env->GetStaticMethodID(vkSharingModeClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSharingMode;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find static method id fromValue");
            return;
        }

        jobject jsharingModeEnumObject = env->CallStaticObjectMethod(vkSharingModeClass, methodId, vkPhysicalDeviceImageDrmFormatModifierInfoEXT->sharingMode);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setSharingMode", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSharingMode;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSharingMode");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject, methodId, jsharingModeEnumObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setQueueFamilyIndices", "([I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setQueueFamilyIndices");
            return;
        }

        jintArray queueFamilyIndicesObject = env->NewIntArray(vkPhysicalDeviceImageDrmFormatModifierInfoEXT->queueFamilyIndexCount);
        if (queueFamilyIndicesObject == nullptr)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for MaxComputeWorkGroupCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject, methodId, queueFamilyIndicesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->SetIntArrayRegion(queueFamilyIndicesObject, 0, vkPhysicalDeviceImageDrmFormatModifierInfoEXT->queueFamilyIndexCount, (const jint *)vkPhysicalDeviceImageDrmFormatModifierInfoEXT->pQueueFamilyIndices);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetIntArrayRegion");
            return;
        }

	}
}
