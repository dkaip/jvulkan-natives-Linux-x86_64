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
 * getVkImageCopy.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImageCopy(
            JNIEnv *env,
            const jobject jVkImageCopyObject,
			VkImageCopy *vkImageCopy,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImageCopyObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageCopyObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getSrcSubresource", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkImageSubresourceLayers;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id valueOf for getSrcSubresource");
			return;
		}

		jobject jSrcVkImageSubresourceLayers = env->CallObjectMethod(jVkImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        getVkImageSubresourceLayers(
                env,
				jSrcVkImageSubresourceLayers,
                &vkImageCopy->srcSubresource,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageSubresourceLayers");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSrcOffset", "()[Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkOffset3D;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id valueOf for getSrcOffset");
			return;
		}

		jobject jSrcVkOffset3D = env->CallObjectMethod(jVkImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        getVkOffset3D(
                env,
				jSrcVkOffset3D,
                &vkImageCopy->srcOffset,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkOffset3D");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDstSubresource", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkImageSubresourceLayers;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id valueOf for getDstSubresource");
			return;
		}

		jobject jDstVkImageSubresourceLayers = env->CallObjectMethod(jVkImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        getVkImageSubresourceLayers(
                env,
				jDstVkImageSubresourceLayers,
                &vkImageCopy->dstSubresource,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageSubresourceLayers");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDstOffset", "()[Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkOffset3D;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id valueOf for getDstOffset");
			return;
		}

		jobject jDstVkOffset3D = env->CallObjectMethod(jVkImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        getVkOffset3D(
                env,
				jDstVkOffset3D,
                &vkImageCopy->dstOffset,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkOffset3D");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getExtent", "()[Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent3D;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id valueOf for getExtent");
			return;
		}

		jobject jExtent3D = env->CallObjectMethod(jVkImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        getVkExtent3D(
                env,
				jExtent3D,
                &vkImageCopy->extent,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkExtent3D");
            return;
        }

    }
}
