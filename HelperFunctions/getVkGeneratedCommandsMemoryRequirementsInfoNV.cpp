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
 * getVkGeneratedCommandsMemoryRequirementsInfoNV.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkGeneratedCommandsMemoryRequirementsInfoNV(
            JNIEnv *env,
            jobject jVkGeneratedCommandsMemoryRequirementsInfoNVObject,
			VkGeneratedCommandsMemoryRequirementsInfoNV *vkGeneratedCommandsMemoryRequirementsInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkGeneratedCommandsMemoryRequirementsInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkGeneratedCommandsMemoryRequirementsInfoNVObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkGeneratedCommandsMemoryRequirementsInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkGeneratedCommandsMemoryRequirementsInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getPipelineBindPoint", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineBindPoint;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getPipelineBindPoint.");
            return;
        }

        jobject jVkPipelineBindPointObject = env->CallObjectMethod(jVkGeneratedCommandsMemoryRequirementsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkPipelineBindPointEnumClass = env->GetObjectClass(jVkPipelineBindPointObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for vkPipelineBindPointEnumClass.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkPipelineBindPoint vkPipelineBindPointEnumValue = (VkPipelineBindPoint)env->CallIntMethod(jVkPipelineBindPointObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPipeline", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipeline;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getPipeline.");
            return;
        }

        jobject jVkPipelineObject = env->CallObjectMethod(jVkGeneratedCommandsMemoryRequirementsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipeline_T *pipelineHandle = (VkPipeline_T *)jvulkan::getHandleValue(env, jVkPipelineObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getIndirectCommandsLayout", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkIndirectCommandsLayoutNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getIndirectCommandsLayout.");
            return;
        }

        jobject jVkIndirectCommandsLayoutNVObject = env->CallObjectMethod(jVkGeneratedCommandsMemoryRequirementsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkIndirectCommandsLayoutNV_T *indirectCommandsLayoutHandle = (VkIndirectCommandsLayoutNV_T *)jvulkan::getHandleValue(env, jVkIndirectCommandsLayoutNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMaxSequencesCount", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getMaxSequencesCount.");
            return;
        }

        uint32_t maxSequencesCount = (uint32_t)env->CallIntMethod(jVkGeneratedCommandsMemoryRequirementsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkGeneratedCommandsMemoryRequirementsInfoNV->sType = sTypeValue;
        vkGeneratedCommandsMemoryRequirementsInfoNV->pNext = pNext;
        vkGeneratedCommandsMemoryRequirementsInfoNV->pipelineBindPoint = vkPipelineBindPointEnumValue;
        vkGeneratedCommandsMemoryRequirementsInfoNV->pipeline = pipelineHandle;
        vkGeneratedCommandsMemoryRequirementsInfoNV->indirectCommandsLayout = indirectCommandsLayoutHandle;
        vkGeneratedCommandsMemoryRequirementsInfoNV->maxSequencesCount = maxSequencesCount;
    }
}



