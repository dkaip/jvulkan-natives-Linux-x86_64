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
 * getVkExternalFormatANDROID.cpp
 *
 *  Created on: Oct 25, 2019
 *      Author: Douglas Kaip
 */

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <vulkan/vulkan_android.h>
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkExternalFormatANDROID(
			JNIEnv *env,
			jobject jVkExternalFormatANDROIDObject,
			VkExternalFormatANDROID *vkExternalFormatANDROID,
			std::vector<void *> *memoryToFree)
	{
		jclass theClass = env->GetObjectClass(jVkExternalFormatANDROIDObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get class for jVkExternalFormatANDROIDObject");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkExternalFormatANDROIDObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkExternalFormatANDROIDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getExternalFormat", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getExternalFormat");
            return;
        }

        jlong externalFormat = env->CallLongMethod(jVkExternalFormatANDROIDObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
        	return;
        }

        vkExternalFormatANDROID->sType 	= (VkStructureType)sTypeValue;
        vkExternalFormatANDROID->pNext	= (void *)pNext;
        vkExternalFormatANDROID->externalFormat = (uint64_t)externalFormat;
	}
}
