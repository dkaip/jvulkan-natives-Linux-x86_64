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
    void getVkPipelineDepthStencilStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineDepthStencilStateCreateInfoObject,
            VkPipelineDepthStencilStateCreateInfo *vkPipelineDepthStencilStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineDepthStencilStateCreateInfoClass = env->GetObjectClass(jVkPipelineDepthStencilStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineDepthStencilStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineDepthStencilStateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "isDepthTestEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jDepthTestEnable = env->CallBooleanMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "isDepthWriteEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jDepthWriteEnable = env->CallBooleanMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "getDepthCompareOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkCompareOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkCompareOpObject = env->CallObjectMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkCompareOpObjectEnumClass = env->GetObjectClass(jVkCompareOpObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkCompareOpObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint depthCompareOpEnumValue = env->CallIntMethod(jVkCompareOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "isDepthBoundsTestEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jDepthBoundsTestEnable = env->CallBooleanMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "isStencilTestEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jStencilTestEnable = env->CallBooleanMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "getFront", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkStencilOpState;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkStencilOpStateObject = env->CallObjectMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkStencilOpState front = {};
        if (jVkStencilOpStateObject != nullptr)
        {
            getVkStencilOpState(
                    env,
                    jVkStencilOpStateObject,
                    &front,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "getBack", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkStencilOpState;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkStencilOpStateObject = env->CallObjectMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkStencilOpState back = {};
        if (jVkStencilOpStateObject != nullptr)
        {
            getVkStencilOpState(
                    env,
                    jVkStencilOpStateObject,
                    &back,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "getMinDepthBounds", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat jMinDepthBounds = env->CallFloatMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineDepthStencilStateCreateInfoClass, "getMaxDepthBounds", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat jMaxDepthBounds = env->CallFloatMethod(jVkPipelineDepthStencilStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }


        vkPipelineDepthStencilStateCreateInfo->sType            = (VkStructureType)sTypeValue;
        vkPipelineDepthStencilStateCreateInfo->pNext            = (void *)pNext;
        vkPipelineDepthStencilStateCreateInfo->flags            = (VkPipelineDepthStencilStateCreateFlags)flags;
        vkPipelineDepthStencilStateCreateInfo->depthTestEnable  = jDepthTestEnable;
        vkPipelineDepthStencilStateCreateInfo->depthWriteEnable = jDepthWriteEnable;
        vkPipelineDepthStencilStateCreateInfo->depthCompareOp   = (VkCompareOp)depthCompareOpEnumValue;
        vkPipelineDepthStencilStateCreateInfo->depthBoundsTestEnable = jDepthBoundsTestEnable;
        vkPipelineDepthStencilStateCreateInfo->stencilTestEnable = jStencilTestEnable;

        vkPipelineDepthStencilStateCreateInfo->front.failOp         = front.failOp;
        vkPipelineDepthStencilStateCreateInfo->front.passOp         = front.passOp;
        vkPipelineDepthStencilStateCreateInfo->front.depthFailOp    = front.depthFailOp;
        vkPipelineDepthStencilStateCreateInfo->front.compareOp      = front.compareOp;
        vkPipelineDepthStencilStateCreateInfo->front.compareMask    = front.compareMask;
        vkPipelineDepthStencilStateCreateInfo->front.writeMask      = front.writeMask;
        vkPipelineDepthStencilStateCreateInfo->front.reference      = front.reference;

        vkPipelineDepthStencilStateCreateInfo->back.failOp          = back.failOp;
        vkPipelineDepthStencilStateCreateInfo->back.passOp          = back.passOp;
        vkPipelineDepthStencilStateCreateInfo->back.depthFailOp     = back.depthFailOp;
        vkPipelineDepthStencilStateCreateInfo->back.compareOp       = back.compareOp;
        vkPipelineDepthStencilStateCreateInfo->back.compareMask     = back.compareMask;
        vkPipelineDepthStencilStateCreateInfo->back.writeMask       = back.writeMask;
        vkPipelineDepthStencilStateCreateInfo->back.reference       = back.reference;

        vkPipelineDepthStencilStateCreateInfo->minDepthBounds = jMinDepthBounds;
        vkPipelineDepthStencilStateCreateInfo->maxDepthBounds = jMaxDepthBounds;
    }
}
