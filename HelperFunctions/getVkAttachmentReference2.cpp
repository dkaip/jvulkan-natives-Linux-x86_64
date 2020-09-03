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

/*
 * getVkAttachmentReference2.cpp
 *
 *  Created on: Jul 22, 2020
 *      Author: Douglas Kaip
 */


#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAttachmentReference2(
            JNIEnv *env,
            const jobject jVkAttachmentReference2Object,
            VkAttachmentReference2 *vkAttachmentReference2,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAttachmentReference2Class = env->GetObjectClass(jVkAttachmentReference2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkAttachmentReference2Object.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSType(env, jVkAttachmentReference2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkAttachmentReference2Object);
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
        jmethodID methodId = env->GetMethodID(vkAttachmentReference2Class, "getAttachment", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getAttachment.");
            return;
        }

        jint jAttachment = env->CallIntMethod(jVkAttachmentReference2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        uint32_t attachment = (uint32_t)jAttachment;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentReference2Class, "getLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getLayout.");
            return;
        }

        jobject jVkImageLayoutTypeObject = env->CallObjectMethod(jVkAttachmentReference2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkImageLayoutTypeObjectEnumClass = env->GetObjectClass(jVkImageLayoutTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkImageLayoutTypeObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkImageLayout layoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

         ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentReference2Class, "getAspectMask", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageAspectFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getAspectMask.");
            return;
        }

        jobject jVkImageAspectFlagBitsTypeObject = env->CallObjectMethod(jVkAttachmentReference2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkImageAspectFlagBitsTypeObjectEnumClass = env->GetObjectClass(jVkImageAspectFlagBitsTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkImageAspectFlagBitsTypeObject.");
            return;
        }


        valueOfMethodId = env->GetMethodID(vkImageAspectFlagBitsTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkImageAspectFlagBits aspectMaskTypeEnumValue = (VkImageAspectFlagBits)env->CallIntMethod(jVkImageAspectFlagBitsTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        vkAttachmentReference2->sType = (VkStructureType)sTypeValue;
        vkAttachmentReference2->pNext = (void *)pNext;
        vkAttachmentReference2->attachment = attachment;
        vkAttachmentReference2->layout = layoutEnumValue;
        vkAttachmentReference2->aspectMask = aspectMaskTypeEnumValue;
    }
}

