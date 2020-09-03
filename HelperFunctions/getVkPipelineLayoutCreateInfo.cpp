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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineLayoutCreateInfo(
        JNIEnv *env,
        const jobject jVkPipelineLayoutCreateInfoObject,
        VkPipelineLayoutCreateInfo *vkPipelineLayoutCreateInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineLayoutCreateInfoClass = env->GetObjectClass(jVkPipelineLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not retrieve class for jVkPipelineLayoutCreateInfoObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkPipelineLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPipelineLayoutCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineLayoutCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineLayoutCreateFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineLayoutCreateInfoClass, "getSetLayouts", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSetLayouts.");
            return;
        }

        jobject jVkDescriptorSetLayoutCollection = env->CallObjectMethod(jVkPipelineLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkDescriptorSetLayout_T **vkDescriptorSetLayouts = nullptr;
        int numberOfDescriptorSetLayouts = 0;

        if (jVkDescriptorSetLayoutCollection != nullptr)
        {
            getVkDescriptorSetLayoutCollection(
                    env,
                    jVkDescriptorSetLayoutCollection,
                    &vkDescriptorSetLayouts,
                    &numberOfDescriptorSetLayouts,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkDescriptorSetLayoutCollection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineLayoutCreateInfoClass, "getPushConstantRanges", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPushConstantRanges.");
            return;
        }

        jobject jVkPushConstantRangeCollectionObject = env->CallObjectMethod(jVkPipelineLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPushConstantRange *vkPushConstantRanges = nullptr;
        int numberOfPushConstantRanges = 0;

        if (jVkPushConstantRangeCollectionObject != nullptr)
        {
            getVkPushConstantRangeCollection(
                    env,
					jVkPushConstantRangeCollectionObject,
                    &vkPushConstantRanges,
                    &numberOfPushConstantRanges,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPushConstantRangeCollection.");
                return;
            }
        }

        vkPipelineLayoutCreateInfo->sType = sTypeValue;
        vkPipelineLayoutCreateInfo->pNext = (void *)pNext;
        vkPipelineLayoutCreateInfo->flags = flags;
        vkPipelineLayoutCreateInfo->setLayoutCount = numberOfDescriptorSetLayouts;
        vkPipelineLayoutCreateInfo->pSetLayouts = vkDescriptorSetLayouts;
        vkPipelineLayoutCreateInfo->pushConstantRangeCount = numberOfPushConstantRanges;
        vkPipelineLayoutCreateInfo->pPushConstantRanges = vkPushConstantRanges;
    }
}
