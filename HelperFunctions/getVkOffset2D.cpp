#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkOffset2D(
            JNIEnv *env,
            jobject jVkOffset2DObject,
            VkOffset2D *vkOffset2D,
            std::vector<void *> *memoryToFree)
    {
        jclass vkOffset2DClass = env->GetObjectClass(jVkOffset2DObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkOffset2DClass, "getX", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint x = env->CallIntMethod(jVkOffset2DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkOffset2DClass, "getY", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint y = env->CallIntMethod(jVkOffset2DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkOffset2D->x = x;
        vkOffset2D->y = y;
    }
}
