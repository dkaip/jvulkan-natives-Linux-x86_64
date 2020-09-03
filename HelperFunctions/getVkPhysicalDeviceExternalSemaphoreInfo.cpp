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
 * getVkPhysicalDeviceExternalSemaphoreInfo.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceExternalSemaphoreInfo(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceExternalSemaphoreInfoObject,
			VkPhysicalDeviceExternalSemaphoreInfo *vkPhysicalDeviceExternalSemaphoreInfo,
            std::vector<void *> *memoryToFree)
    {
    	if (jVkPhysicalDeviceExternalSemaphoreInfoObject == nullptr)
    	{
    		LOGERROR(env, "%s", "jVkPhysicalDeviceExternalSemaphoreInfoObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceExternalSemaphoreInfoObject == nullptr");
    		return;
    	}

    	if (vkPhysicalDeviceExternalSemaphoreInfo == nullptr)
    	{
    		LOGERROR(env, "%s", "vkPhysicalDeviceExternalSemaphoreInfo == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceExternalSemaphoreInfo == nullptr");
    		return;
    	}

        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceExternalSemaphoreInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceExternalSemaphoreInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceExternalSemaphoreInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceExternalSemaphoreInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalSemaphoreHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method Id of getHandleType.");
            return;
        }

        jobject jVkExternalSemaphoreHandleTypeFlagBitsObject = env->CallObjectMethod(jVkPhysicalDeviceExternalSemaphoreInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkExternalSemaphoreHandleTypeFlagBitsClass = env->GetObjectClass(jVkExternalSemaphoreHandleTypeFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkExternalSemaphoreHandleTypeFlagBitsObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkExternalSemaphoreHandleTypeFlagBitsClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method Id of valueOf.");
            return;
        }

        VkExternalSemaphoreHandleTypeFlagBits handleTypeEnumValue = (VkExternalSemaphoreHandleTypeFlagBits)env->CallIntMethod(jVkExternalSemaphoreHandleTypeFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkPhysicalDeviceExternalSemaphoreInfo->sType = sTypeValue;
        vkPhysicalDeviceExternalSemaphoreInfo->pNext = pNext;
        vkPhysicalDeviceExternalSemaphoreInfo->handleType = handleTypeEnumValue;
    }
}
