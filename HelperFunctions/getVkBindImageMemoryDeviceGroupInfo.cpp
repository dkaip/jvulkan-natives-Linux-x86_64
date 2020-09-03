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
 * getVkBindImageMemoryDeviceGroupInfo.cpp
 *
 *  Created on: May 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBindImageMemoryDeviceGroupInfo(
            JNIEnv *env,
            const jobject jVkBindImageMemoryDeviceGroupInfoObject,
			VkBindImageMemoryDeviceGroupInfo *vkBindImageMemoryDeviceGroupInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkBindImageMemoryDeviceGroupInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkBindImageMemoryDeviceGroupInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkBindImageMemoryDeviceGroupInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkBindImageMemoryDeviceGroupInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getDeviceIndices", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDeviceIndices");
            return;
        }

        jintArray jDeviceIndices = (jintArray)env->CallObjectMethod(jVkBindImageMemoryDeviceGroupInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int *pDeviceIndices = nullptr;
        jsize deviceIndexCount = 0;
        if (jDeviceIndices != nullptr)
        {
        	deviceIndexCount = env->GetArrayLength(jDeviceIndices);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength");
                return;
            }


            pDeviceIndices = (int *)calloc(deviceIndexCount, sizeof(int));
            if (pDeviceIndices == nullptr)
            {
            	LOGERROR(env, "%s", "Error trying to allocate memory for pDeviceIndices");
                return;
            }
            memoryToFree->push_back(pDeviceIndices);

            env->GetIntArrayRegion(jDeviceIndices, 0, deviceIndexCount, pDeviceIndices);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetIntArrayRegion");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSplitInstanceBindRegions", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSplitInstanceBindRegions");
            return;
        }

        jobject jSplitInstanceBindRegionsCollection = env->CallObjectMethod(jVkBindImageMemoryDeviceGroupInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int splitInstanceBindRegionCount = 0;
        VkRect2D *splitInstanceBindRegions = nullptr;

        if (jSplitInstanceBindRegionsCollection != nullptr)
        {
            jvulkan::getVkRect2DCollection(
                    env,
					jSplitInstanceBindRegionsCollection,
                    &splitInstanceBindRegions,
                    &splitInstanceBindRegionCount,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }


        vkBindImageMemoryDeviceGroupInfo->sType = sTypeValue;
        vkBindImageMemoryDeviceGroupInfo->pNext = pNext;
        vkBindImageMemoryDeviceGroupInfo->deviceIndexCount = deviceIndexCount;
        vkBindImageMemoryDeviceGroupInfo->pDeviceIndices = (uint32_t *)pDeviceIndices;
        vkBindImageMemoryDeviceGroupInfo->splitInstanceBindRegionCount = splitInstanceBindRegionCount;
        vkBindImageMemoryDeviceGroupInfo->pSplitInstanceBindRegions = splitInstanceBindRegions;
    }
}
