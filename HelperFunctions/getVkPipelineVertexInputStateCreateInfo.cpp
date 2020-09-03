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
    void getVkPipelineVertexInputStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineVertexInputStateCreateInfoObject,
            VkPipelineVertexInputStateCreateInfo *vkPipelineVertexInputStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineVertexInputStateCreateInfoClass = env->GetObjectClass(jVkPipelineVertexInputStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineVertexInputStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkPipelineVertexInputStateCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkPipelineVertexInputStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineVertexInputStateCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineVertexInputStateCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineVertexInputStateCreateInfoClass, "getVertexBindingDescriptions", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkVertexInputBindingDescriptionCollection = env->CallObjectMethod(jVkPipelineVertexInputStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVertexInputBindingDescriptions = 0;
        VkVertexInputBindingDescription *vkVertexInputBindingDescriptions = nullptr;
        if (jVkVertexInputBindingDescriptionCollection != nullptr)
        {
            getVkVertexInputBindingDescriptionCollection(
                    env,
                    jVkVertexInputBindingDescriptionCollection,
                    &vkVertexInputBindingDescriptions,
                    &numberOfVertexInputBindingDescriptions,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {

                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineVertexInputStateCreateInfoClass, "getVertexAttributeDescriptions", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkVertexInputAttributeDescriptionCollection = env->CallObjectMethod(jVkPipelineVertexInputStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVertexInputAttributeDescriptions = 0;
        VkVertexInputAttributeDescription *vkVertexInputAttributeDescription = nullptr;
        if (jVkVertexInputAttributeDescriptionCollection != nullptr)
        {
            getVkVertexInputAttributeDescriptionCollection(
                    env,
                    jVkVertexInputAttributeDescriptionCollection,
                    &vkVertexInputAttributeDescription,
                    &numberOfVertexInputAttributeDescriptions,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {

                return;
            }
        }

        vkPipelineVertexInputStateCreateInfo->sType = sTypeValue;
        vkPipelineVertexInputStateCreateInfo->pNext = (void *)pNext;
        vkPipelineVertexInputStateCreateInfo->flags = (VkPipelineVertexInputStateCreateFlags)flags;
        vkPipelineVertexInputStateCreateInfo->vertexBindingDescriptionCount = numberOfVertexInputBindingDescriptions;
        vkPipelineVertexInputStateCreateInfo->pVertexBindingDescriptions = vkVertexInputBindingDescriptions;
        vkPipelineVertexInputStateCreateInfo->vertexAttributeDescriptionCount = numberOfVertexInputAttributeDescriptions;
        vkPipelineVertexInputStateCreateInfo->pVertexAttributeDescriptions = vkVertexInputAttributeDescription;
    }
}
