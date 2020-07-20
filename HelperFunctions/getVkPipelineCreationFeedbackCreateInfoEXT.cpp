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
 * getVkPipelineCreationFeedbackCreateInfoEXT.cpp
 *
 *  Created on: May 22, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineCreationFeedbackCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkPipelineCreationFeedbackCreateInfoEXTObject,
			VkPipelineCreationFeedbackCreateInfoEXT *vkPipelineCreationFeedbackCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineCreationFeedbackCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineCreationFeedbackCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPipelineCreationFeedbackCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineCreationFeedbackCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getPipelineCreationFeedback", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineCreationFeedbackEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPipelineCreationFeedback");
            return;
        }

        jobject pipelineCreationFeedbackObject = env->CallObjectMethod(jVkPipelineCreationFeedbackCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkPipelineCreationFeedbackEXT *vkPipelineCreationFeedbackEXT = (VkPipelineCreationFeedbackEXT *)calloc(1, sizeof(VkPipelineCreationFeedbackEXT));
        if (vkPipelineCreationFeedbackEXT == nullptr)
        {
        	LOGERROR(env, "%s", "Error trying to allocate memory for *vkPipelineCreationFeedbackEXT");
            return;
        }
        memoryToFree->push_back(vkPipelineCreationFeedbackEXT);

        getVkPipelineCreationFeedbackEXT(
                env,
                pipelineCreationFeedbackObject,
    			vkPipelineCreationFeedbackEXT,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkPipelineCreationFeedbackEXT");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPipelineStageCreationFeedbacks", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPipelineStageCreationFeedbacks");
            return;
        }

        jobject jPipelineStageCreationFeedbacks = env->CallObjectMethod(jVkPipelineCreationFeedbackCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int pipelineStageCreationFeedbackCount = 0;
        VkPipelineCreationFeedbackEXT *pipelineStageCreationFeedbacks = nullptr;
        getVkPipelineCreationFeedbackEXTCollection(
                env,
				jPipelineStageCreationFeedbacks,
                &pipelineStageCreationFeedbacks,
                &pipelineStageCreationFeedbackCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkPipelineCreationFeedbackEXTCollection");
            return;
        }


        vkPipelineCreationFeedbackCreateInfoEXT->sType = sTypeValue;
        vkPipelineCreationFeedbackCreateInfoEXT->pNext = pNext;
        vkPipelineCreationFeedbackCreateInfoEXT->pPipelineCreationFeedback = vkPipelineCreationFeedbackEXT;
        vkPipelineCreationFeedbackCreateInfoEXT->pipelineStageCreationFeedbackCount = pipelineStageCreationFeedbackCount;
        vkPipelineCreationFeedbackCreateInfoEXT->pPipelineStageCreationFeedbacks = pipelineStageCreationFeedbacks;
    }
}
