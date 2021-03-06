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
 * createVkExtent3D.cpp
 *
 *  Created on: Jun 3, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	jobject createVkExtent3D(JNIEnv *env, const VkExtent3D *vkExtent3D)
	{
		jclass vkExtent3DClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkExtent3DClass, "<init>", "(III)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> (III)V");
            return nullptr;
        }

		jobject jVkExtent3DObject =
				env->NewObject(vkExtent3DClass, methodId, vkExtent3D->width, vkExtent3D->height, vkExtent3D->depth);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(III)V(the constructor)");
            return nullptr;
        }

		return jVkExtent3DObject;
	}
}
