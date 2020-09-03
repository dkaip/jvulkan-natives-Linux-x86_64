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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkCommandBufferAllocateInfo(
            JNIEnv *env,
            jobject jVkCommandBufferAllocateInfoObject,
            VkCommandBufferAllocateInfo *vkCommandBufferAllocateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCommandBufferAllocateInfoClass = env->GetObjectClass(jVkCommandBufferAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkCommandBufferAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkCommandBufferAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkCommandBufferAllocateInfoClass, "getCommandPool", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandPool;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkCommandPool = env->CallObjectMethod(jVkCommandBufferAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkCommandPool_T *commandPoolHandle = (VkCommandPool_T *)jvulkan::getHandleValue(env, jVkCommandPool);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferAllocateInfoClass, "getLevel", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkCommandBufferLevel;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkCommandBufferLevelObject = env->CallObjectMethod(jVkCommandBufferAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkLogicOpEnumClass = env->GetObjectClass(jVkCommandBufferLevelObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkLogicOpEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkCommandBufferLevel vkCommandBufferLevelEnumValue = (VkCommandBufferLevel)env->CallIntMethod(jVkCommandBufferLevelObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferAllocateInfoClass, "getCommandBufferCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jCommandBufferCount = env->CallIntMethod(jVkCommandBufferAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkCommandBufferAllocateInfo->sType = sTypeValue;
        vkCommandBufferAllocateInfo->pNext = (void *)pNext;
        vkCommandBufferAllocateInfo->commandPool = commandPoolHandle;
        vkCommandBufferAllocateInfo->level = vkCommandBufferLevelEnumValue;
        vkCommandBufferAllocateInfo->commandBufferCount = jCommandBufferCount;
    }
}
