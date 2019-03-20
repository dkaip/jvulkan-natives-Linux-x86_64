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
    void getVkPipelineColorBlendAttachmentState(
            JNIEnv *env,
            const jobject jVkPipelineColorBlendAttachmentStateObject,
            VkPipelineColorBlendAttachmentState *vkPipelineColorBlendAttachmentState,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineColorBlendAttachmentStateClass = env->GetObjectClass(jVkPipelineColorBlendAttachmentStateObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateClass, "isBlendEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jBlendEnable = env->CallBooleanMethod(jVkPipelineColorBlendAttachmentStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateClass, "getSrcColorBlendFactor", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkBlendFactor;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jSrcColorBlendFactorObject = env->CallObjectMethod(jVkPipelineColorBlendAttachmentStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass srcColorBlendFactorObjectEnumClass = env->GetObjectClass(jSrcColorBlendFactorObject);

        jmethodID valueOfMethodId = env->GetMethodID(srcColorBlendFactorObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBlendFactor srcColorBlendFactorEnumValue = (VkBlendFactor)env->CallIntMethod(jSrcColorBlendFactorObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateClass, "getDstColorBlendFactor", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkBlendFactor;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jDstColorBlendFactorObject = env->CallObjectMethod(jVkPipelineColorBlendAttachmentStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass dstColorBlendFactorObjectEnumClass = env->GetObjectClass(jDstColorBlendFactorObject);

        valueOfMethodId = env->GetMethodID(dstColorBlendFactorObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBlendFactor dstColorBlendFactorEnumValue = (VkBlendFactor)env->CallIntMethod(jDstColorBlendFactorObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateClass, "getColorBlendOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkBlendOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jColorBlendOpObject = env->CallObjectMethod(jVkPipelineColorBlendAttachmentStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass colorBlendOpObjectEnumClass = env->GetObjectClass(jColorBlendOpObject);

        valueOfMethodId = env->GetMethodID(colorBlendOpObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBlendOp colorBlendOpEnumValue = (VkBlendOp)env->CallIntMethod(jColorBlendOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateClass, "getSrcAlphaBlendFactor", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkBlendFactor;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jSrcAlphaBlendFactorObject = env->CallObjectMethod(jVkPipelineColorBlendAttachmentStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass srcAlphaBlendFactorObjectEnumClass = env->GetObjectClass(jSrcAlphaBlendFactorObject);

        valueOfMethodId = env->GetMethodID(srcAlphaBlendFactorObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBlendFactor srcAlphaBlendFactorEnumValue = (VkBlendFactor)env->CallIntMethod(jSrcAlphaBlendFactorObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateClass, "getDstAlphaBlendFactor", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkBlendFactor;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jDstAlphaBlendFactorObject = env->CallObjectMethod(jVkPipelineColorBlendAttachmentStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass dstAlphaBlendFactorObjectEnumClass = env->GetObjectClass(jDstAlphaBlendFactorObject);

        valueOfMethodId = env->GetMethodID(dstAlphaBlendFactorObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBlendFactor dstAlphaBlendFactorEnumValue = (VkBlendFactor)env->CallIntMethod(jDstAlphaBlendFactorObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateClass, "getAlphaBlendOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkBlendOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jgetAlphaBlendOpObject = env->CallObjectMethod(jVkPipelineColorBlendAttachmentStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass alphaBlendOpObjectEnumClass = env->GetObjectClass(jgetAlphaBlendOpObject);

        valueOfMethodId = env->GetMethodID(alphaBlendOpObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBlendOp alphaBlendOpEnumValue = (VkBlendOp)env->CallIntMethod(jgetAlphaBlendOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateClass, "getColorWriteMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineColorBlendAttachmentStateObject, methodId);
        VkColorComponentFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkColorComponentFlagBits");



        vkPipelineColorBlendAttachmentState->blendEnable = jBlendEnable;
        vkPipelineColorBlendAttachmentState->srcColorBlendFactor = srcColorBlendFactorEnumValue;
        vkPipelineColorBlendAttachmentState->dstColorBlendFactor = dstColorBlendFactorEnumValue;
        vkPipelineColorBlendAttachmentState->colorBlendOp = colorBlendOpEnumValue;
        vkPipelineColorBlendAttachmentState->srcAlphaBlendFactor = srcAlphaBlendFactorEnumValue;
        vkPipelineColorBlendAttachmentState->dstAlphaBlendFactor = dstAlphaBlendFactorEnumValue;
        vkPipelineColorBlendAttachmentState->alphaBlendOp = alphaBlendOpEnumValue;
        vkPipelineColorBlendAttachmentState->colorWriteMask = flags;
    }

    void getVkPipelineColorBlendAttachmentStateCollection(
            JNIEnv *env,
            const jobject jVkPipelineColorBlendAttachmentStateCollectionObject,
            VkPipelineColorBlendAttachmentState **vkPipelineColorBlendAttachmentStates,
            int *numberOfVkPipelineColorBlendAttachmentStates,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineColorBlendAttachmentStateCollectionClass = env->GetObjectClass(jVkPipelineColorBlendAttachmentStateCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkPipelineColorBlendAttachmentStateCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkPipelineColorBlendAttachmentStates = numberOfElements;
        *vkPipelineColorBlendAttachmentStates = (VkPipelineColorBlendAttachmentState *)calloc(numberOfElements, sizeof(VkPipelineColorBlendAttachmentState));
        memoryToFree->push_back(*vkPipelineColorBlendAttachmentStates);

        jmethodID iteratorMethodId = env->GetMethodID(vkPipelineColorBlendAttachmentStateCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkPipelineColorBlendAttachmentStateCollectionObject, iteratorMethodId);
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

            jobject jVkPipelineColorBlendAttachmentStateObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkPipelineColorBlendAttachmentState(
                    env,
                    jVkPipelineColorBlendAttachmentStateObject,
                    &((*vkPipelineColorBlendAttachmentStates)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }
}
