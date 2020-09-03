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
 * getVkPhysicalDeviceExternalBufferInfo.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceExternalBufferInfo(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceExternalBufferInfoObject,
			VkPhysicalDeviceExternalBufferInfo *vkPhysicalDeviceExternalBufferInfo,
            std::vector<void *> *memoryToFree)
    {
    	if (jVkPhysicalDeviceExternalBufferInfoObject == nullptr)
    	{
    		LOGERROR(env, "%s", "jVkPhysicalDeviceExternalBufferInfoObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceExternalBufferInfoObject == nullptr");
    		return;
    	}

    	if (vkPhysicalDeviceExternalBufferInfo == nullptr)
    	{
    		LOGERROR(env, "%s", "vkPhysicalDeviceExternalBufferInfo == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceExternalBufferInfo == nullptr");
    		return;
    	}

        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceExternalBufferInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceExternalBufferInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceExternalBufferInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceExternalBufferInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFlags");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPhysicalDeviceExternalBufferInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }
        VkBufferCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkBufferCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getUsage", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getUsage");
            return;
        }

        jobject usageObject = env->CallObjectMethod(jVkPhysicalDeviceExternalBufferInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }
        VkBufferUsageFlags usage = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkBufferUsageFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalMemoryHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method Id of getHandleType.");
            return;
        }

        jobject jVkExternalMemoryHandleTypeFlagBitsObject = env->CallObjectMethod(jVkPhysicalDeviceExternalBufferInfoObject, methodId);
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


        vkPhysicalDeviceExternalBufferInfo->sType = sTypeValue;
        vkPhysicalDeviceExternalBufferInfo->pNext = pNext;
        vkPhysicalDeviceExternalBufferInfo->flags = flags;
        vkPhysicalDeviceExternalBufferInfo->usage = usage;
        vkPhysicalDeviceExternalBufferInfo->handleType = handleTypeEnumValue;
    }
}
