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
 * createVkQueueFamilyProperties.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkQueueFamilyProperties(JNIEnv *env, const VkQueueFamilyProperties *vkQueueFamilyProperties)
	{
		if (vkQueueFamilyProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkQueueFamilyProperties == nullptr");
			return nullptr;
		}

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkQueueFamilyProperties",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor.");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setQueueFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setQueueFlags");
            return nullptr;
        }

        jobject jqueueFlags = createVkQueueFlagsKHRAsEnumSet(env, vkQueueFamilyProperties->queueFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkQueueFlagsKHRAsEnumSet");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jqueueFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setQueueCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setQueueCount");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkQueueFamilyProperties->queueCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setTimestampValidBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTimestampValidBits");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkQueueFamilyProperties->timestampValidBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject vkExtent3D = createVkExtent3D(env, &vkQueueFamilyProperties->minImageTransferGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent3D.");
            return nullptr;
        }

        methodId = env->GetMethodID(theClass, "setMinImageTransferGranularity", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinImageTransferGranularity");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkExtent3D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		return theObject;
	}
}
