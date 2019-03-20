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
    void getVkSwapchainKHRCollection(
            JNIEnv *env,
            const jobject jVkSwapchainKHRCollectionObject,
            VkSwapchainKHR **vkSwapchainKHR,
            int *numberOfVkSwapchainKHRs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSwapchainKHRCollectionClass = env->GetObjectClass(jVkSwapchainKHRCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSwapchainKHRCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSwapchainKHRCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkSwapchainKHRs = numberOfElements;
        *vkSwapchainKHR = (VkSwapchainKHR *)calloc(numberOfElements, sizeof(VkSwapchainKHR *));
        memoryToFree->push_back(*vkSwapchainKHR);

        jmethodID iteratorMethodId = env->GetMethodID(vkSwapchainKHRCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSwapchainKHRCollectionObject, iteratorMethodId);
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

            jobject jVkSwapchainKHRHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkSwapchainKHR_T *vkSwapchainKHRHandle = (VkSwapchainKHR_T *)jvulkan::getHandleValue(env, jVkSwapchainKHRHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkSwapchainKHR)[i] = vkSwapchainKHRHandle;

            i++;
        } while(true);
    }
}
