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
 * createVkSparseImageFormatProperties.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkSparseImageFormatProperties(
			JNIEnv *env,
			VkSparseImageFormatProperties const *vkSparseImageFormatProperties)
	{
		if (vkSparseImageFormatProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkSparseImageFormatProperties == nullptr");
			return nullptr;
		}

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkSparseImageFormatProperties",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject vkImageAspectFlagsEnumSet = createVkImageAspectFlagsAsEnumSet(
        		env,
				vkSparseImageFormatProperties->aspectMask);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkImageAspectFlagsAsEnumSet");
            return nullptr;
        }

		jmethodID methodId = env->GetMethodID(theClass, "setSupportedAlpha", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedAlpha");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkImageAspectFlagsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jVkExtent3D = createVkExtent3D(
        		env,
				&vkSparseImageFormatProperties->imageGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent3D");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setImageGranularity", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageGranularity");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkExtent3D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject vkSparseImageFormatFlagsEnumSet = createVkSparseImageFormatFlagsAsEnumSet(
        		env,
				vkSparseImageFormatProperties->flags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSparseImageFormatFlagsAsEnumSet");
            return nullptr;
        }

		methodId = env->GetMethodID(theClass, "setFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFlags");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSparseImageFormatFlagsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
