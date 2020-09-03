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
 * getVkGeneratedCommandsInfoNV.cpp
 *
 *  Created on: Aug 30, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkGeneratedCommandsInfoNV(
            JNIEnv *env,
            const jobject jVkGeneratedCommandsInfoNVObject,
			VkGeneratedCommandsInfoNV *vkGeneratedCommandsInfoNV,
            std::vector<void *> *memoryToFree)
    {
		if (jVkGeneratedCommandsInfoNVObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkGeneratedCommandsInfoNVObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkGeneratedCommandsInfoNVObject == nullptr");
			return;
		}

		if (vkGeneratedCommandsInfoNV == nullptr)
		{
			LOGERROR(env, "%s", "vkGeneratedCommandsInfoNV == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkGeneratedCommandsInfoNV == nullptr");
			return;
		}

        jclass theClass = env->GetObjectClass(jVkGeneratedCommandsInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkGeneratedCommandsInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkGeneratedCommandsInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkGeneratedCommandsInfoNVObject);
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
        	LOGERROR(env, "%s", "Could not find method id for getPipelineBindPoint.");
            return;
        }

        jobject jVkPipelineBindPointObject = env->CallObjectMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkPipelineBindPointClass = env->GetObjectClass(jVkPipelineBindPointObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPipelineBindPointObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf.");
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
        	LOGERROR(env, "%s", "Could not find methodId for getPipeline");
            return;
        }

        jobject jVkPipelineHandle = env->CallObjectMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipeline_T *pipeline = (VkPipeline_T *)jvulkan::getHandleValue(env, jVkPipelineHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve jVkPipelineHandle handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getIndirectCommandsLayout", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkIndirectCommandsLayoutNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getIndirectCommandsLayout");
            return;
        }

        jobject jIndirectCommandsLayoutHandle = env->CallObjectMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkIndirectCommandsLayoutNV_T *indirectCommandsLayout = (VkIndirectCommandsLayoutNV_T *)jvulkan::getHandleValue(env, jIndirectCommandsLayoutHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve jIndirectCommandsLayoutHandle handle");
    		return;
    	}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getStreams", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getStreams");
			return;
		}

		jobject jCollection = env->CallObjectMethod(jVkGeneratedCommandsInfoNVObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        int numberOfVkIndirectCommandsStreamNVs = 0;
        VkIndirectCommandsStreamNV *vkIndirectCommandsStreamNVs = nullptr;
    	jvulkan::getVkIndirectCommandsStreamNVCollection(
    			env,
				jCollection,
    			&vkIndirectCommandsStreamNVs,
    			&numberOfVkIndirectCommandsStreamNVs,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkIndirectCommandsStreamNVCollection");
            return;
    	}


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSequencesCount", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getSequencesCount");
            return;
        }

        uint32_t sequencesCount = (uint32_t)env->CallIntMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPreprocessBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getPreprocessBuffer");
            return;
        }

        jobject jVkBufferHandle = env->CallObjectMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkBuffer_T *preprocessBuffer = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve jVkBufferHandle handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPreprocessOffset", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getPreprocessOffset");
            return;
        }

        VkDeviceSize preprocessOffset = (VkDeviceSize)env->CallLongMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPreprocessSize", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getPreprocessSize");
            return;
        }

        VkDeviceSize preprocessSize = (VkDeviceSize)env->CallLongMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSequencesCountBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getSequencesCountBuffer");
            return;
        }

        jVkBufferHandle = env->CallObjectMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkBuffer_T *sequencesCountBuffer = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve jVkBufferHandle handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSequencesCountOffset", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getSequencesCountOffset");
            return;
        }

        VkDeviceSize sequencesCountOffset = (VkDeviceSize)env->CallLongMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSequencesIndexBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getSequencesIndexBuffer");
            return;
        }

        jVkBufferHandle = env->CallObjectMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkBuffer_T *sequencesIndexBuffer = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve jVkBufferHandle handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSequencesIndexOffset", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getSequencesIndexOffset");
            return;
        }

        VkDeviceSize sequencesIndexOffset = (VkDeviceSize)env->CallLongMethod(jVkGeneratedCommandsInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }


        vkGeneratedCommandsInfoNV->sType = sTypeValue;
        vkGeneratedCommandsInfoNV->pNext = pNext;
        vkGeneratedCommandsInfoNV->pipelineBindPoint = vkPipelineBindPointEnumValue;
        vkGeneratedCommandsInfoNV->pipeline = pipeline;
        vkGeneratedCommandsInfoNV->indirectCommandsLayout = indirectCommandsLayout;
        vkGeneratedCommandsInfoNV->sequencesCount = numberOfVkIndirectCommandsStreamNVs;
        vkGeneratedCommandsInfoNV->pStreams = vkIndirectCommandsStreamNVs;
        vkGeneratedCommandsInfoNV->sequencesCount = sequencesCount;
        vkGeneratedCommandsInfoNV->preprocessBuffer = preprocessBuffer;
        vkGeneratedCommandsInfoNV->preprocessOffset = preprocessOffset;
        vkGeneratedCommandsInfoNV->preprocessSize = preprocessSize;
        vkGeneratedCommandsInfoNV->sequencesCountBuffer = sequencesCountBuffer;
		vkGeneratedCommandsInfoNV->sequencesCountOffset = sequencesCountOffset;
        vkGeneratedCommandsInfoNV->sequencesIndexBuffer = sequencesIndexBuffer;
		vkGeneratedCommandsInfoNV->sequencesIndexOffset = sequencesIndexOffset;
    }
}
