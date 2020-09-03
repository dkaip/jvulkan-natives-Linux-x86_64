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
    void getVkRenderPassCreateInfo2(
            JNIEnv *env,
            jobject jVkRenderPassCreateInfo2Object,
            VkRenderPassCreateInfo2 *vkRenderPassCreateInfo2,
            std::vector<void *> *memoryToFree)
    {
        jclass vkRenderPassCreateInfo2Class = env->GetObjectClass(jVkRenderPassCreateInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkRenderPassCreateInfo2Object.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkRenderPassCreateInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkRenderPassCreateInfo2Object);
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
        jmethodID methodId = env->GetMethodID(vkRenderPassCreateInfo2Class, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkRenderPassCreateInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }
        VkRenderPassCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkRenderPassCreateFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfo2Class, "getAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getAttachments.");
            return;
        }

        jobject jVkAttachmentDescription2CollectionObject = env->CallObjectMethod(jVkRenderPassCreateInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfVkAttachmentDescription2Objects = 0;
        VkAttachmentDescription2 *vkAttachmentDescription2 = nullptr;
        if (jVkAttachmentDescription2CollectionObject != nullptr)
        {
            jvulkan::getVkAttachmentDescription2Collection(
                    env,
                    jVkAttachmentDescription2CollectionObject,
                    &vkAttachmentDescription2,
                    &numberOfVkAttachmentDescription2Objects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::getVkAttachmentDescription2Collection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfo2Class, "getSubpasses", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getSubpasses.");
            return;
        }

        jobject jVkSubpassDescription2CollectionObject = env->CallObjectMethod(jVkRenderPassCreateInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfVkSubpassDescription2Objects = 0;
        VkSubpassDescription2 *vkSubpassDescription2 = nullptr;
        if (jVkSubpassDescription2CollectionObject != nullptr)
        {
            jvulkan::getVkSubpassDescription2Collection(
                    env,
                    jVkSubpassDescription2CollectionObject,
                    &vkSubpassDescription2,
                    &numberOfVkSubpassDescription2Objects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::getVkSubpassDescription2Collection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfo2Class, "getDependencies", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getDependencies.");
            return;
        }

        jobject jVkSubpassDependency2KHRCollectionObject = env->CallObjectMethod(jVkRenderPassCreateInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfVkSubpassDependency2KHRObjects = 0;
        VkSubpassDependency2KHR *vkSubpassDependency2KHR = nullptr;
        if (jVkSubpassDependency2KHRCollectionObject != nullptr)
        {
            jvulkan::getVkSubpassDependency2Collection(
                    env,
                    jVkSubpassDependency2KHRCollectionObject,
                    &vkSubpassDependency2KHR,
                    &numberOfVkSubpassDependency2KHRObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::getVkSubpassDependency2Collection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfo2Class, "getCorrelatedViewMasks", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getCorrelatedViewMasks.");
            return;
        }

        jobject jCorrelatedViewMasksCollectionObject = env->CallObjectMethod(jVkRenderPassCreateInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfCorrelatedViewMasks = 0;
        uint32_t *correlatedViewMasks = nullptr;
        if (jCorrelatedViewMasksCollectionObject != nullptr)
        {
            jvulkan::getBitSetCollection(
                    env,
                    jCorrelatedViewMasksCollectionObject,
                    &correlatedViewMasks,
                    &numberOfCorrelatedViewMasks,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::getBitSetCollection.");
                return;
            }
        }

        vkRenderPassCreateInfo2->sType = sTypeValue;
        vkRenderPassCreateInfo2->pNext = (void *)pNext;
        vkRenderPassCreateInfo2->flags = flags;

        vkRenderPassCreateInfo2->attachmentCount = numberOfVkAttachmentDescription2Objects;
        vkRenderPassCreateInfo2->pAttachments = vkAttachmentDescription2;
        vkRenderPassCreateInfo2->subpassCount = numberOfVkSubpassDescription2Objects;
        vkRenderPassCreateInfo2->pSubpasses = vkSubpassDescription2;
        vkRenderPassCreateInfo2->dependencyCount = numberOfVkSubpassDependency2KHRObjects;
        vkRenderPassCreateInfo2->pDependencies = vkSubpassDependency2KHR;
        vkRenderPassCreateInfo2->correlatedViewMaskCount = numberOfCorrelatedViewMasks;
        vkRenderPassCreateInfo2->pCorrelatedViewMasks = correlatedViewMasks;
    }
}
