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
    void getVkDescriptorSetAllocateInfo(
            JNIEnv *env,
            const jobject jVkDescriptorSetAllocateInfoObject,
            VkDescriptorSetAllocateInfo *vkDescriptorSetAllocateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetAllocateInfoClass = env->GetObjectClass(jVkDescriptorSetAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSType(env, jVkDescriptorSetAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkDescriptorSetAllocateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkDescriptorSetAllocateInfoClass, "getDescriptorPool", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDescriptorPool;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jDescriptorPoolObject = env->CallObjectMethod(jVkDescriptorSetAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDescriptorPool_T *descriptorPoolHandle = (VkDescriptorPool_T *)jvulkan::getHandleValue(env, jDescriptorPoolObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetAllocateInfoClass, "getSetLayouts", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorSetLayoutCollection = env->CallObjectMethod(jVkDescriptorSetAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkDescriptorSetLayouts = 0;
        VkDescriptorSetLayout *vkDescriptorSetLayouts = nullptr;

        if (jVkDescriptorSetLayoutCollection != nullptr)
        {
            jvulkan::getVkDescriptorSetLayoutCollection(
                    env,
                    jVkDescriptorSetLayoutCollection,
                    &vkDescriptorSetLayouts,
                    &numberOfVkDescriptorSetLayouts,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDescriptorSetAllocateInfo->sType = (VkStructureType)sTypeValue;
        vkDescriptorSetAllocateInfo->pNext = (void *)pNext;
        vkDescriptorSetAllocateInfo->descriptorPool = descriptorPoolHandle;
        vkDescriptorSetAllocateInfo->descriptorSetCount = numberOfVkDescriptorSetLayouts;
        vkDescriptorSetAllocateInfo->pSetLayouts = vkDescriptorSetLayouts;
    }

    void getVkDescriptorSetAllocateInfoCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetAllocateInfoCollectionObject,
            VkDescriptorSetAllocateInfo **vkDescriptorSetAllocateInfos,
            int *numberOfVkDescriptorSetAllocateInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetAllocateInfoCollectionClass = env->GetObjectClass(jVkDescriptorSetAllocateInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorSetAllocateInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorSetAllocateInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDescriptorSetAllocateInfos = numberOfElements;
        *vkDescriptorSetAllocateInfos = (VkDescriptorSetAllocateInfo *)calloc(numberOfElements, sizeof(VkDescriptorSetAllocateInfo));
        memoryToFree->push_back(*vkDescriptorSetAllocateInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorSetAllocateInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorSetAllocateInfoCollectionObject, iteratorMethodId);
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

            jobject jVkDescriptorSetLayoutBindingObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkDescriptorSetAllocateInfo(
                    env,
                    jVkDescriptorSetLayoutBindingObject,
                    &((*vkDescriptorSetAllocateInfos)[i]),
                    memoryToFree);
            std::cout << "Gack11" << std::endl;

            i++;
        } while(true);
    }
}
