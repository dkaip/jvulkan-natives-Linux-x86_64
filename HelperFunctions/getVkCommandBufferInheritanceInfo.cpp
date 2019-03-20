#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
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
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getRenderPass", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkRenderPass;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkRenderPassObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkRenderPass_T *renderPassHandle = (VkRenderPass_T *)hwjvi::getHandleValue(env, jVkRenderPassObject);
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
        methodId = env->GetMethodID(vkCommandBufferInheritanceInfoClass, "getFramebuffer", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkFramebuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFramebufferObject = env->CallObjectMethod(jVkCommandBufferInheritanceInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFramebuffer_T *framebufferHandle = (VkFramebuffer_T *)hwjvi::getHandleValue(env, jVkFramebufferObject);
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
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkQueryControlFlagBits");


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
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkQueryPipelineStatisticFlagBits");

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
