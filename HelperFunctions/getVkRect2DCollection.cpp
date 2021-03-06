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
#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "JVulkanHelperFunctions.hh"

namespace jvulkan
{
    void getVkRect2DCollection(
            JNIEnv *env,
            const jobject jVkRect2DCollectionObject,
            VkRect2D **vkRect2Ds,
            int *numberOfVkRect2Ds,
            std::vector<void *> *memoryToFree)
    {
        if (jVkRect2DCollectionObject == nullptr)
        {
            return;
        }

        jclass vkRect2DCollectionClass = env->GetObjectClass(jVkRect2DCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkRect2DCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkRect2DCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkRect2Ds = numberOfElements;
        *vkRect2Ds = (VkRect2D *)calloc(numberOfElements, sizeof(VkRect2D));
        memoryToFree->push_back(*vkRect2Ds);

        jmethodID iteratorMethodId = env->GetMethodID(vkRect2DCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkRect2DCollectionObject, iteratorMethodId);
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

            jobject jVkRect2DsObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkRect2D(
                    env,
                    jVkRect2DsObject,
                    &(*vkRect2Ds)[i],
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                break;
            }

            i++;
        } while(true);
    }
}
