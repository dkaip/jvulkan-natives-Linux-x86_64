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
 * createVkPhysicalDeviceSparseImageFormatInfo2.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkPhysicalDeviceSparseImageFormatInfo2(
			JNIEnv *env,
			VkPhysicalDeviceSparseImageFormatInfo2 const *vkPhysicalDeviceSparseImageFormatInfo2)
	{
		if (vkPhysicalDeviceSparseImageFormatInfo2 == nullptr)
		{
			LOGERROR(env, "%s", "vkPhysicalDeviceSparseImageFormatInfo2 == nullptr");
			return nullptr;
		}

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceSparseImageFormatInfo2",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkFormat = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat",
				vkPhysicalDeviceSparseImageFormatInfo2->format);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		jmethodID methodId = env->GetMethodID(theClass, "setFormat", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFormat");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkFormat);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkImageType = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageType",
				vkPhysicalDeviceSparseImageFormatInfo2->type);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setType", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageType;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setType");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkImageType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkSampleCountFlagBits = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits",
				vkPhysicalDeviceSparseImageFormatInfo2->samples);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setSamples", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSamples");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkSampleCountFlagBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jUsage = createVkImageUsageFlagsAsEnumSet(
    			env,
				vkPhysicalDeviceSparseImageFormatInfo2->usage);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setUsage", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setUsage");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jUsage);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkImageTiling = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageTiling",
				vkPhysicalDeviceSparseImageFormatInfo2->tiling);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setTiling", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageTiling;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTiling");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkImageTiling);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
