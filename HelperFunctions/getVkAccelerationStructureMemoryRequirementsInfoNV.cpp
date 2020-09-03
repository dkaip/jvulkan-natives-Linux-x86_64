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
 * getVkAccelerationStructureMemoryRequirementsInfoNV.cpp
 *
 *  Created on: Aug 30, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAccelerationStructureMemoryRequirementsInfoNV(
            JNIEnv *env,
            jobject jVkAccelerationStructureMemoryRequirementsInfoNVObject,
			VkAccelerationStructureMemoryRequirementsInfoNV *vkAccelerationStructureMemoryRequirementsInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkAccelerationStructureMemoryRequirementsInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkAccelerationStructureMemoryRequirementsInfoNVObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkAccelerationStructureMemoryRequirementsInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkAccelerationStructureMemoryRequirementsInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkAccelerationStructureMemoryRequirementsTypeKHR;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAccelerationStructureMemoryRequirementsTypeKHRObject = env->CallObjectMethod(jVkAccelerationStructureMemoryRequirementsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkAccelerationStructureMemoryRequirementsTypeKHRClass = env->GetObjectClass(jVkAccelerationStructureMemoryRequirementsTypeKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetObjectClass.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkAccelerationStructureMemoryRequirementsTypeKHRClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkAccelerationStructureMemoryRequirementsTypeKHR vkAccelerationStructureTypeNVEnumValue = (VkAccelerationStructureMemoryRequirementsTypeKHR)env->CallIntMethod(jVkAccelerationStructureMemoryRequirementsTypeKHRObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getAccelerationStructure", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkAccelerationStructureKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getAccelerationStructure method Id");
            return;
        }

        jobject jVkAccelerationStructureKHRObject = env->CallObjectMethod(jVkAccelerationStructureMemoryRequirementsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getAccelerationStructure");
            return;
        }

        VkAccelerationStructureKHR accelerationStructureKHRHandle = (VkAccelerationStructureKHR)jvulkan::getHandleValue(env, jVkAccelerationStructureKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue for jVkAccelerationStructureKHRObject");
            return;
        }


        vkAccelerationStructureMemoryRequirementsInfoNV->sType = sTypeValue;
        vkAccelerationStructureMemoryRequirementsInfoNV->pNext = pNext;
        vkAccelerationStructureMemoryRequirementsInfoNV->type  = vkAccelerationStructureTypeNVEnumValue;
        vkAccelerationStructureMemoryRequirementsInfoNV->accelerationStructure = accelerationStructureKHRHandle;
    }
}
