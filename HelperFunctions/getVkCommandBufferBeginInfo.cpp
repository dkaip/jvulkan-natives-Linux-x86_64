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
    void getVkCommandBufferBeginInfo(
            JNIEnv *env,
            jobject jVkCommandBufferBeginInfoObject,
            VkCommandBufferBeginInfo *vkCommandBufferBeginInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCommandBufferBeginInfoClass = env->GetObjectClass(jVkCommandBufferBeginInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSType(env, jVkCommandBufferBeginInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkCommandBufferBeginInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkCommandBufferBeginInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkCommandBufferBeginInfoObject, methodId);
        VkCommandBufferUsageFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkCommandBufferUsageFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferBeginInfoClass, "getInheritanceInfo", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkCommandBufferInheritanceInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkCommandBufferInheritanceInfoObject = env->CallObjectMethod(jVkCommandBufferBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkCommandBufferInheritanceInfo *vkCommandBufferInheritanceInfo = nullptr;
        if (jVkCommandBufferInheritanceInfoObject != nullptr)
        {
            vkCommandBufferInheritanceInfo = (VkCommandBufferInheritanceInfo *)calloc(1, sizeof(VkCommandBufferInheritanceInfo));
            memoryToFree->push_back(vkCommandBufferInheritanceInfo);

            getVkCommandBufferInheritanceInfo(env, jVkCommandBufferInheritanceInfoObject, vkCommandBufferInheritanceInfo, memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }

        }

        vkCommandBufferBeginInfo->sType = (VkStructureType)sTypeValue;
        vkCommandBufferBeginInfo->pNext = (void *)pNext;
        vkCommandBufferBeginInfo->flags = flags;
        vkCommandBufferBeginInfo->pInheritanceInfo = vkCommandBufferInheritanceInfo;
    }
}
