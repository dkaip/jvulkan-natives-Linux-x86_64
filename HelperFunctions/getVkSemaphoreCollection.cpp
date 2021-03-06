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
    void getVkSemaphoreCollection(
            JNIEnv *env,
            const jobject jVkSemaphoreCollectionObject,
            VkSemaphore **vkSemaphores,
            int *numberOfVkSemaphores,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSemaphoreCollectionClass = env->GetObjectClass(jVkSemaphoreCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSemaphoreCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSemaphoreCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkSemaphores = numberOfElements;
        *vkSemaphores = (VkSemaphore *)calloc(numberOfElements, sizeof(VkSemaphore *));
        memoryToFree->push_back(*vkSemaphores);

        jmethodID iteratorMethodId = env->GetMethodID(vkSemaphoreCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSemaphoreCollectionObject, iteratorMethodId);
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

            jobject jVkSemaphoreHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkSemaphore_T *vkSemaphoreHandle = (VkSemaphore_T *)jvulkan::getHandleValue(env, jVkSemaphoreHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkSemaphores)[i] = vkSemaphoreHandle;

            i++;
        } while(true);
    }
}
