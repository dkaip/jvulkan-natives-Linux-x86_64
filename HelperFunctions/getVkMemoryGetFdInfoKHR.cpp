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
 * getVkMemoryGetFdInfoKHR.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkMemoryGetFdInfoKHR(
            JNIEnv *env,
            jobject jVkMemoryGetFdInfoKHR,
			VkMemoryGetFdInfoKHR *vkMemoryGetFdInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkMemoryGetFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkMemoryGetFdInfoKHR");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkMemoryGetFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkMemoryGetFdInfoKHR);
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
        	LOGERROR(env, "%s", "Could not find methodId for getMemory");
            return;
        }

        jobject jVkDeviceMemoryHandle = env->CallObjectMethod(jVkMemoryGetFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkDeviceMemory_T *deviceMemoryHandle = (VkDeviceMemory_T *)jvulkan::getHandleValue(env, jVkDeviceMemoryHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkFence handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalMemoryHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to find method id for getHandleType");
            return;
        }

        jobject jVkExternalMemoryHandleTypeFlagBitsObject = env->CallObjectMethod(jVkMemoryGetFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getHandleType");
            return;
        }

        jclass vkExternalMemoryHandleTypeFlagBitsEnumClass = env->GetObjectClass(jVkExternalMemoryHandleTypeFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkExternalMemoryHandleTypeFlagBitsObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkExternalMemoryHandleTypeFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkExternalMemoryHandleTypeFlagBits vkExternalMemoryHandleTypeFlagBitsEnumValue = (VkExternalMemoryHandleTypeFlagBits)env->CallIntMethod(jVkExternalMemoryHandleTypeFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }


        vkMemoryGetFdInfoKHR->sType 		= sTypeValue;
        vkMemoryGetFdInfoKHR->pNext 		= (void *)pNext;
        vkMemoryGetFdInfoKHR->memory		= deviceMemoryHandle;
        vkMemoryGetFdInfoKHR->handleType = vkExternalMemoryHandleTypeFlagBitsEnumValue;
    }
}
