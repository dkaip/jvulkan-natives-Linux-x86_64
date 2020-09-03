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
 * getVkPhysicalDeviceExternalFenceInfo.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceExternalFenceInfo(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceExternalFenceInfoObject,
			VkPhysicalDeviceExternalFenceInfo *vkPhysicalDeviceExternalFenceInfo,
            std::vector<void *> *memoryToFree)
    {
    	if (jVkPhysicalDeviceExternalFenceInfoObject == nullptr)
    	{
    		LOGERROR(env, "%s", "jVkPhysicalDeviceExternalFenceInfoObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceExternalFenceInfoObject == nullptr");
    		return;
    	}

    	if (vkPhysicalDeviceExternalFenceInfo == nullptr)
    	{
    		LOGERROR(env, "%s", "vkPhysicalDeviceExternalFenceInfo == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceExternalFenceInfo == nullptr");
    		return;
    	}

        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceExternalFenceInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceExternalFenceInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceExternalFenceInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceExternalFenceInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalFenceHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method Id of getHandleType.");
            return;
        }

        jobject jVkExternalFenceHandleTypeFlagBitsObject = env->CallObjectMethod(jVkPhysicalDeviceExternalFenceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkExternalFenceHandleTypeFlagBitsClass = env->GetObjectClass(jVkExternalFenceHandleTypeFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceExternalFenceInfoObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkExternalFenceHandleTypeFlagBitsClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method Id of valueOf.");
            return;
        }

        VkExternalFenceHandleTypeFlagBits handleTypeEnumValue = (VkExternalFenceHandleTypeFlagBits)env->CallIntMethod(jVkExternalFenceHandleTypeFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkPhysicalDeviceExternalFenceInfo->sType = sTypeValue;
        vkPhysicalDeviceExternalFenceInfo->pNext = pNext;
        vkPhysicalDeviceExternalFenceInfo->handleType = handleTypeEnumValue;
    }
}
