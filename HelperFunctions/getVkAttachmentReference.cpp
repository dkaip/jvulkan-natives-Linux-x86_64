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
/*
 * getVkAttachmentReference.cpp
 *
 *  Created on: May 20, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAttachmentReference(
            JNIEnv *env,
            const jobject jVkAttachmentReferenceObject,
			VkAttachmentReference *vkAttachmentReference,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkAttachmentReferenceObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkAttachmentReferenceObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getAttachment", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAttachment");
            return;
        }

        jint jAttachment = env->CallIntMethod(jVkAttachmentReferenceObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        uint32_t attachment = (uint32_t)jAttachment;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getLayout");
            return;
        }

        jobject jVkImageLayoutTypeObject = env->CallObjectMethod(jVkAttachmentReferenceObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
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
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        vkAttachmentReference->attachment = attachment;
        vkAttachmentReference->layout = layoutEnumValue;
    }
}
