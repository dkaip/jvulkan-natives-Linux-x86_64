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
 * getVkSparseImageMemoryBind.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSparseImageMemoryBind(
        JNIEnv *env,
        const jobject jVkSparseImageMemoryBindObject,
		VkSparseImageMemoryBind *vkSparseImageMemoryBind,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSparseImageMemoryBindObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkSparseImageMemoryBindObject");
            return;
        }

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "getSubresource", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkImageSubresource;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getSubresource");
			return;
		}

		jobject jSubresourceObject = env->CallObjectMethod(jVkSparseImageMemoryBindObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

	    getVkImageSubresource(
	            env,
				jSubresourceObject,
				&vkSparseImageMemoryBind->subresource,
	            memoryToFree);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Error calling getVkImageSubresource.");
	        return;
	    }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getOffset", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkOffset3D;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getOffset");
			return;
		}

		jobject jOffsetObject = env->CallObjectMethod(jVkSparseImageMemoryBindObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

	    getVkOffset3D(
	            env,
				jOffsetObject,
				&vkSparseImageMemoryBind->offset,
	            memoryToFree);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Error calling getVkOffset3D.");
	        return;
	    }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getExtent", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent3D;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getExtent");
			return;
		}

		jobject jExtentObject = env->CallObjectMethod(jVkSparseImageMemoryBindObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

	    getVkExtent3D(
	            env,
				jExtentObject,
				&vkSparseImageMemoryBind->extent,
	            memoryToFree);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Error calling getVkExtent3D.");
	        return;
	    }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getMemory", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDeviceMemory;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getMemory");
			return;
		}

		jobject jVkDeviceMemory = env->CallObjectMethod(jVkSparseImageMemoryBindObject, methodId);
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

		jlong memoryOffset = env->CallLongMethod(jVkSparseImageMemoryBindObject, methodId);
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

		jobject flagsObject = env->CallObjectMethod(jVkSparseImageMemoryBindObject, methodId);
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


		vkSparseImageMemoryBind->memory				= deviceMemoryHandle;
		vkSparseImageMemoryBind->memoryOffset		= memoryOffset;
		vkSparseImageMemoryBind->flags				= flags;
    }
}
