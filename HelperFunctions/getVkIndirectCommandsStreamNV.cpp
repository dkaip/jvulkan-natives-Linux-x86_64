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
 * getVkIndirectCommandsStreamNV.cpp
 *
 *  Created on: Aug 30, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkIndirectCommandsStreamNV(
            JNIEnv *env,
            const jobject jVkIndirectCommandsStreamNVObject,
			VkIndirectCommandsStreamNV *vkIndirectCommandsStreamNV,
            std::vector<void *> *memoryToFree)
    {
		if (jVkIndirectCommandsStreamNVObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkIndirectCommandsStreamNVObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkIndirectCommandsStreamNVObject == nullptr");
			return;
		}

		if (vkIndirectCommandsStreamNV == nullptr)
		{
			LOGERROR(env, "%s", "vkIndirectCommandsStreamNV == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkIndirectCommandsStreamNV == nullptr");
			return;
		}

        jclass theClass = env->GetObjectClass(jVkIndirectCommandsStreamNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkIndirectCommandsStreamNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getBuffer");
            return;
        }

        jobject jVkBufferHandle = env->CallObjectMethod(jVkIndirectCommandsStreamNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkBuffer_T *buffer = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve jVkBufferHandle handle");
    		return;
    	}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getOffset", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getOffset");
            return;
        }

        VkDeviceSize offset = (VkDeviceSize)env->CallLongMethod(jVkIndirectCommandsStreamNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }


        vkIndirectCommandsStreamNV->buffer = buffer;
        vkIndirectCommandsStreamNV->offset = offset;
    }
}
