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
 * getVkImageSubresource.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkImageSubresource(
        JNIEnv *env,
        const jobject jVkImageSubresourceObject,
		VkImageSubresource *vkImageSubresource,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImageSubresourceObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkImageSubresourceObject");
            return;
        }

		////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getAspectMask", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getAspectMask");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkImageSubresourceObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkImageAspectFlags aspectMask = (VkImageAspectFlags)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageAspectFlagBits");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getMipLevel", "()I");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getMipLevel");
			return;
		}

		jint mipLevel = env->CallIntMethod(jVkImageSubresourceObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getArrayLayer", "()I");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getArrayLayer");
			return;
		}

		jint arrayLayer = env->CallIntMethod(jVkImageSubresourceObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
			return;
		}


		vkImageSubresource->aspectMask	= aspectMask;
		vkImageSubresource->mipLevel	= mipLevel;
		vkImageSubresource->arrayLayer	= arrayLayer;
    }
}
