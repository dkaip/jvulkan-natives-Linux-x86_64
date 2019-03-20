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

namespace hwjvi
{
    void getVkPresentInfoKHR(
            JNIEnv *env,
            jobject jVkPresentInfoKHRObject,
            VkPresentInfoKHR *vkPresentInfoKHR,
            jobject *jVkResultsCollectionObject,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPresentInfoKHRClass = env->GetObjectClass(jVkPresentInfoKHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPresentInfoKHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPresentInfoKHRClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkPresentInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPresentInfoKHRClass, "getWaitSemaphores", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jWaitSemaphoreCollection = env->CallObjectMethod(jVkPresentInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfWaitSemaphores = 0;
        VkSemaphore *waitSemaphores = nullptr;

        if (jWaitSemaphoreCollection != nullptr)
        {
            hwjvi::getVkSemaphoreCollection(
                    env,
                    jWaitSemaphoreCollection,
                    &waitSemaphores,
                    &numberOfWaitSemaphores,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPresentInfoKHRClass, "getSwapchains", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jSwapchainCollection = env->CallObjectMethod(jVkPresentInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfSwapchains = 0;
        VkSwapchainKHR *swapchains = nullptr;

        if (jWaitSemaphoreCollection != nullptr)
        {
            hwjvi::getVkSwapchainKHRCollection(
                    env,
                    jSwapchainCollection,
                    &swapchains,
                    &numberOfSwapchains,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPresentInfoKHRClass, "getImageIndices", "()[I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jImageIndicesArray = (jintArray)env->CallObjectMethod(jVkPresentInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int *imageIndicesArray = nullptr;
        jsize arrayLength = 0;
        if (jImageIndicesArray != nullptr)
        {
            arrayLength = env->GetArrayLength(jImageIndicesArray);

            imageIndicesArray = (int *)calloc(arrayLength, sizeof(int));
            memoryToFree->push_back(imageIndicesArray);

            env->GetIntArrayRegion(jImageIndicesArray, 0, arrayLength, imageIndicesArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPresentInfoKHRClass, "getResults", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        *jVkResultsCollectionObject = env->CallObjectMethod(jVkPresentInfoKHRObject, methodId);

        VkResult* vkResultsCollection = nullptr;
        if((*jVkResultsCollectionObject) != nullptr)
        {
            jclass vkResultsCollectionClass = env->GetObjectClass((*jVkResultsCollectionObject));
            if (env->ExceptionOccurred())
            {
                return;
            }

            jmethodID methodId = env->GetMethodID(vkResultsCollectionClass, "size", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint numberOfElements = env->CallIntMethod((*jVkResultsCollectionObject), methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkResultsCollection = (VkResult *)calloc(numberOfElements, sizeof(VkResult));
            memoryToFree->push_back(vkResultsCollection);
        }

        vkPresentInfoKHR->sType = (VkStructureType)sTypeValue;
        vkPresentInfoKHR->pNext = (void *)pNext;
        vkPresentInfoKHR->waitSemaphoreCount = numberOfWaitSemaphores;
        vkPresentInfoKHR->pWaitSemaphores = waitSemaphores;
        vkPresentInfoKHR->swapchainCount = numberOfSwapchains;
        vkPresentInfoKHR->pSwapchains = swapchains;
        vkPresentInfoKHR->pImageIndices = (uint32_t *)imageIndicesArray;
        vkPresentInfoKHR->pResults = vkResultsCollection;
    }
}
