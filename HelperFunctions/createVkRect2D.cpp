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
 * createVkRect2D.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	jobject createVkRect2D(JNIEnv *env, const VkRect2D *vkRect2D)
	{
		if (vkRect2D)
		{
			LOGERROR(env, "%s", "vkRect2D == nullptr");
			return nullptr;
		}

		jclass vkRect2DClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkRect2D");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkRect2D");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkRect2DClass, "<init>", "(II)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> (II)V");
            return nullptr;
        }

		jobject jVkRect2DObject =
				env->NewObject(vkRect2DClass, methodId, vkRect2D->offset, vkRect2D->extent);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

		return jVkRect2DObject;
	}
}
