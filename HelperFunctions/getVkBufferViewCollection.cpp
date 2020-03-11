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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBufferViewCollection(
            JNIEnv *env,
            const jobject jVkBufferViewCollectionObject,
            VkBufferView **vkBufferViews,
            int *numberOfVkBufferViews,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferViewCollectionClass = env->GetObjectClass(jVkBufferViewCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkBufferViewCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBufferViewCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for size.");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBufferViewCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfVkBufferViews = numberOfElements;
        *vkBufferViews = (VkBufferView *)calloc(numberOfElements, sizeof(VkBufferView *));
        if (*vkBufferViews == nullptr)
        {
        	LOGERROR(env, "Could not allocate %d elements for vkBufferViews,", numberOfElements);
        	return;
        }

        memoryToFree->push_back(*vkBufferViews);

        jmethodID iteratorMethodId = env->GetMethodID(vkBufferViewCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for iterator.");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkBufferViewCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for iteratorObject.");
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for hasNext.");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for next.");
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkBufferViewHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
                break;
            }

            VkBufferView_T *vkBufferViewHandle = (VkBufferView_T *)jvulkan::getHandleValue(env, jVkBufferViewHandleObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getHandleValue.");
                return;
            }

            if (vkBufferViewHandle == nullptr)
            {
            	LOGERROR(env, "%s", "vkBufferViewHandle is null");
            }

            (*vkBufferViews)[i] = vkBufferViewHandle;

            i++;
        } while(true);
    }
}
