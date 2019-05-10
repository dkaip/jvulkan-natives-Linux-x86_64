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
 * getVkComputePipelineCreateInfoCollection.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: dkaip
 */


#include "HelperFunctions.hh"
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
        int sTypeValue = getSTypeAsInt(env, jVkComputePipelineCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNext(env, jVkComputePipelineCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
            return;
        }

        void *pNext = nullptr;

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
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkComputePipelineCreateInfoClass, "getStage", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/CreateInfos/VkPipelineShaderStageCreateInfo;");
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
        methodId = env->GetMethodID(vkComputePipelineCreateInfoClass, "getLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPipelineLayout;");
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
        methodId = env->GetMethodID(vkComputePipelineCreateInfoClass, "getBasePipelineHandle", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPipeline;");
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

        vkComputePipelineCreateInfo->sType              = (VkStructureType)sTypeValue;
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

    void getVkComputePipelineCreateInfoCollection(
            JNIEnv *env,
            const jobject jVkComputePipelineCreateInfoCollectionObject,
            VkComputePipelineCreateInfo **vkComputePipelineCreateInfos,
            int *numberOfCreateInfos,
            std::vector<void *> *memoryToFree)
    {
        if (jVkComputePipelineCreateInfoCollectionObject == nullptr)
        {
            return;
        }

        jclass vkComputePipelineCreateInfoCollectionClass = env->GetObjectClass(jVkComputePipelineCreateInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkComputePipelineCreateInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkComputePipelineCreateInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfCreateInfos = numberOfElements;
        *vkComputePipelineCreateInfos = (VkComputePipelineCreateInfo *)calloc(numberOfElements, sizeof(VkComputePipelineCreateInfo));
        memoryToFree->push_back(*vkComputePipelineCreateInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkComputePipelineCreateInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkComputePipelineCreateInfoCollectionObject, iteratorMethodId);
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

            jobject jVkComputePipelineCreateInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkComputePipelineCreateInfo(
                    env,
                    jVkComputePipelineCreateInfoObject,
                    &(*vkComputePipelineCreateInfos)[i],
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                break;
            }

            i++;
        } while(true);
    }
}

