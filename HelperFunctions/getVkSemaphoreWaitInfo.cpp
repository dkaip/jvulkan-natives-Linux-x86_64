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
 * getVkSemaphoreWaitInfo.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSemaphoreWaitInfo(
            JNIEnv *env,
            jobject jVkSemaphoreWaitInfo,
			VkSemaphoreWaitInfo *vkSemaphoreWaitInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSemaphoreWaitInfo);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class of jVkSemaphoreWaitInfo");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkSemaphoreWaitInfo);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSemaphoreWaitInfo);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (jpNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getFlags");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkSemaphoreWaitInfo, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkSemaphoreWaitFlags flags = (VkSemaphoreWaitFlags)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkSemaphoreWaitFlagBits");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getSemaphores", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getSemaphores");
			return;
		}

		jobject jCollection = env->CallObjectMethod(jVkSemaphoreWaitInfo, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        int numberOfSemaphores = 0;
        VkSemaphore *semaphores = nullptr;
    	jvulkan::getVulkanHandleCollection(
    			env,
				jCollection,
    			(void **)&semaphores,
    			&numberOfSemaphores,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVulkanHandleCollection");
            return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getValues", "()[J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getValues");
            return;
        }

        jlongArray jValuesObject = (jlongArray)env->CallObjectMethod(jVkSemaphoreWaitInfo, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint64_t *values = nullptr;
        jsize arrayLength = 0;
        if (jValuesObject != nullptr)
        {
            arrayLength = env->GetArrayLength(jValuesObject);

            values = (uint64_t *)calloc(arrayLength, sizeof(uint64_t));
            memoryToFree->push_back(values);

            env->GetLongArrayRegion(jValuesObject, 0, arrayLength, (long int *)values);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }


		vkSemaphoreWaitInfo->sType 		= sTypeValue;
        vkSemaphoreWaitInfo->pNext 		= (void *)pNext;
        vkSemaphoreWaitInfo->flags		= flags;
        vkSemaphoreWaitInfo->semaphoreCount	= numberOfSemaphores;
        vkSemaphoreWaitInfo->pSemaphores 	= semaphores;
        vkSemaphoreWaitInfo->pValues		= values;
    }
}
