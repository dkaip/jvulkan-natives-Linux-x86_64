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
 * getVkGraphicsPipelineShaderGroupsCreateInfoNV.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkGraphicsPipelineShaderGroupsCreateInfoNV(
            JNIEnv *env,
            jobject jVkGraphicsPipelineShaderGroupsCreateInfoNVObject,
			VkGraphicsPipelineShaderGroupsCreateInfoNV *vkGraphicsPipelineShaderGroupsCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkGraphicsPipelineShaderGroupsCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkGraphicsPipelineShaderGroupsCreateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkGraphicsPipelineShaderGroupsCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkGraphicsPipelineShaderGroupsCreateInfoNVObject);
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
		jmethodID methodId = env->GetMethodID(theClass, "getGroups", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getGroups");
			return;
		}

		jobject jCollection = env->CallObjectMethod(jVkGraphicsPipelineShaderGroupsCreateInfoNVObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        uint32_t groupCount = 0;
        VkGraphicsShaderGroupCreateInfoNV *pGroups = nullptr;
    	jvulkan::getVkGraphicsShaderGroupCreateInfoNVCollection(
    			env,
				jCollection,
    			&pGroups,
    			(int *)&groupCount,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkGraphicsShaderGroupCreateInfoNVCollection");
            return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPipelines", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPipelines");
            return;
        }

        jobject  jVkPipelinesObject = env->CallObjectMethod(jVkGraphicsPipelineShaderGroupsCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint32_t pipelineCount = 0;
        VkPipeline_T **pPipelines = nullptr;
    	jvulkan::getVkPipelineCollection(
    			env,
				jVkPipelinesObject,
    			&pPipelines,
    			(int *)&pPipelines,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkPipelineCollection.");
    		return;
    	}


        vkGraphicsPipelineShaderGroupsCreateInfoNV->sType 	= sTypeValue;
        vkGraphicsPipelineShaderGroupsCreateInfoNV->pNext 	= (void *)pNext;
        vkGraphicsPipelineShaderGroupsCreateInfoNV->groupCount = groupCount;
        vkGraphicsPipelineShaderGroupsCreateInfoNV->pGroups = pGroups;
        vkGraphicsPipelineShaderGroupsCreateInfoNV->pipelineCount = pipelineCount;
        vkGraphicsPipelineShaderGroupsCreateInfoNV->pPipelines = pPipelines;
    }
}
