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
 * getVkSparseMemoryBind.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: dkaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSparseMemoryBind(
        JNIEnv *env,
        const jobject jVkSparseMemoryBindObject,
		VkSparseMemoryBind *vkSparseMemoryBind,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSparseMemoryBindObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkSparseMemoryBindObject");
            return;
        }

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "getResourceOffset", "()J");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getResourceOffset");
			return;
		}

		jlong resourceOffset = env->CallLongMethod(jVkSparseMemoryBindObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getSize", "()J");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getSize");
			return;
		}

		jlong size = env->CallLongMethod(jVkSparseMemoryBindObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getMemory", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDeviceMemory;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getMemory");
			return;
		}

		jobject jVkDeviceMemory = env->CallObjectMethod(jVkSparseMemoryBindObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkDeviceMemory_T *deviceMemoryHandle = (VkDeviceMemory_T *)jvulkan::getHandleValue(env, jVkDeviceMemory);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not retrieve VkDeviceMemory handle");
	        return;
	    }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getMemoryOffset", "()J");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getMemoryOffset");
			return;
		}

		jlong memoryOffset = env->CallLongMethod(jVkSparseMemoryBindObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getFlags");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkSparseMemoryBindObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkSparseMemoryBindFlags flags = (VkSparseMemoryBindFlags)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSparseMemoryBindFlagBits");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}


		vkSparseMemoryBind->resourceOffset		= resourceOffset;
		vkSparseMemoryBind->size				= size;
		vkSparseMemoryBind->memory				= deviceMemoryHandle;
		vkSparseMemoryBind->memoryOffset		= memoryOffset;
		vkSparseMemoryBind->flags				= flags;
    }
}
