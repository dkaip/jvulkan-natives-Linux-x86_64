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
    void getVkSubpassDescription2KHR(
            JNIEnv *env,
            const jobject jVkSubpassDescription2KHRObject,
            VkSubpassDescription2KHR *vkSubpassDescription2KHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubpassDescription2KHRClass = env->GetObjectClass(jVkSubpassDescription2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkSubpassDescription2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkSubpassDescription2KHRObject);
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
        jmethodID methodId = env->GetMethodID(vkSubpassDescription2KHRClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkSubpassDescription2KHRObject, methodId);
        VkSubpassDescriptionFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkSubpassDescriptionFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2KHRClass, "getPipelineBindPoint", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineBindPoint;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineBindPointTypeObject = env->CallObjectMethod(jVkSubpassDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkPipelineBindPointTypeObjectEnumClass = env->GetObjectClass(jVkPipelineBindPointTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineBindPoint pipelineBindPointTypeEnumValue = (VkPipelineBindPoint)env->CallIntMethod(jVkPipelineBindPointTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2KHRClass, "getViewMask", "()Ljava/util/BitSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jBitSetObject = env->CallObjectMethod(jVkSubpassDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass bitSetClass = env->GetObjectClass(jBitSetObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID lengthMethodId = env->GetMethodID(bitSetClass, "length", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID getMethodId = env->GetMethodID(bitSetClass, "get", "(I)Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jBitSetLength = env->CallIntMethod(jBitSetObject, lengthMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int bitSetLength = std::min(jBitSetLength, 32);
        uint32_t viewMask = 0;

        for (int i = 0; i < bitSetLength; i++)
        {
            jboolean isSet = env->CallBooleanMethod(jBitSetObject, getMethodId, i);
            if (env->ExceptionOccurred())
            {
                return;
            }

            if (isSet == true)
            {
                viewMask |= 1 << i;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2KHRClass, "getInputAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAttachmentReference2KHRCollectionObject = env->CallObjectMethod(jVkSubpassDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfInputAttachementObjects = 0;
        VkAttachmentReference2KHR *inputAttachments = nullptr;
        if (jVkAttachmentReference2KHRCollectionObject != nullptr)
        {
            jvulkan::getVkAttachmentReference2KHRCollection(
                    env,
                    jVkAttachmentReference2KHRCollectionObject,
                    &inputAttachments,
                    &numberOfInputAttachementObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2KHRClass, "getColorAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkAttachmentReference2KHRCollectionObject = env->CallObjectMethod(jVkSubpassDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfColorAttachementObjects = 0;
        VkAttachmentReference2KHR *colorAttachments = nullptr;
        if (jVkAttachmentReference2KHRCollectionObject != nullptr)
        {
            jvulkan::getVkAttachmentReference2KHRCollection(
                    env,
                    jVkAttachmentReference2KHRCollectionObject,
                    &colorAttachments,
                    &numberOfColorAttachementObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2KHRClass, "getResolveAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkAttachmentReference2KHRCollectionObject = env->CallObjectMethod(jVkSubpassDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfResolveAttachementObjects = 0;
        VkAttachmentReference2KHR *resolveAttachments = nullptr;
        if (jVkAttachmentReference2KHRCollectionObject != nullptr)
        {
            jvulkan::getVkAttachmentReference2KHRCollection(
                    env,
                    jVkAttachmentReference2KHRCollectionObject,
                    &resolveAttachments,
                    &numberOfResolveAttachementObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2KHRClass, "getDepthStencilAttachment", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkAttachmentReference2KHR;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAttachmentReference2KHRObject = env->CallObjectMethod(jVkSubpassDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkAttachmentReference2KHR *depthStencilAttachment = nullptr;

        if (jVkAttachmentReference2KHRObject != nullptr)
        {
            depthStencilAttachment = (VkAttachmentReference2KHR *)calloc(1, sizeof(VkAttachmentReference2KHR));
            memoryToFree->push_back(depthStencilAttachment);
            jvulkan::getVkAttachmentReference2KHR(
                    env,
                    jVkAttachmentReference2KHRObject,
                    depthStencilAttachment,
                    memoryToFree);
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2KHRClass, "getPreserveAttachments", "()[I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jPreserveAttachments = (jintArray)env->CallObjectMethod(jVkSubpassDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int *preserveAttachmentsArray = nullptr;
        jsize arrayLength = 0;
        if (jPreserveAttachments != nullptr)
        {
            arrayLength = env->GetArrayLength(jPreserveAttachments);

            preserveAttachmentsArray = (int *)calloc(arrayLength, sizeof(int));
            memoryToFree->push_back(preserveAttachmentsArray);

            env->GetIntArrayRegion(jPreserveAttachments, 0, arrayLength, preserveAttachmentsArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkSubpassDescription2KHR->sType = (VkStructureType)sTypeValue;
        vkSubpassDescription2KHR->pNext = (void *)pNext;
        vkSubpassDescription2KHR->flags = flags;

        vkSubpassDescription2KHR->pipelineBindPoint = pipelineBindPointTypeEnumValue;
        vkSubpassDescription2KHR->viewMask = viewMask;
        vkSubpassDescription2KHR->inputAttachmentCount = numberOfInputAttachementObjects;
        vkSubpassDescription2KHR->pInputAttachments = inputAttachments;
        vkSubpassDescription2KHR->colorAttachmentCount = numberOfColorAttachementObjects;
        vkSubpassDescription2KHR->pColorAttachments = colorAttachments;
        vkSubpassDescription2KHR->pResolveAttachments = resolveAttachments;
        vkSubpassDescription2KHR->pDepthStencilAttachment = depthStencilAttachment;
        vkSubpassDescription2KHR->preserveAttachmentCount = arrayLength;
        vkSubpassDescription2KHR->pPreserveAttachments = (uint32_t *)preserveAttachmentsArray;
    }

    void getVkSubpassDescription2KHRCollection(
            JNIEnv *env,
            const jobject jVkSubpassDescription2KHRCollectionObject,
            VkSubpassDescription2KHR **vkSubpassDescription2KHRs,
            int *numberOfVkSubpassDescription2KHRs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubpassDescription2KHRCollectionClass = env->GetObjectClass(jVkSubpassDescription2KHRCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSubpassDescription2KHRCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSubpassDescription2KHRCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkSubpassDescription2KHRs = numberOfElements;
        *vkSubpassDescription2KHRs = (VkSubpassDescription2KHR *)calloc(numberOfElements, sizeof(VkSubpassDescription2KHR));
        memoryToFree->push_back(*vkSubpassDescription2KHRs);

        jmethodID iteratorMethodId = env->GetMethodID(vkSubpassDescription2KHRCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSubpassDescription2KHRCollectionObject, iteratorMethodId);
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

            jobject jVkSubpassDescription2KHRObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkSubpassDescription2KHR(
                    env,
                    jVkSubpassDescription2KHRObject,
                    &((*vkSubpassDescription2KHRs)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
