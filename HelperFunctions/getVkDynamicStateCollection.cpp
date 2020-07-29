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
    void getVkDynamicStateCollection(
            JNIEnv *env,
            const jobject jVkDynamicStateCollectionObject,
            VkDynamicState **vkDynamicStates,
            int *numberOfVkDynamicStates,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDynamicStateCollectionClass = env->GetObjectClass(jVkDynamicStateCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDynamicStateCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDynamicStateCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDynamicStates = numberOfElements;
        *vkDynamicStates = (VkDynamicState *)calloc(numberOfElements, sizeof(VkDynamicState));
        memoryToFree->push_back(*vkDynamicStates);

        jmethodID iteratorMethodId = env->GetMethodID(vkDynamicStateCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(vkDynamicStateCollectionClass, iteratorMethodId);
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

        jclass vkDynamicStateClass;
        jmethodID valueOfMethodId;
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

            jobject jVkDynamicStateObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (i == 0)
            {
                vkDynamicStateClass = env->GetObjectClass(jVkDynamicStateObject);
                if (env->ExceptionOccurred())
                {
                    return;
                }

                valueOfMethodId = env->GetMethodID(vkDynamicStateClass, "valueOf", "()I");
                if (env->ExceptionOccurred())
                {
                    return;
                }
            }

            (*vkDynamicStates)[i] = (VkDynamicState)env->CallIntMethod(jVkDynamicStateObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }
}
