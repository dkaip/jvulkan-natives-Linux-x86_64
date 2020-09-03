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
    void getVkVertexInputBindingDescription(
            JNIEnv *env,
            const jobject jVkVertexInputBindingDescriptionObject,
            VkVertexInputBindingDescription *vkVertexInputBindingDescription,
            std::vector<void *> *memoryToFree)
    {
        jclass vkVertexInputBindingDescriptionClass = env->GetObjectClass(jVkVertexInputBindingDescriptionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkVertexInputBindingDescriptionClass, "getBinding", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint binding = env->CallIntMethod(jVkVertexInputBindingDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputBindingDescriptionClass, "getStride", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint stride = env->CallIntMethod(jVkVertexInputBindingDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputBindingDescriptionClass, "getInputRate", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkVertexInputRate;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkVertexInputRateObject = env->CallObjectMethod(jVkVertexInputBindingDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkVertexInputRateEnumClass = env->GetObjectClass(jVkVertexInputRateObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkVertexInputRateEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkVertexInputRateEnumValue = env->CallIntMethod(jVkVertexInputRateObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkVertexInputBindingDescription->binding = binding;
        vkVertexInputBindingDescription->stride = stride;
        vkVertexInputBindingDescription->inputRate = (VkVertexInputRate)vkVertexInputRateEnumValue;
    }

    void getVkVertexInputBindingDescriptionCollection(
            JNIEnv *env,
            const jobject jVkVertexInputBindingDescriptionCollectionObject,
            VkVertexInputBindingDescription **vkVertexInputBindingDescriptions,
            int *numberOfVkVertexInputBindingDescriptions,
            std::vector<void *> *memoryToFree)
    {
        jclass vkVertexInputBindingDescriptionCollectionClass = env->GetObjectClass(jVkVertexInputBindingDescriptionCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkVertexInputBindingDescriptionCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkVertexInputBindingDescriptionCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkVertexInputBindingDescriptions = numberOfElements;
        *vkVertexInputBindingDescriptions = (VkVertexInputBindingDescription *)calloc(numberOfElements, sizeof(VkVertexInputBindingDescription));
        memoryToFree->push_back(*vkVertexInputBindingDescriptions);

        jmethodID iteratorMethodId = env->GetMethodID(vkVertexInputBindingDescriptionCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkVertexInputBindingDescriptionCollectionObject, iteratorMethodId);
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

            jobject jVkVertexInputBindingDescriptionObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkVertexInputBindingDescription(
                    env,
                    jVkVertexInputBindingDescriptionObject,
                    &((*vkVertexInputBindingDescriptions)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }

    void getVkVertexInputAttributeDescription(
            JNIEnv *env,
            const jobject jVkVertexInputAttributeDescriptionObject,
            VkVertexInputAttributeDescription *vkVertexInputAttributeDescription,
            std::vector<void *> *memoryToFree)
    {
        jclass vkVertexInputAttributeDescriptionClass = env->GetObjectClass(jVkVertexInputAttributeDescriptionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkVertexInputAttributeDescriptionClass, "getLocation", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint location = env->CallIntMethod(jVkVertexInputAttributeDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputAttributeDescriptionClass, "getBinding", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint binding = env->CallIntMethod(jVkVertexInputAttributeDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputAttributeDescriptionClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFormatObject = env->CallObjectMethod(jVkVertexInputAttributeDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFormatEnumClass = env->GetObjectClass(jVkFormatObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkFormatEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkFormatEnumValue = env->CallIntMethod(jVkFormatObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputAttributeDescriptionClass, "getOffset", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint offset = env->CallIntMethod(jVkVertexInputAttributeDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkVertexInputAttributeDescription->location = location;
        vkVertexInputAttributeDescription->binding  = binding;
        vkVertexInputAttributeDescription->format   = (VkFormat)vkFormatEnumValue;
        vkVertexInputAttributeDescription->offset   = offset;
    }

    void getVkVertexInputAttributeDescriptionCollection(
            JNIEnv *env,
            const jobject jVkVertexInputAttributeDescriptionCollectionObject,
            VkVertexInputAttributeDescription **vkVertexInputAttributeDescription,
            int *numberOfVkVertexInputAttributeDescriptions,
            std::vector<void *> *memoryToFree)
    {
        jclass vkVertexInputAttributeDescriptionCollectionClass = env->GetObjectClass(jVkVertexInputAttributeDescriptionCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkVertexInputAttributeDescriptionCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkVertexInputAttributeDescriptionCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkVertexInputAttributeDescriptions = numberOfElements;
        *vkVertexInputAttributeDescription = (VkVertexInputAttributeDescription *)calloc(numberOfElements, sizeof(VkVertexInputAttributeDescription));
        memoryToFree->push_back(*vkVertexInputAttributeDescription);

        jmethodID iteratorMethodId = env->GetMethodID(vkVertexInputAttributeDescriptionCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkVertexInputAttributeDescriptionCollectionObject, iteratorMethodId);
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

            jobject jVkVertexInputAttributeDescriptionObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkVertexInputAttributeDescription(
                    env,
                    jVkVertexInputAttributeDescriptionObject,
                    &((*vkVertexInputAttributeDescription)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }

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
        int sTypeValue = getSType(env, jVkPipelineVertexInputStateCreateInfoObject);
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

        vkPipelineVertexInputStateCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineVertexInputStateCreateInfo->pNext = (void *)pNext;
        vkPipelineVertexInputStateCreateInfo->flags = (VkPipelineVertexInputStateCreateFlags)flags;
        vkPipelineVertexInputStateCreateInfo->vertexBindingDescriptionCount = numberOfVertexInputBindingDescriptions;
        vkPipelineVertexInputStateCreateInfo->pVertexBindingDescriptions = vkVertexInputBindingDescriptions;
        vkPipelineVertexInputStateCreateInfo->vertexAttributeDescriptionCount = numberOfVertexInputAttributeDescriptions;
        vkPipelineVertexInputStateCreateInfo->pVertexAttributeDescriptions = vkVertexInputAttributeDescription;
    }
}
