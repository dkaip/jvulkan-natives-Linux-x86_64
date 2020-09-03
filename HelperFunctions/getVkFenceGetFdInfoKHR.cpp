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
 * getVkFenceGetFdInfoKHR.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkFenceGetFdInfoKHR(
            JNIEnv *env,
            jobject jVkFenceGetFdInfoKHR,
			VkFenceGetFdInfoKHR *vkFenceGetFdInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkFenceGetFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkFenceGetFdInfoKHR");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkFenceGetFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkFenceGetFdInfoKHR);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFence", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkFence;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getFence");
            return;
        }

        jobject jVkFenceHandle = env->CallObjectMethod(jVkFenceGetFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkFence_T *fenceHandle = (VkFence_T *)jvulkan::getHandleValue(env, jVkFenceHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkFence handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalFenceHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to find method id for getHandleType");
            return;
        }

        jobject jVkExternalFenceHandleTypeFlagBitsObject = env->CallObjectMethod(jVkFenceGetFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getHandleType");
            return;
        }

        jclass vkExternalFenceHandleTypeFlagBitsEnumClass = env->GetObjectClass(jVkExternalFenceHandleTypeFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkExternalSemaphoreHandleTypeFlagBitsObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkExternalFenceHandleTypeFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkExternalFenceHandleTypeFlagBits vkExternalFenceHandleTypeFlagBitsEnumValue = (VkExternalFenceHandleTypeFlagBits)env->CallIntMethod(jVkExternalFenceHandleTypeFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }


        vkFenceGetFdInfoKHR->sType 		= sTypeValue;
        vkFenceGetFdInfoKHR->pNext 		= (void *)pNext;
        vkFenceGetFdInfoKHR->fence		= fenceHandle;
        vkFenceGetFdInfoKHR->handleType = vkExternalFenceHandleTypeFlagBitsEnumValue;
    }
}
