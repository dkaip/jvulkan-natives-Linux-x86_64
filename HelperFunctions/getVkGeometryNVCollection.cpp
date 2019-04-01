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
 * getVkGeometryNVCollection.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

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
        int sTypeValue = getSTypeAsInt(env, jVkGeometryNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkGeometryNVClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkGeometryNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryNVClass, "getGeometryType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkGeometryTypeNV;");
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
        methodId = env->GetMethodID(vkGeometryNVClass, "getGeometry", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkGeometryDataNV;");
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
                "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkGeometryFlagBitsNV");

        vkGeometryNV->sType         = (VkStructureType)sTypeValue;
        vkGeometryNV->pNext         = (void *)pNext;
        vkGeometryNV->geometryType  = vkGeometryTypeNVEnumValue;

        getVkGeometryDataNV(
                env,
                jVkGeometryDataNVObject,
                &(vkGeometryNV->geometry),
                memoryToFree);

        vkGeometryNV->flags         = flags;
    }

    void getVkGeometryNVCollection(
            JNIEnv *env,
            const jobject jVkGeometryNVCollectionObject,
            VkGeometryNV **vkGeometryNVs,
            int *numberOfVkGeometryNVs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorBufferInfoCollectionClass = env->GetObjectClass(jVkGeometryNVCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorBufferInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkGeometryNVCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkGeometryNVs = numberOfElements;
        *vkGeometryNVs = (VkGeometryNV *)calloc(numberOfElements, sizeof(VkGeometryNV));
        memoryToFree->push_back(*vkGeometryNVs);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorBufferInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkGeometryNVCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkGeometryNVObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkGeometryNV(
                    env,
                    jVkGeometryNVObject,
                    &((*vkGeometryNVs)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}

