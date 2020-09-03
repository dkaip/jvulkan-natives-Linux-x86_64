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
 * getVkDedicatedAllocationBufferCreateInfoNV.cpp
 *
 *  Created on: May 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDedicatedAllocationBufferCreateInfoNV(
            JNIEnv *env,
            const jobject jVkDedicatedAllocationBufferCreateInfoNVObject,
			VkDedicatedAllocationBufferCreateInfoNV *vkDedicatedAllocationBufferCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDedicatedAllocationBufferCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDedicatedAllocationBufferCreateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkDedicatedAllocationBufferCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDedicatedAllocationBufferCreateInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isStorageBuffer8BitAccess", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStorageBuffer8BitAccess");
            return;
        }

        jboolean dedicatedAllocation = env->CallBooleanMethod(jVkDedicatedAllocationBufferCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkDedicatedAllocationBufferCreateInfoNV->sType = sTypeValue;
        vkDedicatedAllocationBufferCreateInfoNV->pNext = pNext;
        vkDedicatedAllocationBufferCreateInfoNV->dedicatedAllocation = dedicatedAllocation;
    }
}
