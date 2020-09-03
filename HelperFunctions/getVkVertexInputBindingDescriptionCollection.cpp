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
    void getVkVertexInputBindingDescriptionCollection(
            JNIEnv *env,
            const jobject jVkVertexInputBindingDescriptionCollectionObject,
            VkVertexInputBindingDescription **vkVertexInputBindingDescriptions,
            int *numberOfVkVertexInputBindingDescriptions,
            std::vector<void *> *memoryToFree)
    {
        jclass vkVertexInputBindingDescriptionCollectionClass = env->GetObjectClass(jVkVertexInputBindingDescriptionCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkVertexInputBindingDescriptionCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkVertexInputBindingDescriptionCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkVertexInputBindingDescriptions = numberOfElements;
        *vkVertexInputBindingDescriptions = (VkVertexInputBindingDescription *)calloc(numberOfElements, sizeof(VkVertexInputBindingDescription));
        memoryToFree->push_back(*vkVertexInputBindingDescriptions);

        jmethodID iteratorMethodId = env->GetMethodID(vkVertexInputBindingDescriptionCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkVertexInputBindingDescriptionCollectionObject, iteratorMethodId);
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

            jobject jVkVertexInputBindingDescriptionObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkVertexInputBindingDescription(
                    env,
                    jVkVertexInputBindingDescriptionObject,
                    &((*vkVertexInputBindingDescriptions)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }
}
