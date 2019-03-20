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
    void getVkDescriptorPoolCreateInfo(
            JNIEnv *env,
            jobject jVkDescriptorPoolCreateInfoObject,
            VkDescriptorPoolCreateInfo *vkDescriptorPoolCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorPoolCreateInfoClass = env->GetObjectClass(jVkDescriptorPoolCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDescriptorPoolCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorPoolCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkDescriptorPoolCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorPoolCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDescriptorPoolCreateInfoObject, methodId);
        VkDescriptorPoolCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkDescriptorPoolCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorPoolCreateInfoClass, "getMaxSets", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jMaxSets = env->CallIntMethod(jVkDescriptorPoolCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorPoolCreateInfoClass, "getPoolSizes", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorPoolSizeCollection = env->CallObjectMethod(jVkDescriptorPoolCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkDescriptorPoolSizes = 0;
        VkDescriptorPoolSize *vkDescriptorPoolSizes = nullptr;

        if (jVkDescriptorPoolSizeCollection != nullptr)
        {
            jvulkan::getVkDescriptorPoolSizeCollection(
                    env,
                    jVkDescriptorPoolSizeCollection,
                    &vkDescriptorPoolSizes,
                    &numberOfVkDescriptorPoolSizes,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDescriptorPoolCreateInfo->sType = (VkStructureType)sTypeValue;
        vkDescriptorPoolCreateInfo->pNext = (void *)pNext;
        vkDescriptorPoolCreateInfo->flags = flags;
        vkDescriptorPoolCreateInfo->maxSets = jMaxSets;
        vkDescriptorPoolCreateInfo->poolSizeCount = numberOfVkDescriptorPoolSizes;
        vkDescriptorPoolCreateInfo->pPoolSizes = vkDescriptorPoolSizes;
    }
}
