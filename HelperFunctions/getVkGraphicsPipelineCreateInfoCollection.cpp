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
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkGraphicsPipelineCreateInfoObject);
        if (env->ExceptionOccurred())
        {
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
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getStages", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineShaderStageCreateInfos = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
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
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getVertexInputState", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPipelineVertexInputStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineVertexInputStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineVertexInputStateCreateInfo *vkPipelineVertexInputStateCreateInfo = nullptr;
        if (jVkPipelineVertexInputStateCreateInfoObject != nullptr)
        {
            vkPipelineVertexInputStateCreateInfo = (VkPipelineVertexInputStateCreateInfo *)calloc(1, sizeof(VkPipelineVertexInputStateCreateInfo));
            memoryToFree->push_back(vkPipelineVertexInputStateCreateInfo);

            jvulkan::getVkPipelineVertexInputStateCreateInfo(
                    env,
                    jVkPipelineVertexInputStateCreateInfoObject,
                    vkPipelineVertexInputStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getInputAssemblyState", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPipelineInputAssemblyStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineInputAssemblyStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineInputAssemblyStateCreateInfo *vkPipelineInputAssemblyStateCreateInfo = nullptr;
        if (jVkPipelineInputAssemblyStateCreateInfoObject != nullptr)
        {
            vkPipelineInputAssemblyStateCreateInfo = (VkPipelineInputAssemblyStateCreateInfo *)calloc(1, sizeof(VkPipelineInputAssemblyStateCreateInfo));
            memoryToFree->push_back(vkPipelineInputAssemblyStateCreateInfo);

            jvulkan::getVkPipelineInputAssemblyStateCreateInfo(
                    env,
                    jVkPipelineInputAssemblyStateCreateInfoObject,
                    vkPipelineInputAssemblyStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getTessellationState", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPipelineTessellationStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineTessellationStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineTessellationStateCreateInfo *vkPipelineTessellationStateCreateInfo = nullptr;
        if (jVkPipelineTessellationStateCreateInfoObject != nullptr)
        {
            vkPipelineTessellationStateCreateInfo = (VkPipelineTessellationStateCreateInfo *)calloc(1, sizeof(VkPipelineTessellationStateCreateInfo));
            memoryToFree->push_back(vkPipelineTessellationStateCreateInfo);

            jvulkan::getVkPipelineTessellationStateCreateInfo(
                    env,
                    jVkPipelineTessellationStateCreateInfoObject,
                    vkPipelineTessellationStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getViewportState", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPipelineViewportStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineViewportStateCreateInfoObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineViewportStateCreateInfo *vkPipelineViewportStateCreateInfo = nullptr;
        if (jVkPipelineViewportStateCreateInfoObject != nullptr)
        {
            vkPipelineViewportStateCreateInfo = (VkPipelineViewportStateCreateInfo *)calloc(1, sizeof(VkPipelineViewportStateCreateInfo));
            memoryToFree->push_back(vkPipelineViewportStateCreateInfo);

            jvulkan::getVkPipelineViewportStateCreateInfo(
                    env,
                    jVkPipelineViewportStateCreateInfoObject,
                    vkPipelineViewportStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getRasterizationState", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPipelineRasterizationStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineRasterizationStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineRasterizationStateCreateInfo *vkPipelineRasterizationStateCreateInfo = nullptr;
        if (jVkPipelineRasterizationStateCreateInfo != nullptr)
        {
            vkPipelineRasterizationStateCreateInfo = (VkPipelineRasterizationStateCreateInfo *)calloc(1, sizeof(VkPipelineRasterizationStateCreateInfo));
            memoryToFree->push_back(vkPipelineRasterizationStateCreateInfo);

            jvulkan::getVkPipelineRasterizationStateCreateInfo(
                    env,
                    jVkPipelineRasterizationStateCreateInfo,
                    vkPipelineRasterizationStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getMultisampleState", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPipelineMultisampleStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineMultisampleStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineMultisampleStateCreateInfo *vkPipelineMultisampleStateCreateInfo = nullptr;
        if (jVkPipelineMultisampleStateCreateInfo != nullptr)
        {
            vkPipelineMultisampleStateCreateInfo = (VkPipelineMultisampleStateCreateInfo *)calloc(1, sizeof(VkPipelineMultisampleStateCreateInfo));
            memoryToFree->push_back(vkPipelineMultisampleStateCreateInfo);

            jvulkan::getVkPipelineMultisampleStateCreateInfo(
                    env,
                    jVkPipelineMultisampleStateCreateInfo,
                    vkPipelineMultisampleStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getDepthStencilState", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPipelineDepthStencilStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineDepthStencilStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineDepthStencilStateCreateInfo *vkPipelineDepthStencilStateCreateInfo = nullptr;
        if (jVkPipelineDepthStencilStateCreateInfo != nullptr)
        {
            vkPipelineDepthStencilStateCreateInfo = (VkPipelineDepthStencilStateCreateInfo *)calloc(1, sizeof(VkPipelineDepthStencilStateCreateInfo));
            memoryToFree->push_back(vkPipelineDepthStencilStateCreateInfo);

            jvulkan::getVkPipelineDepthStencilStateCreateInfo(
                    env,
                    jVkPipelineDepthStencilStateCreateInfo,
                    vkPipelineDepthStencilStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getColorBlendState", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPipelineColorBlendStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineColorBlendStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineColorBlendStateCreateInfo *vkPipelineColorBlendStateCreateInfo = nullptr;

        vkPipelineColorBlendStateCreateInfo = (VkPipelineColorBlendStateCreateInfo *)calloc(1, sizeof(VkPipelineColorBlendStateCreateInfo));
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
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getDynamicState", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkPipelineDynamicStateCreateInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineDynamicStateCreateInfo = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineDynamicStateCreateInfo *vkPipelineDynamicStateCreateInfo = nullptr;
        if (jVkPipelineDynamicStateCreateInfo != nullptr)
        {
            vkPipelineDynamicStateCreateInfo = (VkPipelineDynamicStateCreateInfo *)calloc(1, sizeof(VkPipelineDynamicStateCreateInfo));
            memoryToFree->push_back(vkPipelineDynamicStateCreateInfo);

            jvulkan::getVkPipelineDynamicStateCreateInfo(
                    env,
                    jVkPipelineDynamicStateCreateInfo,
                    vkPipelineDynamicStateCreateInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPipelineLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineLayoutObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
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
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getRenderPass", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkRenderPass;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkRenderPassObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkRenderPass_T *renderPassHandle = (VkRenderPass_T *)jvulkan::getHandleValue(env, jVkRenderPassObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getSubpass", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint subpass = env->CallIntMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getBasePipelineHandle", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPipeline;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipeline_T *baseipelineLayoutHandle = nullptr;
        if (jVkPipelineObject != nullptr)
        {
            baseipelineLayoutHandle = (VkPipeline_T *)jvulkan::getHandleValue(env, jVkPipelineObject);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoClass, "getBasePipelineIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint basePipelineIndex = env->CallIntMethod(jVkGraphicsPipelineCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
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

    void getVkGraphicsPipelineCreateInfoCollection(
            JNIEnv *env,
            const jobject jVkGraphicsPipelineCreateInfoCollectionObject,
            VkGraphicsPipelineCreateInfo **graphicsPipelineCreateInfos,
            int *numberOfCreateInfos,
            std::vector<void *> *memoryToFree)
    {
        if (jVkGraphicsPipelineCreateInfoCollectionObject == nullptr)
        {
            return;
        }

        jclass vkGraphicsPipelineCreateInfoCollectionClass = env->GetObjectClass(jVkGraphicsPipelineCreateInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkGraphicsPipelineCreateInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkGraphicsPipelineCreateInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfCreateInfos = numberOfElements;
        *graphicsPipelineCreateInfos = (VkGraphicsPipelineCreateInfo *)calloc(numberOfElements, sizeof(VkGraphicsPipelineCreateInfo));
        memoryToFree->push_back(*graphicsPipelineCreateInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkGraphicsPipelineCreateInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkGraphicsPipelineCreateInfoCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkGraphicsPipelineCreateInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkGraphicsPipelineCreateInfo(
                    env,
                    jVkGraphicsPipelineCreateInfoObject,
                    &(*graphicsPipelineCreateInfos)[i],
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                break;
            }

            i++;
        } while(true);
    }
}
