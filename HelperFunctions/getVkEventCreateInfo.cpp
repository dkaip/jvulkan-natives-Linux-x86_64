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
 * getVkEventCreateInfo.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkEventCreateInfo(
			JNIEnv *env,
			jobject jVkEventCreateInfoObject,
			VkEventCreateInfo *vkEventCreateInfo,
			std::vector<void *> *memoryToFree)
	{
		jclass theClass = env->GetObjectClass(jVkEventCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get class for jVkEventCreateInfoObject");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkEventCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		jobject jpNextObject = getpNextObject(env, jVkEventCreateInfoObject);
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

		jobject flagsObject = env->CallObjectMethod(jVkEventCreateInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkEventCreateFlags flags = (VkEventCreateFlags)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkEventCreateFlagBits");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}


		vkEventCreateInfo->sType 	= (VkStructureType)sTypeValue;
		vkEventCreateInfo->pNext	= (void *)pNext;
		vkEventCreateInfo->flags 	= flags;
	}
}
