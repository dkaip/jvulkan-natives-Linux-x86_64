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
 * getVkDeviceMemoryOpaqueCaptureAddressInfo.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDeviceMemoryOpaqueCaptureAddressInfo(
            JNIEnv *env,
            const jobject jVkDeviceMemoryOpaqueCaptureAddressInfoObject,
			VkDeviceMemoryOpaqueCaptureAddressInfo *vkDeviceMemoryOpaqueCaptureAddressInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDeviceMemoryOpaqueCaptureAddressInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDeviceMemoryOpaqueCaptureAddressInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDeviceMemoryOpaqueCaptureAddressInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDeviceMemoryOpaqueCaptureAddressInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (jpNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getMemory", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDeviceMemory;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getMemory");
            return;
        }

        jobject jVkDeviceMemoryHandle = env->CallObjectMethod(jVkDeviceMemoryOpaqueCaptureAddressInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkDeviceMemory_T *memoryHandle = (VkDeviceMemory_T *)jvulkan::getHandleValue(env, jVkDeviceMemoryHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkDeviceMemory handle");
    		return;
    	}


    	vkDeviceMemoryOpaqueCaptureAddressInfo->sType 		= sTypeValue;
    	vkDeviceMemoryOpaqueCaptureAddressInfo->pNext 		= pNext;
    	vkDeviceMemoryOpaqueCaptureAddressInfo->memory		= memoryHandle;
    }
}
