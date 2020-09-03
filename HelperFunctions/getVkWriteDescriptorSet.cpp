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
 * getVkWriteDescriptorSet.cpp
 *
 *  Created on: Mar 10, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkWriteDescriptorSet(
            JNIEnv *env,
            const jobject jVkWriteDescriptorSetObject,
            VkWriteDescriptorSet *vkWriteDescriptorSet,
            std::vector<void *> *memoryToFree)
    {
        jclass vkWriteDescriptorSetClass = env->GetObjectClass(jVkWriteDescriptorSetObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkWriteDescriptorSetObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSType(env, jVkWriteDescriptorSetObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkWriteDescriptorSetObject);
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
        jmethodID methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getDstSet", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDescriptorSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getDstSet.");
            return;
        }

        jobject jVkDescriptorSetObject = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkDescriptorSet_T *descriptorSetHandle = nullptr;
        if (jVkDescriptorSetObject != nullptr)
        {
        	descriptorSetHandle = (VkDescriptorSet_T *)jvulkan::getHandleValue(env, jVkDescriptorSetObject);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error trying to get jVkDescriptorSetObject.");
				return;
			}
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getDstBinding", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getDstBinding.");
            return;
        }

        jint jDstBinding = env->CallIntMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getDstArrayElement", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getDstArrayElement.");
            return;
        }

        jint jDstArrayElement = env->CallIntMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getDescriptorType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkDescriptorType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getDescriptorType.");
            return;
        }

        jobject jVkDescriptorTypeObject = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkDescriptorTypeEnumClass = env->GetObjectClass(jVkDescriptorTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkDescriptorTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkDescriptorType vkDescriptorTypeEnumValue = (VkDescriptorType)env->CallIntMethod(jVkDescriptorTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getImageInfo", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getImageInfo.");
            return;
        }

        jobject jVkDescriptorImageInfoCollection = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfVkDescriptorImageInfos = 0;
        VkDescriptorImageInfo *vkDescriptorImageInfos = nullptr;

        if (jVkDescriptorImageInfoCollection != nullptr)
        {
            jvulkan::getVkDescriptorImageInfoCollection(
                    env,
                    jVkDescriptorImageInfoCollection,
                    &vkDescriptorImageInfos,
                    &numberOfVkDescriptorImageInfos,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkDescriptorImageInfoCollection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getBufferInfo", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getBufferInfo.");
            return;
        }

        jobject jVkDescriptorBufferInfoCollection = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfVkDescriptorBufferInfos = 0;
        VkDescriptorBufferInfo *vkDescriptorBufferInfos = nullptr;

        if (jVkDescriptorBufferInfoCollection != nullptr)
        {
            jvulkan::getVkDescriptorBufferInfoCollection(
                    env,
                    jVkDescriptorBufferInfoCollection,
                    &vkDescriptorBufferInfos,
                    &numberOfVkDescriptorBufferInfos,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkDescriptorBufferInfoCollection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getTexelBufferView", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getTexelBufferView.");
            return;
        }

        jobject jVkBufferViewCollection = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfVkBufferViews = 0;
        VkBufferView *vkBufferViews = nullptr;

        if (jVkBufferViewCollection != nullptr)
        {
            jvulkan::getVkBufferViewCollection(
                    env,
                    jVkBufferViewCollection,
                    &vkBufferViews,
                    &numberOfVkBufferViews,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkBufferViewCollection.");
                return;
            }
        }

        uint32_t descriptorCount = 0xFFFFFFFF;

        if (numberOfVkDescriptorImageInfos != 0)
        {
            if (numberOfVkDescriptorBufferInfos != 0 ||
                numberOfVkBufferViews != 0)
            {
            	LOGERROR(env, "%s", "numberOfVkDescriptorImageInfos is not 0 so numberOfVkDescriptorImageInfos and numberOfVkBufferViews should be");
                return;
            }
            else
                descriptorCount = (uint32_t)numberOfVkDescriptorImageInfos;
        }

        if (numberOfVkDescriptorBufferInfos != 0)
        {
            if (numberOfVkDescriptorImageInfos != 0 ||
                numberOfVkBufferViews != 0)
            {
            	LOGERROR(env, "%s", "numberOfVkDescriptorBufferInfos is not 0 so numberOfVkDescriptorImageInfos and numberOfVkBufferViews should be");
                return;
            }
            else
                descriptorCount = (uint32_t)numberOfVkDescriptorBufferInfos;
        }

        if (numberOfVkBufferViews != 0)
        {
            if (numberOfVkDescriptorImageInfos != 0 ||
                numberOfVkDescriptorBufferInfos != 0)
            {
            	LOGERROR(env, "%s", "numberOfVkBufferViews is not 0 so numberOfVkDescriptorImageInfos and numberOfVkDescriptorBufferInfos should be");
                return;
            }
            else
                descriptorCount = (uint32_t)numberOfVkBufferViews;
        }

        vkWriteDescriptorSet->sType = (VkStructureType)sTypeValue;
        vkWriteDescriptorSet->pNext = (void *)pNext;
        vkWriteDescriptorSet->dstSet = descriptorSetHandle;
        vkWriteDescriptorSet->dstBinding = jDstBinding;
        vkWriteDescriptorSet->dstArrayElement = jDstArrayElement;
        vkWriteDescriptorSet->descriptorType = vkDescriptorTypeEnumValue;
        vkWriteDescriptorSet->descriptorCount = descriptorCount;
        vkWriteDescriptorSet->pImageInfo = vkDescriptorImageInfos;
        vkWriteDescriptorSet->pBufferInfo = vkDescriptorBufferInfos;
        vkWriteDescriptorSet->pTexelBufferView = vkBufferViews;
    }
}
