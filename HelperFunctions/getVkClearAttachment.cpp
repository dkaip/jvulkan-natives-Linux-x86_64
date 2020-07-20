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
 * getVkClearAttachment.cpp
 *
 *  Created on: Oct 22, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkClearAttachment(
            JNIEnv *env,
            const jobject jVkClearAttachmentObject,
			VkClearAttachment *vkClearAttachment,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkClearAttachmentObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not class for jVkClearAttachmentObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getAspectMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAspectMask");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkClearAttachmentObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }
        VkImageAspectFlags aspectMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageAspectFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getColorAttachment", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method ID for getColorAttachment");
            return;
        }

        jint colorAttachment = env->CallIntMethod(jVkClearAttachmentObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getClearValue", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkClearValue;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method ID for getClearValue");
            return;
        }

        jobject clearValueObject = env->CallObjectMethod(jVkClearAttachmentObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        getVkClearValue(
                env,
                clearValueObject,
				&vkClearAttachment->clearValue,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkClearValue");
            return;
        }


        vkClearAttachment->aspectMask = aspectMask;
		vkClearAttachment->colorAttachment = colorAttachment;
    }
}
