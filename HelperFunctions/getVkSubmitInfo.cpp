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

#include "JVulkanHelperFunctions.hh"
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
        jobject jpNextObject = getpNextObject(env, jVkSubmitInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkSubmitInfoClass, "getWaitSemaphores", "()Ljava/util/Collection;");
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
}
