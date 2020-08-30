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
    void getVkCommandBufferInheritanceInfo(
            JNIEnv *env,
            jobject jVkCommandBufferInheritanceInfoObject,
            VkCommandBufferInheritanceInfo *vkCommandBufferInheritanceInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCommandBufferInheritanceInfoClass = env->GetObjectClass(jVkCommandBufferInheritanceInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkCommandBufferInheritanceInfoObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkCommandBufferInheritanceInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkCommandBufferInheritanceInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getRenderPass", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkRenderPass;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getRenderPass.");
            return;
        }

        jobject jVkRenderPassObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
            return;
        }

        VkRenderPass_T *renderPassHandle = (VkRenderPass_T *)jvulkan::getHandleValue(env, jVkRenderPassObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getHandleValue failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getSubpass", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSubpass.");
            return;
        }

        jint jsubpass = env->CallIntMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallIntMethod failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getFramebuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkFramebuffer;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFramebuffer.");
            return;
        }

        jobject jVkFramebufferObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
            return;
        }

        VkFramebuffer_T *framebufferHandle = (VkFramebuffer_T *)jvulkan::getHandleValue(env, jVkFramebufferObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getHandleValue failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "isOcclusionQueryEnable", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isOcclusionQueryEnable.");
            return;
        }

        jboolean jOcclusionQueryEnable = env->CallBooleanMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallBooleanMethod failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getQueryFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getQueryFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
            return;
        }

        VkQueryControlFlags vkQueryControlFlags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkQueryControlFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getEnumSetValue failed.");
            return;
        }


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getPipelineStatistics", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPipelineStatistics.");
            return;
        }

        flagsObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
            return;
        }

        VkQueryPipelineStatisticFlags vkQueryPipelineStatisticFlags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkQueryPipelineStatisticFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getEnumSetValue failed.");
            return;
        }


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
