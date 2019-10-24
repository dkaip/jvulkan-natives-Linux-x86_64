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
 * getVkDescriptorBufferInfo.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "JVulkanHelperFunctions.hh"

namespace jvulkan
{
    void getVkDescriptorBufferInfo(
            JNIEnv *env,
            const jobject jVkDescriptorBufferInfoObject,
            VkDescriptorBufferInfo *vkDescriptorBufferInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorBufferInfoClass = env->GetObjectClass(jVkDescriptorBufferInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorBufferInfoClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBufferObject = env->CallObjectMethod(jVkDescriptorBufferInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorBufferInfoClass, "getOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong jOffset = env->CallLongMethod(jVkDescriptorBufferInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
         methodId = env->GetMethodID(vkDescriptorBufferInfoClass, "getRange", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong jRange = env->CallLongMethod(jVkDescriptorBufferInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkDescriptorBufferInfo->buffer = bufferHandle;
        vkDescriptorBufferInfo->offset = jOffset;
        vkDescriptorBufferInfo->range = jRange;
    }
}
