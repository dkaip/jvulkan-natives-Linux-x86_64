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
    void getVkCopyDescriptorSet(
            JNIEnv *env,
            jobject jVkCopyDescriptorSetObject,
            VkCopyDescriptorSet *vkCopyDescriptorSet,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCopyDescriptorSetClass = env->GetObjectClass(jVkCopyDescriptorSetObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkCopyDescriptorSetObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkCopyDescriptorSetObject);
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
        jmethodID methodId = env->GetMethodID(vkCopyDescriptorSetClass, "getSrcSet", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDescriptorSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorSetObject = env->CallObjectMethod(jVkCopyDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDescriptorSet_T *srcSetHandle = (VkDescriptorSet_T *)jvulkan::getHandleValue(env, jVkDescriptorSetObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCopyDescriptorSetClass, "getSrcBinding", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jSrcBinding = env->CallIntMethod(jVkCopyDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCopyDescriptorSetClass, "getSrcArrayElement", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jSrcArrayElement = env->CallIntMethod(jVkCopyDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCopyDescriptorSetClass, "getDstSet", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDescriptorSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkDescriptorSetObject = env->CallObjectMethod(jVkCopyDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDescriptorSet_T *dstSetHandle = (VkDescriptorSet_T *)jvulkan::getHandleValue(env, jVkDescriptorSetObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCopyDescriptorSetClass, "getDstBinding", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jDstBinding = env->CallIntMethod(jVkCopyDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCopyDescriptorSetClass, "getDstArrayElement", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jDstArrayElement = env->CallIntMethod(jVkCopyDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCopyDescriptorSetClass, "getDescriptorCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jDescriptorCount = env->CallIntMethod(jVkCopyDescriptorSetObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkCopyDescriptorSet->sType = sTypeValue;
        vkCopyDescriptorSet->pNext = (void *)pNext;
        vkCopyDescriptorSet->srcSet = srcSetHandle;
        vkCopyDescriptorSet->srcBinding = jSrcBinding;
        vkCopyDescriptorSet->srcArrayElement = jSrcArrayElement;
        vkCopyDescriptorSet->dstSet = dstSetHandle;
        vkCopyDescriptorSet->dstBinding = jDstBinding;
        vkCopyDescriptorSet->dstArrayElement = jDstArrayElement;
        vkCopyDescriptorSet->descriptorCount = jDescriptorCount;
    }

    void getVkCopyDescriptorSetCollection(
            JNIEnv *env,
            const jobject jVkCopyDescriptorSetCollectionObject,
            VkCopyDescriptorSet **vkCopyDescriptorSets,
            int *numberOfVkCopyDescriptorSets,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCopyDescriptorSetCollectionClass = env->GetObjectClass(jVkCopyDescriptorSetCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkCopyDescriptorSetCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkCopyDescriptorSetCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkCopyDescriptorSets = numberOfElements;
        *vkCopyDescriptorSets = (VkCopyDescriptorSet *)calloc(numberOfElements, sizeof(VkCopyDescriptorSet));
        memoryToFree->push_back(*vkCopyDescriptorSets);

        jmethodID iteratorMethodId = env->GetMethodID(vkCopyDescriptorSetCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkCopyDescriptorSetCollectionObject, iteratorMethodId);
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

            jobject jVkCopyDescriptorSetObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkCopyDescriptorSet(
                    env,
                    jVkCopyDescriptorSetObject,
                    &((*vkCopyDescriptorSets)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
