#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkPipelineDynamicStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineDynamicStateCreateInfoObject,
            VkPipelineDynamicStateCreateInfo *vkPipelineDynamicStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineDynamicStateCreateInfoClass = env->GetObjectClass(jVkPipelineDynamicStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineDynamicStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPipelineDynamicStateCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkPipelineDynamicStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDynamicStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineDynamicStateCreateInfoObject, methodId);
        VkPipelineDynamicStateCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineDynamicStateCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDynamicStateCreateInfoClass, "getDynamicStates", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDynamicStates = env->CallObjectMethod(jVkPipelineDynamicStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkDynamicStates = 0;
        VkDynamicState *vkDynamicStates = nullptr;
        hwjvi::getVkDynamicStateCollection(
                env,
                jVkDynamicStates,
                &vkDynamicStates,
                &numberOfVkDynamicStates,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkPipelineDynamicStateCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineDynamicStateCreateInfo->pNext = (void *)pNext;
        vkPipelineDynamicStateCreateInfo->flags = flags;
        vkPipelineDynamicStateCreateInfo->dynamicStateCount = numberOfVkDynamicStates;
        vkPipelineDynamicStateCreateInfo->pDynamicStates = vkDynamicStates;
    }
}
