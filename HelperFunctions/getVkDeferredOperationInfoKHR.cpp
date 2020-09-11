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
 * getVkDeferredOperationInfoKHR.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDeferredOperationInfoKHR(
            JNIEnv *env,
            jobject jVkDeferredOperationInfoKHRObject,
			VkDeferredOperationInfoKHR *vkDeferredOperationInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDeferredOperationInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkDeferredOperationInfoKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDeferredOperationInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDeferredOperationInfoKHRObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getOperationHandle", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDeferredOperationKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getOperationHandle");
            return;
        }

        jobject jVkDeferredOperationKHRObject = env->CallObjectMethod(jVkDeferredOperationInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkDeferredOperationKHR_T *operationHandle = (VkDeferredOperationKHR_T *)jvulkan::getHandleValue(env, jVkDeferredOperationKHRObject);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkFence handle");
    		return;
    	}


    	vkDeferredOperationInfoKHR->sType 	= sTypeValue;
    	vkDeferredOperationInfoKHR->pNext 	= (void *)pNext;
    	vkDeferredOperationInfoKHR->operationHandle	= operationHandle;
    }
}
