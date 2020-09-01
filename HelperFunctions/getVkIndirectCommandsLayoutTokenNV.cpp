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
 * getVkIndirectCommandsLayoutTokenNV.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkIndirectCommandsLayoutTokenNV(
            JNIEnv *env,
            const jobject jVkIndirectCommandsLayoutTokenNVObject,
			VkIndirectCommandsLayoutTokenNV *vkIndirectCommandsLayoutTokenNV,
            std::vector<void *> *memoryToFree)
    {
		if (jVkIndirectCommandsLayoutTokenNVObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkIndirectCommandsLayoutTokenNVObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkIndirectCommandsLayoutTokenNVObject == nullptr");
			return;
		}

		if (vkIndirectCommandsLayoutTokenNV == nullptr)
		{
			LOGERROR(env, "%s", "vkIndirectCommandsLayoutTokenNV == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkIndirectCommandsLayoutTokenNV == nullptr");
			return;
		}

        jclass theClass = env->GetObjectClass(jVkIndirectCommandsLayoutTokenNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkIndirectCommandsLayoutTokenNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSTypeAsInt(env, jVkIndirectCommandsLayoutTokenNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkIndirectCommandsLayoutTokenNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getTokenType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkIndirectCommandsTokenTypeNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getTokenType.");
            return;
        }

        jobject jVkIndirectCommandsTokenTypeNVObject = env->CallObjectMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkIndirectCommandsTokenTypeNVClass = env->GetObjectClass(jVkIndirectCommandsTokenTypeNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetObjectClass.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkIndirectCommandsTokenTypeNVClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf.");
            return;
        }

        VkIndirectCommandsTokenTypeNV tokenTypeEnumValue = (VkIndirectCommandsTokenTypeNV)env->CallIntMethod(jVkIndirectCommandsTokenTypeNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getStream", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getStream");
            return;
        }

        uint32_t stream = (uint32_t)env->CallIntMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getOffset", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getOffset");
            return;
        }

        uint32_t offset = (uint32_t)env->CallIntMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getVertexBindingUnit", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getVertexBindingUnit");
            return;
        }

        uint32_t vertexBindingUnit = (uint32_t)env->CallIntMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isVertexDynamicStride", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVertexDynamicStride");
            return;
        }

        VkBool32 vertexDynamicStride = (VkBool32)env->CallBooleanMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPushconstantPipelineLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineLayout;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getPushconstantPipelineLayout method Id");
            return;
        }

        jobject jVkPipelineLayoutObject = env->CallObjectMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getPushconstantPipelineLayout");
            return;
        }

        VkPipelineLayout pushconstantPipelineLayout = (VkPipelineLayout)jvulkan::getHandleValue(env, jVkPipelineLayoutObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue for jVkPipelineLayoutObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPushconstantShaderStageFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPushconstantShaderStageFlags");
            return;
        }

        jobject pushconstantShaderStageFlagsObject = env->CallObjectMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkShaderStageFlags pushconstantShaderStageFlags = (VkShaderStageFlags)getEnumSetValue(
                env,
				pushconstantShaderStageFlagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderStageFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPushconstantOffset", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPushconstantOffset");
            return;
        }

        uint32_t pushconstantOffset = (uint32_t)env->CallIntMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPushconstantSize", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPushconstantSize");
            return;
        }

        uint32_t pushconstantSize = (uint32_t)env->CallIntMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getIndirectStateFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getIndirectStateFlags");
            return;
        }

        jobject indirectStateFlagsObject = env->CallObjectMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkIndirectStateFlagsNV indirectStateFlags = (VkIndirectStateFlagsNV)getEnumSetValue(
                env,
				indirectStateFlagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkIndirectStateFlagBitsNV");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getIndexTypes", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getIndexTypes");
            return;
        }

        jobject jIndexTypesCollectionObject = env->CallObjectMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int numberOfIndexTypes = 0;
        VkIndexType *vkIndexTypes = nullptr;
    	jvulkan::getVkIndexTypeCollection(
    			env,
				jIndexTypesCollectionObject,
    			&vkIndexTypes,
    			&numberOfIndexTypes,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkIndexTypeCollection");
            return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getIndexTypeValues", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getIndexTypeValues");
            return;
        }

        jintArray jIndexTypeValuesArray = (jintArray)env->CallObjectMethod(jVkIndirectCommandsLayoutTokenNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint32_t numberOfIndexTypeValues = (uint32_t)env->GetArrayLength(jIndexTypeValuesArray);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetArrayLength");
            return;
        }

        if (numberOfIndexTypes != numberOfIndexTypeValues)
		{
			LOGERROR(env, "%s", "The number of indexTypes and indexTypeValue MUST be the same.");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "The number of indexTypes and indexTypeValue MUST be the same.");
			return;
		}

        int *data = env->GetIntArrayElements(jIndexTypeValuesArray, 0);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetIntArrayElements");
            return;
        }

        int *indexTypeValues = (int *)calloc((size_t)numberOfIndexTypeValues, sizeof(int));
        memoryToFree->push_back(indexTypeValues);
        if (data != nullptr)
        {
            memcpy(indexTypeValues, data, numberOfIndexTypeValues * sizeof(int));
            env->ReleaseIntArrayElements(jIndexTypeValuesArray, data, JNI_ABORT);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling ReleaseIntArrayElements");
                return;
            }
        }


        vkIndirectCommandsLayoutTokenNV->sType = sTypeValue;
        vkIndirectCommandsLayoutTokenNV->pNext = pNext;
        vkIndirectCommandsLayoutTokenNV->tokenType = tokenTypeEnumValue;
        vkIndirectCommandsLayoutTokenNV->stream = stream;
        vkIndirectCommandsLayoutTokenNV->offset = offset;
        vkIndirectCommandsLayoutTokenNV->vertexBindingUnit = vertexBindingUnit;
        vkIndirectCommandsLayoutTokenNV->vertexDynamicStride = vertexDynamicStride;
        vkIndirectCommandsLayoutTokenNV->pushconstantPipelineLayout = pushconstantPipelineLayout;
        vkIndirectCommandsLayoutTokenNV->pushconstantShaderStageFlags = pushconstantShaderStageFlags;
        vkIndirectCommandsLayoutTokenNV->pushconstantOffset = pushconstantOffset;
        vkIndirectCommandsLayoutTokenNV->pushconstantSize = pushconstantSize;
        vkIndirectCommandsLayoutTokenNV->indirectStateFlags = indirectStateFlags;
        vkIndirectCommandsLayoutTokenNV->indexTypeCount = (uint32_t)numberOfIndexTypes;
        vkIndirectCommandsLayoutTokenNV->pIndexTypes = vkIndexTypes;
        vkIndirectCommandsLayoutTokenNV->pIndexTypeValues = (uint32_t *)indexTypeValues;
    }
}
