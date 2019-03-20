#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkPipelineTessellationStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineTessellationStateCreateInfoObject,
            VkPipelineTessellationStateCreateInfo *vkPipelineTessellationStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineTessellationStateCreateInfoClass = env->GetObjectClass(jVkPipelineTessellationStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineTessellationStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPipelineTessellationStateCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkPipelineTessellationStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineTessellationStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineTessellationStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineTessellationStateCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineTessellationStateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineTessellationStateCreateInfoClass, "getPatchControlPoints", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint patchControlPoints = env->CallIntMethod(jVkPipelineTessellationStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkPipelineTessellationStateCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineTessellationStateCreateInfo->pNext = (void *)pNext;
        vkPipelineTessellationStateCreateInfo->flags = flags;
        vkPipelineTessellationStateCreateInfo->patchControlPoints = patchControlPoints;
    }
}
