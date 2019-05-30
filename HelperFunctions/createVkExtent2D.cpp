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
 * createVkExtent2D.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	jobject createVkExtent2D(JNIEnv *env, const VkExtent2D *vkExtent2D)
	{
		jclass vkExtent2DClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkExtent2DClass, "<init>", "(II)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> (II)V");
            return nullptr;
        }

		jobject jVkExtent2DObject =
				env->NewObject(vkExtent2DClass, methodId, vkExtent2D->width, vkExtent2D->height);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

		return jVkExtent2DObject;
	}
}
