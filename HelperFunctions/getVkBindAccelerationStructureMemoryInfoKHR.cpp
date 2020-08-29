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
 * getVkBindAccelerationStructureMemoryInfoKHR.cpp
 *
 *  Created on: Jul 29, 2020
 *      Author: Douglas Kaip
 */
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBindAccelerationStructureMemoryInfoKHR(
            JNIEnv *env,
            const jobject jVkBindAccelerationStructureMemoryInfoKHRObject,
            VkBindAccelerationStructureMemoryInfoKHR *vkBindAccelerationStructureMemoryInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBindAccelerationStructureMemoryInfoKHRClass = env->GetObjectClass(jVkBindAccelerationStructureMemoryInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkBindAccelerationStructureMemoryInfoKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSTypeAsInt(env, jVkBindAccelerationStructureMemoryInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkBindAccelerationStructureMemoryInfoKHRObject);
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
        jmethodID methodId = env->GetMethodID(vkBindAccelerationStructureMemoryInfoKHRClass, "getAccelerationStructure", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkAccelerationStructureKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAccelerationStructure");
            return;
        }

        jobject jVkAccelerationStructureKHRObject = env->CallObjectMethod(jVkBindAccelerationStructureMemoryInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkAccelerationStructureKHR vkAccelerationStructureKHRHandle = (VkAccelerationStructureKHR)jvulkan::getHandleValue(env, jVkAccelerationStructureKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling jvulkan::getHandleValue");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBindAccelerationStructureMemoryInfoKHRClass, "getMemory", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDeviceMemory;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMemory");
            return;
        }

        jobject jVkDeviceMemoryObject = env->CallObjectMethod(jVkBindAccelerationStructureMemoryInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkDeviceMemory_T *vkDeviceMemoryHandle = (VkDeviceMemory_T *)jvulkan::getHandleValue(env, jVkDeviceMemoryObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling jvulkan::getHandleValue");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBindAccelerationStructureMemoryInfoKHRClass, "getMemoryOffset", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMemoryOffset");
            return;
        }

        jlong offset = env->CallLongMethod(jVkBindAccelerationStructureMemoryInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBindAccelerationStructureMemoryInfoKHRClass, "getDeviceIndices", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDeviceIndices");
            return;
        }

        jintArray jDeviceIndexArray = (jintArray)env->CallObjectMethod(jVkBindAccelerationStructureMemoryInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jsize numberOfIndices = env->GetArrayLength(jDeviceIndexArray);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetArrayLength");
            return;
        }

        int *data = env->GetIntArrayElements(jDeviceIndexArray, 0);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetIntArrayElements");
            return;
        }

        int *deviceIndicesArray = (int *)calloc((size_t)numberOfIndices, sizeof(int));
        memoryToFree->push_back(deviceIndicesArray);
        if (data != nullptr)
        {
            memcpy(deviceIndicesArray, data, numberOfIndices * sizeof(int));
            env->ReleaseIntArrayElements(jDeviceIndexArray, data, JNI_ABORT);
        }

        vkBindAccelerationStructureMemoryInfoKHR->sType = sTypeValue;
        vkBindAccelerationStructureMemoryInfoKHR->pNext = pNext;
        vkBindAccelerationStructureMemoryInfoKHR->accelerationStructure = vkAccelerationStructureKHRHandle;
        vkBindAccelerationStructureMemoryInfoKHR->memory = vkDeviceMemoryHandle;
        vkBindAccelerationStructureMemoryInfoKHR->memoryOffset = offset;
        vkBindAccelerationStructureMemoryInfoKHR->deviceIndexCount = numberOfIndices;
        vkBindAccelerationStructureMemoryInfoKHR->pDeviceIndices = (uint32_t *)deviceIndicesArray;
    }
}
