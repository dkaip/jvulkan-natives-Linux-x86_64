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
 * getVkIndirectCommandsLayoutCreateInfoNV.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkIndirectCommandsLayoutCreateInfoNV(
            JNIEnv *env,
            const jobject jVkIndirectCommandsLayoutCreateInfoNVObject,
			VkIndirectCommandsLayoutCreateInfoNV *vkIndirectCommandsLayoutCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkIndirectCommandsLayoutCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkIndirectCommandsLayoutCreateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSTypeAsInt(env, jVkIndirectCommandsLayoutCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkIndirectCommandsLayoutCreateInfoNVObject);
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
		jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getFlags");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkIndirectCommandsLayoutCreateInfoNVObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkIndirectCommandsLayoutUsageFlagsNV flags = (VkIndirectCommandsLayoutUsageFlagsNV)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkIndirectCommandsLayoutUsageFlagBitsNV");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPipelineBindPoint", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineBindPoint;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getPipelineBindPoint.");
            return;
        }

        jobject jVkPipelineBindPointTypeObject = env->CallObjectMethod(jVkIndirectCommandsLayoutCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkPipelineBindPointTypeObjectEnumClass = env->GetObjectClass(jVkPipelineBindPointTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkAttachmentDescription2Object.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkPipelineBindPoint pipelineBindPointTypeEnumValue = (VkPipelineBindPoint)env->CallIntMethod(jVkPipelineBindPointTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getTokens", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getTokens");
			return;
		}

		jobject jCollection = env->CallObjectMethod(jVkIndirectCommandsLayoutCreateInfoNVObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        int tokenCount = 0;
        VkIndirectCommandsLayoutTokenNV *tokens = nullptr;
    	jvulkan::getVkIndirectCommandsLayoutTokenNVCollection(
    			env,
				jCollection,
    			&tokens,
    			&tokenCount,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkIndirectCommandsLayoutTokenNVCollection");
            return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getStreamStrides", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getStreamStrides");
            return;
        }

        jintArray jStreamStridesArray = (jintArray)env->CallObjectMethod(jVkIndirectCommandsLayoutCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint32_t streamCount = (uint32_t)env->GetArrayLength(jStreamStridesArray);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetArrayLength");
            return;
        }

        int *data = env->GetIntArrayElements(jStreamStridesArray, 0);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetIntArrayElements");
            return;
        }

        int *streamStrides = (int *)calloc((size_t)streamCount, sizeof(int));
        memoryToFree->push_back(streamStrides);
        if (data != nullptr)
        {
            memcpy(streamStrides, data, streamCount * sizeof(int));
            env->ReleaseIntArrayElements(jStreamStridesArray, data, JNI_ABORT);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling ReleaseIntArrayElements");
                return;
            }
        }


        vkIndirectCommandsLayoutCreateInfoNV->sType = sTypeValue;
        vkIndirectCommandsLayoutCreateInfoNV->pNext = pNext;
        vkIndirectCommandsLayoutCreateInfoNV->flags = flags;
        vkIndirectCommandsLayoutCreateInfoNV->pipelineBindPoint = pipelineBindPointTypeEnumValue;
        vkIndirectCommandsLayoutCreateInfoNV->tokenCount = tokenCount;
        vkIndirectCommandsLayoutCreateInfoNV->pTokens = tokens;
        vkIndirectCommandsLayoutCreateInfoNV->streamCount = streamCount;
        vkIndirectCommandsLayoutCreateInfoNV->pStreamStrides = (uint32_t *)streamStrides;
    }
}
