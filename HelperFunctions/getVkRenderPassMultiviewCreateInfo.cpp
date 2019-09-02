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
 * getVkRenderPassMultiviewCreateInfo.cpp
 *
 *  Created on: May 20, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkRenderPassMultiviewCreateInfo(
            JNIEnv *env,
            const jobject jVkRenderPassMultiviewCreateInfoObject,
			VkRenderPassMultiviewCreateInfo *vkRenderPassMultiviewCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRenderPassMultiviewCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkRenderPassMultiviewCreateInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkRenderPassMultiviewCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkRenderPassMultiviewCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getViewMasks", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getViewMasks");
            return;
        }

        jintArray jViewMasks = (jintArray)env->CallObjectMethod(jVkRenderPassMultiviewCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int *viewMasksArray = nullptr;
        jsize subpassCount = 0;
        if (jViewMasks != nullptr)
        {
        	subpassCount = env->GetArrayLength(jViewMasks);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength");
                return;
            }


        	viewMasksArray = (int *)calloc(subpassCount, sizeof(int));
            memoryToFree->push_back(viewMasksArray);

            env->GetIntArrayRegion(jViewMasks, 0, subpassCount, viewMasksArray);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetIntArrayRegion");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getViewOffsets", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getViewOffsets");
            return;
        }

        jintArray jViewOffsets = (jintArray)env->CallObjectMethod(jVkRenderPassMultiviewCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int *viewOffsetsArray = nullptr;
        jsize dependencyCount = 0;
        if (jViewMasks != nullptr)
        {
        	dependencyCount = env->GetArrayLength(jViewOffsets);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength");
                return;
            }


        	viewOffsetsArray = (int *)calloc(dependencyCount, sizeof(int));
            memoryToFree->push_back(viewOffsetsArray);

            env->GetIntArrayRegion(jViewOffsets, 0, dependencyCount, viewOffsetsArray);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetIntArrayRegion");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getCorrelationMasks", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getCorrelationMasks");
            return;
        }

        jintArray jCorrelationMasks = (jintArray)env->CallObjectMethod(jVkRenderPassMultiviewCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int *correlationMasksArray = nullptr;
        jsize correlationMaskCount = 0;
        if (jCorrelationMasks != nullptr)
        {
        	correlationMaskCount = env->GetArrayLength(jCorrelationMasks);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength");
                return;
            }

        	correlationMasksArray = (int *)calloc(correlationMaskCount, sizeof(int));
            memoryToFree->push_back(correlationMasksArray);

            env->GetIntArrayRegion(jCorrelationMasks, 0, correlationMaskCount, correlationMasksArray);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetIntArrayRegion");
                return;
            }
        }


        vkRenderPassMultiviewCreateInfo->sType = sTypeValue;
        vkRenderPassMultiviewCreateInfo->pNext = pNext;
        vkRenderPassMultiviewCreateInfo->subpassCount = subpassCount;
		vkRenderPassMultiviewCreateInfo->pViewMasks = (uint32_t *)viewMasksArray;
		vkRenderPassMultiviewCreateInfo->dependencyCount = dependencyCount;
		vkRenderPassMultiviewCreateInfo->pViewOffsets = viewOffsetsArray;
		vkRenderPassMultiviewCreateInfo->correlationMaskCount = correlationMaskCount;
		vkRenderPassMultiviewCreateInfo->pCorrelationMasks = (uint32_t *)correlationMasksArray;
    }
}
