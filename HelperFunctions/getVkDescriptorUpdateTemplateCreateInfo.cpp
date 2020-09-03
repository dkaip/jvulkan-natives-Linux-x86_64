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
 * getVkDescriptorUpdateTemplateCreateInfo.cpp
 *
 *  Created on: May 8, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDescriptorUpdateTemplateCreateInfo(
            JNIEnv *env,
            jobject jVkDescriptorUpdateTemplateCreateInfoObject,
			VkDescriptorUpdateTemplateCreateInfo *vkDescriptorUpdateTemplateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorUpdateTemplateCreateInfoClass = env->GetObjectClass(jVkDescriptorUpdateTemplateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDescriptorUpdateTemplateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkDescriptorUpdateTemplateCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkDescriptorUpdateTemplateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getFlags methodId");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDescriptorUpdateTemplateCreateInfoObject, methodId);
        VkDescriptorUpdateTemplateCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkDescriptorUpdateTemplateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateCreateInfoClass, "getDescriptorUpdateEntries", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDescriptorUpdateEntries methodId");
            return;
        }

        jobject jVkDescriptorUpdateTemplateEntryCollection = env->CallObjectMethod(jVkDescriptorUpdateTemplateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getDescriptorUpdateEntries");
            return;
        }

        int numberOfVkDescriptorUpdateTemplateEntries = 0;
        VkDescriptorUpdateTemplateEntry *vkDescriptorUpdateTemplateEntries = nullptr;

        if (jVkDescriptorUpdateTemplateEntryCollection != nullptr)
        {
            jvulkan::getVkDescriptorUpdateTemplateEntryCollection(
                    env,
					jVkDescriptorUpdateTemplateEntryCollection,
                    &vkDescriptorUpdateTemplateEntries,
                    &numberOfVkDescriptorUpdateTemplateEntries,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkDescriptorUpdateTemplateEntryCollection");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateCreateInfoClass, "getTemplateType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkDescriptorUpdateTemplateType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType methodId");
            return;
        }

        jobject jVkDescriptorUpdateTemplateTypeObject = env->CallObjectMethod(jVkDescriptorUpdateTemplateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getTemplateType");
            return;
        }

        jclass vkDescriptorUpdateTemplateTypeEnumClass = env->GetObjectClass(jVkDescriptorUpdateTemplateTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkDescriptorUpdateTemplateTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkDescriptorUpdateTemplateType vkDescriptorUpdateTemplateTypeEnumValue = (VkDescriptorUpdateTemplateType)env->CallIntMethod(jVkDescriptorUpdateTemplateTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateCreateInfoClass, "getDescriptorSetLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDescriptorSetLayout;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDescriptorSetLayout methodId");
            return;
        }

        jobject jVkDescriptorSetLayoutHandleObject = env->CallObjectMethod(jVkDescriptorUpdateTemplateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getDescriptorSetLayout");
            return;
        }

        VkDescriptorSetLayout_T *vkDescriptorSetLayoutHandle = (VkDescriptorSetLayout_T *)jvulkan::getHandleValue(env, jVkDescriptorSetLayoutHandleObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue for jVkDescriptorSetLayoutHandleObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateCreateInfoClass, "getPipelineBindPoint", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineBindPoint;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getPipelineBindPoint methodId");
            return;
        }

        jobject jVkPipelineBindPointObject = env->CallObjectMethod(jVkDescriptorUpdateTemplateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getPipelineBindPoint");
            return;
        }

        jclass vkPipelineBindPointEnumClass = env->GetObjectClass(jVkPipelineBindPointObject);

        valueOfMethodId = env->GetMethodID(vkPipelineBindPointEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkPipelineBindPoint vkPipelineBindPointEnumValue = (VkPipelineBindPoint)env->CallIntMethod(jVkPipelineBindPointObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateCreateInfoClass, "getPipelineLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineLayout;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getPipelineLayout methodId");
            return;
        }

        jobject jVkPipelineLayoutHandleObject = env->CallObjectMethod(jVkDescriptorUpdateTemplateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getPipelineLayout");
            return;
        }

        VkPipelineLayout_T *vkPipelineLayoutHandle = (VkPipelineLayout_T *)jvulkan::getHandleValue(env, jVkPipelineLayoutHandleObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue for jVkPipelineLayoutHandleObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateCreateInfoClass, "getSet", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getSet methodId");
            return;
        }

        jint jset = env->CallIntMethod(jVkDescriptorUpdateTemplateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for set value");
            return;
        }


        vkDescriptorUpdateTemplateCreateInfo->sType = sTypeValue;
        vkDescriptorUpdateTemplateCreateInfo->pNext = (void *)pNext;
        vkDescriptorUpdateTemplateCreateInfo->flags = flags;
        vkDescriptorUpdateTemplateCreateInfo->descriptorUpdateEntryCount = numberOfVkDescriptorUpdateTemplateEntries;
        vkDescriptorUpdateTemplateCreateInfo->pDescriptorUpdateEntries = vkDescriptorUpdateTemplateEntries;
        vkDescriptorUpdateTemplateCreateInfo->templateType = vkDescriptorUpdateTemplateTypeEnumValue;
        vkDescriptorUpdateTemplateCreateInfo->descriptorSetLayout = vkDescriptorSetLayoutHandle;
        vkDescriptorUpdateTemplateCreateInfo->pipelineBindPoint = vkPipelineBindPointEnumValue;
        vkDescriptorUpdateTemplateCreateInfo->pipelineLayout = vkPipelineLayoutHandle;
        vkDescriptorUpdateTemplateCreateInfo->set = jset;
    }
}



