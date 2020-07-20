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
#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkResetFences
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkResetFences
  (JNIEnv *env , jobject, jobject jVkDevice, jobject jVkFenceCollectionObject)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass collectionClass = env->GetObjectClass(jVkFenceCollectionObject);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID iteratorMethodId = env->GetMethodID(collectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject iteratorObject = env->CallObjectMethod(jVkFenceCollectionObject, iteratorMethodId);
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

    jmethodID methodId = env->GetMethodID(collectionClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jsize collectionSize = env->CallIntMethod(jVkFenceCollectionObject, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    if (collectionSize == 0)
    {
        cerr << "Collection size is zero." << endl;
        return;
    }

    VkFence_T  **arrayOfPointers = (VkFence_T **)calloc(collectionSize, sizeof(VkFence_T *));

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

        jobject jVkFenceObject = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
            break;
        }

        VkFence_T *fenceHandle = (VkFence_T *)jvulkan::getHandleValue(env, jVkFenceObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        arrayOfPointers[i++] = fenceHandle;

    } while (i < collectionSize);

    vkResetFences(logicalDeviceHandle, collectionSize, (VkFence_T * const *)arrayOfPointers);

    free(arrayOfPointers);
}

