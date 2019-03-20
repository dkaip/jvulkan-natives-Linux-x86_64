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
    void getVkDescriptorSetLayoutBinding(
            JNIEnv *env,
            const jobject jVkDescriptorSetLayoutBindingObject,
            VkDescriptorSetLayoutBinding *vkDescriptorSetLayoutBinding,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetLayoutBindingClass = env->GetObjectClass(jVkDescriptorSetLayoutBindingObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorSetLayoutBindingClass, "getBinding", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jBinding = env->CallIntMethod(jVkDescriptorSetLayoutBindingObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetLayoutBindingClass, "getDescriptorType", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkDescriptorType;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorTypeObject = env->CallObjectMethod(jVkDescriptorSetLayoutBindingObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkDescriptorTypeObjectEnumClass = env->GetObjectClass(jVkDescriptorTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkDescriptorTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDescriptorType descriptorTypeEnumValue = (VkDescriptorType)env->CallIntMethod(jVkDescriptorTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetLayoutBindingClass, "getDescriptorCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jDescriptorCount = env->CallIntMethod(jVkDescriptorSetLayoutBindingObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetLayoutBindingClass, "getStageFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDescriptorSetLayoutBindingObject, methodId);
        VkShaderStageFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkShaderStageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetLayoutBindingClass, "getImmutableSamplers", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSamplerCollection = env->CallObjectMethod(jVkDescriptorSetLayoutBindingObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkSamplers = 0;
        VkSampler *vkSamplers = nullptr;

        if (jVkSamplerCollection != nullptr)
        {
            hwjvi::getVkSamplerCollection(
                    env,
                    jVkSamplerCollection,
                    &vkSamplers,
                    &numberOfVkSamplers,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDescriptorSetLayoutBinding->binding = jBinding;
        vkDescriptorSetLayoutBinding->descriptorType = descriptorTypeEnumValue;
        vkDescriptorSetLayoutBinding->descriptorCount = jDescriptorCount;
        vkDescriptorSetLayoutBinding->stageFlags = flags;
        vkDescriptorSetLayoutBinding->pImmutableSamplers = vkSamplers;
//
//        std::cerr << "Binding is " << jBinding << std::endl;
//        std::cerr << "descriptorType is " << descriptorTypeEnumValue << std::endl;
//        std::cerr << "descriptorCount is " << jDescriptorCount << std::endl;
//        std::cerr << "stageFlags is " << flags << std::endl;
//        std::cerr << "pImmutableSamplers is " << vkSamplers << std::endl;
    }

    void getVkDescriptorSetLayoutBindingCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetLayoutBindingCollectionObject,
            VkDescriptorSetLayoutBinding **vkDescriptorSetLayoutBindings,
            int *numberOfVkDescriptorSetLayoutBindings,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetLayoutBindingCollectionClass = env->GetObjectClass(jVkDescriptorSetLayoutBindingCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorSetLayoutBindingCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorSetLayoutBindingCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDescriptorSetLayoutBindings = numberOfElements;
        *vkDescriptorSetLayoutBindings = (VkDescriptorSetLayoutBinding *)calloc(numberOfElements, sizeof(VkDescriptorSetLayoutBinding));
        memoryToFree->push_back(*vkDescriptorSetLayoutBindings);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorSetLayoutBindingCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorSetLayoutBindingCollectionObject, iteratorMethodId);
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

            getVkDescriptorSetLayoutBinding(
                    env,
                    jVkDescriptorSetLayoutBindingObject,
                    &((*vkDescriptorSetLayoutBindings)[i]),
                    memoryToFree);

//            std::cerr << "Binding is " << (*vkDescriptorSetLayoutBindings)[i].binding << std::endl;
//            std::cerr << "descriptorType is " << (*vkDescriptorSetLayoutBindings)[i].descriptorType << std::endl;
//            std::cerr << "descriptorCount is " << (*vkDescriptorSetLayoutBindings)[i].descriptorCount << std::endl;
//            std::cerr << "stageFlags is " << (*vkDescriptorSetLayoutBindings)[i].stageFlags << std::endl;
//            std::cerr << "pImmutableSamplers is " << (*vkDescriptorSetLayoutBindings)[i].pImmutableSamplers << std::endl;
            i++;
        } while(true);
    }
}
