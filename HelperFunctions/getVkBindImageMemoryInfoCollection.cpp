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
    void getVkBindImageMemoryInfo(
            JNIEnv *env,
            const jobject jVkBindImageMemoryInfoObject,
            VkBindImageMemoryInfo *vkBindImageMemoryInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBindBufferMemoryInfoClass = env->GetObjectClass(jVkBindImageMemoryInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkBindImageMemoryInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkBindImageMemoryInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkBindBufferMemoryInfoClass, "getImage", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkImage;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageObject = env->CallObjectMethod(jVkBindImageMemoryInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImage_T *vkImageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jVkImageObject);
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

        jobject jVkDeviceMemoryObject = env->CallObjectMethod(jVkBindImageMemoryInfoObject, methodId);
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

        jlong offset = env->CallLongMethod(jVkBindImageMemoryInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkBindImageMemoryInfo->sType = (VkStructureType)sTypeValue;
        vkBindImageMemoryInfo->pNext = (void *)pNext;
        vkBindImageMemoryInfo->image = vkImageHandle;
        vkBindImageMemoryInfo->memory = vkDeviceMemoryHandle;
        vkBindImageMemoryInfo->memoryOffset = offset;
    }

    void getVkBindImageMemoryInfoCollection(
            JNIEnv *env,
            const jobject jVkBindBufferMemoryInfoCollectionObject,
            VkBindImageMemoryInfo **vkBindImageMemoryInfos,
            int *numberOfVkBindImageMemoryInfos,
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

        *numberOfVkBindImageMemoryInfos = numberOfElements;
        *vkBindImageMemoryInfos = (VkBindImageMemoryInfo *)calloc(numberOfElements, sizeof(VkBindImageMemoryInfo));
        memoryToFree->push_back(*vkBindImageMemoryInfos);

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

            jobject jVkBindImageMemoryInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkBindImageMemoryInfo(
                    env,
                    jVkBindImageMemoryInfoObject,
                    &((*vkBindImageMemoryInfos)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}

