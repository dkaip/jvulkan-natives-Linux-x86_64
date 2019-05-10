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
#include "HelperFunctions.hh"
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
        jobject pNextObject = getpNext(env, jVkBindBufferMemoryInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkBindBufferMemoryInfoClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkBuffer;");
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
        methodId = env->GetMethodID(vkBindBufferMemoryInfoClass, "getMemory", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDeviceMemory;");
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

    void getVkBindBufferMemoryInfoCollection(
            JNIEnv *env,
            const jobject jVkBindBufferMemoryInfoCollectionObject,
            VkBindBufferMemoryInfo **vkBindBufferMemoryInfos,
            int *numberOfVkBindBufferMemoryInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBindBufferMemoryInfoCollectionClass = env->GetObjectClass(jVkBindBufferMemoryInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBindBufferMemoryInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBindBufferMemoryInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkBindBufferMemoryInfos = numberOfElements;
        *vkBindBufferMemoryInfos = (VkBindBufferMemoryInfo *)calloc(numberOfElements, sizeof(VkBindBufferMemoryInfo));
        memoryToFree->push_back(*vkBindBufferMemoryInfos);

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

            jobject jVkBindBufferMemoryInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkBindBufferMemoryInfo(
                    env,
                    jVkBindBufferMemoryInfoObject,
                    &((*vkBindBufferMemoryInfos)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}

