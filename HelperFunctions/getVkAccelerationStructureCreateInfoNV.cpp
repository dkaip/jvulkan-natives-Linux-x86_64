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

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAccelerationStructureCreateInfoNV(
            JNIEnv *env,
            jobject jVkAccelerationStructureCreateInfoNVObject,
            VkAccelerationStructureCreateInfoNV *vkAccelerationStructureCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAccelerationStructureCreateInfoNVClass = env->GetObjectClass(jVkAccelerationStructureCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkAccelerationStructureCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNext(env, jVkAccelerationStructureCreateInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(vkAccelerationStructureCreateInfoNVClass, "getCompactedSize", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong compactedSize = env->CallLongMethod(jVkAccelerationStructureCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAccelerationStructureCreateInfoNVClass, "getInfo", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/CreateInfos/VkAccelerationStructureCreateInfoNV;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAccelerationStructureInfoNV = env->CallObjectMethod(jVkAccelerationStructureCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkAccelerationStructureCreateInfoNV->sType = (VkStructureType)sTypeValue;
        vkAccelerationStructureCreateInfoNV->pNext = (void *)pNext;
        vkAccelerationStructureCreateInfoNV->compactedSize = compactedSize;

        getVkAccelerationStructureInfoNV(
                env,
                jVkAccelerationStructureInfoNV,
                &(vkAccelerationStructureCreateInfoNV->info),
                memoryToFree);
    }
}
