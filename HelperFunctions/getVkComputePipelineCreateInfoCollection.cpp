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
 * getVkComputePipelineCreateInfoCollection.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: Douglas Kaip
 */


#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkComputePipelineCreateInfoCollection(
            JNIEnv *env,
            const jobject jVkComputePipelineCreateInfoCollectionObject,
            VkComputePipelineCreateInfo **vkComputePipelineCreateInfos,
            int *numberOfCreateInfos,
            std::vector<void *> *memoryToFree)
    {
        if (jVkComputePipelineCreateInfoCollectionObject == nullptr)
        {
            return;
        }

        jclass vkComputePipelineCreateInfoCollectionClass = env->GetObjectClass(jVkComputePipelineCreateInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkComputePipelineCreateInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkComputePipelineCreateInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfCreateInfos = numberOfElements;
        *vkComputePipelineCreateInfos = (VkComputePipelineCreateInfo *)calloc(numberOfElements, sizeof(VkComputePipelineCreateInfo));
        memoryToFree->push_back(*vkComputePipelineCreateInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkComputePipelineCreateInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkComputePipelineCreateInfoCollectionObject, iteratorMethodId);
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

            jobject jVkComputePipelineCreateInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkComputePipelineCreateInfo(
                    env,
                    jVkComputePipelineCreateInfoObject,
                    &(*vkComputePipelineCreateInfos)[i],
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                break;
            }

            i++;
        } while(true);
    }
}

