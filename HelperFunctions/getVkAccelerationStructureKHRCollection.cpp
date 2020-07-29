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
 * getVkAccelerationStructureNVCollection.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAccelerationStructureKHRCollection(
            JNIEnv *env,
            const jobject jVkAccelerationStructureKHRCollectionObject,
			VkAccelerationStructureKHR **vkAccelerationStructureKHRs,
            int *numberOfVkAccelerationStructureKHRs,
            std::vector<void *> *memoryToFree)
    {
        if (jVkAccelerationStructureKHRCollectionObject == nullptr)
        {
        	LOGWARN(env, "%s", "jVkAccelerationStructureKHRCollectionObject was null");
            return;
        }

        jclass vkAccelerationStructureKHRCollectionClass = env->GetObjectClass(jVkAccelerationStructureKHRCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkAccelerationStructureKHRCollectionObject");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkAccelerationStructureKHRCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkAccelerationStructureKHRCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfVkAccelerationStructureKHRs = numberOfElements;
        *vkAccelerationStructureKHRs = (VkAccelerationStructureKHR *)calloc(numberOfElements, sizeof(VkAccelerationStructureKHR));
        if (*vkAccelerationStructureKHRs == nullptr)
        {
        	LOGERROR(env, "%s", "Could not allocate memory for*vkAccelerationStructureNVs.");
            return;
        }
        memoryToFree->push_back(*vkAccelerationStructureKHRs);

        jmethodID iteratorMethodId = env->GetMethodID(vkAccelerationStructureKHRCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkAccelerationStructureKHRCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
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
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkAccelerationStructureKHRObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            	break;
            }

            VkAccelerationStructureKHR vkAccelerationStructureKHRHandle = (VkAccelerationStructureKHR)getHandleValue(env, jVkAccelerationStructureKHRObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getHandleValue.");
                return;
            }

            (*vkAccelerationStructureKHRs)[i] = vkAccelerationStructureKHRHandle;

            i++;
        } while(true);
    }
}
