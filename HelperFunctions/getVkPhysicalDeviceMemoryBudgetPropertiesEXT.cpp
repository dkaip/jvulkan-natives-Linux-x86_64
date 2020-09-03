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
 * getVkPhysicalDeviceMemoryBudgetPropertiesEXT.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceMemoryBudgetPropertiesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject,
			VkPhysicalDeviceMemoryBudgetPropertiesEXT *vkPhysicalDeviceMemoryBudgetPropertiesEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getHeapBudget", "()[J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getHeapBudget");
            return;
        }

        jlongArray jHeapBudgetArrayObject = (jlongArray)env->CallObjectMethod(jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint64_t *heapBudget = nullptr;
        jsize arrayLength = 0;
        if (jHeapBudgetArrayObject != nullptr)
        {
            arrayLength = env->GetArrayLength(jHeapBudgetArrayObject);

            heapBudget = (uint64_t *)calloc(arrayLength, sizeof(uint64_t));
            memoryToFree->push_back(heapBudget);

            env->GetLongArrayRegion(jHeapBudgetArrayObject, 0, arrayLength, (long int *)heapBudget);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getHeapUsage", "()[J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getHeapUsage");
            return;
        }

        jlongArray jHeapUsageArrayObject = (jlongArray)env->CallObjectMethod(jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint64_t *heapUsage = nullptr;
        arrayLength = 0;
        if (jHeapUsageArrayObject != nullptr)
        {
            arrayLength = env->GetArrayLength(jHeapUsageArrayObject);

            heapUsage = (uint64_t *)calloc(arrayLength, sizeof(uint64_t));
            memoryToFree->push_back(heapUsage);

            env->GetLongArrayRegion(jHeapUsageArrayObject, 0, arrayLength, (long int *)heapUsage);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }


        vkPhysicalDeviceMemoryBudgetPropertiesEXT->sType = sTypeValue;
        vkPhysicalDeviceMemoryBudgetPropertiesEXT->pNext = pNext;
        (void)memcpy(vkPhysicalDeviceMemoryBudgetPropertiesEXT->heapBudget, heapBudget, sizeof(vkPhysicalDeviceMemoryBudgetPropertiesEXT->heapBudget));
        (void)memcpy(vkPhysicalDeviceMemoryBudgetPropertiesEXT->heapUsage, heapUsage, sizeof(vkPhysicalDeviceMemoryBudgetPropertiesEXT->heapUsage));
    }
}
