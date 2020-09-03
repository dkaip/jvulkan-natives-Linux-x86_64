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
    void getVkPipelineViewportStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineViewportStateCreateInfoObject,
            VkPipelineViewportStateCreateInfo *vkPipelineViewportStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineViewportStateCreateInfoClass = env->GetObjectClass(jVkPipelineViewportStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSType(env, jVkPipelineViewportStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineViewportStateCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkPipelineViewportStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineViewportStateCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineVertexInputStateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineViewportStateCreateInfoClass, "getViewports", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkViewports = env->CallObjectMethod(jVkPipelineViewportStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkViewports = 0;
        VkViewport *vkViewports = nullptr;
        getVkViewportCollection(
                env,
                jVkViewports,
                &vkViewports,
                &numberOfVkViewports,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineViewportStateCreateInfoClass, "getScissors", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkRect2Ds = env->CallObjectMethod(jVkPipelineViewportStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkRect2Ds = 0;
        VkRect2D *vkRect2Ds = nullptr;
        getVkRect2DCollection(
                env,
                jVkRect2Ds,
                &vkRect2Ds,
                &numberOfVkRect2Ds,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }


        vkPipelineViewportStateCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineViewportStateCreateInfo->pNext = (void *)pNext;
        vkPipelineViewportStateCreateInfo->flags = (VkPipelineViewportStateCreateFlags)flags;
        vkPipelineViewportStateCreateInfo->viewportCount = numberOfVkViewports;
        vkPipelineViewportStateCreateInfo->pViewports = vkViewports;
        vkPipelineViewportStateCreateInfo->scissorCount = numberOfVkRect2Ds;
        vkPipelineViewportStateCreateInfo->pScissors = vkRect2Ds;
    }
}
