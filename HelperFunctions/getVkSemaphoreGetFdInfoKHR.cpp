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
 * getVkSemaphoreGetFdInfoKHR.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSemaphoreGetFdInfoKHR(
            JNIEnv *env,
            jobject jVkSemaphoreGetFdInfoKHR,
			VkSemaphoreGetFdInfoKHR *vkSemaphoreGetFdInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSemaphoreGetFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkSemaphoreGetFdInfoKHR");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkSemaphoreGetFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSemaphoreGetFdInfoKHR);
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
        jmethodID methodId = env->GetMethodID(theClass, "getSemaphore", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkSemaphore;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getSemaphore");
            return;
        }

        jobject jVkSemaphoreHandle = env->CallObjectMethod(jVkSemaphoreGetFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkSemaphore_T *semaphoreHandle = (VkSemaphore_T *)jvulkan::getHandleValue(env, jVkSemaphoreHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkSemaphore handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalSemaphoreHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to find method id for getHandleType");
            return;
        }

        jobject jVkExternalSemaphoreHandleTypeFlagBitsObject = env->CallObjectMethod(jVkSemaphoreGetFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getHandleType");
            return;
        }

        jclass vkExternalSemaphoreHandleTypeFlagBitsEnumClass = env->GetObjectClass(jVkExternalSemaphoreHandleTypeFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkExternalSemaphoreHandleTypeFlagBitsObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkExternalSemaphoreHandleTypeFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkExternalSemaphoreHandleTypeFlagBits vkExternalSemaphoreHandleTypeFlagBitsEnumValue = (VkExternalSemaphoreHandleTypeFlagBits)env->CallIntMethod(jVkExternalSemaphoreHandleTypeFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }


        vkSemaphoreGetFdInfoKHR->sType 		= sTypeValue;
        vkSemaphoreGetFdInfoKHR->pNext 		= (void *)pNext;
        vkSemaphoreGetFdInfoKHR->semaphore	= semaphoreHandle;
        vkSemaphoreGetFdInfoKHR->handleType = vkExternalSemaphoreHandleTypeFlagBitsEnumValue;
    }
}
