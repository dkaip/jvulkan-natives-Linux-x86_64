#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkRenderPassCreateInfo2KHR(
            JNIEnv *env,
            jobject jVkRenderPassCreateInfo2KHRObject,
            VkRenderPassCreateInfo2KHR *vkRenderPassCreateInfo2KHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkRenderPassCreateInfo2KHRClass = env->GetObjectClass(jVkRenderPassCreateInfo2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkRenderPassCreateInfo2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkRenderPassCreateInfo2KHRClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkRenderPassCreateInfo2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfo2KHRClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkRenderPassCreateInfo2KHRObject, methodId);
        VkRenderPassCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkRenderPassCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfo2KHRClass, "getAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAttachmentDescription2KHRCollectionObject = env->CallObjectMethod(jVkRenderPassCreateInfo2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkAttachmentDescription2KHRObjects = 0;
        VkAttachmentDescription2KHR *vkAttachmentDescription2KHR = nullptr;
        if (jVkAttachmentDescription2KHRCollectionObject != nullptr)
        {
            hwjvi::getVkAttachmentDescription2KHRCollection(
                    env,
                    jVkAttachmentDescription2KHRCollectionObject,
                    &vkAttachmentDescription2KHR,
                    &numberOfVkAttachmentDescription2KHRObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfo2KHRClass, "getSubpasses", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSubpassDescription2KHRCollectionObject = env->CallObjectMethod(jVkRenderPassCreateInfo2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkSubpassDescription2KHRObjects = 0;
        VkSubpassDescription2KHR *vkSubpassDescription2KHR = nullptr;
        if (jVkSubpassDescription2KHRCollectionObject != nullptr)
        {
            hwjvi::getVkSubpassDescription2KHRCollection(
                    env,
                    jVkSubpassDescription2KHRCollectionObject,
                    &vkSubpassDescription2KHR,
                    &numberOfVkSubpassDescription2KHRObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfo2KHRClass, "getDependencies", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSubpassDependency2KHRCollectionObject = env->CallObjectMethod(jVkRenderPassCreateInfo2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkSubpassDependency2KHRObjects = 0;
        VkSubpassDependency2KHR *vkSubpassDependency2KHR = nullptr;
        if (jVkSubpassDependency2KHRCollectionObject != nullptr)
        {
            hwjvi::getVkSubpassDependency2KHRCollection(
                    env,
                    jVkSubpassDependency2KHRCollectionObject,
                    &vkSubpassDependency2KHR,
                    &numberOfVkSubpassDependency2KHRObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfo2KHRClass, "getCorrelatedViewMasks", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jCorrelatedViewMasksCollectionObject = env->CallObjectMethod(jVkRenderPassCreateInfo2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfCorrelatedViewMasks = 0;
        uint32_t *correlatedViewMasks = nullptr;
        if (jCorrelatedViewMasksCollectionObject != nullptr)
        {
            hwjvi::getBitSetCollection(
                    env,
                    jCorrelatedViewMasksCollectionObject,
                    &correlatedViewMasks,
                    &numberOfCorrelatedViewMasks,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkRenderPassCreateInfo2KHR->sType = (VkStructureType)sTypeValue;
        vkRenderPassCreateInfo2KHR->pNext = (void *)pNext;
        vkRenderPassCreateInfo2KHR->flags = flags;

        vkRenderPassCreateInfo2KHR->attachmentCount = numberOfVkAttachmentDescription2KHRObjects;
        vkRenderPassCreateInfo2KHR->pAttachments = vkAttachmentDescription2KHR;
        vkRenderPassCreateInfo2KHR->subpassCount = numberOfVkSubpassDescription2KHRObjects;
        vkRenderPassCreateInfo2KHR->pSubpasses = vkSubpassDescription2KHR;
        vkRenderPassCreateInfo2KHR->dependencyCount = numberOfVkSubpassDependency2KHRObjects;
        vkRenderPassCreateInfo2KHR->pDependencies = vkSubpassDependency2KHR;
        vkRenderPassCreateInfo2KHR->correlatedViewMaskCount = numberOfCorrelatedViewMasks;
        vkRenderPassCreateInfo2KHR->pCorrelatedViewMasks = correlatedViewMasks;
    }
}
