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
#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAttachmentDescription2KHR(
            JNIEnv *env,
            const jobject jVkAttachmentDescription2KHRObject,
            VkAttachmentDescription2KHR *vkAttachmentDescription2KHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAttachmentDescription2KHRClass = env->GetObjectClass(jVkAttachmentDescription2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkAttachmentDescription2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNext(env, jVkAttachmentDescription2KHRObject);
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
        jmethodID methodId = env->GetMethodID(vkAttachmentDescription2KHRClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkAttachmentDescription2KHRObject, methodId);
        VkAttachmentDescriptionFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentDescriptionFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2KHRClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFormatTypeObject = env->CallObjectMethod(jVkAttachmentDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFormatTypeObjectEnumClass = env->GetObjectClass(jVkFormatTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkFormatTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFormat formatTypeEnumValue = (VkFormat)env->CallIntMethod(jVkFormatTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2KHRClass, "getSamples", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSampleCountFlagBitsTypeObject = env->CallObjectMethod(jVkAttachmentDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkSampleCountFlagBitsTypeObjectEnumClass = env->GetObjectClass(jVkSampleCountFlagBitsTypeObject);

        valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSampleCountFlagBits samplesTypeEnumValue = (VkSampleCountFlagBits)env->CallIntMethod(jVkSampleCountFlagBitsTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2KHRClass, "getLoadOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentLoadOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAttachmentLoadOpTypeObject = env->CallObjectMethod(jVkAttachmentDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkAttachmentLoadOpTypeObjectEnumClass = env->GetObjectClass(jVkAttachmentLoadOpTypeObject);

        valueOfMethodId = env->GetMethodID(vkAttachmentLoadOpTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkAttachmentLoadOp loadOpEnumValue = (VkAttachmentLoadOp)env->CallIntMethod(jVkAttachmentLoadOpTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2KHRClass, "getStoreOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentStoreOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkAttachmentStoreOpTypeObject = env->CallObjectMethod(jVkAttachmentDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkAttachmentStoreOpTypeObjectEnumClass = env->GetObjectClass(jVkAttachmentStoreOpTypeObject);

        valueOfMethodId = env->GetMethodID(vkAttachmentStoreOpTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkAttachmentStoreOp storeOpEnumValue = (VkAttachmentStoreOp)env->CallIntMethod(jVkAttachmentStoreOpTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2KHRClass, "getStencilLoadOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentLoadOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkAttachmentLoadOpTypeObject = env->CallObjectMethod(jVkAttachmentDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkAttachmentLoadOpTypeObjectEnumClass = env->GetObjectClass(jVkAttachmentLoadOpTypeObject);

        valueOfMethodId = env->GetMethodID(vkAttachmentLoadOpTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkAttachmentLoadOp stencilLoadOpEnumValue = (VkAttachmentLoadOp)env->CallIntMethod(jVkAttachmentLoadOpTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2KHRClass, "getStencilStoreOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentStoreOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkAttachmentStoreOpTypeObject = env->CallObjectMethod(jVkAttachmentDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkAttachmentStoreOpTypeObjectEnumClass = env->GetObjectClass(jVkAttachmentStoreOpTypeObject);

        valueOfMethodId = env->GetMethodID(vkAttachmentStoreOpTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkAttachmentStoreOp stencilStoreOpEnumValue = (VkAttachmentStoreOp)env->CallIntMethod(jVkAttachmentStoreOpTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2KHRClass, "getInitialLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageLayoutTypeObject = env->CallObjectMethod(jVkAttachmentDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageLayoutTypeObjectEnumClass = env->GetObjectClass(jVkImageLayoutTypeObject);

        valueOfMethodId = env->GetMethodID(vkImageLayoutTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageLayout initialLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2KHRClass, "getFinalLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkImageLayoutTypeObject = env->CallObjectMethod(jVkAttachmentDescription2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkImageLayoutTypeObjectEnumClass = env->GetObjectClass(jVkImageLayoutTypeObject);

        valueOfMethodId = env->GetMethodID(vkImageLayoutTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageLayout finalLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkAttachmentDescription2KHR->sType = (VkStructureType)sTypeValue;
        vkAttachmentDescription2KHR->pNext = (void *)pNext;
        vkAttachmentDescription2KHR->flags = flags;
        vkAttachmentDescription2KHR->format = formatTypeEnumValue;
        vkAttachmentDescription2KHR->samples = samplesTypeEnumValue;
        vkAttachmentDescription2KHR->loadOp = loadOpEnumValue;
        vkAttachmentDescription2KHR->storeOp = storeOpEnumValue;
        vkAttachmentDescription2KHR->stencilLoadOp = stencilLoadOpEnumValue;
        vkAttachmentDescription2KHR->stencilStoreOp = stencilStoreOpEnumValue;
        vkAttachmentDescription2KHR->initialLayout = initialLayoutEnumValue;
        vkAttachmentDescription2KHR->finalLayout = finalLayoutEnumValue;
    }

    void getVkAttachmentDescription2KHRCollection(
            JNIEnv *env,
            const jobject jVkAttachmentDescription2KHRCollectionObject,
            VkAttachmentDescription2KHR **vkAttachmentDescription2KHRs,
            int *numberOfVkAttachmentDescription2KHRs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAttachmentDescription2KHRCollectionClass = env->GetObjectClass(jVkAttachmentDescription2KHRCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkAttachmentDescription2KHRCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkAttachmentDescription2KHRCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkAttachmentDescription2KHRs = numberOfElements;
        *vkAttachmentDescription2KHRs = (VkAttachmentDescription2KHR *)calloc(numberOfElements, sizeof(VkAttachmentDescription2KHR));
        memoryToFree->push_back(*vkAttachmentDescription2KHRs);

        jmethodID iteratorMethodId = env->GetMethodID(vkAttachmentDescription2KHRCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkAttachmentDescription2KHRCollectionObject, iteratorMethodId);
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

            jobject jVkAttachmentDescription2KHRObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkAttachmentDescription2KHR(
                    env,
                    jVkAttachmentDescription2KHRObject,
                    &((*vkAttachmentDescription2KHRs)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
