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
 * getVkMappedMemoryRange.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkMappedMemoryRange(
            JNIEnv *env,
            const jobject jVkMappedMemoryRangeObject,
			VkMappedMemoryRange *vkMappedMemoryRange,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkMappedMemoryRangeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkMappedMemoryRangeObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkMappedMemoryRangeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkMappedMemoryRangeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getMemory", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDeviceMemory;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id for getMemory");
			return;
		}

		jobject jVulkanHandleObject = env->CallObjectMethod(jVkMappedMemoryRangeObject, methodId);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkDeviceMemory vkDeviceMemoryHandle = (VkDeviceMemory)jvulkan::getHandleValue(env, jVulkanHandleObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not retrieve VkDeviceMemory handle");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getOffset", "()J");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id for getOffset");
			return;
		}

		jlong offset = env->CallLongMethod(jVkMappedMemoryRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSize", "()J");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id for getSize");
			return;
		}

		jlong size = env->CallLongMethod(jVkMappedMemoryRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }


        vkMappedMemoryRange->sType 	= sTypeValue;
        vkMappedMemoryRange->pNext 	= pNext;
        vkMappedMemoryRange->memory = vkDeviceMemoryHandle;
        vkMappedMemoryRange->offset = offset;
        vkMappedMemoryRange->size  	= size;
    }
}
