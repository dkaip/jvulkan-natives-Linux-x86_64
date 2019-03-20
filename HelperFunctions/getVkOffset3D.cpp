#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkOffset3D(
            JNIEnv *env,
            jobject jVkOffset3DObject,
            VkOffset3D *vkOffset3D,
            std::vector<void *> *memoryToFree)
    {
        jclass vkOffset3DClass = env->GetObjectClass(jVkOffset3DObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkOffset3DClass, "getX", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint x = env->CallIntMethod(jVkOffset3DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkOffset3DClass, "getY", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint y = env->CallIntMethod(jVkOffset3DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkOffset3DClass, "getZ", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint z = env->CallIntMethod(jVkOffset3DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkOffset3D->x = x;
        vkOffset3D->y = y;
        vkOffset3D->z = z;
    }
}
