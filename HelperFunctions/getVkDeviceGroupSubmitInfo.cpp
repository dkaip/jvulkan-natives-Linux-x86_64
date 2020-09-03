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
 * getVkDeviceGroupSubmitInfo.cpp
 *
 *  Created on: May 19, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDeviceGroupSubmitInfo(
            JNIEnv *env,
            const jobject jVkDeviceGroupSubmitInfoObject,
			VkDeviceGroupSubmitInfo *vkDeviceGroupSubmitInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDeviceGroupSubmitInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDeviceGroupSubmitInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDeviceGroupSubmitInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDeviceGroupSubmitInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getWaitSemaphoreDeviceIndices", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getWaitSemaphoreDeviceIndices");
            return;
        }

        jintArray jWaitSemaphoreDeviceIndicesArrayObject = (jintArray)env->CallObjectMethod(jVkDeviceGroupSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        uint32_t *pWaitSemaphoreDeviceIndices = nullptr;
        jsize arrayLength = 0;
        if (jWaitSemaphoreDeviceIndicesArrayObject != nullptr)
        {
            arrayLength = env->GetArrayLength(jWaitSemaphoreDeviceIndicesArrayObject);

            pWaitSemaphoreDeviceIndices = (uint32_t *)calloc(arrayLength, sizeof(uint32_t));
            memoryToFree->push_back(pWaitSemaphoreDeviceIndices);

            env->GetIntArrayRegion(jWaitSemaphoreDeviceIndicesArrayObject, 0, arrayLength, (int *)pWaitSemaphoreDeviceIndices);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDeviceGroupSubmitInfo->waitSemaphoreCount = arrayLength;
        vkDeviceGroupSubmitInfo->pWaitSemaphoreDeviceIndices = pWaitSemaphoreDeviceIndices;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getCommandBufferDeviceMasks", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getCommandBufferDeviceMasks");
            return;
        }

        jintArray jCommandBufferDeviceMasksArrayObject = (jintArray)env->CallObjectMethod(jVkDeviceGroupSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        uint32_t *pCommandBufferDeviceMasks = nullptr;
        arrayLength = 0;
        if (jCommandBufferDeviceMasksArrayObject != nullptr)
        {
            arrayLength = env->GetArrayLength(jCommandBufferDeviceMasksArrayObject);

            pCommandBufferDeviceMasks = (uint32_t *)calloc(arrayLength, sizeof(uint32_t));
            memoryToFree->push_back(pCommandBufferDeviceMasks);

            env->GetIntArrayRegion(jCommandBufferDeviceMasksArrayObject, 0, arrayLength, (int *)pCommandBufferDeviceMasks);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDeviceGroupSubmitInfo->commandBufferCount = arrayLength;
        vkDeviceGroupSubmitInfo->pCommandBufferDeviceMasks = pCommandBufferDeviceMasks;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSignalSemaphoreDeviceIndices", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSignalSemaphoreDeviceIndices");
            return;
        }

        jintArray jSignalSemaphoreDeviceIndicesArrayObject = (jintArray)env->CallObjectMethod(jVkDeviceGroupSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        uint32_t *pSignalSemaphoreDeviceIndices = nullptr;
        arrayLength = 0;
        if (jSignalSemaphoreDeviceIndicesArrayObject != nullptr)
        {
            arrayLength = env->GetArrayLength(jSignalSemaphoreDeviceIndicesArrayObject);

            pSignalSemaphoreDeviceIndices = (uint32_t *)calloc(arrayLength, sizeof(uint32_t));
            memoryToFree->push_back(pSignalSemaphoreDeviceIndices);

            env->GetIntArrayRegion(jSignalSemaphoreDeviceIndicesArrayObject, 0, arrayLength, (int *)pSignalSemaphoreDeviceIndices);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDeviceGroupSubmitInfo->signalSemaphoreCount = arrayLength;
        vkDeviceGroupSubmitInfo->pSignalSemaphoreDeviceIndices = pSignalSemaphoreDeviceIndices;



        vkDeviceGroupSubmitInfo->sType = sTypeValue;
        vkDeviceGroupSubmitInfo->pNext = pNext;
    }
}
