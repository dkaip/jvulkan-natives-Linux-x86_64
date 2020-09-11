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
 * getVkComputePipelineCreateInfo.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkComputePipelineCreateInfo(
            JNIEnv *env,
            jobject jVkComputePipelineCreateInfoObject,
            VkComputePipelineCreateInfo *vkComputePipelineCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkComputePipelineCreateInfoClass = env->GetObjectClass(jVkComputePipelineCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkComputePipelineCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkComputePipelineCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkComputePipelineCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkComputePipelineCreateInfoObject, methodId);
        VkPipelineCreateFlags flags = (VkPipelineCreateFlags)getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkComputePipelineCreateInfoClass, "getStage", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkPipelineShaderStageCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineShaderStageCreateInfo = env->CallObjectMethod(jVkComputePipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkComputePipelineCreateInfoClass, "getLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineLayoutObject = env->CallObjectMethod(jVkComputePipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineLayout_T *pipelineLayoutHandle = (VkPipelineLayout_T *)jvulkan::getHandleValue(env, jVkPipelineLayoutObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkComputePipelineCreateInfoClass, "getBasePipelineHandle", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipeline;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineObject = env->CallObjectMethod(jVkComputePipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipeline_T *basePipelineHandle = (VkPipeline_T *)jvulkan::getHandleValue(env, jVkPipelineObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkComputePipelineCreateInfoClass, "getBasePipelineIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint basePipelineIndex = env->CallIntMethod(jVkComputePipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkComputePipelineCreateInfo->sType              = sTypeValue;
        vkComputePipelineCreateInfo->pNext              = (void *)pNext;
        vkComputePipelineCreateInfo->flags              = flags;

        getVkPipelineShaderStageCreateInfo(
                env,
                jVkPipelineShaderStageCreateInfo,
                &(vkComputePipelineCreateInfo->stage),
                memoryToFree);

        vkComputePipelineCreateInfo->layout             = pipelineLayoutHandle;
        vkComputePipelineCreateInfo->basePipelineHandle = basePipelineHandle;
        vkComputePipelineCreateInfo->basePipelineIndex  = basePipelineIndex;
    }
}

