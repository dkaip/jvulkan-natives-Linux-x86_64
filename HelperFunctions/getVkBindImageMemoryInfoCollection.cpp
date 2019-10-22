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
 * getVkBindBufferMemoryInfoCollection.cpp
 *
 *  Created on: Mar 22, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBindImageMemoryInfoCollection(
            JNIEnv *env,
            const jobject jVkBindBufferMemoryInfoCollectionObject,
            VkBindImageMemoryInfo **vkBindImageMemoryInfos,
            int *numberOfVkBindImageMemoryInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBindBufferMemoryInfoCollectionClass = env->GetObjectClass(jVkBindBufferMemoryInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBindBufferMemoryInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBindBufferMemoryInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkBindImageMemoryInfos = numberOfElements;
        *vkBindImageMemoryInfos = (VkBindImageMemoryInfo *)calloc(numberOfElements, sizeof(VkBindImageMemoryInfo));
        memoryToFree->push_back(*vkBindImageMemoryInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkBindBufferMemoryInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(vkBindBufferMemoryInfoCollectionClass, iteratorMethodId);
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

            jobject jVkBindImageMemoryInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkBindImageMemoryInfo(
                    env,
                    jVkBindImageMemoryInfoObject,
                    &((*vkBindImageMemoryInfos)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}

