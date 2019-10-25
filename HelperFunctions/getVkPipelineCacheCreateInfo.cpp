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
 * getVkPipelineCacheCreateInfo.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkPipelineCacheCreateInfo(
			JNIEnv *env,
			jobject jVkPipelineCacheCreateInfoObject,
			VkPipelineCacheCreateInfo *vkPipelineCacheCreateInfo,
			std::vector<void *> *memoryToFree)
	{
		jclass theClass = env->GetObjectClass(jVkPipelineCacheCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get class for jVkPipelineCacheCreateInfoObject");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPipelineCacheCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		jobject jpNextObject = getpNextObject(env, jVkPipelineCacheCreateInfoObject);
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

		jobject flagsObject = env->CallObjectMethod(jVkPipelineCacheCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkPipelineCacheCreateFlags flags = (VkPipelineCacheCreateFlags)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineCacheCreateFlagBits");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getInitialDataSize", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getInitialDataSize");
            return;
        }

        jlong initialDataSize = env->CallLongMethod(jVkPipelineCacheCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getInitialData", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPipelineCache;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getInitialData");
            return;
        }

        jobject jHandle = env->CallObjectMethod(jVkPipelineCacheCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

    	void *handle = (void *)jvulkan::getHandleValue(env, jHandle);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not retrieve jHandle handle");
            return;
        }


		vkPipelineCacheCreateInfo->sType 	= (VkStructureType)sTypeValue;
		vkPipelineCacheCreateInfo->pNext	= (void *)pNext;
		vkPipelineCacheCreateInfo->flags 	= flags;
		vkPipelineCacheCreateInfo->initialDataSize 	= initialDataSize;
		vkPipelineCacheCreateInfo->pInitialData 	= handle;
	}
}
