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
 * populateVkPhysicalDeviceShaderCorePropertiesAMD.cpp
 *
 *  Created on: May 13, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceShaderCorePropertiesAMD(
		JNIEnv *env,
		jobject jVkPhysicalDeviceShaderCorePropertiesAMDObject,
		const VkPhysicalDeviceShaderCorePropertiesAMD* vkPhysicalDeviceShaderCorePropertiesAMD,
		std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceShaderCorePropertiesAMDClass = env->GetObjectClass(
				jVkPhysicalDeviceShaderCorePropertiesAMDObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceShaderCorePropertiesAMD");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setShaderEngineCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderEngineCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->shaderEngineCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setShaderArraysPerEngineCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderArraysPerEngineCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->shaderArraysPerEngineCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setComputeUnitsPerShaderArray", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setComputeUnitsPerShaderArray");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->computeUnitsPerShaderArray);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setSimdPerComputeUnit", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSimdPerComputeUnit");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->simdPerComputeUnit);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setWavefrontsPerSimd", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setWavefrontsPerSimd");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->wavefrontsPerSimd);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setWavefrontSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setWavefrontSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->wavefrontSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setSgprsPerSimd", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSgprsPerSimd");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->sgprsPerSimd);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setMinSgprAllocation", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinSgprAllocation");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->minSgprAllocation);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setMaxSgprAllocation", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSgprAllocation");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->maxSgprAllocation);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setSgprAllocationGranularity", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSgprAllocationGranularity");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->sgprAllocationGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setVgprsPerSimd", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setVgprsPerSimd");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->vgprsPerSimd);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setMinVgprAllocation", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinVgprAllocation");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->minVgprAllocation);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setMaxVgprAllocation", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVgprAllocation");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->maxVgprAllocation);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceShaderCorePropertiesAMDClass, "setVgprAllocationGranularity", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setVgprAllocationGranularity");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShaderCorePropertiesAMDObject, methodId, vkPhysicalDeviceShaderCorePropertiesAMD->vgprAllocationGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}

