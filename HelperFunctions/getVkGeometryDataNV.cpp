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

/*
 * getVkGeometryDataNV.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "JVulkanHelperFunctions.hh"

namespace jvulkan
{
    void getVkGeometryDataNV(
            JNIEnv *env,
            const jobject jVkGeometryDataNVObject,
            VkGeometryDataNV *vkGeometryDataNV,
            std::vector<void *> *memoryToFree)
    {
        jclass vkGeometryDataNVClass = env->GetObjectClass(jVkGeometryDataNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkGeometryDataNVClass, "getTriangles", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkGeometryTrianglesNV;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkGeometryTrianglesNVObject = env->CallObjectMethod(jVkGeometryDataNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryDataNVClass, "getAabbs", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkGeometryAABBNV;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkGeometryAABBNVObject = env->CallObjectMethod(jVkGeometryDataNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        getVkGeometryTrianglesNV(
                env,
                jVkGeometryTrianglesNVObject,
                &(vkGeometryDataNV->triangles),
                memoryToFree);

        getVkGeometryAABBNV(
                env,
                jVkGeometryAABBNVObject,
                &(vkGeometryDataNV->aabbs),
                memoryToFree);
    }
}
