#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
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
        int sTypeValue = getSTypeAsInt(env, jVkCommandBufferAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkCommandBufferAllocateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkCommandBufferAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferAllocateInfoClass, "getCommandPool", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandPool;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkCommandPool = env->CallObjectMethod(jVkCommandBufferAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkCommandPool_T *commandPoolHandle = (VkCommandPool_T *)hwjvi::getHandleValue(env, jVkCommandPool);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferAllocateInfoClass, "getLevel", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkCommandBufferLevel;");
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

        vkCommandBufferAllocateInfo->sType = (VkStructureType)sTypeValue;
        vkCommandBufferAllocateInfo->pNext = (void *)pNext;
        vkCommandBufferAllocateInfo->commandPool = commandPoolHandle;
        vkCommandBufferAllocateInfo->level = vkCommandBufferLevelEnumValue;
        vkCommandBufferAllocateInfo->commandBufferCount = jCommandBufferCount;
    }
}
