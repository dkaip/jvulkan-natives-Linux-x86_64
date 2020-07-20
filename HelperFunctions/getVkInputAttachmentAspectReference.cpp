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
 * getVkInputAttachmentAspectReference.cpp
 *
 *  Created on: May 20, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkInputAttachmentAspectReference(
            JNIEnv *env,
            const jobject jVkInputAttachmentAspectReferenceObject,
			VkInputAttachmentAspectReference *vkInputAttachmentAspectReference,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkInputAttachmentAspectReferenceObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkInputAttachmentAspectReferenceObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getSubpass", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSubpass");
            return;
        }

        jint subpass = env->CallIntMethod(jVkInputAttachmentAspectReferenceObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getInputAttachmentIndex", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getInputAttachmentIndex");
            return;
        }

        jint inputAttachmentIndex = env->CallIntMethod(jVkInputAttachmentAspectReferenceObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getAspectMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAspectMask");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkInputAttachmentAspectReferenceObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkImageAspectFlags vkImageAspectFlags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageAspectFlags");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
            return;
        }


        vkInputAttachmentAspectReference->subpass = subpass;
		vkInputAttachmentAspectReference->inputAttachmentIndex = inputAttachmentIndex;
		vkInputAttachmentAspectReference->aspectMask = vkImageAspectFlags;
    }
}
