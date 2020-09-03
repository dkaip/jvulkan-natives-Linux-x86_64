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
 * getVkShaderModuleCreateInfo.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: Douglas
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkShaderModuleCreateInfo(
		JNIEnv *env,
		const jobject jVkShaderModuleCreateInfoObject,
		VkShaderModuleCreateInfo *shaderModuleCreateInfo,
		std::vector<void *> *memoryToFree)
	{
		jclass vkShaderModuleCreateInfoClass = env->GetObjectClass(jVkShaderModuleCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get object class for jVkShaderModuleCreateInfoObject");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		int sTypeValue = getSType(env, jVkShaderModuleCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get getSTypeAsInt jVkShaderModuleCreateInfoObject");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkShaderModuleCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkShaderModuleCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get methodId for getFlags");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkShaderModuleCreateInfoObject, methodId);
		int32_t flags = getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderModuleCreateFlagBits");

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkShaderModuleCreateInfoClass, "getCodeSize", "()J");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get methodId for getCodeSize");
			return;
		}

		jlong codeSize = env->CallLongMethod(jVkShaderModuleCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed on CallLongMethod for getCodeSize");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkShaderModuleCreateInfoClass, "getCode", "()[B");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get methodId for getCode");
			return;
		}

		jintArray jcodeArray = (jintArray)env->CallObjectMethod(jVkShaderModuleCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed on CallObjectMethod for getCode");
			return;
		}

		uint32_t *code = nullptr;
		jsize arrayLength = 0;
		if (jcodeArray != nullptr)
		{
			arrayLength = env->GetArrayLength(jcodeArray);

			code = (uint32_t *)calloc(arrayLength, sizeof(int));
			memoryToFree->push_back(code);

			env->GetIntArrayRegion(jcodeArray, 0, arrayLength, (int *)code);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Failed on GetIntArrayRegion for jcodeArray");
				return;
			}
		}

		shaderModuleCreateInfo->sType = (VkStructureType)sTypeValue;
		shaderModuleCreateInfo->pNext = (void *)pNext;
		shaderModuleCreateInfo->flags = flags;
		shaderModuleCreateInfo->codeSize = (size_t)codeSize;
		shaderModuleCreateInfo->pCode = (uint32_t *)code;
	}
}
