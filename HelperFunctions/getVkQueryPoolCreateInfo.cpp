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
 * getVkQueryPoolCreateInfo.cpp
 *
 *  Created on: Oct 25, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkQueryPoolCreateInfo(
			JNIEnv *env,
			jobject jVkQueryPoolCreateInfoObject,
			VkQueryPoolCreateInfo *vkQueryPoolCreateInfo,
			std::vector<void *> *memoryToFree)
	{
		jclass theClass = env->GetObjectClass(jVkQueryPoolCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get class for jVkQueryPoolCreateInfoObject");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkQueryPoolCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		jobject jpNextObject = getpNextObject(env, jVkQueryPoolCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getpNext failed.");
			return;
		}

		void *pNext = nullptr;
		if (jpNextObject != nullptr)
		{
			LOGERROR(env, "%s", "pNext must be NULL");
		}

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getFlags");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkQueryPoolCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkQueryPoolCreateFlags flags = (VkQueryPoolCreateFlags)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkQueryPoolCreateFlagBits");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getQueryType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkQueryType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getQueryType");
            return;
        }

        jobject jVkQueryTypeObject = env->CallObjectMethod(jVkQueryPoolCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkImageLayoutTypeObjectEnumClass = env->GetObjectClass(jVkQueryTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkQueryType vkQueryTypeEnumValue = (VkQueryType)env->CallIntMethod(jVkQueryTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getQueryCount", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getQueryCount");
            return;
        }

        jint queryCount = env->CallLongMethod(jVkQueryPoolCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getPipelineStatistics", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getPipelineStatistics");
			return;
		}

		jobject pipelineStatisticsObject = env->CallObjectMethod(jVkQueryPoolCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkQueryPipelineStatisticFlags pipelineStatistics = (VkQueryPipelineStatisticFlags)getEnumSetValue(
				env,
				pipelineStatisticsObject,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkQueryPipelineStatisticFlagBits");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}


        vkQueryPoolCreateInfo->sType 	= (VkStructureType)sTypeValue;
        vkQueryPoolCreateInfo->pNext	= (void *)pNext;
        vkQueryPoolCreateInfo->flags 	= flags;
        vkQueryPoolCreateInfo->queryType = vkQueryTypeEnumValue;
        vkQueryPoolCreateInfo->queryCount = queryCount;
        vkQueryPoolCreateInfo->pipelineStatistics = pipelineStatistics;
	}
}
