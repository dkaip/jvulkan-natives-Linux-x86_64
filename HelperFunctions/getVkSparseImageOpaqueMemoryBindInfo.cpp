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
 * getVkSparseImageOpaqueMemoryBindInfo.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSparseImageOpaqueMemoryBindInfo(
        JNIEnv *env,
        const jobject jVkSparseImageOpaqueMemoryBindInfoObject,
		VkSparseImageOpaqueMemoryBindInfo *vkSparseImageOpaqueMemoryBindInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSparseImageOpaqueMemoryBindInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkSparseImageOpaqueMemoryBindInfoObject");
            return;
        }

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "getImage", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getImage");
			return;
		}

		jobject jVkImage = env->CallObjectMethod(jVkSparseImageOpaqueMemoryBindInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkImage_T *imageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jVkImage);
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

		jobject jCollection = env->CallObjectMethod(jVkSparseImageOpaqueMemoryBindInfoObject, methodId);
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


    	vkSparseImageOpaqueMemoryBindInfo->image 		= imageHandle;
    	vkSparseImageOpaqueMemoryBindInfo->bindCount	= numberOfVkSparseMemoryBinds;
    	vkSparseImageOpaqueMemoryBindInfo->pBinds		= vkSparseMemoryBinds;
    }
}
