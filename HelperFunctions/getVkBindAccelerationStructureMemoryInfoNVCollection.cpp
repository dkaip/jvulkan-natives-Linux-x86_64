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
 * getVkBindAccelerationStructureMemoryInfoNVCollection.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBindAccelerationStructureMemoryInfoNV(
            JNIEnv *env,
            const jobject jVkBindAccelerationStructureMemoryInfoNVObject,
            VkBindAccelerationStructureMemoryInfoNV *vkBindAccelerationStructureMemoryInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBindAccelerationStructureMemoryInfoNVClass = env->GetObjectClass(jVkBindAccelerationStructureMemoryInfoNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkBindAccelerationStructureMemoryInfoNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkBindAccelerationStructureMemoryInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(vkBindAccelerationStructureMemoryInfoNVClass, "getAccelerationStructure", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkAccelerationStructureNV;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAccelerationStructureNVObject = env->CallObjectMethod(jVkBindAccelerationStructureMemoryInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkAccelerationStructureNV_T *vkAccelerationStructureNVHandle = (VkAccelerationStructureNV_T *)jvulkan::getHandleValue(env, jVkAccelerationStructureNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBindAccelerationStructureMemoryInfoNVClass, "getMemory", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDeviceMemory;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDeviceMemoryObject = env->CallObjectMethod(jVkBindAccelerationStructureMemoryInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDeviceMemory_T *vkDeviceMemoryHandle = (VkDeviceMemory_T *)jvulkan::getHandleValue(env, jVkDeviceMemoryObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBindAccelerationStructureMemoryInfoNVClass, "getMemoryOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong offset = env->CallLongMethod(jVkBindAccelerationStructureMemoryInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBindAccelerationStructureMemoryInfoNVClass, "getDeviceIndices", "()[I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jDeviceIndexArray = (jintArray)env->CallObjectMethod(jVkBindAccelerationStructureMemoryInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jsize numberOfIndices = env->GetArrayLength(jDeviceIndexArray);

        int *data = env->GetIntArrayElements(jDeviceIndexArray, 0);
        int *deviceIndicesArray = (int *)calloc((size_t)numberOfIndices, sizeof(int));
        memoryToFree->push_back(deviceIndicesArray);
        if (data != nullptr)
        {
            memcpy(deviceIndicesArray, data, numberOfIndices * sizeof(int));
            env->ReleaseIntArrayElements(jDeviceIndexArray, data, JNI_ABORT);
        }

        vkBindAccelerationStructureMemoryInfoNV->sType = (VkStructureType)sTypeValue;
        vkBindAccelerationStructureMemoryInfoNV->pNext = (void *)pNext;
        vkBindAccelerationStructureMemoryInfoNV->accelerationStructure = vkAccelerationStructureNVHandle;
        vkBindAccelerationStructureMemoryInfoNV->memory = vkDeviceMemoryHandle;
        vkBindAccelerationStructureMemoryInfoNV->memoryOffset = offset;
        vkBindAccelerationStructureMemoryInfoNV->deviceIndexCount = numberOfIndices;
        vkBindAccelerationStructureMemoryInfoNV->pDeviceIndices = (uint32_t *)deviceIndicesArray;
    }

    void getVkBindAccelerationStructureMemoryInfoNVCollection(
            JNIEnv *env,
            const jobject jVkBindAccelerationStructureMemoryInfoNVCollectionObject,
            VkBindAccelerationStructureMemoryInfoNV **vkBindAccelerationStructureMemoryInfoNVs,
            int *numberOfVkBindAccelerationStructureMemoryInfoNVs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBindBufferMemoryInfoCollectionClass = env->GetObjectClass(jVkBindAccelerationStructureMemoryInfoNVCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBindBufferMemoryInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBindAccelerationStructureMemoryInfoNVCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkBindAccelerationStructureMemoryInfoNVs = numberOfElements;
        *vkBindAccelerationStructureMemoryInfoNVs = (VkBindAccelerationStructureMemoryInfoNV *)calloc(numberOfElements, sizeof(VkBindAccelerationStructureMemoryInfoNV));
        memoryToFree->push_back(*vkBindAccelerationStructureMemoryInfoNVs);

        jmethodID iteratorMethodId = env->GetMethodID(vkBindBufferMemoryInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(vkBindBufferMemoryInfoCollectionClass, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkBindAccelerationStructureMemoryInfoNVObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkBindAccelerationStructureMemoryInfoNV(
                    env,
                    jVkBindAccelerationStructureMemoryInfoNVObject,
                    &((*vkBindAccelerationStructureMemoryInfoNVs)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
