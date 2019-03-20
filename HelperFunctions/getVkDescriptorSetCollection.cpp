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
    void getVkDescriptorSetCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetCollectionObject,
            VkDescriptorSet **vkDescriptorSets,
            int *numberOfVkDescriptorSets,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetCollectionClass = env->GetObjectClass(jVkDescriptorSetCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorSetCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorSetCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDescriptorSets = numberOfElements;
        *vkDescriptorSets = (VkDescriptorSet *)calloc(numberOfElements, sizeof(VkDescriptorSet *));
        memoryToFree->push_back(*vkDescriptorSets);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorSetCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorSetCollectionObject, iteratorMethodId);
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

            jobject jVkDescriptorSetHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkDescriptorSet_T *vkDescriptorSetHandle = (VkDescriptorSet_T *)jvulkan::getHandleValue(env, jVkDescriptorSetHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkDescriptorSets)[i] = vkDescriptorSetHandle;

            i++;
        } while(true);
    }
}
