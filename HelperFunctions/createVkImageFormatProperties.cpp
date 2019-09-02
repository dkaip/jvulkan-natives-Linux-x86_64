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
 * createVkImageFormatProperties.cpp
 *
 *  Created on: Jun 3, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	jobject createVkImageFormatProperties(JNIEnv *env, const VkImageFormatProperties *vkImageFormatProperties)
	{
		// Locate the VkImageFormatProperties class
		jclass theClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkImageFormatProperties");

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(theClass, "<init>", "()V");

		// Create the Java VkImageFormatProperties object
		jobject jVkImageFormatPropertiesObject =
				env->NewObject(theClass, methodId);

        ///////////////////////////////////////////////////////////////////////////
		populateVkImageFormatProperties(
				env,
				jVkImageFormatPropertiesObject,
				vkImageFormatProperties,
				nullptr);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Error calling populateVkImageFormatProperties");
	    	return nullptr;
	    }

		return jVkImageFormatPropertiesObject;
	}
}
