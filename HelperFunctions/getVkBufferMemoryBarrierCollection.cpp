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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
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
