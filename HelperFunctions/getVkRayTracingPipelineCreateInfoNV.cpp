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
 * getVkRayTracingPipelineCreateInfoNV.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkRayTracingPipelineCreateInfoNV(
            JNIEnv *env,
            jobject jVkRayTracingPipelineCreateInfoNVObject,
			VkRayTracingPipelineCreateInfoNV *vkRayTracingPipelineCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRayTracingPipelineCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkRayTracingPipelineCreateInfoNVObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkRayTracingPipelineCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkRayTracingPipelineCreateInfoNVObject);
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
        	LOGERROR(env, "%s", "Could not get method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkRayTracingPipelineCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineCreateFlags flags = (VkPipelineCreateFlags)getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineCreateFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getStages", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getStages.");
            return;
        }

        jobject jVkPipelineShaderStageCreateInfos = env->CallObjectMethod(jVkRayTracingPipelineCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfPipelineShaderStageInfos = 0;
        VkPipelineShaderStageCreateInfo *vkPipelineShaderStageCreateInfos = nullptr;
        if (jVkPipelineShaderStageCreateInfos != nullptr)
        {
            jvulkan::getVkPipelineShaderStageCreateInfoCollection(
                    env,
                    jVkPipelineShaderStageCreateInfos,
                    &vkPipelineShaderStageCreateInfos,
                    &numberOfPipelineShaderStageInfos,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineShaderStageCreateInfoCollection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getGroups", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getGroups.");
            return;
        }

        jobject jVkRayTracingShaderGroupCreateInfoNVs = env->CallObjectMethod(jVkRayTracingPipelineCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfVkRayTracingShaderGroupCreateInfoNV = 0;
        VkRayTracingShaderGroupCreateInfoNV *vkRayTracingShaderGroupCreateInfoNVs = nullptr;
        if (jVkRayTracingShaderGroupCreateInfoNVs != nullptr)
        {
            jvulkan::getVkRayTracingShaderGroupCreateInfoNVCollection(
                    env,
					jVkRayTracingShaderGroupCreateInfoNVs,
                    &vkRayTracingShaderGroupCreateInfoNVs,
                    &numberOfVkRayTracingShaderGroupCreateInfoNV,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkRayTracingShaderGroupCreateInfoNVCollection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMaxRecursionDepth", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getMaxRecursionDepth.");
            return;
        }

        uint32_t maxRecursionDepth = (uint32_t)env->CallIntMethod(jVkRayTracingPipelineCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineLayout;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getLayout.");
            return;
        }

        jobject jVkPipelineLayoutObject = env->CallObjectMethod(jVkRayTracingPipelineCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineLayout_T *pipelineLayoutHandle = (VkPipelineLayout_T *)jvulkan::getHandleValue(env, jVkPipelineLayoutObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getBasePipelineHandle", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipeline;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getBasePipelineHandle.");
            return;
        }

        jobject jVkPipelineObject = env->CallObjectMethod(jVkRayTracingPipelineCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipeline_T *baseipelineLayoutHandle = nullptr;
        if (jVkPipelineObject != nullptr)
        {
            baseipelineLayoutHandle = (VkPipeline_T *)jvulkan::getHandleValue(env, jVkPipelineObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getHandleValue.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getBasePipelineIndex", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getBasePipelineIndex.");
            return;
        }

        uint32_t basePipelineIndex = (uint32_t)env->CallIntMethod(jVkRayTracingPipelineCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkRayTracingPipelineCreateInfoNV->sType = sTypeValue;
        vkRayTracingPipelineCreateInfoNV->pNext = pNext;
        vkRayTracingPipelineCreateInfoNV->flags = flags;
        vkRayTracingPipelineCreateInfoNV->stageCount = numberOfPipelineShaderStageInfos;
        vkRayTracingPipelineCreateInfoNV->pStages = vkPipelineShaderStageCreateInfos;
        vkRayTracingPipelineCreateInfoNV->groupCount = numberOfVkRayTracingShaderGroupCreateInfoNV;
        vkRayTracingPipelineCreateInfoNV->pGroups = vkRayTracingShaderGroupCreateInfoNVs;
        vkRayTracingPipelineCreateInfoNV->maxRecursionDepth = maxRecursionDepth;
        vkRayTracingPipelineCreateInfoNV->layout = pipelineLayoutHandle;
        vkRayTracingPipelineCreateInfoNV->basePipelineHandle = baseipelineLayoutHandle;
        vkRayTracingPipelineCreateInfoNV->basePipelineIndex = basePipelineIndex;
    }
}
