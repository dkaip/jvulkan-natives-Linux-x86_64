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
 * getVkImportSemaphoreFdInfoKHR.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImportSemaphoreFdInfoKHR(
            JNIEnv *env,
            jobject jVkImportSemaphoreFdInfoKHR,
			VkImportSemaphoreFdInfoKHR *vkImportSemaphoreFdInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImportSemaphoreFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkImportSemaphoreFdInfoKHR");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkImportSemaphoreFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImportSemaphoreFdInfoKHR);
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
        	LOGERROR(env, "%s", "Could not find methodId for getSemaphore");
            return;
        }

        jobject jVkSemaphoreHandle = env->CallObjectMethod(jVkImportSemaphoreFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkSemaphore_T *semaphoreHandle = (VkSemaphore_T *)jvulkan::getHandleValue(env, jVkSemaphoreHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkSemaphore handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getFlags");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkImportSemaphoreFdInfoKHR, methodId);
        VkSemaphoreImportFlags flags = (VkSemaphoreImportFlags)getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSemaphoreImportFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkExternalSemaphoreHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType getHandleType");
            return;
        }

        jobject jVkExternalSemaphoreHandleTypeFlagBitsObject = env->CallObjectMethod(jVkImportSemaphoreFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getHandleType");
            return;
        }

        jclass vkExternalSemaphoreHandleTypeFlagBitsEnumClass = env->GetObjectClass(jVkExternalSemaphoreHandleTypeFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkExternalFenceHandleTypeFlagBitsObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkExternalSemaphoreHandleTypeFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkExternalSemaphoreHandleTypeFlagBits vkExternalSemaphoreHandleTypeFlagBitsEnumValue = (VkExternalSemaphoreHandleTypeFlagBits)env->CallIntMethod(jVkExternalSemaphoreHandleTypeFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getFd", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getFd");
            return;
        }

        jint fd = env->CallIntMethod(jVkImportSemaphoreFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkImportSemaphoreFdInfoKHR->sType 		= sTypeValue;
        vkImportSemaphoreFdInfoKHR->pNext 		= (void *)pNext;
        vkImportSemaphoreFdInfoKHR->semaphore	= semaphoreHandle;
        vkImportSemaphoreFdInfoKHR->flags 		= flags;
        vkImportSemaphoreFdInfoKHR->handleType 	= vkExternalSemaphoreHandleTypeFlagBitsEnumValue;
        vkImportSemaphoreFdInfoKHR->fd 			= fd;
    }
}

