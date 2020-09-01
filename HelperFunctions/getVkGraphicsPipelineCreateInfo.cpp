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
 * getVkGraphicsPipelineCreateInfo.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkGraphicsPipelineCreateInfo(
            JNIEnv *env,
            jobject jVkGraphicsPipelineCreateInfoObject,
            VkGraphicsPipelineCreateInfo *vkGraphicsPipelineCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkGraphicsPipelineCreateInfoClass = env->GetObjectClass(jVkGraphicsPipelineCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkGraphicsPipelineCreateInfoObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkGraphicsPipelineCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkGraphicsPipelineCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineCreateFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getStages", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getStages.");
            return;
        }

        jobject jVkPipelineShaderStageCreateInfos = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
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
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getVertexInputState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineVertexInputStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getVertexInputState.");
            return;
        }

        jobject jVkPipelineVertexInputStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineVertexInputStateCreateInfo *vkPipelineVertexInputStateCreateInfo = nullptr;
        if (jVkPipelineVertexInputStateCreateInfoObject != nullptr)
        {
            vkPipelineVertexInputStateCreateInfo = (VkPipelineVertexInputStateCreateInfo *)calloc(1, sizeof(VkPipelineVertexInputStateCreateInfo));
            if(vkPipelineVertexInputStateCreateInfo == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for vkPipelineVertexInputStateCreateInfo.", sizeof(VkPipelineVertexInputStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(vkPipelineVertexInputStateCreateInfo);

            jvulkan::getVkPipelineVertexInputStateCreateInfo(
                    env,
                    jVkPipelineVertexInputStateCreateInfoObject,
                    vkPipelineVertexInputStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineVertexInputStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getInputAssemblyState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineInputAssemblyStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getInputAssemblyState.");
            return;
        }

        jobject jVkPipelineInputAssemblyStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineInputAssemblyStateCreateInfo *vkPipelineInputAssemblyStateCreateInfo = nullptr;
        if (jVkPipelineInputAssemblyStateCreateInfoObject != nullptr)
        {
            vkPipelineInputAssemblyStateCreateInfo = (VkPipelineInputAssemblyStateCreateInfo *)calloc(1, sizeof(VkPipelineInputAssemblyStateCreateInfo));
            if(vkPipelineInputAssemblyStateCreateInfo == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for vkPipelineInputAssemblyStateCreateInfo.", sizeof(VkPipelineInputAssemblyStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(vkPipelineInputAssemblyStateCreateInfo);

            jvulkan::getVkPipelineInputAssemblyStateCreateInfo(
                    env,
                    jVkPipelineInputAssemblyStateCreateInfoObject,
                    vkPipelineInputAssemblyStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineInputAssemblyStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getTessellationState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineTessellationStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getTessellationState.");
            return;
        }

        jobject jVkPipelineTessellationStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineTessellationStateCreateInfo *vkPipelineTessellationStateCreateInfo = nullptr;
        if (jVkPipelineTessellationStateCreateInfoObject != nullptr)
        {
            vkPipelineTessellationStateCreateInfo = (VkPipelineTessellationStateCreateInfo *)calloc(1, sizeof(VkPipelineTessellationStateCreateInfo));
            if(vkPipelineTessellationStateCreateInfo == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for vkPipelineTessellationStateCreateInfo.", sizeof(VkPipelineTessellationStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(vkPipelineTessellationStateCreateInfo);

            jvulkan::getVkPipelineTessellationStateCreateInfo(
                    env,
                    jVkPipelineTessellationStateCreateInfoObject,
                    vkPipelineTessellationStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineTessellationStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getViewportState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineViewportStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getViewportState.");
            return;
        }

        jobject jVkPipelineViewportStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineViewportStateCreateInfo *vkPipelineViewportStateCreateInfo = nullptr;
        if (jVkPipelineViewportStateCreateInfoObject != nullptr)
        {
            vkPipelineViewportStateCreateInfo = (VkPipelineViewportStateCreateInfo *)calloc(1, sizeof(VkPipelineViewportStateCreateInfo));
            if(vkPipelineViewportStateCreateInfo == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for vkPipelineViewportStateCreateInfo.", sizeof(VkPipelineViewportStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(vkPipelineViewportStateCreateInfo);

            jvulkan::getVkPipelineViewportStateCreateInfo(
                    env,
                    jVkPipelineViewportStateCreateInfoObject,
                    vkPipelineViewportStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineViewportStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getRasterizationState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineRasterizationStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getRasterizationState.");
            return;
        }

        jobject jVkPipelineRasterizationStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineRasterizationStateCreateInfo *vkPipelineRasterizationStateCreateInfo = nullptr;
        if (jVkPipelineRasterizationStateCreateInfo != nullptr)
        {
            vkPipelineRasterizationStateCreateInfo = (VkPipelineRasterizationStateCreateInfo *)calloc(1, sizeof(VkPipelineRasterizationStateCreateInfo));
            if(vkPipelineRasterizationStateCreateInfo == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for vkPipelineRasterizationStateCreateInfo.", sizeof(VkPipelineRasterizationStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(vkPipelineRasterizationStateCreateInfo);

            jvulkan::getVkPipelineRasterizationStateCreateInfo(
                    env,
                    jVkPipelineRasterizationStateCreateInfo,
                    vkPipelineRasterizationStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineRasterizationStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getMultisampleState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineMultisampleStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineMultisampleStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineMultisampleStateCreateInfo *vkPipelineMultisampleStateCreateInfo = nullptr;
        if (jVkPipelineMultisampleStateCreateInfo != nullptr)
        {
            vkPipelineMultisampleStateCreateInfo = (VkPipelineMultisampleStateCreateInfo *)calloc(1, sizeof(VkPipelineMultisampleStateCreateInfo));
            if(vkPipelineMultisampleStateCreateInfo == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for vkPipelineMultisampleStateCreateInfo.", sizeof(VkPipelineMultisampleStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(vkPipelineMultisampleStateCreateInfo);

            jvulkan::getVkPipelineMultisampleStateCreateInfo(
                    env,
                    jVkPipelineMultisampleStateCreateInfo,
                    vkPipelineMultisampleStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineMultisampleStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getDepthStencilState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineDepthStencilStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getDepthStencilState.");
            return;
        }

        jobject jVkPipelineDepthStencilStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineDepthStencilStateCreateInfo *vkPipelineDepthStencilStateCreateInfo = nullptr;
        if (jVkPipelineDepthStencilStateCreateInfo != nullptr)
        {
            vkPipelineDepthStencilStateCreateInfo = (VkPipelineDepthStencilStateCreateInfo *)calloc(1, sizeof(VkPipelineDepthStencilStateCreateInfo));
            if(vkPipelineDepthStencilStateCreateInfo == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for vkPipelineDepthStencilStateCreateInfo.", sizeof(VkPipelineDepthStencilStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(vkPipelineDepthStencilStateCreateInfo);

            jvulkan::getVkPipelineDepthStencilStateCreateInfo(
                    env,
                    jVkPipelineDepthStencilStateCreateInfo,
                    vkPipelineDepthStencilStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineDepthStencilStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getColorBlendState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineColorBlendStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getColorBlendState.");
            return;
        }

        jobject jVkPipelineColorBlendStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineColorBlendStateCreateInfo *vkPipelineColorBlendStateCreateInfo = nullptr;

        vkPipelineColorBlendStateCreateInfo = (VkPipelineColorBlendStateCreateInfo *)calloc(1, sizeof(VkPipelineColorBlendStateCreateInfo));
        if(vkPipelineColorBlendStateCreateInfo == nullptr)
        {
        	LOGERROR(env, "Error trying to allocate %d bytes for vkPipelineColorBlendStateCreateInfo.", sizeof(VkPipelineColorBlendStateCreateInfo));

        	return;
        }

        memoryToFree->push_back(vkPipelineColorBlendStateCreateInfo);
        if (jVkPipelineColorBlendStateCreateInfo != nullptr)
        {
            jvulkan::getVkPipelineColorBlendStateCreateInfo(
                    env,
                    jVkPipelineColorBlendStateCreateInfo,
                    vkPipelineColorBlendStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineColorBlendStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getDynamicState", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkPipelineDynamicStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getDynamicState.");
            return;
        }

        jobject jVkPipelineDynamicStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineDynamicStateCreateInfo *vkPipelineDynamicStateCreateInfo = nullptr;
        if (jVkPipelineDynamicStateCreateInfo != nullptr)
        {
            vkPipelineDynamicStateCreateInfo = (VkPipelineDynamicStateCreateInfo *)calloc(1, sizeof(VkPipelineDynamicStateCreateInfo));
            if(vkPipelineDynamicStateCreateInfo == nullptr)
            {
            	LOGERROR(env, "Error trying to allocate %d bytes for vkPipelineDynamicStateCreateInfo.", sizeof(VkPipelineDynamicStateCreateInfo));

            	return;
            }

            memoryToFree->push_back(vkPipelineDynamicStateCreateInfo);

            jvulkan::getVkPipelineDynamicStateCreateInfo(
                    env,
                    jVkPipelineDynamicStateCreateInfo,
                    vkPipelineDynamicStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPipelineDynamicStateCreateInfo.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineLayout;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getLayout.");
            return;
        }

        jobject jVkPipelineLayoutObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
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
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getRenderPass", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkRenderPass;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getRenderPass.");
            return;
        }

        jobject jVkRenderPassObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkRenderPass_T *renderPassHandle = (VkRenderPass_T *)jvulkan::getHandleValue(env, jVkRenderPassObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getSubpass", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getSubpass.");
            return;
        }

        jint subpass = env->CallIntMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getBasePipelineHandle", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipeline;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getBasePipelineHandle.");
            return;
        }

        jobject jVkPipelineObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
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
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getBasePipelineIndex", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getBasePipelineIndex.");
            return;
        }

        jint basePipelineIndex = env->CallIntMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        vkGraphicsPipelineCreateInfo->sType = (VkStructureType)sTypeValue;
        vkGraphicsPipelineCreateInfo->pNext = (void *)pNext;
        vkGraphicsPipelineCreateInfo->flags = (VkPipelineCreateFlags)flags;
        vkGraphicsPipelineCreateInfo->stageCount = numberOfPipelineShaderStageInfos;
        vkGraphicsPipelineCreateInfo->pStages = vkPipelineShaderStageCreateInfos;
        vkGraphicsPipelineCreateInfo->pVertexInputState = vkPipelineVertexInputStateCreateInfo;
        vkGraphicsPipelineCreateInfo->pInputAssemblyState = vkPipelineInputAssemblyStateCreateInfo;
        vkGraphicsPipelineCreateInfo->pTessellationState = vkPipelineTessellationStateCreateInfo;
        vkGraphicsPipelineCreateInfo->pViewportState = vkPipelineViewportStateCreateInfo;
        vkGraphicsPipelineCreateInfo->pRasterizationState = vkPipelineRasterizationStateCreateInfo;
        vkGraphicsPipelineCreateInfo->pMultisampleState = vkPipelineMultisampleStateCreateInfo;
        vkGraphicsPipelineCreateInfo->pDepthStencilState = vkPipelineDepthStencilStateCreateInfo;
        vkGraphicsPipelineCreateInfo->pColorBlendState = vkPipelineColorBlendStateCreateInfo;
        vkGraphicsPipelineCreateInfo->pDynamicState = vkPipelineDynamicStateCreateInfo;
        vkGraphicsPipelineCreateInfo->layout = pipelineLayoutHandle;
        vkGraphicsPipelineCreateInfo->renderPass = renderPassHandle;
        vkGraphicsPipelineCreateInfo->subpass = subpass;
        vkGraphicsPipelineCreateInfo->basePipelineHandle = baseipelineLayoutHandle;
        vkGraphicsPipelineCreateInfo->basePipelineIndex = basePipelineIndex;
    }
}
