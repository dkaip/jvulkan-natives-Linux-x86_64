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
    void getVkAttachmentReference2KHR(
            JNIEnv *env,
            const jobject jVkAttachmentReference2KHRObject,
            VkAttachmentReference2KHR *vkAttachmentReference2KHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAttachmentReference2KHRClass = env->GetObjectClass(jVkAttachmentReference2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkAttachmentReference2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkAttachmentReference2KHRObject);
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
        jmethodID methodId = env->GetMethodID(vkAttachmentReference2KHRClass, "getAttachment", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jAttachment = env->CallIntMethod(jVkAttachmentReference2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        uint32_t attachment = (uint32_t)jAttachment;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentReference2KHRClass, "getLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageLayoutTypeObject = env->CallObjectMethod(jVkAttachmentReference2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageLayoutTypeObjectEnumClass = env->GetObjectClass(jVkImageLayoutTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageLayout layoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

         ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentReference2KHRClass, "getAspectMask", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageAspectFlagBits;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageAspectFlagBitsTypeObject = env->CallObjectMethod(jVkAttachmentReference2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageAspectFlagBitsTypeObjectEnumClass = env->GetObjectClass(jVkImageAspectFlagBitsTypeObject);

        valueOfMethodId = env->GetMethodID(vkImageAspectFlagBitsTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageAspectFlagBits aspectMaskTypeEnumValue = (VkImageAspectFlagBits)env->CallIntMethod(jVkImageAspectFlagBitsTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkAttachmentReference2KHR->sType = (VkStructureType)sTypeValue;
        vkAttachmentReference2KHR->pNext = (void *)pNext;
        vkAttachmentReference2KHR->attachment = attachment;
        vkAttachmentReference2KHR->layout = layoutEnumValue;
        vkAttachmentReference2KHR->aspectMask = aspectMaskTypeEnumValue;
    }

    void getVkAttachmentReference2KHRCollection(
            JNIEnv *env,
            const jobject jVkAttachmentReference2KHRCollectionObject,
            VkAttachmentReference2KHR **vkAttachmentReference2KHRs,
            int *numberOfVkAttachmentReference2KHRs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAttachmentReference2KHRCollectionClass = env->GetObjectClass(jVkAttachmentReference2KHRCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkAttachmentReference2KHRCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkAttachmentReference2KHRCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkAttachmentReference2KHRs = numberOfElements;
        *vkAttachmentReference2KHRs = (VkAttachmentReference2KHR *)calloc(numberOfElements, sizeof(VkAttachmentReference2KHR));
        memoryToFree->push_back(*vkAttachmentReference2KHRs);

        jmethodID iteratorMethodId = env->GetMethodID(vkAttachmentReference2KHRCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkAttachmentReference2KHRCollectionObject, iteratorMethodId);
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

            jobject jVkAttachmentReference2KHRObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkAttachmentReference2KHR(
                    env,
                    jVkAttachmentReference2KHRObject,
                    &((*vkAttachmentReference2KHRs)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
