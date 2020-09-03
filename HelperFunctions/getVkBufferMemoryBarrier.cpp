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
 * getVkBufferMemoryBarrier.cpp
 *
 *  Created on: Sep 3, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBufferMemoryBarrier(
            JNIEnv *env,
            const jobject jVkBufferMemoryBarrierObject,
            VkBufferMemoryBarrier *vkBufferMemoryBarrier,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferMemoryBarrierClass = env->GetObjectClass(jVkBufferMemoryBarrierObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkBufferMemoryBarrierObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkBufferMemoryBarrierObject);
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
        jmethodID methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getSrcAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkBufferMemoryBarrierObject, methodId);
        VkAccessFlags srcAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkAccessFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getDstAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkBufferMemoryBarrierObject, methodId);
        VkAccessFlags dstAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkAccessFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getSrcQueueFamilyIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint srcQueueFamilyIndex = env->CallIntMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getDstQueueFamilyIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint dstQueueFamilyIndex = env->CallIntMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBufferObject = env->CallObjectMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *vkBufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong offset = env->CallLongMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getSize", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong size = env->CallLongMethod(jVkBufferMemoryBarrierObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkBufferMemoryBarrier->sType = sTypeValue;
        vkBufferMemoryBarrier->pNext = (void *)pNext;
        vkBufferMemoryBarrier->srcAccessMask = srcAccessMask;
        vkBufferMemoryBarrier->dstAccessMask = dstAccessMask;
        vkBufferMemoryBarrier->srcQueueFamilyIndex = srcQueueFamilyIndex;
        vkBufferMemoryBarrier->dstQueueFamilyIndex = dstQueueFamilyIndex;
        vkBufferMemoryBarrier->buffer = vkBufferHandle;
        vkBufferMemoryBarrier->offset = offset;
        vkBufferMemoryBarrier->size = size;
    }
}
