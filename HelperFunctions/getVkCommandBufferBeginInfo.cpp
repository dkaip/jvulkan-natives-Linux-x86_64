#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
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
        int sTypeValue = getSTypeAsInt(env, jVkCommandBufferBeginInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkCommandBufferBeginInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkCommandBufferBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferBeginInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkCommandBufferBeginInfoObject, methodId);
        VkCommandBufferUsageFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkCommandBufferUsageFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandBufferBeginInfoClass, "getInheritanceInfo", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkCommandBufferInheritanceInfo;");
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
