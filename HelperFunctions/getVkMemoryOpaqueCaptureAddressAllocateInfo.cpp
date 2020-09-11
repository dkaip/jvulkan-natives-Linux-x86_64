/*
 * Copyright 2020 Douglas Kaip
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
 * getVkMemoryOpaqueCaptureAddressAllocateInfo.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkMemoryOpaqueCaptureAddressAllocateInfo(
            JNIEnv *env,
            jobject jVkMemoryOpaqueCaptureAddressAllocateInfoObject,
			VkMemoryOpaqueCaptureAddressAllocateInfo *vkMemoryOpaqueCaptureAddressAllocateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkMemoryOpaqueCaptureAddressAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkMemoryOpaqueCaptureAddressAllocateInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkMemoryOpaqueCaptureAddressAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkMemoryOpaqueCaptureAddressAllocateInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getOpaqueCaptureAddress", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VulkanHandle;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getOpaqueCaptureAddress");
            return;
        }

        jobject jVulkanHandleObject = env->CallObjectMethod(jVkMemoryOpaqueCaptureAddressAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        uint64_t opaqueCaptureAddress = (uint64_t)jvulkan::getHandleValue(env, jVulkanHandleObject);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkFence handle");
    		return;
    	}


    	vkMemoryOpaqueCaptureAddressAllocateInfo->sType 	= sTypeValue;
    	vkMemoryOpaqueCaptureAddressAllocateInfo->pNext 	= (void *)pNext;
    	vkMemoryOpaqueCaptureAddressAllocateInfo->opaqueCaptureAddress = opaqueCaptureAddress;
    }
}
