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
    void getVkDescriptorPoolSize(
            JNIEnv *env,
            const jobject jVkDescriptorPoolSizeObject,
            VkDescriptorPoolSize *vkDescriptorPoolSize,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorPoolSizeClass = env->GetObjectClass(jVkDescriptorPoolSizeObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorPoolSizeClass, "getType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkDescriptorType;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorTypeObject = env->CallObjectMethod(jVkDescriptorPoolSizeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkDescriptorTypeObjectEnumClass = env->GetObjectClass(jVkDescriptorTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkDescriptorTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDescriptorType descriptorTypeEnumValue = (VkDescriptorType)env->CallIntMethod(jVkDescriptorTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorPoolSizeClass, "getDescriptorCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jDescriptorCount = env->CallIntMethod(jVkDescriptorPoolSizeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkDescriptorPoolSize->type = descriptorTypeEnumValue;
        vkDescriptorPoolSize->descriptorCount = jDescriptorCount;
    }

    void getVkDescriptorPoolSizeCollection(
            JNIEnv *env,
            const jobject jVkDescriptorPoolSizeCollectionObject,
            VkDescriptorPoolSize **vkDescriptorPoolSizes,
            int *numberOfVkDescriptorPoolSizes,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorPoolSizeCollectionClass = env->GetObjectClass(jVkDescriptorPoolSizeCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorPoolSizeCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorPoolSizeCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDescriptorPoolSizes = numberOfElements;
        *vkDescriptorPoolSizes = (VkDescriptorPoolSize *)calloc(numberOfElements, sizeof(VkDescriptorPoolSize));
        memoryToFree->push_back(*vkDescriptorPoolSizes);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorPoolSizeCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorPoolSizeCollectionObject, iteratorMethodId);
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

            jobject jVkDescriptorPoolSizeObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkDescriptorPoolSize(
                    env,
                    jVkDescriptorPoolSizeObject,
                    &((*vkDescriptorPoolSizes)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
