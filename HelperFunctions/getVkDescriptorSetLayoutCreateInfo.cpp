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
    void getVkDescriptorSetLayoutCreateInfo(
            JNIEnv *env,
            jobject jVkDescriptorSetLayoutCreateInfoObject,
            VkDescriptorSetLayoutCreateInfo *vkDescriptorSetLayoutCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetLayoutCreateInfoClass = env->GetObjectClass(jVkDescriptorSetLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDescriptorSetLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDescriptorSetLayoutCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkDescriptorSetLayoutCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDescriptorSetLayoutCreateInfoObject, methodId);
        VkDescriptorSetLayoutCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkDescriptorSetLayoutCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetLayoutCreateInfoClass, "getBindings", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorSetLayoutBindingCollection = env->CallObjectMethod(jVkDescriptorSetLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkDescriptorSetLayoutBindingCollection = 0;
        VkDescriptorSetLayoutBinding *vkDescriptorSetLayoutBindings = nullptr;

        if (jVkDescriptorSetLayoutBindingCollection != nullptr)
        {
            jvulkan::getVkDescriptorSetLayoutBindingCollection(
                    env,
                    jVkDescriptorSetLayoutBindingCollection,
                    &vkDescriptorSetLayoutBindings,
                    &numberOfVkDescriptorSetLayoutBindingCollection,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDescriptorSetLayoutCreateInfo->sType = sTypeValue;
        vkDescriptorSetLayoutCreateInfo->pNext = (void *)pNext;
        vkDescriptorSetLayoutCreateInfo->flags = flags;
        vkDescriptorSetLayoutCreateInfo->bindingCount = numberOfVkDescriptorSetLayoutBindingCollection;
        vkDescriptorSetLayoutCreateInfo->pBindings = vkDescriptorSetLayoutBindings;
    }
}
