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
 * getVkMemoryAllocateFlagsInfo.cpp
 *
 *  Created on: May 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkMemoryAllocateFlagsInfo(
            JNIEnv *env,
            const jobject jVkMemoryAllocateFlagsInfoObject,
			VkMemoryAllocateFlagsInfo *vkMemoryAllocateFlagsInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkMemoryAllocateFlagsInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkMemoryAllocateFlagsInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkMemoryAllocateFlagsInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkMemoryAllocateFlagsInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getFlags method Id");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkMemoryAllocateFlagsInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkMemoryAllocateFlags flags = getEnumSetValue(
                env,
				flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkMemoryAllocateFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDeviceMask", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getDeviceMask.");
            return;
        }

        jint deviceMask = env->CallIntMethod(jVkMemoryAllocateFlagsInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkMemoryAllocateFlagsInfoObject.");
            return;
        }


        vkMemoryAllocateFlagsInfo->sType = sTypeValue;
        vkMemoryAllocateFlagsInfo->pNext = pNext;
        vkMemoryAllocateFlagsInfo->flags = flags;
        vkMemoryAllocateFlagsInfo->deviceMask = deviceMask;
    }
}
