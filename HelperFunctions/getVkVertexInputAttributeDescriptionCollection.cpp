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
    void getVkVertexInputAttributeDescriptionCollection(
            JNIEnv *env,
            const jobject jVkVertexInputAttributeDescriptionCollectionObject,
            VkVertexInputAttributeDescription **vkVertexInputAttributeDescription,
            int *numberOfVkVertexInputAttributeDescriptions,
            std::vector<void *> *memoryToFree)
    {
        jclass vkVertexInputAttributeDescriptionCollectionClass = env->GetObjectClass(jVkVertexInputAttributeDescriptionCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkVertexInputAttributeDescriptionCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkVertexInputAttributeDescriptionCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkVertexInputAttributeDescriptions = numberOfElements;
        *vkVertexInputAttributeDescription = (VkVertexInputAttributeDescription *)calloc(numberOfElements, sizeof(VkVertexInputAttributeDescription));
        memoryToFree->push_back(*vkVertexInputAttributeDescription);

        jmethodID iteratorMethodId = env->GetMethodID(vkVertexInputAttributeDescriptionCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkVertexInputAttributeDescriptionCollectionObject, iteratorMethodId);
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

            jobject jVkVertexInputAttributeDescriptionObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkVertexInputAttributeDescription(
                    env,
                    jVkVertexInputAttributeDescriptionObject,
                    &((*vkVertexInputAttributeDescription)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }
}
