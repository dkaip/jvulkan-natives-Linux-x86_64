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
 * getVkSemaphoreSignalInfo.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSemaphoreSignalInfo(
            JNIEnv *env,
            jobject jVkSemaphoreSignalInfo,
			VkSemaphoreSignalInfo *vkSemaphoreSignalInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSemaphoreSignalInfo);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkSemaphoreSignalInfo");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkSemaphoreSignalInfo);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSemaphoreSignalInfo);
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
        	LOGERROR(env, "%s", "Could not find method id for getSemaphore");
			return;
		}

		jobject jVkSemaphore = env->CallObjectMethod(jVkSemaphoreSignalInfo, methodId);
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

        jlong value = env->CallLongMethod(jVkSemaphoreSignalInfo, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        vkSemaphoreSignalInfo->sType 		= sTypeValue;
        vkSemaphoreSignalInfo->pNext 		= (void *)pNext;
        vkSemaphoreSignalInfo->semaphore	= semaphoreHandle;
        vkSemaphoreSignalInfo->value		= value;
    }
}
