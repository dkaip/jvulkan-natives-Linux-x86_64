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
 * getVkImageBlit.cpp
 *
 *  Created on: Oct 15, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImageBlit(
            JNIEnv *env,
            const jobject jVkImageBlitObject,
			VkImageBlit *vkImageBlit,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImageBlitObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageBlitObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getSrcSubresource", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageSubresourceLayers;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id valueOf for getSrcSubresource");
			return;
		}

		jobject jVkImageSubresourceLayers = env->CallObjectMethod(jVkImageBlitObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkImageSubresourceLayers    srcSubresource = {};
        getVkImageSubresourceLayers(
                env,
                jVkImageSubresourceLayers,
                &srcSubresource,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageSubresourceLayers");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSrcOffsets", "()[Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset3D;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id valueOf for getSrcOffsets");
			return;
		}

		jobjectArray jVkOffset3DArray = (jobjectArray)env->CallObjectMethod(jVkImageBlitObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkOffset3D srcOffsets[2];

        jobject jVkOffset3D = (jobject) env->GetObjectArrayElement(jVkOffset3DArray, 0);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetObjectArrayElement");
            return;
        }

        getVkOffset3D(
                env,
				jVkOffset3D,
                &srcOffsets[0],
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkOffset3D");
            return;
        }

        jVkOffset3D = (jobject) env->GetObjectArrayElement(jVkOffset3DArray, 1);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetObjectArrayElement");
            return;
        }

        getVkOffset3D(
                env,
				jVkOffset3D,
                &srcOffsets[1],
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkOffset3D");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDstSubresource", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageSubresourceLayers;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id valueOf for getDstSubresource");
			return;
		}

		jVkImageSubresourceLayers = env->CallObjectMethod(jVkImageBlitObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkImageSubresourceLayers    dstSubresource = {};
        getVkImageSubresourceLayers(
                env,
                jVkImageSubresourceLayers,
                &dstSubresource,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageSubresourceLayers");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDstOffsets", "()[Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset3D;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find method id valueOf for getDstOffsets");
			return;
		}

		jVkOffset3DArray = (jobjectArray)env->CallObjectMethod(jVkImageBlitObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkOffset3D dstOffsets[2];

        jVkOffset3D = (jobject) env->GetObjectArrayElement(jVkOffset3DArray, 0);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetObjectArrayElement");
            return;
        }

        getVkOffset3D(
                env,
				jVkOffset3D,
                &dstOffsets[0],
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkOffset3D");
            return;
        }

        jVkOffset3D = (jobject) env->GetObjectArrayElement(jVkOffset3DArray, 1);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetObjectArrayElement");
            return;
        }

        getVkOffset3D(
                env,
				jVkOffset3D,
                &dstOffsets[1],
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkOffset3D");
            return;
        }

        memcpy(&vkImageBlit->srcSubresource, &srcSubresource, sizeof(vkImageBlit->srcSubresource));
        memcpy(&vkImageBlit->srcOffsets, srcOffsets, sizeof(vkImageBlit->srcOffsets));
        memcpy(&vkImageBlit->dstSubresource, &dstSubresource, sizeof(vkImageBlit->dstSubresource));
        memcpy(&vkImageBlit->dstOffsets, dstOffsets, sizeof(vkImageBlit->dstOffsets));
    }
}
