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
 * getVkGraphicsShaderGroupCreateInfoNV.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkGraphicsShaderGroupCreateInfoNV(
            JNIEnv *env,
            jobject jVkGraphicsShaderGroupCreateInfoNVObject,
			VkGraphicsShaderGroupCreateInfoNV *vkGraphicsShaderGroupCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkGraphicsShaderGroupCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkGraphicsShaderGroupCreateInfoNVObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkGraphicsShaderGroupCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkGraphicsShaderGroupCreateInfoNVObject);
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
		jmethodID methodId = env->GetMethodID(theClass, "getStages", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getStages");
			return;
		}

		jobject jCollection = env->CallObjectMethod(jVkGraphicsShaderGroupCreateInfoNVObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        uint32_t stageCount = 0;
        VkPipelineShaderStageCreateInfo *pStages = nullptr;
    	jvulkan::getVkPipelineShaderStageCreateInfoCollection(
    			env,
				jCollection,
    			&pStages,
    			(int *)&stageCount,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkPipelineShaderStageCreateInfoCollection");
            return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getVertexInputState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineVertexInputStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getVertexInputState.");
            return;
        }

        jobject jVkPipelineVertexInputStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsShaderGroupCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineVertexInputStateCreateInfo *pVertexInputState = nullptr;
        if (jVkPipelineVertexInputStateCreateInfoObject != nullptr)
        {
        	pVertexInputState = (VkPipelineVertexInputStateCreateInfo *)calloc(1, sizeof(VkPipelineVertexInputStateCreateInfo));
            if(pVertexInputState == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for pVertexInputState.", sizeof(VkPipelineVertexInputStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(pVertexInputState);

            jvulkan::getVkPipelineVertexInputStateCreateInfo(
                    env,
                    jVkPipelineVertexInputStateCreateInfoObject,
					pVertexInputState,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineVertexInputStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getTessellationState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineTessellationStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getTessellationState.");
            return;
        }

        jobject jVkPipelineTessellationStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsShaderGroupCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineTessellationStateCreateInfo *pTessellationState = nullptr;
        if (jVkPipelineTessellationStateCreateInfoObject != nullptr)
        {
        	pTessellationState = (VkPipelineTessellationStateCreateInfo *)calloc(1, sizeof(VkPipelineTessellationStateCreateInfo));
            if(pTessellationState == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for pTessellationState.", sizeof(VkPipelineVertexInputStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(pVertexInputState);

            jvulkan::getVkPipelineTessellationStateCreateInfo(
                    env,
					jVkPipelineTessellationStateCreateInfoObject,
					pTessellationState,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineTessellationStateCreateInfo.");
                return;
            }
        }


        vkGraphicsShaderGroupCreateInfoNV->sType = sTypeValue;
        vkGraphicsShaderGroupCreateInfoNV->pNext = (void *)pNext;
        vkGraphicsShaderGroupCreateInfoNV->stageCount =stageCount;
        vkGraphicsShaderGroupCreateInfoNV->pStages = pStages;
        vkGraphicsShaderGroupCreateInfoNV->pVertexInputState = pVertexInputState;
        vkGraphicsShaderGroupCreateInfoNV->pTessellationState = pTessellationState;
    }
}
