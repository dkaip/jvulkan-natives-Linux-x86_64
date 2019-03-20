#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkExtent3D(
            JNIEnv *env,
            jobject jVkExtent3DObject,
            VkExtent3D *vkExtent3D,
            std::vector<void *> *memoryToFree)
    {
        jclass vkExtent3DClass = env->GetObjectClass(jVkExtent3DObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkExtent3DClass, "getWidth", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint width = env->CallIntMethod(jVkExtent3DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkExtent3DClass, "getHeight", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint height = env->CallIntMethod(jVkExtent3DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkExtent3DClass, "getDepth", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint depth = env->CallIntMethod(jVkExtent3DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkExtent3D->width  = width;
        vkExtent3D->height = height;
        vkExtent3D->depth  = depth;
    }
}
