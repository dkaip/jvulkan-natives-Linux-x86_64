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
 * getVkWriteDescriptorSetAccelerationStructureKHR.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkWriteDescriptorSetAccelerationStructureKHR(
            JNIEnv *env,
            const jobject jVkWriteDescriptorSetAccelerationStructureKHRObject,
			VkWriteDescriptorSetAccelerationStructureKHR *vkWriteDescriptorSetAccelerationStructureKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkWriteDescriptorSetAccelerationStructureKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkWriteDescriptorSetAccelerationStructureKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkWriteDescriptorSetAccelerationStructureKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkWriteDescriptorSetAccelerationStructureKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getAccelerationStructures", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAccelerationStructureKHRCollection = env->CallObjectMethod(jVkWriteDescriptorSetAccelerationStructureKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfAccelerationStructures = 0;
        VkAccelerationStructureKHR *vkAccelerationStructureKHRHandles = nullptr;
        if (jVkAccelerationStructureKHRCollection != nullptr)
        {
            getVkAccelerationStructureKHRCollection(
                    env,
					jVkAccelerationStructureKHRCollection,
                    &vkAccelerationStructureKHRHandles,
                    &numberOfAccelerationStructures,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {

                return;
            }
        }


        vkWriteDescriptorSetAccelerationStructureKHR->sType = sTypeValue;
        vkWriteDescriptorSetAccelerationStructureKHR->pNext = pNext;
        vkWriteDescriptorSetAccelerationStructureKHR->accelerationStructureCount = numberOfAccelerationStructures;
        vkWriteDescriptorSetAccelerationStructureKHR->pAccelerationStructures = vkAccelerationStructureKHRHandles;
    }
}
