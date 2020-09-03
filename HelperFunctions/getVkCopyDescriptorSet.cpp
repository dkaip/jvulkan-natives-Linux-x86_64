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
        	LOGERROR(env, "%s", "pNext must be null.");
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
}
