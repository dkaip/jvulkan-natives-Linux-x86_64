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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkMemoryBarrier(
            JNIEnv *env,
            const jobject jVkMemoryBarrierObject,
            VkMemoryBarrier *vkMemoryBarrier,
            std::vector<void *> *memoryToFree)
    {
        jclass vkMemoryBarrierClass = env->GetObjectClass(jVkMemoryBarrierObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkMemoryBarrierObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkMemoryBarrierObject);
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
        jmethodID methodId = env->GetMethodID(vkMemoryBarrierClass, "getSrcAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkMemoryBarrierObject, methodId);
        VkPipelineStageFlags srcAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkMemoryBarrierClass, "getDstAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkMemoryBarrierObject, methodId);
        VkPipelineStageFlags dstAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

        vkMemoryBarrier->sType = (VkStructureType)sTypeValue;
        vkMemoryBarrier->pNext = (void *)pNext;
        vkMemoryBarrier->srcAccessMask = srcAccessMask;
        vkMemoryBarrier->dstAccessMask = dstAccessMask;
    }

    void getVkMemoryBarrierCollection(
            JNIEnv *env,
            const jobject jVkMemoryBarrierCollectionObject,
            VkMemoryBarrier **vkMemoryBarriers,
            int *numberOfVkMemoryBarriers,
            std::vector<void *> *memoryToFree)
    {
        jclass vkMemoryBarrierCollectionClass = env->GetObjectClass(jVkMemoryBarrierCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkMemoryBarrierCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkMemoryBarrierCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkMemoryBarriers = numberOfElements;
        *vkMemoryBarriers = (VkMemoryBarrier *)calloc(numberOfElements, sizeof(VkMemoryBarrier));
        memoryToFree->push_back(*vkMemoryBarriers);

        jmethodID iteratorMethodId = env->GetMethodID(vkMemoryBarrierCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(vkMemoryBarrierCollectionClass, iteratorMethodId);
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

            jobject jVkMemoryBarrierObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkMemoryBarrier(
                    env,
                    jVkMemoryBarrierObject,
                    &((*vkMemoryBarriers)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
