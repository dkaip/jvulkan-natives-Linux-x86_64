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
/*
 * getVkViewport.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkViewport(
            JNIEnv *env,
            jobject jVkViewportObject,
            VkViewport *vkViewport,
            std::vector<void *> *memoryToFree)
    {
        jclass vkViewportClass = env->GetObjectClass(jVkViewportObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkViewportClass, "getX", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat x = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getY", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat y = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getWidth", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat width = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getHeight", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat height = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getMinDepth", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat minDepth = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getMaxDepth", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat maxDepth = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkViewport->x = x;
        vkViewport->y = y;
        vkViewport->width  = width;
        vkViewport->height = height;
        vkViewport->minDepth = minDepth;
        vkViewport->maxDepth = maxDepth;
    }
}
