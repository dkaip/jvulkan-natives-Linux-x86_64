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
 * getVkQueryPoolPerformanceQueryCreateInfoINTEL.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkQueryPoolPerformanceQueryCreateInfoINTEL(
            JNIEnv *env,
            jobject jVkQueryPoolPerformanceQueryCreateInfoINTELObject,
			VkQueryPoolPerformanceQueryCreateInfoINTEL *vkQueryPoolPerformanceQueryCreateInfoINTEL,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkQueryPoolPerformanceQueryCreateInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkQueryPoolPerformanceQueryCreateInfoINTELObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkQueryPoolPerformanceQueryCreateInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkQueryPoolPerformanceQueryCreateInfoINTELObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getPerformanceCountersSampling", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkQueryPoolSamplingModeINTEL;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to find method id for getPerformanceCountersSampling");
            return;
        }

        jobject jVkQueryPoolSamplingModeINTELObject = env->CallObjectMethod(jVkQueryPoolPerformanceQueryCreateInfoINTELObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getPerformanceCountersSampling");
            return;
        }

        jclass vkQueryPoolSamplingModeINTELObjectEnumClass = env->GetObjectClass(jVkQueryPoolSamplingModeINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkQueryPoolSamplingModeINTELObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkQueryPoolSamplingModeINTELObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkQueryPoolSamplingModeINTEL performanceCountersSampling = (VkQueryPoolSamplingModeINTEL)env->CallIntMethod(jVkQueryPoolSamplingModeINTELObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }


        vkQueryPoolPerformanceQueryCreateInfoINTEL->sType 	= sTypeValue;
        vkQueryPoolPerformanceQueryCreateInfoINTEL->pNext 	= (void *)pNext;
        vkQueryPoolPerformanceQueryCreateInfoINTEL->performanceCountersSampling = performanceCountersSampling;
    }
}
