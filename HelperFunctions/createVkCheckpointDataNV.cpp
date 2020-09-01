/*
 * Copyright 2020 Douglas Kaip
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
 * createVkCheckpointDataNV.cpp
 *
 *  Created on: Sep 1, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkCheckpointDataNV(
			JNIEnv *env,
			VkCheckpointDataNV const *vkCheckpointDataNV)
	{
		if (vkCheckpointDataNV == nullptr)
		{
			LOGERROR(env, "%s", "vkCheckpointDataNV == nullptr");
			return nullptr;
		}

		jclass vkCheckpointDataNVClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkCheckpointDataNV");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkCheckpointDataNV");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkCheckpointDataNVClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkCheckpointDataNVObject =
				env->NewObject(vkCheckpointDataNVClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkComponentTypeNV = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineStageFlagBits",
				vkCheckpointDataNV->stage);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkCheckpointDataNVClass, "setStage", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineStageFlagBits;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setStage");
            return nullptr;
        }

        env->CallVoidMethod(jVkCheckpointDataNVObject, methodId, jVkComponentTypeNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jCheckpointMarker = createVulkanHandle(
        		env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Handles/CheckpointMarker",
				vkCheckpointDataNV->pCheckpointMarker);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle");
            return nullptr;
        }

		methodId = env->GetMethodID(vkCheckpointDataNVClass, "setCheckpointMarker", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/CheckpointMarker;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCheckpointMarker");
            return nullptr;
        }

        env->CallVoidMethod(jVkCheckpointDataNVObject, methodId, jCheckpointMarker);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkCheckpointDataNVObject;
	}
}
