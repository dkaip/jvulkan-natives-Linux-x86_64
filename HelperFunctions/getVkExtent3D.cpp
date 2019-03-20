/*
 * Copyright 2019 Douglas Kaip
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace jvulkan
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
