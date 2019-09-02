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
    void getVkWriteDescriptorSet(
            JNIEnv *env,
            const jobject jVkWriteDescriptorSetObject,
            VkWriteDescriptorSet *vkWriteDescriptorSet,
            std::vector<void *> *memoryToFree)
    {
        jclass vkWriteDescriptorSetClass = env->GetObjectClass(jVkWriteDescriptorSetObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkWriteDescriptorSetObject);
        if (env->ExceptionOccurred())
        {
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
        jmethodID methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getDstSet", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDescriptorSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorSetObject = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDescriptorSet_T *descriptorSetHandle = (VkDescriptorSet_T *)jvulkan::getHandleValue(env, jVkDescriptorSetObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getDstBinding", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jDstBinding = env->CallIntMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getDstArrayElement", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jDstArrayElement = env->CallIntMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getDescriptorType", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkDescriptorType;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorTypeObject = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkDescriptorTypeEnumClass = env->GetObjectClass(jVkDescriptorTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkDescriptorTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDescriptorType vkDescriptorTypeEnumValue = (VkDescriptorType)env->CallIntMethod(jVkDescriptorTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getImageInfo", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorImageInfoCollection = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
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
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getBufferInfo", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorBufferInfoCollection = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
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
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkWriteDescriptorSetClass, "getTexelBufferView", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBufferViewCollection = env->CallObjectMethod(jVkWriteDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
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
                return;
            }
        }

        uint32_t descriptorCount = 0xFFFFFFFF;

        if (numberOfVkDescriptorImageInfos != 0)
        {
            if (numberOfVkDescriptorBufferInfos != 0 ||
                numberOfVkBufferViews != 0)
            {
                std::cerr << "numberOfVkDescriptorImageInfos is not 0 so numberOfVkDescriptorImageInfos and numberOfVkBufferViews should be" << std::endl;
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
                std::cerr << "numberOfVkDescriptorBufferInfos is not 0 so numberOfVkDescriptorImageInfos and numberOfVkBufferViews should be" << std::endl;
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
                std::cerr << "numberOfVkBufferViews is not 0 so numberOfVkDescriptorImageInfos and numberOfVkDescriptorBufferInfos should be" << std::endl;
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

    void getVkWriteDescriptorSetCollection(
            JNIEnv *env,
            const jobject jVkWriteDescriptorSetCollectionObject,
            VkWriteDescriptorSet **vkWriteDescriptorSets,
            int *numberOfVkWriteDescriptorSets,
            std::vector<void *> *memoryToFree)
    {
        jclass vkWriteDescriptorSetCollectionClass = env->GetObjectClass(jVkWriteDescriptorSetCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkWriteDescriptorSetCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkWriteDescriptorSetCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkWriteDescriptorSets = numberOfElements;
        *vkWriteDescriptorSets = (VkWriteDescriptorSet *)calloc(numberOfElements, sizeof(VkWriteDescriptorSet));
        memoryToFree->push_back(*vkWriteDescriptorSets);

        jmethodID iteratorMethodId = env->GetMethodID(vkWriteDescriptorSetCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkWriteDescriptorSetCollectionObject, iteratorMethodId);
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

            jobject jVkWriteDescriptorSetObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkWriteDescriptorSet(
                    env,
                    jVkWriteDescriptorSetObject,
                    &((*vkWriteDescriptorSets)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
