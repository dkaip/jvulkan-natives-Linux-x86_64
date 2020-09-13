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
 * getVkAndroidHardwareBufferUsageANDROID.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAndroidHardwareBufferUsageANDROID(
            JNIEnv *env,
            jobject jVkAndroidHardwareBufferUsageANDROIDObject,
			VkAndroidHardwareBufferUsageANDROID *vkAndroidHardwareBufferUsageANDROID,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkAndroidHardwareBufferUsageANDROIDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkAndroidHardwareBufferUsageANDROIDObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkAndroidHardwareBufferUsageANDROIDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkAndroidHardwareBufferUsageANDROIDObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getAndroidHardwareBufferUsage", "()J;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAndroidHardwareBufferUsage.");
            return;
        }

        uint64_t androidHardwareBufferUsage = (uint64_t)env->CallLongMethod(jVkAndroidHardwareBufferUsageANDROIDObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }


        vkAndroidHardwareBufferUsageANDROID->sType 	= sTypeValue;
        vkAndroidHardwareBufferUsageANDROID->pNext 	= (void *)pNext;
        vkAndroidHardwareBufferUsageANDROID->androidHardwareBufferUsage	= androidHardwareBufferUsage;
    }
}
