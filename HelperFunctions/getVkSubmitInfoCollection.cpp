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
#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkSubmitInfo(
            JNIEnv *env,
            jobject jVkSubmitInfoObject,
            VkSubmitInfo *vkSubmitInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubmitInfoClass = env->GetObjectClass(jVkSubmitInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkSubmitInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkSubmitInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubmitInfoClass, "getWaitSemaphores", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jWaitSemaphoreCollection = env->CallObjectMethod(jVkSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfWaitSemaphores = 0;
        VkSemaphore *waitSemaphores = nullptr;

        if (jWaitSemaphoreCollection != nullptr)
        {
            hwjvi::getVkSemaphoreCollection(
                    env,
                    jWaitSemaphoreCollection,
                    &waitSemaphores,
                    &numberOfWaitSemaphores,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubmitInfoClass, "getWaitDstStageMask", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jWaitDstStageMaskCollection = env->CallObjectMethod(jVkSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfWaitDstStageMasks = 0;
        VkPipelineStageFlags *pipelineStageFlags = nullptr;

        if (jWaitDstStageMaskCollection != nullptr)
        {
            hwjvi::getVkPipelineStageFlagsCollection(
                    env,
                    jWaitDstStageMaskCollection,
                    &pipelineStageFlags,
                    &numberOfWaitDstStageMasks,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubmitInfoClass, "getCommandBuffers", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jCommandBufferCollection = env->CallObjectMethod(jVkSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfCommandBuffers = 0;
        VkCommandBuffer *commandBuffers = nullptr;

        if (jCommandBufferCollection != nullptr)
        {
            hwjvi::getVkCommandBufferCollection(
                    env,
                    jCommandBufferCollection,
                    &commandBuffers,
                    &numberOfCommandBuffers,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubmitInfoClass, "getSignalSemaphores", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jSignalSemaphoreCollection = env->CallObjectMethod(jVkSubmitInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfSignalSemaphores = 0;
        VkSemaphore *signalSemaphores = nullptr;

        if (jWaitSemaphoreCollection != nullptr)
        {
            hwjvi::getVkSemaphoreCollection(
                    env,
                    jSignalSemaphoreCollection,
                    &signalSemaphores,
                    &numberOfSignalSemaphores,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkSubmitInfo->sType = (VkStructureType)sTypeValue;
        vkSubmitInfo->pNext = (void *)pNext;
        vkSubmitInfo->waitSemaphoreCount = numberOfWaitSemaphores;
        vkSubmitInfo->pWaitSemaphores = waitSemaphores;
        vkSubmitInfo->pWaitDstStageMask = pipelineStageFlags;
        vkSubmitInfo->commandBufferCount = numberOfCommandBuffers;
        vkSubmitInfo->pCommandBuffers = commandBuffers;
        vkSubmitInfo->signalSemaphoreCount = numberOfSignalSemaphores;
        vkSubmitInfo->pSignalSemaphores = signalSemaphores;
    }

    void getVkSubmitInfoCollection(
            JNIEnv *env,
            const jobject jVkSubmitInfoCollectionObject,
            VkSubmitInfo **vkSubmitInfos,
            int *numberOfVkSubmitInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubmitInfoCollectionClass = env->GetObjectClass(jVkSubmitInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSubmitInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSubmitInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkSubmitInfos = numberOfElements;
        *vkSubmitInfos = (VkSubmitInfo *)calloc(numberOfElements, sizeof(VkSubmitInfo));
        memoryToFree->push_back(*vkSubmitInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkSubmitInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSubmitInfoCollectionObject, iteratorMethodId);
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

            jobject jVkSubmitInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkSubmitInfo(
                    env,
                    jVkSubmitInfoObject,
                    &((*vkSubmitInfos)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }
}
