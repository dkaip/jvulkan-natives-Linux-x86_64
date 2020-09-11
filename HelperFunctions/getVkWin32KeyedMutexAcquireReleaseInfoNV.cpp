/*
 * Copyright 2020 Douglas Kaip
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
 * getVkWin32KeyedMutexAcquireReleaseInfoNV.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Douglas Kaip
 */

#ifdef _WIN64

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkWin32KeyedMutexAcquireReleaseInfoNV(
            JNIEnv *env,
            jobject jVkWin32KeyedMutexAcquireReleaseInfoNVObject,
			VkWin32KeyedMutexAcquireReleaseInfoNV *vkWin32KeyedMutexAcquireReleaseInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkWin32KeyedMutexAcquireReleaseInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkWin32KeyedMutexAcquireReleaseInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkWin32KeyedMutexAcquireReleaseInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkWin32KeyedMutexAcquireReleaseInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getAcquireSyncs", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAcquireSyncs");
            return;
        }

        jobject  jAcquireSyncsObject = env->CallObjectMethod(jVkWin32KeyedMutexAcquireReleaseInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint32_t acquireCount = 0;
        uint32_t acquireSyncsCount = 0;
        VkDeviceMemory_T **pAcquireSyncs = nullptr;
    	jvulkan::getVkDeviceMemoryCollection(
    			env,
				jAcquireSyncsObject,
    			&pAcquireSyncs,
    			(int *)&acquireSyncsCount,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkDeviceMemoryCollection.");
    		return;
    	}

    	acquireCount = acquireSyncsCount;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getAcquireKeys", "()[J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAcquireKeys");
            return;
        }

        jlongArray jAcquireKeysValuesArrayObject = env->CallObjectMethod(jVkWin32KeyedMutexAcquireReleaseInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint64_t *pAcquireKeys = nullptr;
        uint32_t acquireKeysCount = 0;
        if (jAcquireKeysValuesArrayObject != nullptr)
        {
        	acquireKeysCount = env->GetArrayLength(jAcquireKeysValuesArrayObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength");
                return;
            }

        	pAcquireKeys = (uint64_t *)calloc(acquireKeysCount, sizeof(uint64_t));
        	if (pAcquireKeys == nullptr)
        	{
            	LOGERROR(env, "Could not allocate %d bytes for pAcquireKeys.", (acquireKeysCount * sizeof(uint64_t)));
                return;
        	}
            memoryToFree->push_back(pAcquireKeys);

            env->GetLongArrayRegion(jAcquireKeysValuesArrayObject, 0, acquireKeysCount, (long int *)pAcquireKeys);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetLongArrayRegion");
                return;
            }
        }

        if (acquireCount != acquireKeysCount)
        {
        	LOGERROR(env, "The number of acquireKeys (%d) should have been the same as the acquireSyncs (%d).", acquireKeysCount, acquireCount);
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getAcquireTimeouts", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAcquireTimeouts");
            return;
        }

        jintArray jAcquireTimeoutsValuesArrayObject = env->CallObjectMethod(jVkWin32KeyedMutexAcquireReleaseInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint32_t *pAcquireTimeouts = nullptr;
        uint32_t acquireTimeoutsCount = 0;
        if (jAcquireTimeoutsValuesArrayObject != nullptr)
        {
        	acquireTimeoutsCount = env->GetArrayLength(jAcquireTimeoutsValuesArrayObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength");
                return;
            }

            pAcquireTimeouts = (uint64_t *)calloc(acquireTimeoutsCount, sizeof(uint64_t));
        	if (pAcquireKeys == nullptr)
        	{
            	LOGERROR(env, "Could not allocate %d bytes for pAcquireTimeouts.", (acquireTimeoutsCount * sizeof(uint64_t)));
                return;
        	}
            memoryToFree->push_back(pAcquireTimeouts);

            env->GetIntArrayRegion(jAcquireTimeoutsValuesArrayObject, 0, (int)acquireTimeoutsCount, (int *)pAcquireKeys);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetIntArrayRegion");
                return;
            }
        }

        if (acquireCount != acquireTimeoutsCount)
        {
        	LOGERROR(env, "The number of acquireTimeouts (%d) should have been the same as the acquireSyncs (%d).", acquireTimeoutsCount, acquireCount);
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getReleaseSyncs", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getReleaseSyncs");
            return;
        }

        jobject  jReleaseSyncsObject = env->CallObjectMethod(jVkWin32KeyedMutexAcquireReleaseInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint32_t releaseCount = 0;
        uint32_t releaseSyncsCount = 0;
        VkDeviceMemory_T **pReleaseSyncs = nullptr;
    	jvulkan::getVkDeviceMemoryCollection(
    			env,
				jReleaseSyncsObject,
    			&pReleaseSyncs,
    			(int *)&releaseSyncsCount,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkDeviceMemoryCollection.");
    		return;
    	}

    	releaseCount = releaseSyncsCount;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getReleaseKeys", "()[J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getReleaseKeys");
            return;
        }

        jlongArray jReleaseKeysValuesArrayObject = env->CallObjectMethod(jVkWin32KeyedMutexAcquireReleaseInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint64_t *pReleaseKeys = nullptr;
        uint32_t releaseKeysCount = 0;
        if (jReleaseKeysValuesArrayObject != nullptr)
        {
        	releaseKeysCount = env->GetArrayLength(jReleaseKeysValuesArrayObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength");
                return;
            }

            pReleaseKeys = (uint64_t *)calloc(releaseKeysCount, sizeof(uint64_t));
        	if (pReleaseKeys == nullptr)
        	{
            	LOGERROR(env, "Could not allocate %d bytes for pReleaseKeys.", (releaseKeysCount * sizeof(uint64_t)));
                return;
        	}
            memoryToFree->push_back(pReleaseKeys);

            env->GetLongArrayRegion(jReleaseKeysValuesArrayObject, 0, releaseKeysCount, (long int *)pReleaseKeys);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetLongArrayRegion");
                return;
            }
        }

        if (releaseCount != releaseKeysCount)
        {
        	LOGERROR(env, "The number of releaseKeys (%d) should have been the same as the releaseCounts (%d).", releaseKeysCount, releaseCount);
        	return;
        }


        vkWin32KeyedMutexAcquireReleaseInfoNV->sType 	= sTypeValue;
        vkWin32KeyedMutexAcquireReleaseInfoNV->pNext 	= (void *)pNext;
        vkWin32KeyedMutexAcquireReleaseInfoNV->acquireCount = acquireCount;
        vkWin32KeyedMutexAcquireReleaseInfoNV->pAcquireSyncs = pAcquireSyncs;
        vkWin32KeyedMutexAcquireReleaseInfoNV->pAcquireKeys = pAcquireKeys;
        vkWin32KeyedMutexAcquireReleaseInfoNV->pAcquireTimeouts = pAcquireTimeouts;
        vkWin32KeyedMutexAcquireReleaseInfoNV->releaseCount = releaseCount;
        vkWin32KeyedMutexAcquireReleaseInfoNV->pReleaseSyncs = pReleaseSyncs;
        vkWin32KeyedMutexAcquireReleaseInfoNV->pReleaseKeys = pReleaseKeys;
    }
}
#endif
