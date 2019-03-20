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
    void getVkCommandBufferCollection(
            JNIEnv *env,
            const jobject jVkCommandBufferCollectionObject,
            VkCommandBuffer **vkCommandBuffers,
            int *numberOfVkCommandBuffers,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCommandBufferCollectionClass = env->GetObjectClass(jVkCommandBufferCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkCommandBufferCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkCommandBufferCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkCommandBuffers = numberOfElements;
        *vkCommandBuffers = (VkCommandBuffer *)calloc(numberOfElements, sizeof(VkCommandBuffer *));
        memoryToFree->push_back(*vkCommandBuffers);

        jmethodID iteratorMethodId = env->GetMethodID(vkCommandBufferCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkCommandBufferCollectionObject, iteratorMethodId);
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

            jobject jVkCommandBufferHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkCommandBuffer_T *vkCommandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBufferHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkCommandBuffers)[i] = vkCommandBufferHandle;

            i++;
        } while(true);
    }
}
