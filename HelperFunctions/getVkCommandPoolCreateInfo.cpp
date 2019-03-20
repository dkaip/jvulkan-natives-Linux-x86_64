#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkCommandPoolCreateInfo(
            JNIEnv *env,
            jobject jVkCommandPoolCreateInfoObject,
            VkCommandPoolCreateInfo *vkCommandPoolCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCommandPoolCreateInfoClass = env->GetObjectClass(jVkCommandPoolCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkCommandPoolCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkCommandPoolCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkCommandPoolCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandPoolCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkCommandPoolCreateInfoObject, methodId);
        VkCommandPoolCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkCommandPoolCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandPoolCreateInfoClass, "getQueueFamilyIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jQueueFamilyIndex = env->CallIntMethod(jVkCommandPoolCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkCommandPoolCreateInfo->sType = (VkStructureType)sTypeValue;
        vkCommandPoolCreateInfo->pNext = (void *)pNext;
        vkCommandPoolCreateInfo->flags = flags;
        vkCommandPoolCreateInfo->queueFamilyIndex = jQueueFamilyIndex;
    }
}
