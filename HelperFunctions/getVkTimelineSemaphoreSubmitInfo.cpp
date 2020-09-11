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
 * getVkTimelineSemaphoreSubmitInfo.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkTimelineSemaphoreSubmitInfo(
            JNIEnv *env,
            jobject jVkTimelineSemaphoreSubmitInfoObject,
			VkTimelineSemaphoreSubmitInfo *vkTimelineSemaphoreSubmitInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkTimelineSemaphoreSubmitInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkTimelineSemaphoreSubmitInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkTimelineSemaphoreSubmitInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkTimelineSemaphoreSubmitInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getWaitSemaphoreValues", "()[J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getWaitSemaphoreValues");
            return;
        }

        jlongArray jWaitSemaphoreValuesArrayObject = (jlongArray)env->CallObjectMethod(jVkTimelineSemaphoreSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint64_t *pWaitSemaphoreValues = nullptr;
        uint32_t waitSemaphoreValueCount = 0;
        if (jWaitSemaphoreValuesArrayObject != nullptr)
        {
        	waitSemaphoreValueCount = env->GetArrayLength(jWaitSemaphoreValuesArrayObject);

            pWaitSemaphoreValues = (uint64_t *)calloc(waitSemaphoreValueCount, sizeof(uint64_t));
            memoryToFree->push_back(pWaitSemaphoreValues);

            env->GetLongArrayRegion(jWaitSemaphoreValuesArrayObject, 0, waitSemaphoreValueCount, (long int *)pWaitSemaphoreValues);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSignalSemaphoreValues", "()[J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSignalSemaphoreValues");
            return;
        }

        jlongArray jSignalSemaphoreValuesArrayObject = (jlongArray)env->CallObjectMethod(jVkTimelineSemaphoreSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint64_t *pSignalSemaphoreValues = nullptr;
        uint32_t signalSemaphoreValueCount = 0;
        if (jSignalSemaphoreValuesArrayObject != nullptr)
        {
        	signalSemaphoreValueCount = env->GetArrayLength(jSignalSemaphoreValuesArrayObject);

            pSignalSemaphoreValues = (uint64_t *)calloc(signalSemaphoreValueCount, sizeof(uint64_t));
            memoryToFree->push_back(pSignalSemaphoreValues);

            env->GetLongArrayRegion(jSignalSemaphoreValuesArrayObject, 0, signalSemaphoreValueCount, (long int *)pSignalSemaphoreValues);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }


        vkTimelineSemaphoreSubmitInfo->sType 	= sTypeValue;
        vkTimelineSemaphoreSubmitInfo->pNext 	= (void *)pNext;
        vkTimelineSemaphoreSubmitInfo->waitSemaphoreValueCount = waitSemaphoreValueCount;
        vkTimelineSemaphoreSubmitInfo->pWaitSemaphoreValues = pWaitSemaphoreValues;
        vkTimelineSemaphoreSubmitInfo->signalSemaphoreValueCount = signalSemaphoreValueCount;
        vkTimelineSemaphoreSubmitInfo->pSignalSemaphoreValues = pSignalSemaphoreValues;
    }
}
