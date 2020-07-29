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
 * getVkImageFormatProperties.cpp
 *
 *  Created on: May 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImageFormatProperties(
            JNIEnv *env,
            const jobject jVkImageFormatPropertiesObject,
			VkImageFormatProperties *vkImageFormatProperties,
            std::vector<void *> *memoryToFree)
    {
		if (jVkImageFormatPropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkImageFormatPropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkImageFormatPropertiesObject == nullptr");
			return;
		}

		if (vkImageFormatProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkImageFormatProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkImageFormatProperties == nullptr");
			return;
		}

        jclass theClass = env->GetObjectClass(jVkImageFormatPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageFormatPropertiesObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getMaxExtent", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMaxExtent.");
            return;
        }

        jobject jVkExtent3DObject = env->CallObjectMethod(jVkImageFormatPropertiesObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkExtent3D maxExtent = {};
		getVkExtent3D(
				env,
				jVkExtent3DObject,
				&maxExtent,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling getVkExtent3D.");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMaxMipLevels", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMaxMipLevels.");
            return;
        }

        jint maxMipLevels = env->CallIntMethod(jVkImageFormatPropertiesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMaxArrayLayers", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMaxArrayLayers.");
            return;
        }

        jint maxArrayLayers = env->CallIntMethod(jVkImageFormatPropertiesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSampleCounts", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getSampleCounts.");
            return;
        }

        jobject surfaceCountersObject = env->CallObjectMethod(jVkImageFormatPropertiesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkSampleCountFlags vkSampleCountFlags = (VkSampleCountFlags)getEnumSetValue(
                env,
				surfaceCountersObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMaxResourceSize", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMaxResourceSize.");
            return;
        }

        jlong maxResourceSize = env->CallLongMethod(jVkImageFormatPropertiesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }


        vkImageFormatProperties->maxExtent.width = maxExtent.width;
        vkImageFormatProperties->maxExtent.height = maxExtent.height;
        vkImageFormatProperties->maxExtent.depth = maxExtent.depth;
        vkImageFormatProperties->maxMipLevels = maxMipLevels;
        vkImageFormatProperties->maxArrayLayers = maxArrayLayers;
        vkImageFormatProperties->sampleCounts = vkSampleCountFlags;
        vkImageFormatProperties->maxResourceSize = maxResourceSize;
    }
}
