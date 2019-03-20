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

namespace jvulkan
{
    void getVkCommandBufferInheritanceInfo(
            JNIEnv *env,
            jobject jVkCommandBufferInheritanceInfoObject,
            VkCommandBufferInheritanceInfo *vkCommandBufferInheritanceInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCommandBufferInheritanceInfoClass = env->GetObjectClass(jVkCommandBufferInheritanceInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkCommandBufferInheritanceInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getRenderPass", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkRenderPass;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkRenderPassObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkRenderPass_T *renderPassHandle = (VkRenderPass_T *)jvulkan::getHandleValue(env, jVkRenderPassObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getSubpass", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jsubpass = env->CallIntMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getFramebuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkFramebuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFramebufferObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFramebuffer_T *framebufferHandle = (VkFramebuffer_T *)jvulkan::getHandleValue(env, jVkFramebufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "isOcclusionQueryEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jOcclusionQueryEnable = env->CallBooleanMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getQueryFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        VkQueryControlFlags vkQueryControlFlags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkQueryControlFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getPipelineStatistics", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        VkQueryPipelineStatisticFlags vkQueryPipelineStatisticFlags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkQueryPipelineStatisticFlagBits");

        vkCommandBufferInheritanceInfo->sType = (VkStructureType)sTypeValue;
        vkCommandBufferInheritanceInfo->pNext = (void *)pNext;
        vkCommandBufferInheritanceInfo->renderPass = renderPassHandle;
        vkCommandBufferInheritanceInfo->subpass = jsubpass;
        vkCommandBufferInheritanceInfo->framebuffer = framebufferHandle;
        vkCommandBufferInheritanceInfo->occlusionQueryEnable = jOcclusionQueryEnable;
        vkCommandBufferInheritanceInfo->queryFlags = vkQueryControlFlags;
        vkCommandBufferInheritanceInfo->pipelineStatistics = vkQueryPipelineStatisticFlags;
    }
}
