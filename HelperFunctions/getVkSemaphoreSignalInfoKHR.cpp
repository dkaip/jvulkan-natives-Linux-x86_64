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
 * getVkSemaphoreSignalInfoKHR.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSemaphoreSignalInfoKHR(
            JNIEnv *env,
            jobject jVkSemaphoreSignalInfoKHR,
			VkSemaphoreSignalInfoKHR *vkSemaphoreSignalInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSemaphoreSignalInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkSemaphoreSignalInfoKHR");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkSemaphoreSignalInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSemaphoreSignalInfoKHR);
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
		jmethodID methodId = env->GetMethodID(theClass, "getSemaphore", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkSemaphore;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getSemaphore");
			return;
		}

		jobject jVkSemaphore = env->CallObjectMethod(jVkSemaphoreSignalInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkSemaphore_T *semaphoreHandle = (VkSemaphore_T *)jvulkan::getHandleValue(env, jVkSemaphore);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not retrieve VkSemaphore handle");
	        return;
	    }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getValue", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getValue");
            return;
        }

        jlong value = env->CallLongMethod(jVkSemaphoreSignalInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        vkSemaphoreSignalInfoKHR->sType 		= sTypeValue;
        vkSemaphoreSignalInfoKHR->pNext 		= (void *)pNext;
        vkSemaphoreSignalInfoKHR->semaphore	= semaphoreHandle;
        vkSemaphoreSignalInfoKHR->value		= value;
    }
}
