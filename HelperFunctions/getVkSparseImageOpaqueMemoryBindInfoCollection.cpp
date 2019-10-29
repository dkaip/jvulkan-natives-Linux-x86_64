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
/*
 * getVkSparseImageOpaqueMemoryBindInfoCollection.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSparseImageOpaqueMemoryBindInfoCollection(
            JNIEnv *env,
            const jobject jVkSparseImageOpaqueMemoryBindInfoCollectionObject,
			VkSparseImageOpaqueMemoryBindInfo **vkSparseImageOpaqueMemoryBindInfos,
            int *numberOfVkSparseImageOpaqueMemoryBindInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSparseImageOpaqueMemoryBindInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkSparseImageOpaqueMemoryBindInfoCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSparseImageOpaqueMemoryBindInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        *numberOfVkSparseImageOpaqueMemoryBindInfos = numberOfElements;
        *vkSparseImageOpaqueMemoryBindInfos = (VkSparseImageOpaqueMemoryBindInfo *)calloc(numberOfElements, sizeof(VkSparseImageOpaqueMemoryBindInfo));
        if (*vkSparseImageOpaqueMemoryBindInfos == nullptr)
        {
        	LOGERROR(env, "%s", "Error trying to allocate memory for *vkSparseImageOpaqueMemoryBindInfos");
            return;
        }

        memoryToFree->push_back(*vkSparseImageOpaqueMemoryBindInfos);

        jmethodID iteratorMethodId = env->GetMethodID(theClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSparseImageOpaqueMemoryBindInfoCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for iteratorObject.");
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for hasNext");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for next");
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkSparseImageOpaqueMemoryBindInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod");
                break;
            }

            getVkSparseImageOpaqueMemoryBindInfo(
                    env,
					jVkSparseImageOpaqueMemoryBindInfoObject,
                    &((*vkSparseImageOpaqueMemoryBindInfos)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling method getVkSparseImageOpaqueMemoryBindInfo");
                break;
            }

            i++;
        } while(true);
    }
}
