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
 * createVkOffset2D.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	jobject createVkOffset2D(JNIEnv *env, const VkOffset2D *vkOffset2D)
	{
		if (vkOffset2D)
		{
			LOGERROR(env, "%s", "vkOffset2D == nullptr");
			return nullptr;
		}

		jclass vkOffset2DClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset2D");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkOffset2DClass, "<init>", "(II)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> (II)V");
            return nullptr;
        }

		jobject jVkOffset2DObject =
				env->NewObject(vkOffset2DClass, methodId, vkOffset2D->x, vkOffset2D->y);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

		return jVkOffset2DObject;
	}
}
