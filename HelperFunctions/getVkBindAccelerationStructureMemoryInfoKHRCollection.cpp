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
/*
 * getVkBindAccelerationStructureMemoryInfoKHRCollection.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBindAccelerationStructureMemoryInfoKHRCollection(
            JNIEnv *env,
            const jobject jVkBindAccelerationStructureMemoryInfoKHRCollectionObject,
            VkBindAccelerationStructureMemoryInfoKHR **vkBindAccelerationStructureMemoryInfoKHRs,
            int *numberOfVkBindAccelerationStructureMemoryInfoKHRs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBindBufferMemoryInfoCollectionClass = env->GetObjectClass(jVkBindAccelerationStructureMemoryInfoKHRCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkAttachmentSampleLocationsEXTCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBindBufferMemoryInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBindAccelerationStructureMemoryInfoKHRCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        *numberOfVkBindAccelerationStructureMemoryInfoKHRs = numberOfElements;
        *vkBindAccelerationStructureMemoryInfoKHRs = (VkBindAccelerationStructureMemoryInfoKHR *)calloc(numberOfElements, sizeof(VkBindAccelerationStructureMemoryInfoKHR));
        if (*vkBindAccelerationStructureMemoryInfoKHRs == nullptr)
        {
        	LOGERROR(env, "%s", "Error trying to allocate memory for *vkBindAccelerationStructureMemoryInfoKHRs");
            return;
        }

        memoryToFree->push_back(*vkBindAccelerationStructureMemoryInfoKHRs);

        jmethodID iteratorMethodId = env->GetMethodID(vkBindBufferMemoryInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(vkBindBufferMemoryInfoCollectionClass, iteratorMethodId);
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

            jobject jVkBindAccelerationStructureMemoryInfoKHRObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod");
                break;
            }

            getVkBindAccelerationStructureMemoryInfoKHR(
                    env,
                    jVkBindAccelerationStructureMemoryInfoKHRObject,
                    &((*vkBindAccelerationStructureMemoryInfoKHRs)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling method getVkBindAccelerationStructureMemoryInfoKHR");
                break;
            }

            i++;
        } while(true);
    }
}
