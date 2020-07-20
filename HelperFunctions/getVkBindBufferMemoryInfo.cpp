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
 * getVkBindBufferMemoryInfoCollection.cpp
 *
 *  Created on: Mar 22, 2019
 *      Author: Douglas Kaip
 */
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBindBufferMemoryInfo(
            JNIEnv *env,
            const jobject jVkBindBufferMemoryInfoObject,
            VkBindBufferMemoryInfo *vkBindBufferMemoryInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBindBufferMemoryInfoClass = env->GetObjectClass(jVkBindBufferMemoryInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkBindBufferMemoryInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkBindBufferMemoryInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkBindBufferMemoryInfoClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBufferObject = env->CallObjectMethod(jVkBindBufferMemoryInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *vkBufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBindBufferMemoryInfoClass, "getMemory", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDeviceMemory;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDeviceMemoryObject = env->CallObjectMethod(jVkBindBufferMemoryInfoObject, methodId);
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
        methodId = env->GetMethodID(vkBindBufferMemoryInfoClass, "getMemoryOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong offset = env->CallLongMethod(jVkBindBufferMemoryInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkBindBufferMemoryInfo->sType = (VkStructureType)sTypeValue;
        vkBindBufferMemoryInfo->pNext = (void *)pNext;
        vkBindBufferMemoryInfo->buffer = vkBufferHandle;
        vkBindBufferMemoryInfo->memory = vkDeviceMemoryHandle;
        vkBindBufferMemoryInfo->memoryOffset = offset;
    }
}
