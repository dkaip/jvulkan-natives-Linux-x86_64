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
#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkDescriptorImageInfo(
            JNIEnv *env,
            const jobject jVkDescriptorImageInfoObject,
            VkDescriptorImageInfo *vkDescriptorImageInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorImageInfoClass = env->GetObjectClass(jVkDescriptorImageInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorImageInfoClass, "getSampler", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkSampler;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSamplerObject = env->CallObjectMethod(jVkDescriptorImageInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSampler_T *samplerHandle = (VkSampler_T *)hwjvi::getHandleValue(env, jVkSamplerObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorImageInfoClass, "getImageView", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkImageView;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageViewObject = env->CallObjectMethod(jVkDescriptorImageInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageView_T *imageViewHandle = (VkImageView_T *)hwjvi::getHandleValue(env, jVkImageViewObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorImageInfoClass, "getImageLayout", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageLayoutObject = env->CallObjectMethod(jVkDescriptorImageInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageLayoutEnumClass = env->GetObjectClass(jVkImageLayoutObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageLayout vkImageLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkDescriptorImageInfo->sampler = samplerHandle;
        vkDescriptorImageInfo->imageView = imageViewHandle;
        vkDescriptorImageInfo->imageLayout = vkImageLayoutEnumValue;
    }

    void getVkDescriptorImageInfoCollection(
            JNIEnv *env,
            const jobject jVkDescriptorImageInfoCollectionObject,
            VkDescriptorImageInfo **vkDescriptorImageInfos,
            int *numberOfVkDescriptorImageInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorImageInfoCollectionClass = env->GetObjectClass(jVkDescriptorImageInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorImageInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorImageInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDescriptorImageInfos = numberOfElements;
        *vkDescriptorImageInfos = (VkDescriptorImageInfo *)calloc(numberOfElements, sizeof(VkDescriptorImageInfo));
        memoryToFree->push_back(*vkDescriptorImageInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorImageInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorImageInfoCollectionObject, iteratorMethodId);
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

            jobject jVkDescriptorImageInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkDescriptorImageInfo(
                    env,
                    jVkDescriptorImageInfoObject,
                    &((*vkDescriptorImageInfos)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
