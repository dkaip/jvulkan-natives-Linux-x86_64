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
/*
 * getVkD3D12FenceSubmitInfoKHR.cpp
 *
 *  Created on: May 19, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
//    void getVkD3D12FenceSubmitInfoKHR(
//            JNIEnv *env,
//            const jobject jVkD3D12FenceSubmitInfoKHRObject,
//			VkD3D12FenceSubmitInfoKHR *vkD3D12FenceSubmitInfoKHR,
//            std::vector<void *> *memoryToFree)
//    {
//        jclass theClass = env->GetObjectClass(jVkD3D12FenceSubmitInfoKHRObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find class for jVkD3D12FenceSubmitInfoKHRObject");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkD3D12FenceSubmitInfoKHRObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        jobject jpNextObject = getpNextObject(env, jVkD3D12FenceSubmitInfoKHRObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Call to getpNext failed.");
//            return;
//        }
//
//        void *pNext = nullptr;
//        if (jpNextObject != nullptr)
//        {
//        	getpNextChain(
//        			env,
//					jpNextObject,
//        			&pNext,
//        			memoryToFree);
//            if (env->ExceptionOccurred())
//            {
//            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
//                return;
//            }
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        jmethodID methodId = env->GetMethodID(theClass, "getWaitSemaphoreValues", "()[J");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for getWaitSemaphoreValues");
//            return;
//        }
//
//        jlongArray jWaitSemaphoreValuesArrayObject = env->CallObjectMethod(jVkD3D12FenceSubmitInfoKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
//            return;
//        }
//
//        uint64_t *pWaitSemaphoreValues = nullptr;
//        jsize arrayLength = 0;
//        if (jWaitSemaphoreValuesArrayObject != nullptr)
//        {
//            arrayLength = env->GetArrayLength(jWaitSemaphoreValuesArrayObject);
//
//            pWaitSemaphoreValues = (uint64_t *)calloc(arrayLength, sizeof(uint64_t));
//            memoryToFree->push_back(pWaitSemaphoreValues);
//
//            env->GetLongArrayRegion(jWaitSemaphoreValuesArrayObject, 0, arrayLength, (long int *)pWaitSemaphoreValues);
//            if (env->ExceptionOccurred())
//            {
//                return;
//            }
//        }
//
//        vkD3D12FenceSubmitInfoKHR->waitSemaphoreValuesCount = arrayLength;
//        vkD3D12FenceSubmitInfoKHR->pWaitSemaphoreValues = pWaitSemaphoreValues;
//
//        ////////////////////////////////////////////////////////////////////////
//        methodId = env->GetMethodID(theClass, "getSignalSemaphoreValues", "()[J");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for getSignalSemaphoreValues");
//            return;
//        }
//
//        jlongArray jSignalSemaphoreValuesArrayObject = env->CallObjectMethod(jVkD3D12FenceSubmitInfoKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
//            return;
//        }
//
//        uint64_t *pSignalSemaphoreValues = nullptr;
//        arrayLength = 0;
//        if (jSignalSemaphoreValuesArrayObject != nullptr)
//        {
//            arrayLength = env->GetArrayLength(jSignalSemaphoreValuesArrayObject);
//
//            pSignalSemaphoreValues = (uint64_t *)calloc(arrayLength, sizeof(uint64_t));
//            memoryToFree->push_back(pSignalSemaphoreValues);
//
//            env->GetLongArrayRegion(jSignalSemaphoreValuesArrayObject, 0, arrayLength, (long int *)pSignalSemaphoreValues);
//            if (env->ExceptionOccurred())
//            {
//                return;
//            }
//        }
//
//        vkD3D12FenceSubmitInfoKHR->signalSemaphoreValuesCount = arrayLength;
//        vkD3D12FenceSubmitInfoKHR->pSignalSemaphoreValues = pSignalSemaphoreValues;
//
//
//
//        vkD3D12FenceSubmitInfoKHR->sType = sTypeValue;
//        vkD3D12FenceSubmitInfoKHR->pNext = pNext;
//    }
}
