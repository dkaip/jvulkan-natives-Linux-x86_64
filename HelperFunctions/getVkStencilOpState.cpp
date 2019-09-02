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
    void getVkStencilOpState(
            JNIEnv *env,
            jobject jVkStencilOpStateObject,
            VkStencilOpState *vkStencilOpState,
            std::vector<void *> *memoryToFree)
    {
        jclass vkStencilOpStateClass = env->GetObjectClass(jVkStencilOpStateObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkStencilOpStateClass, "getFailOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkStencilOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkStencilOpObject = env->CallObjectMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkStencilOpEnumClass = env->GetObjectClass(jVkStencilOpObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkStencilOpEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint failOpEnumValue = env->CallIntMethod(jVkStencilOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getPassOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkStencilOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkStencilOpObject = env->CallObjectMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkStencilOpEnumClass = env->GetObjectClass(jVkStencilOpObject);

        valueOfMethodId = env->GetMethodID(vkStencilOpEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint passOpEnumValue = env->CallIntMethod(jVkStencilOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getDepthFailOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkStencilOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkStencilOpObject = env->CallObjectMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkStencilOpEnumClass = env->GetObjectClass(jVkStencilOpObject);

        valueOfMethodId = env->GetMethodID(vkStencilOpEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint depthFailOpEnumValue = env->CallIntMethod(jVkStencilOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getCompareOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkCompareOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkCompareOpObject = env->CallObjectMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkCompareOpObjectEnumClass = env->GetObjectClass(jVkCompareOpObject);

        valueOfMethodId = env->GetMethodID(vkCompareOpObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint compareOpEnumValue = env->CallIntMethod(jVkCompareOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getCompareMask", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint compareMask = env->CallIntMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getWriteMask", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint writeMask = env->CallIntMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getReference", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint reference = env->CallIntMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkStencilOpState->failOp        = (VkStencilOp)failOpEnumValue;
        vkStencilOpState->passOp        = (VkStencilOp)passOpEnumValue;
        vkStencilOpState->depthFailOp   = (VkStencilOp)depthFailOpEnumValue;
        vkStencilOpState->compareOp     = (VkCompareOp)compareOpEnumValue;
        vkStencilOpState->compareMask   = compareMask;
        vkStencilOpState->writeMask     = writeMask;
        vkStencilOpState->reference     = reference;
    }
}
