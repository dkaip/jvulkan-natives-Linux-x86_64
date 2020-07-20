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
 * getVkSparseBufferMemoryBindInfo.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSparseBufferMemoryBindInfo(
        JNIEnv *env,
        const jobject jVkSparseBufferMemoryBindInfoObject,
		VkSparseBufferMemoryBindInfo *vkSparseBufferMemoryBindInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSparseBufferMemoryBindInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkSparseBufferMemoryBindInfoObject");
            return;
        }

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getBuffer");
			return;
		}

		jobject jVkBuffer = env->CallObjectMethod(jVkSparseBufferMemoryBindInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBuffer);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not retrieve VkBuffer handle");
	        return;
	    }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getBinds", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getBinds");
			return;
		}

		jobject jCollection = env->CallObjectMethod(jVkSparseBufferMemoryBindInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        int numberOfVkSparseMemoryBinds = 0;
        VkSparseMemoryBind *vkSparseMemoryBinds = nullptr;
    	jvulkan::getVkSparseMemoryBindCollection(
    			env,
				jCollection,
    			&vkSparseMemoryBinds,
    			&numberOfVkSparseMemoryBinds,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkSparseMemoryBindCollection");
            return;
    	}


    	vkSparseBufferMemoryBindInfo->buffer 	= bufferHandle;
    	vkSparseBufferMemoryBindInfo->bindCount	= numberOfVkSparseMemoryBinds;
    	vkSparseBufferMemoryBindInfo->pBinds	= vkSparseMemoryBinds;
    }
}
