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
    void getVkPipelineDynamicStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineDynamicStateCreateInfoObject,
            VkPipelineDynamicStateCreateInfo *vkPipelineDynamicStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineDynamicStateCreateInfoClass = env->GetObjectClass(jVkPipelineDynamicStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineDynamicStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPipelineDynamicStateCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkPipelineDynamicStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDynamicStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineDynamicStateCreateInfoObject, methodId);
        VkPipelineDynamicStateCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineDynamicStateCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDynamicStateCreateInfoClass, "getDynamicStates", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDynamicStates = env->CallObjectMethod(jVkPipelineDynamicStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkDynamicStates = 0;
        VkDynamicState *vkDynamicStates = nullptr;
        hwjvi::getVkDynamicStateCollection(
                env,
                jVkDynamicStates,
                &vkDynamicStates,
                &numberOfVkDynamicStates,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkPipelineDynamicStateCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineDynamicStateCreateInfo->pNext = (void *)pNext;
        vkPipelineDynamicStateCreateInfo->flags = flags;
        vkPipelineDynamicStateCreateInfo->dynamicStateCount = numberOfVkDynamicStates;
        vkPipelineDynamicStateCreateInfo->pDynamicStates = vkDynamicStates;
    }
}
