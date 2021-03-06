/*
 * Copyright 2019-2020 Douglas Kaip
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

#include "JVulkanHelperFunctions.hh"

namespace jvulkan
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
