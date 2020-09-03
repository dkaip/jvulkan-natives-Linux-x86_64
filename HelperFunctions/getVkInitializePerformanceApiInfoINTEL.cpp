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
 * getVkInitializePerformanceApiInfoINTEL.cpp
 *
 *  Created on: Sep 1, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkInitializePerformanceApiInfoINTEL(
            JNIEnv *env,
            jobject jVkInitializePerformanceApiInfoINTEL,
			VkInitializePerformanceApiInfoINTEL *vkInitializePerformanceApiInfoINTEL,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkInitializePerformanceApiInfoINTEL);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkInitializePerformanceApiInfoINTEL");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkInitializePerformanceApiInfoINTEL);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkInitializePerformanceApiInfoINTEL);
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
        jmethodID methodId = env->GetMethodID(theClass, "getUserData", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VulkanHandle;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getUserData");
            return;
        }

        jobject jUserDataHandle = env->CallObjectMethod(jVkInitializePerformanceApiInfoINTEL, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        void *userData = (void *)jvulkan::getHandleValue(env, jUserDataHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkFence handle");
    		return;
    	}


    	vkInitializePerformanceApiInfoINTEL->sType 		= sTypeValue;
    	vkInitializePerformanceApiInfoINTEL->pNext 		= (void *)pNext;
    	vkInitializePerformanceApiInfoINTEL->pUserData  = userData;
    }
}

