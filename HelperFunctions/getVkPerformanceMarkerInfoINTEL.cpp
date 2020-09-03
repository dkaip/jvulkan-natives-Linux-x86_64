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
 * getVkPerformanceMarkerInfoINTEL.cpp
 *
 *  Created on: Sep 1, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPerformanceMarkerInfoINTEL(
            JNIEnv *env,
            jobject jVkPerformanceMarkerInfoINTELObject,
			VkPerformanceMarkerInfoINTEL *vkPerformanceMarkerInfoINTEL,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPerformanceMarkerInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPerformanceMarkerInfoINTELObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPerformanceMarkerInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPerformanceMarkerInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (jpNextObject != nullptr)
        {
			LOGERROR(env, "%s", "pNext must be null.");
			return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getMarker", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getMarker.");
            return;
        }

        uint64_t marker = (uint64_t)env->CallLongMethod(jVkPerformanceMarkerInfoINTELObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }


        vkPerformanceMarkerInfoINTEL->sType = sTypeValue;
        vkPerformanceMarkerInfoINTEL->pNext = pNext;
        vkPerformanceMarkerInfoINTEL->marker = marker;
    }
}
