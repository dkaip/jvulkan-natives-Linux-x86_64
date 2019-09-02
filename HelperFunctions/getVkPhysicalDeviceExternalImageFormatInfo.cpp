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
 * getVkPhysicalDeviceExternalImageFormatInfo.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceExternalImageFormatInfo(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceExternalImageFormatInfoObject,
			VkPhysicalDeviceExternalImageFormatInfo *vkPhysicalDeviceExternalImageFormatInfo,
            std::vector<void *> *memoryToFree)
    {
    	if (jVkPhysicalDeviceExternalImageFormatInfoObject == nullptr)
    	{
    		LOGERROR(env, "%s", "jVkPhysicalDeviceExternalImageFormatInfoObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceExternalImageFormatInfoObject == nullptr");
    		return;
    	}

    	if (vkPhysicalDeviceExternalImageFormatInfo == nullptr)
    	{
    		LOGERROR(env, "%s", "vkPhysicalDeviceExternalImageFormatInfo == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceExternalImageFormatInfo == nullptr");
    		return;
    	}

        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceExternalImageFormatInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceExternalImageFormatInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDeviceExternalImageFormatInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceExternalImageFormatInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkExternalMemoryHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method Id of getHandleType.");
            return;
        }

        jobject jVkExternalMemoryHandleTypeFlagBitsObject = env->CallObjectMethod(jVkPhysicalDeviceExternalImageFormatInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkExternalMemoryHandleTypeFlagBitsClass = env->GetObjectClass(jVkExternalMemoryHandleTypeFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkExternalMemoryHandleTypeFlagBitsObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkExternalMemoryHandleTypeFlagBitsClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method Id of valueOf.");
            return;
        }

        VkExternalMemoryHandleTypeFlagBits handleTypeEnumValue = (VkExternalMemoryHandleTypeFlagBits)env->CallIntMethod(jVkExternalMemoryHandleTypeFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkPhysicalDeviceExternalImageFormatInfo->sType = sTypeValue;
        vkPhysicalDeviceExternalImageFormatInfo->pNext = pNext;
        vkPhysicalDeviceExternalImageFormatInfo->handleType = handleTypeEnumValue;
    }
}
