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
 * getVkDedicatedAllocationMemoryAllocateInfoNV.cpp
 *
 *  Created on: May 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDedicatedAllocationMemoryAllocateInfoNV(
            JNIEnv *env,
            const jobject jVkDedicatedAllocationMemoryAllocateInfoNVObject,
			VkDedicatedAllocationMemoryAllocateInfoNV *vkDedicatedAllocationMemoryAllocateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDedicatedAllocationMemoryAllocateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDedicatedAllocationMemoryAllocateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkDedicatedAllocationMemoryAllocateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDedicatedAllocationMemoryAllocateInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getImage", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkImage;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getImage method Id");
            return;
        }

        jobject jVkImageObject = env->CallObjectMethod(jVkDedicatedAllocationMemoryAllocateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getImage");
            return;
        }

        VkImage_T *vkImageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jVkImageObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getBuffer method Id");
            return;
        }

        jobject jVkBufferObject = env->CallObjectMethod(jVkDedicatedAllocationMemoryAllocateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getBuffer");
            return;
        }

        VkBuffer_T *vkBufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }


        vkDedicatedAllocationMemoryAllocateInfoNV->sType = sTypeValue;
        vkDedicatedAllocationMemoryAllocateInfoNV->pNext = pNext;
        vkDedicatedAllocationMemoryAllocateInfoNV->image = vkImageHandle;
        vkDedicatedAllocationMemoryAllocateInfoNV->buffer = vkBufferHandle;
    }
}
