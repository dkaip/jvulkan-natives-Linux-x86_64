#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkRect2D(
            JNIEnv *env,
            jobject jVkRect2DObject,
            VkRect2D *vkRect2D,
            std::vector<void *> *memoryToFree)
    {
        jclass vkRect2DClass = env->GetObjectClass(jVkRect2DObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkRect2DClass, "getOffset", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkOffset2D;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkOffset2DObject = env->CallObjectMethod(jVkRect2DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        getVkOffset2D(env, jVkOffset2DObject, &(vkRect2D->offset), memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRect2DClass, "getExtent", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkExtent2D;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkExtent2DObject = env->CallObjectMethod(jVkRect2DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        getVkExtent2D(env, jVkExtent2DObject, &(vkRect2D->extent), memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }
}
