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
 * getVkAcquireProfilingLockInfoKHR.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAcquireProfilingLockInfoKHR(
            JNIEnv *env,
            const jobject jVkAcquireProfilingLockInfoKHRObject,
			VkAcquireProfilingLockInfoKHR *vkAcquireProfilingLockInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAcquireProfilingLockInfoKHRClass = env->GetObjectClass(jVkAcquireProfilingLockInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkAcquireProfilingLockInfoKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSTypeAsInt(env, jVkAcquireProfilingLockInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkAcquireProfilingLockInfoKHRObject);
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
        jmethodID methodId = env->GetMethodID(vkAcquireProfilingLockInfoKHRClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkAcquireProfilingLockInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkAcquireProfilingLockFlagsKHR flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkAcquireProfilingLockFlagBitsKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAcquireProfilingLockInfoKHRClass, "getTimeout", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getTimeout");
            return;
        }

        jlong timeout = env->CallLongMethod(jVkAcquireProfilingLockInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }


        vkAcquireProfilingLockInfoKHR->sType   = (VkStructureType)sTypeValue;
        vkAcquireProfilingLockInfoKHR->pNext   = (void *)pNext;
        vkAcquireProfilingLockInfoKHR->flags   = flags;
        vkAcquireProfilingLockInfoKHR->timeout = (uint64_t)timeout;
    }
}
