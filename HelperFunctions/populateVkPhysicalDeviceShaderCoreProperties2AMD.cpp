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
 * populateVkPhysicalDeviceShaderCoreProperties2AMD.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceShaderCoreProperties2AMD(
			JNIEnv *env,
			jobject jVkPhysicalDeviceShaderCoreProperties2AMDObject,
			const VkPhysicalDeviceShaderCoreProperties2AMD *vkPhysicalDeviceShaderCoreProperties2AMD,
			std::vector<void *> *memoryToFree)
	{
		if (jVkPhysicalDeviceShaderCoreProperties2AMDObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkPhysicalDeviceShaderCoreProperties2AMDObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceShaderCoreProperties2AMDObject == nullptr");
			return;
		}

		if (vkPhysicalDeviceShaderCoreProperties2AMD == nullptr)
		{
			LOGERROR(env, "%s", "vkPhysicalDeviceShaderCoreProperties2AMD == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceShaderCoreProperties2AMD == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceShaderCoreProperties2AMDObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceShaderCoreProperties2AMDObject.");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setShaderCoreFeatures", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderCoreFeatures");
            return;
        }

        jobject vkShaderCorePropertiesFlagsAMDEnumSet = createVkShaderCorePropertiesFlagBitsAMDAsEnumSet(env, vkPhysicalDeviceShaderCoreProperties2AMD->shaderCoreFeatures);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSampleCountFlagBitsAsEnumSet");
            return;
        }

        if (vkShaderCorePropertiesFlagsAMDEnumSet == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createVkShaderCorePropertiesFlagBitsAMDAsEnumSet, setShaderCoreFeatures was nullptr");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCoreProperties2AMDObject, methodId, vkShaderCorePropertiesFlagsAMDEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setActiveComputeUnitCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setActiveComputeUnitCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCoreProperties2AMDObject, methodId, vkPhysicalDeviceShaderCoreProperties2AMD->activeComputeUnitCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
