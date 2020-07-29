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
 * getVkAccelerationStructureInfoNV.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAccelerationStructureInfoNV(
            JNIEnv *env,
            jobject jVkAccelerationStructureInfoNVObject,
            VkAccelerationStructureInfoNV *vkAccelerationStructureInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAccelerationStructureInfoNVClass = env->GetObjectClass(jVkAccelerationStructureInfoNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkAccelerationStructureInfoNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkAccelerationStructureInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkAccelerationStructureInfoNVClass, "getType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkAccelerationStructureTypeNV;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAccelerationStructureTypeNVObject = env->CallObjectMethod(jVkAccelerationStructureInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkAccelerationStructureTypeNVClass = env->GetObjectClass(jVkAccelerationStructureTypeNVObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkAccelerationStructureTypeNVClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkAccelerationStructureTypeNV vkAccelerationStructureTypeNVEnumValue = (VkAccelerationStructureTypeNV)env->CallIntMethod(jVkAccelerationStructureTypeNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAccelerationStructureInfoNVClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkAccelerationStructureInfoNVObject, methodId);
        VkBuildAccelerationStructureFlagsNV flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkBuildAccelerationStructureFlagBitsNV");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAccelerationStructureInfoNVClass, "getInstanceCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jInstanceCount = env->CallIntMethod(jVkAccelerationStructureInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkAccelerationStructureInfoNV->sType = (VkStructureType)sTypeValue;
        vkAccelerationStructureInfoNV->pNext = (void *)pNext;
        vkAccelerationStructureInfoNV->type  = vkAccelerationStructureTypeNVEnumValue;
        vkAccelerationStructureInfoNV->flags = flags;
        vkAccelerationStructureInfoNV->instanceCount = jInstanceCount;
    }
}
