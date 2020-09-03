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
 * getVkImportFenceFdInfoKHR.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImportFenceFdInfoKHR(
            JNIEnv *env,
            jobject jVkImportFenceFdInfoKHR,
			VkImportFenceFdInfoKHR *vkImportFenceFdInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImportFenceFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkImportFenceFdInfoKHR");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkImportFenceFdInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImportFenceFdInfoKHR);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFence", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkFence;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFence");
            return;
        }

        jobject jVkFenceHandle = env->CallObjectMethod(jVkImportFenceFdInfoKHR, methodId);
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
        methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getFlags");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkImportFenceFdInfoKHR, methodId);
        VkFenceImportFlags flags = (VkFenceImportFlags)getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkFenceImportFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalFenceHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to find method id for getHandleType");
            return;
        }

        jobject jVkExternalFenceHandleTypeFlagBitsObject = env->CallObjectMethod(jVkImportFenceFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getHandleType");
            return;
        }

        jclass vkExternalFenceHandleTypeFlagBitsEnumClass = env->GetObjectClass(jVkExternalFenceHandleTypeFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkExternalFenceHandleTypeFlagBitsObject");
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

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getFd", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getFd");
            return;
        }

        jint fd = env->CallIntMethod(jVkImportFenceFdInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkImportFenceFdInfoKHR->sType 		= sTypeValue;
        vkImportFenceFdInfoKHR->pNext 		= (void *)pNext;
        vkImportFenceFdInfoKHR->fence 		= fenceHandle;
        vkImportFenceFdInfoKHR->flags 		= flags;
        vkImportFenceFdInfoKHR->handleType 	= vkExternalFenceHandleTypeFlagBitsEnumValue;
        vkImportFenceFdInfoKHR->fd 			= fd;
    }
}

