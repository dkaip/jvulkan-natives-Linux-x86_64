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
