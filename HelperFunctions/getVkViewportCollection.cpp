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
 * getVkViewportCollection.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkViewportCollection(
            JNIEnv *env,
            const jobject jVkViewportCollectionObject,
            VkViewport **viewports,
            int *numberOfViewports,
            std::vector<void *> *memoryToFree)
    {
        if (jVkViewportCollectionObject == nullptr)
        {
            return;
        }

        jclass vkViewportCollectionClass = env->GetObjectClass(jVkViewportCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkViewportCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkViewportCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfViewports = numberOfElements;
        *viewports = (VkViewport *)calloc(numberOfElements, sizeof(VkViewport));
        memoryToFree->push_back(*viewports);

        jmethodID iteratorMethodId = env->GetMethodID(vkViewportCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkViewportCollectionObject, iteratorMethodId);
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

            jobject jVkViewportObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkViewport(
                    env,
                    jVkViewportObject,
                    &(*viewports)[i],
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                break;
            }

            i++;
        } while(true);
    }
}
