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

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
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
        	LOGERROR(env, "%s", "Could not get class of jVkSubmitInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkSubmitInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkSubmitInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getpNext");
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
        	LOGERROR(env, "%s", "Could not find methodId for getWaitSemaphores");
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
            jvulkan::getVkSemaphoreCollection(
                    env,
                    jWaitSemaphoreCollection,
                    &waitSemaphores,
                    &numberOfWaitSemaphores,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getVkSemaphoreCollection failed");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubmitInfoClass, "getWaitDstStageMask", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getWaitDstStageMask");
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
            jvulkan::getVkPipelineStageFlagsCollection(
                    env,
                    jWaitDstStageMaskCollection,
                    &pipelineStageFlags,
                    &numberOfWaitDstStageMasks,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getVkPipelineStageFlagsCollection failed");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubmitInfoClass, "getCommandBuffers", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getCommandBuffers");
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
            jvulkan::getVkCommandBufferCollection(
                    env,
                    jCommandBufferCollection,
                    &commandBuffers,
                    &numberOfCommandBuffers,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getVkCommandBufferCollection failed");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubmitInfoClass, "getSignalSemaphores", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getSignalSemaphores");
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
            jvulkan::getVkSemaphoreCollection(
                    env,
                    jSignalSemaphoreCollection,
                    &signalSemaphores,
                    &numberOfSignalSemaphores,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getVkSemaphoreCollection failed");
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
        	LOGERROR(env, "%s", "Could not get class for jVkSubmitInfoCollectionObject");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSubmitInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get methodId for size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSubmitInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallIntMethod failed for size");
            return;
        }

        *numberOfVkSubmitInfos = numberOfElements;
        *vkSubmitInfos = (VkSubmitInfo *)calloc(numberOfElements, sizeof(VkSubmitInfo));
        memoryToFree->push_back(*vkSubmitInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkSubmitInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get methodId for iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSubmitInfoCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallObjectMethod failed for iterator");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "GetObjectClass failed for iterator");
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get methodId for hasNext");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get methodId for next");
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "CallBooleanMethod failed for hasNext");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkSubmitInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "CallObjectMethod failed for next");
                break;
            }

            getVkSubmitInfo(
                    env,
                    jVkSubmitInfoObject,
                    &((*vkSubmitInfos)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "getVkSubmitInfo failed");
                return;
            }

            i++;
        } while(true);
    }
}
