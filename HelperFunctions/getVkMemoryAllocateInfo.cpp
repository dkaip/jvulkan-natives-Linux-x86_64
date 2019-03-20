#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkMemoryAllocateInfo(
            JNIEnv *env,
            jobject jVkMemoryAllocateInfoObject,
            VkMemoryAllocateInfo *vkMemoryAllocateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkMemoryAllocateInfoClass = env->GetObjectClass(jVkMemoryAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkMemoryAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkMemoryAllocateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkMemoryAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkMemoryAllocateInfoClass, "getAllocationSize", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong jAllocationSize = env->CallLongMethod(jVkMemoryAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkMemoryAllocateInfoClass, "getMemoryTypeIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jMemoryTypeIndex = env->CallIntMethod(jVkMemoryAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkMemoryAllocateInfo->sType = (VkStructureType)sTypeValue;
        vkMemoryAllocateInfo->pNext = (void *)pNext;
        vkMemoryAllocateInfo->allocationSize = jAllocationSize;
        vkMemoryAllocateInfo->memoryTypeIndex = jMemoryTypeIndex;
    }
}
