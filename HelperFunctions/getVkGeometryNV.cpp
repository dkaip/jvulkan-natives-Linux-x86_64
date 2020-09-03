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
 * getVkGeometryNV.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkGeometryNV(
            JNIEnv *env,
            const jobject jVkGeometryNVObject,
            VkGeometryNV *vkGeometryNV,
            std::vector<void *> *memoryToFree)
    {
        jclass vkGeometryNVClass = env->GetObjectClass(jVkGeometryNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkGeometryNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkGeometryNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkGeometryNVClass, "getGeometryType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkGeometryTypeNV;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkGeometryTypeNVObject = env->CallObjectMethod(jVkGeometryNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkGeometryTypeNVClass = env->GetObjectClass(jVkGeometryTypeNVObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkGeometryTypeNVClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkGeometryTypeNV vkGeometryTypeNVEnumValue = (VkGeometryTypeNV)env->CallIntMethod(jVkGeometryTypeNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryNVClass, "getGeometry", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkGeometryDataNV;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkGeometryDataNVObject = env->CallObjectMethod(jVkGeometryNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryNVClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkGeometryNVObject, methodId);
        VkGeometryFlagsNV flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkGeometryFlagBitsNV");

        vkGeometryNV->sType         = sTypeValue;
        vkGeometryNV->pNext         = (void *)pNext;
        vkGeometryNV->geometryType  = vkGeometryTypeNVEnumValue;

        getVkGeometryDataNV(
                env,
                jVkGeometryDataNVObject,
                &(vkGeometryNV->geometry),
                memoryToFree);

        vkGeometryNV->flags         = flags;
    }
}
