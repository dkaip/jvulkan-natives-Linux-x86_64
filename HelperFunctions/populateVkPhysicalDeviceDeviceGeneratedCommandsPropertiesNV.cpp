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
 * populateVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(
			JNIEnv *env,
			jobject jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject,
			const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV *vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setMaxGraphicsShaderGroupCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGraphicsShaderGroupCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject, methodId, vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV->maxGraphicsShaderGroupCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxIndirectSequenceCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxIndirectSequenceCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject, methodId, vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV->maxIndirectSequenceCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxIndirectCommandsTokenCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxIndirectCommandsTokenCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject, methodId, vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV->maxIndirectCommandsTokenCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxIndirectCommandsStreamCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxIndirectCommandsStreamCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject, methodId, vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV->maxIndirectCommandsStreamCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxIndirectCommandsTokenOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxIndirectCommandsTokenOffset");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject, methodId, vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV->maxIndirectCommandsTokenOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxIndirectCommandsStreamStride", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxIndirectCommandsStreamStride");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject, methodId, vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV->maxIndirectCommandsStreamStride);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinSequencesCountBufferOffsetAlignment", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinSequencesCountBufferOffsetAlignment");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject, methodId, vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV->minSequencesCountBufferOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinSequencesIndexBufferOffsetAlignment", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinSequencesIndexBufferOffsetAlignment");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject, methodId, vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV->minSequencesIndexBufferOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinIndirectCommandsBufferOffsetAlignment", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinIndirectCommandsBufferOffsetAlignment");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNVObject, methodId, vkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV->minIndirectCommandsBufferOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
