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
 * populateVkExternalImageFormatPropertiesNV.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkExternalImageFormatPropertiesNV(
			JNIEnv *env,
			jobject jVkExternalImageFormatPropertiesNVObject,
			const VkExternalImageFormatPropertiesNV *vkExternalImageFormatPropertiesNV)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkExternalImageFormatPropertiesNVObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/jVkExternalImageFormatPropertiesNVObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
		jobject jVkImageFormatProperties = createVkImageFormatProperties(env, &vkExternalImageFormatPropertiesNV->imageFormatProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkImageFormatProperties.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setImageFormatProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageFormatProperties;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageFormatProperties");
            return;
        }

        env->CallVoidMethod(jVkExternalImageFormatPropertiesNVObject, methodId, jVkImageFormatProperties);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setExternalMemoryFeatures", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExternalMemoryFeatures");
            return;
        }

        jobject vkExternalMemoryFeatureFlagsNV = createVkExternalMemoryFeatureFlagsNVAsEnumSet(env, vkExternalImageFormatPropertiesNV->externalMemoryFeatures);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageUsageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkExternalImageFormatPropertiesNVObject, methodId, vkExternalMemoryFeatureFlagsNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setExportFromImportedHandleTypes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExportFromImportedHandleTypes");
            return;
        }

        jobject vkExternalMemoryHandleTypeFlagsNV = createVkExternalMemoryHandleTypeFlagsNVAsEnumSet(env, vkExternalImageFormatPropertiesNV->exportFromImportedHandleTypes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageUsageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkExternalImageFormatPropertiesNVObject, methodId, vkExternalMemoryHandleTypeFlagsNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setCompatibleHandleTypes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCompatibleHandleTypes");
            return;
        }

        vkExternalMemoryHandleTypeFlagsNV = createVkExternalMemoryHandleTypeFlagsNVAsEnumSet(env, vkExternalImageFormatPropertiesNV->compatibleHandleTypes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageUsageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkExternalImageFormatPropertiesNVObject, methodId, vkExternalMemoryHandleTypeFlagsNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
