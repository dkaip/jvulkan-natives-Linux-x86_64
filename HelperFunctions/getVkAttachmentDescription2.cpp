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
 * getVkAttachmentDescription2.cpp
 *
 *  Created on: Jul 22, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAttachmentDescription2(
            JNIEnv *env,
            const jobject jVkAttachmentDescription2Object,
            VkAttachmentDescription2KHR *vkAttachmentDescription2,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAttachmentDescription2Class = env->GetObjectClass(jVkAttachmentDescription2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkAttachmentDescription2Object.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkAttachmentDescription2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkAttachmentDescription2Object);
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
        jmethodID methodId = env->GetMethodID(vkAttachmentDescription2Class, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkAttachmentDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkAttachmentDescriptionFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentDescriptionFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2Class, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFormat.");
            return;
        }

        jobject jVkFormatTypeObject = env->CallObjectMethod(jVkAttachmentDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkFormatTypeObjectEnumClass = env->GetObjectClass(jVkFormatTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkFormatTypeObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkFormatTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkFormat formatTypeEnumValue = (VkFormat)env->CallIntMethod(jVkFormatTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2Class, "getSamples", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getSamples.");
            return;
        }

        jobject jVkSampleCountFlagBitsTypeObject = env->CallObjectMethod(jVkAttachmentDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkSampleCountFlagBitsTypeObjectEnumClass = env->GetObjectClass(jVkSampleCountFlagBitsTypeObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkSampleCountFlagBits samplesTypeEnumValue = (VkSampleCountFlagBits)env->CallIntMethod(jVkSampleCountFlagBitsTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2Class, "getLoadOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentLoadOp;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getLoadOp.");
            return;
        }

        jobject jVkAttachmentLoadOpTypeObject = env->CallObjectMethod(jVkAttachmentDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkAttachmentLoadOpTypeObjectEnumClass = env->GetObjectClass(jVkAttachmentLoadOpTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkAttachmentLoadOpTypeObject.");
            return;
        }

        valueOfMethodId = env->GetMethodID(vkAttachmentLoadOpTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkAttachmentLoadOp loadOpEnumValue = (VkAttachmentLoadOp)env->CallIntMethod(jVkAttachmentLoadOpTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2Class, "getStoreOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentStoreOp;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getStoreOp.");
            return;
        }

        jobject jVkAttachmentStoreOpTypeObject = env->CallObjectMethod(jVkAttachmentDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkAttachmentStoreOpTypeObjectEnumClass = env->GetObjectClass(jVkAttachmentStoreOpTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkAttachmentStoreOpTypeObject.");
            return;
        }


        valueOfMethodId = env->GetMethodID(vkAttachmentStoreOpTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkAttachmentStoreOp storeOpEnumValue = (VkAttachmentStoreOp)env->CallIntMethod(jVkAttachmentStoreOpTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2Class, "getStencilLoadOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentLoadOp;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getStencilLoadOp.");
            return;
        }

        jVkAttachmentLoadOpTypeObject = env->CallObjectMethod(jVkAttachmentDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        vkAttachmentLoadOpTypeObjectEnumClass = env->GetObjectClass(jVkAttachmentLoadOpTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkAttachmentLoadOpTypeObject.");
            return;
        }

        valueOfMethodId = env->GetMethodID(vkAttachmentLoadOpTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkAttachmentLoadOp stencilLoadOpEnumValue = (VkAttachmentLoadOp)env->CallIntMethod(jVkAttachmentLoadOpTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2Class, "getStencilStoreOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkAttachmentStoreOp;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getStencilStoreOp.");
            return;
        }

        jVkAttachmentStoreOpTypeObject = env->CallObjectMethod(jVkAttachmentDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        vkAttachmentStoreOpTypeObjectEnumClass = env->GetObjectClass(jVkAttachmentStoreOpTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkAttachmentStoreOpTypeObject.");
            return;
        }

        valueOfMethodId = env->GetMethodID(vkAttachmentStoreOpTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkAttachmentStoreOp stencilStoreOpEnumValue = (VkAttachmentStoreOp)env->CallIntMethod(jVkAttachmentStoreOpTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2Class, "getInitialLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getInitialLayout.");
            return;
        }

        jobject jVkImageLayoutTypeObject = env->CallObjectMethod(jVkAttachmentDescription2Object, methodId);
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

        valueOfMethodId = env->GetMethodID(vkImageLayoutTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkImageLayout initialLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentDescription2Class, "getFinalLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFinalLayout.");
            return;
        }

        jVkImageLayoutTypeObject = env->CallObjectMethod(jVkAttachmentDescription2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        vkImageLayoutTypeObjectEnumClass = env->GetObjectClass(jVkImageLayoutTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkImageLayoutTypeObject.");
            return;
        }

        valueOfMethodId = env->GetMethodID(vkImageLayoutTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkImageLayout finalLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        vkAttachmentDescription2->sType 		= sTypeValue;
        vkAttachmentDescription2->pNext 		= (void *)pNext;
        vkAttachmentDescription2->flags 		= flags;
        vkAttachmentDescription2->format 		= formatTypeEnumValue;
        vkAttachmentDescription2->samples 		= samplesTypeEnumValue;
        vkAttachmentDescription2->loadOp 		= loadOpEnumValue;
        vkAttachmentDescription2->storeOp 		= storeOpEnumValue;
        vkAttachmentDescription2->stencilLoadOp = stencilLoadOpEnumValue;
        vkAttachmentDescription2->stencilStoreOp = stencilStoreOpEnumValue;
        vkAttachmentDescription2->initialLayout = initialLayoutEnumValue;
        vkAttachmentDescription2->finalLayout 	= finalLayoutEnumValue;
    }
}
