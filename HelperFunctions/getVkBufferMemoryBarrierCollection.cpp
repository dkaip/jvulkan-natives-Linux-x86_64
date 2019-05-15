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

#include "HelperFunctions.hh"
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
        int sTypeValue = getSTypeAsInt(env, jVkBufferMemoryBarrierObject);
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
        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
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
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAccessFlagBits");

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
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAccessFlagBits");

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
        methodId = env->GetMethodID(vkBufferMemoryBarrierClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkBuffer;");
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

        vkBufferMemoryBarrier->sType = (VkStructureType)sTypeValue;
        vkBufferMemoryBarrier->pNext = (void *)pNext;
        vkBufferMemoryBarrier->srcAccessMask = srcAccessMask;
        vkBufferMemoryBarrier->dstAccessMask = dstAccessMask;
        vkBufferMemoryBarrier->srcQueueFamilyIndex = srcQueueFamilyIndex;
        vkBufferMemoryBarrier->dstQueueFamilyIndex = dstQueueFamilyIndex;
        vkBufferMemoryBarrier->buffer = vkBufferHandle;
        vkBufferMemoryBarrier->offset = offset;
        vkBufferMemoryBarrier->size = size;
    }

    void getVkBufferMemoryBarrierCollection(
            JNIEnv *env,
            const jobject jVkBufferMemoryBarrierCollectionObject,
            VkBufferMemoryBarrier **vkBufferMemoryBarriers,
            int *numberOfVkBufferMemoryBarriers,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferMemoryBarrierCollectionClass = env->GetObjectClass(jVkBufferMemoryBarrierCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBufferMemoryBarrierCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBufferMemoryBarrierCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkBufferMemoryBarriers = numberOfElements;
        *vkBufferMemoryBarriers = (VkBufferMemoryBarrier *)calloc(numberOfElements, sizeof(VkBufferMemoryBarrier));
        memoryToFree->push_back(*vkBufferMemoryBarriers);

        jmethodID iteratorMethodId = env->GetMethodID(vkBufferMemoryBarrierCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkBufferMemoryBarrierCollectionObject, iteratorMethodId);
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

            jobject jVkBufferMemoryBarrierObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkBufferMemoryBarrier(
                    env,
                    jVkBufferMemoryBarrierObject,
                    &((*vkBufferMemoryBarriers)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
