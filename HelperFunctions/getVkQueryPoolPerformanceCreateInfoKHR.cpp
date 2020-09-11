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
 * getVkQueryPoolPerformanceCreateInfoKHR.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkQueryPoolPerformanceCreateInfoKHR(
            JNIEnv *env,
            const jobject jVkQueryPoolPerformanceCreateInfoKHRObject,
			VkQueryPoolPerformanceCreateInfoKHR *vkQueryPoolPerformanceCreateInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkQueryPoolPerformanceCreateInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkQueryPoolPerformanceCreateInfoKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkQueryPoolPerformanceCreateInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkQueryPoolPerformanceCreateInfoKHRObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getQueueFamilyIndex", "()I;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getQueueFamilyIndex");
            return;
        }

        uint32_t queueFamilyIndex = (uint32_t)env->CallIntMethod(jVkQueryPoolPerformanceCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getCounterIndices", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getCounterIndices");
            return;
        }

        jintArray jCounterIndices = (jintArray)env->CallObjectMethod(jVkQueryPoolPerformanceCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int *counterIndicesArray = nullptr;
        jsize arrayLength = 0;
        if (jCounterIndices != nullptr)
        {
            arrayLength = env->GetArrayLength(jCounterIndices);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength");
                return;
            }

            counterIndicesArray = (int *)calloc(arrayLength, sizeof(int));
            if (counterIndicesArray == nullptr)
            {
            	LOGERROR(env, "%s", "Error trying to allocate memory for counterIndicesArray.");
            	return;
            }
            memoryToFree->push_back(counterIndicesArray);

            env->GetIntArrayRegion(jCounterIndices, 0, arrayLength, counterIndicesArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }


        vkQueryPoolPerformanceCreateInfoKHR->sType = sTypeValue;
        vkQueryPoolPerformanceCreateInfoKHR->pNext = pNext;
        vkQueryPoolPerformanceCreateInfoKHR->queueFamilyIndex  = queueFamilyIndex;
		vkQueryPoolPerformanceCreateInfoKHR->counterIndexCount = arrayLength;
        vkQueryPoolPerformanceCreateInfoKHR->pCounterIndices   = (uint32_t *)counterIndicesArray;
    }
}
