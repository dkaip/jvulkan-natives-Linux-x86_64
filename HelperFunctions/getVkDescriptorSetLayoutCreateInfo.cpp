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
    void getVkDescriptorSetLayoutCreateInfo(
            JNIEnv *env,
            jobject jVkDescriptorSetLayoutCreateInfoObject,
            VkDescriptorSetLayoutCreateInfo *vkDescriptorSetLayoutCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetLayoutCreateInfoClass = env->GetObjectClass(jVkDescriptorSetLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDescriptorSetLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorSetLayoutCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkDescriptorSetLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetLayoutCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDescriptorSetLayoutCreateInfoObject, methodId);
        VkDescriptorSetLayoutCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkDescriptorSetLayoutCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetLayoutCreateInfoClass, "getBindings", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorSetLayoutBindingCollection = env->CallObjectMethod(jVkDescriptorSetLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkDescriptorSetLayoutBindingCollection = 0;
        VkDescriptorSetLayoutBinding *vkDescriptorSetLayoutBindings = nullptr;

        if (jVkDescriptorSetLayoutBindingCollection != nullptr)
        {
            hwjvi::getVkDescriptorSetLayoutBindingCollection(
                    env,
                    jVkDescriptorSetLayoutBindingCollection,
                    &vkDescriptorSetLayoutBindings,
                    &numberOfVkDescriptorSetLayoutBindingCollection,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDescriptorSetLayoutCreateInfo->sType = (VkStructureType)sTypeValue;
        vkDescriptorSetLayoutCreateInfo->pNext = (void *)pNext;
        vkDescriptorSetLayoutCreateInfo->flags = flags;
        vkDescriptorSetLayoutCreateInfo->bindingCount = numberOfVkDescriptorSetLayoutBindingCollection;
        vkDescriptorSetLayoutCreateInfo->pBindings = vkDescriptorSetLayoutBindings;
    }
}
