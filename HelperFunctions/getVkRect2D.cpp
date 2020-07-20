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

#include "JVulkanHelperFunctions.hh"

namespace jvulkan
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
        jmethodID methodId = env->GetMethodID(vkRect2DClass, "getOffset", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D;");
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
        methodId = env->GetMethodID(vkRect2DClass, "getExtent", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;");
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
