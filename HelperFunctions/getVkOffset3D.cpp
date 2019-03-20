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
