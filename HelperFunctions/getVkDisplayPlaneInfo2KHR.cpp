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
 * getVkDisplayPlaneInfo2KHR.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDisplayPlaneInfo2KHR(
            JNIEnv *env,
            jobject jVkDisplayPlaneInfo2KHR,
			VkDisplayPlaneInfo2KHR *vkDisplayPlaneInfo2KHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDisplayPlaneInfo2KHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkDisplayPlaneInfo2KHR");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDisplayPlaneInfo2KHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDisplayPlaneInfo2KHR);
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
        jmethodID methodId = env->GetMethodID(theClass, "getMode", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDisplayModeKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getMode");
            return;
        }

        jobject jVkDisplayModeKHRHandle = env->CallObjectMethod(jVkDisplayPlaneInfo2KHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkDisplayModeKHR_T *displayModeHandle = (VkDisplayModeKHR_T *)jvulkan::getHandleValue(env, jVkDisplayModeKHRHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkDisplayModeKHR handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPlaneIndex", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to find method id for getPlaneIndex");
            return;
        }

        jint planeIndex = env->CallIntMethod(jVkDisplayPlaneInfo2KHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for getPlaneIndex");
            return;
        }


        vkDisplayPlaneInfo2KHR->sType 		= sTypeValue;
        vkDisplayPlaneInfo2KHR->pNext 		= (void *)pNext;
        vkDisplayPlaneInfo2KHR->mode		= displayModeHandle;
        vkDisplayPlaneInfo2KHR->planeIndex	= planeIndex;
    }
}
