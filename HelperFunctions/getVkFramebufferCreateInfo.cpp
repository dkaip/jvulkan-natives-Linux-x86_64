#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkFramebufferCreateInfo(
            JNIEnv *env,
            jobject jVkFramebufferCreateInfoObject,
            VkFramebufferCreateInfo *vkFramebufferCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkFramebufferCreateInfoClass = env->GetObjectClass(jVkFramebufferCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkFramebufferCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkFramebufferCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkFramebufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkFramebufferCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkFramebufferCreateInfoObject, methodId);
        VkFramebufferCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFramebufferCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkFramebufferCreateInfoClass, "getRenderPass", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkRenderPass;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jRenderPassHandleObject = env->CallObjectMethod(jVkFramebufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkRenderPass_T *renderPassHandle = (VkRenderPass_T *)hwjvi::getHandleValue(env, jRenderPassHandleObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkFramebufferCreateInfoClass, "getAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageViewCollection = env->CallObjectMethod(jVkFramebufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkImageViewHandles = 0;
        VkImageView *vkImageViewHandles = nullptr;
        if (jVkImageViewCollection != nullptr)
        {
            getVkImageViewCollection(
                    env,
                    jVkImageViewCollection,
                    &vkImageViewHandles,
                    &numberOfVkImageViewHandles,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {

                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkFramebufferCreateInfoClass, "getWidth", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jwidth = env->CallIntMethod(jVkFramebufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkFramebufferCreateInfoClass, "getHeight", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jheight = env->CallIntMethod(jVkFramebufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkFramebufferCreateInfoClass, "getLayers", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jlayers = env->CallIntMethod(jVkFramebufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkFramebufferCreateInfo->sType = (VkStructureType)sTypeValue;
        vkFramebufferCreateInfo->pNext = (void *)pNext;
        vkFramebufferCreateInfo->flags = flags;
        vkFramebufferCreateInfo->renderPass = renderPassHandle;
        vkFramebufferCreateInfo->attachmentCount = numberOfVkImageViewHandles;
        vkFramebufferCreateInfo->pAttachments = vkImageViewHandles;
        vkFramebufferCreateInfo->width = jwidth;
        vkFramebufferCreateInfo->height = jheight;
        vkFramebufferCreateInfo->layers = jlayers;

    }
}
