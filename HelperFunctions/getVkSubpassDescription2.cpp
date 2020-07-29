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
 * getVkSubpassDescription2.cpp
 *
 *  Created on: Jul 22, 2020
 *      Author: dkaip
 */


#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSubpassDescription2(
            JNIEnv *env,
            const jobject jVkSubpassDescription2Object,
            VkSubpassDescription2 *vkSubpassDescription2,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubpassDescription2Class = env->GetObjectClass(jVkSubpassDescription2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkSubpassDescription2Object.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkSubpassDescription2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkSubpassDescription2Object);
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
        jmethodID methodId = env->GetMethodID(vkSubpassDescription2Class, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkSubpassDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }
        VkSubpassDescriptionFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkSubpassDescriptionFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2Class, "getPipelineBindPoint", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineBindPoint;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getPipelineBindPoint.");
            return;
        }

        jobject jVkPipelineBindPointTypeObject = env->CallObjectMethod(jVkSubpassDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkPipelineBindPointTypeObjectEnumClass = env->GetObjectClass(jVkPipelineBindPointTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkAttachmentDescription2Object.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkPipelineBindPoint pipelineBindPointTypeEnumValue = (VkPipelineBindPoint)env->CallIntMethod(jVkPipelineBindPointTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2Class, "getViewMask", "()Ljava/util/BitSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getViewMask.");
            return;
        }

        jobject jBitSetObject = env->CallObjectMethod(jVkSubpassDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass bitSetClass = env->GetObjectClass(jBitSetObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jBitSetObject.");
            return;
        }

        jmethodID lengthMethodId = env->GetMethodID(bitSetClass, "length", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for length.");
            return;
        }

        jmethodID getMethodId = env->GetMethodID(bitSetClass, "get", "(I)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for get.");
            return;
        }

        jint jBitSetLength = env->CallIntMethod(jBitSetObject, lengthMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        int bitSetLength = std::min(jBitSetLength, 32);
        uint32_t viewMask = 0;

        for (int i = 0; i < bitSetLength; i++)
        {
            jboolean isSet = env->CallBooleanMethod(jBitSetObject, getMethodId, i);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
                return;
            }

            if (isSet == true)
            {
                viewMask |= 1 << i;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2Class, "getInputAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getInputAttachments.");
            return;
        }

        jobject jVkAttachmentReference2CollectionObject = env->CallObjectMethod(jVkSubpassDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfInputAttachementObjects = 0;
        VkAttachmentReference2 *inputAttachments = nullptr;
        if (jVkAttachmentReference2CollectionObject != nullptr)
        {
            jvulkan::getVkAttachmentReference2Collection(
                    env,
                    jVkAttachmentReference2CollectionObject,
                    &inputAttachments,
                    &numberOfInputAttachementObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::getVkAttachmentReference2Collection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2Class, "getColorAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getColorAttachments.");
            return;
        }

        jVkAttachmentReference2CollectionObject = env->CallObjectMethod(jVkSubpassDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfColorAttachementObjects = 0;
        VkAttachmentReference2 *colorAttachments = nullptr;
        if (jVkAttachmentReference2CollectionObject != nullptr)
        {
            jvulkan::getVkAttachmentReference2Collection(
                    env,
                    jVkAttachmentReference2CollectionObject,
                    &colorAttachments,
                    &numberOfColorAttachementObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::getVkAttachmentReference2Collection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2Class, "getResolveAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getResolveAttachments.");
            return;
        }

        jVkAttachmentReference2CollectionObject = env->CallObjectMethod(jVkSubpassDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfResolveAttachementObjects = 0;
        VkAttachmentReference2 *resolveAttachments = nullptr;
        if (jVkAttachmentReference2CollectionObject != nullptr)
        {
            jvulkan::getVkAttachmentReference2Collection(
                    env,
                    jVkAttachmentReference2CollectionObject,
                    &resolveAttachments,
                    &numberOfResolveAttachementObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::getVkAttachmentReference2Collection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2Class, "getDepthStencilAttachment", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkAttachmentReference2;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getDepthStencilAttachment.");
            return;
        }

        jobject jVkAttachmentReference2Object = env->CallObjectMethod(jVkSubpassDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkAttachmentReference2 *depthStencilAttachment = nullptr;

        if (jVkAttachmentReference2Object != nullptr)
        {
            depthStencilAttachment = (VkAttachmentReference2 *)calloc(1, sizeof(VkAttachmentReference2));
            memoryToFree->push_back(depthStencilAttachment);
            jvulkan::getVkAttachmentReference2(
                    env,
                    jVkAttachmentReference2Object,
                    depthStencilAttachment,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::getVkAttachmentReference2.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDescription2Class, "getPreserveAttachments", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getPreserveAttachments.");
            return;
        }

        jintArray jPreserveAttachments = (jintArray)env->CallObjectMethod(jVkSubpassDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
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
            	LOGERROR(env, "%s", "Error calling GetIntArrayRegion.");
                return;
            }
        }

        vkSubpassDescription2->sType = (VkStructureType)sTypeValue;
        vkSubpassDescription2->pNext = (void *)pNext;
        vkSubpassDescription2->flags = flags;

        vkSubpassDescription2->pipelineBindPoint = pipelineBindPointTypeEnumValue;
        vkSubpassDescription2->viewMask = viewMask;
        vkSubpassDescription2->inputAttachmentCount = numberOfInputAttachementObjects;
        vkSubpassDescription2->pInputAttachments = inputAttachments;
        vkSubpassDescription2->colorAttachmentCount = numberOfColorAttachementObjects;
        vkSubpassDescription2->pColorAttachments = colorAttachments;
        vkSubpassDescription2->pResolveAttachments = resolveAttachments;
        vkSubpassDescription2->pDepthStencilAttachment = depthStencilAttachment;
        vkSubpassDescription2->preserveAttachmentCount = arrayLength;
        vkSubpassDescription2->pPreserveAttachments = (uint32_t *)preserveAttachmentsArray;
    }
}
