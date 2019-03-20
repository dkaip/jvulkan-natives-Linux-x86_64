#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkExtent2D(
            JNIEnv *env,
            jobject jVkExtent2DObject,
            VkExtent2D *vkExtent2D,
            std::vector<void *> *memoryToFree)
    {
        jclass vkExtent2DClass = env->GetObjectClass(jVkExtent2DObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkExtent2DClass, "getWidth", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint width = env->CallIntMethod(jVkExtent2DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkExtent2DClass, "getHeight", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint height = env->CallIntMethod(jVkExtent2DObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkExtent2D->width = width;
        vkExtent2D->height = height;
    }
}
