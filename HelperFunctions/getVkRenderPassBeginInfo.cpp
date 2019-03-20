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
    void getVkRenderPassBeginInfo(
            JNIEnv *env,
            jobject jVkRenderPassBeginInfoObject,
            VkRenderPassBeginInfo *vkRenderPassBeginInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkRenderPassBeginInfoClass = env->GetObjectClass(jVkRenderPassBeginInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkRenderPassBeginInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkRenderPassBeginInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkRenderPassBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassBeginInfoClass, "getRenderPass", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkRenderPass;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkRenderPassObject = env->CallObjectMethod(jVkRenderPassBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkRenderPass_T *renderPassHandle = (VkRenderPass_T *)jvulkan::getHandleValue(env, jVkRenderPassObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassBeginInfoClass, "getFramebuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkFramebuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFramebufferObject = env->CallObjectMethod(jVkRenderPassBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFramebuffer_T *framebufferHandle = (VkFramebuffer_T *)jvulkan::getHandleValue(env, jVkFramebufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassBeginInfoClass, "getRenderArea", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkRect2D;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkRect2DObject = env->CallObjectMethod(jVkRenderPassBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkRect2D vkRect2D = {};
        if (jVkRect2DObject != nullptr)
        {
//            std::cout << "jVkRect2DObject is " << jVkRect2DObject << std::endl;
            getVkRect2D(env, jVkRect2DObject, &vkRect2D, memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassBeginInfoClass, "getClearValues", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jClearValuesCollectionObject = env->CallObjectMethod(jVkRenderPassBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfClearValues = 0;
        VkClearValue *vkClearValues = nullptr;
        if (jClearValuesCollectionObject != nullptr)
        {
            jvulkan::getVkClearValueCollection(
                    env,
                    jClearValuesCollectionObject,
                    &vkClearValues,
                    &numberOfClearValues,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkRenderPassBeginInfo->sType = (VkStructureType)sTypeValue;
        vkRenderPassBeginInfo->pNext = (void *)pNext;
        vkRenderPassBeginInfo->renderPass = renderPassHandle;
        vkRenderPassBeginInfo->framebuffer = framebufferHandle;
        memcpy(&vkRenderPassBeginInfo->renderArea, &vkRect2D, sizeof(VkRect2D));
        vkRenderPassBeginInfo->clearValueCount = numberOfClearValues;
        vkRenderPassBeginInfo->pClearValues = vkClearValues;
    }
}
