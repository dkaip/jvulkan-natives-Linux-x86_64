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
 * getVkBindSparseInfo.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkBindSparseInfo(
        JNIEnv *env,
        const jobject jVkBindSparseInfoObject,
		VkBindSparseInfo *vkBindSparseInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkBindSparseInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkBindSparseInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkBindSparseInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkBindSparseInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
            return;
        }

        void *pNext = nullptr;

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "getWaitSemaphores", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getWaitSemaphores");
			return;
		}

		jobject jCollection = env->CallObjectMethod(jVkBindSparseInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        int numberOfWaitSemaphores = 0;
        VkSemaphore *waitSemaphores = nullptr;
    	jvulkan::getVulkanHandleCollection(
    			env,
				jCollection,
    			(void **)&waitSemaphores,
    			&numberOfWaitSemaphores,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVulkanHandleCollection");
            return;
    	}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getBufferBinds", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getBufferBinds");
			return;
		}

		jCollection = env->CallObjectMethod(jVkBindSparseInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        int numberOfBufferBinds = 0;
        VkSparseBufferMemoryBindInfo *bufferBinds = nullptr;
    	jvulkan::getVkSparseBufferMemoryBindInfoCollection(
    			env,
				jCollection,
				&bufferBinds,
    			&numberOfBufferBinds,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkSparseBufferMemoryBindInfoCollection");
            return;
    	}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getImageOpaqueBinds", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getImageOpaqueBinds");
			return;
		}

		jCollection = env->CallObjectMethod(jVkBindSparseInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        int numberOfImageOpaqueBinds = 0;
        VkSparseImageOpaqueMemoryBindInfo *imageOpaqueBinds = nullptr;
    	jvulkan::getVkSparseImageOpaqueMemoryBindInfoCollection(
    			env,
				jCollection,
				&imageOpaqueBinds,
    			&numberOfImageOpaqueBinds,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkSparseImageOpaqueMemoryBindInfoCollection");
            return;
    	}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getImageBinds", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getImageBinds");
			return;
		}

		jCollection = env->CallObjectMethod(jVkBindSparseInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        int numberOfImageBinds = 0;
        VkSparseImageMemoryBindInfo *imageBinds = nullptr;
    	jvulkan::getVkSparseImageMemoryBindInfoCollection(
    			env,
				jCollection,
				&imageBinds,
    			&numberOfImageBinds,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVkSparseImageMemoryBindInfoCollection");
            return;
    	}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "getSignalSemaphores", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getSignalSemaphores");
			return;
		}

		jCollection = env->CallObjectMethod(jVkBindSparseInfoObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

        int numberOfSignalSemaphores = 0;
        VkSemaphore *signalSemaphores = nullptr;
    	jvulkan::getVulkanHandleCollection(
    			env,
				jCollection,
    			(void **)&signalSemaphores,
    			&numberOfSignalSemaphores,
    			memoryToFree);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling getVulkanHandleCollection");
            return;
    	}


        vkBindSparseInfo->sType = sTypeValue;
        vkBindSparseInfo->pNext = (void *)pNext;
        vkBindSparseInfo->waitSemaphoreCount 	= numberOfWaitSemaphores;
        vkBindSparseInfo->pWaitSemaphores 		= waitSemaphores;
        vkBindSparseInfo->bufferBindCount 		= numberOfBufferBinds;
        vkBindSparseInfo->pBufferBinds			= bufferBinds;
        vkBindSparseInfo->imageOpaqueBindCount	= numberOfImageOpaqueBinds;
        vkBindSparseInfo->pImageOpaqueBinds		= imageOpaqueBinds;
        vkBindSparseInfo->imageBindCount		= numberOfImageBinds;
        vkBindSparseInfo->pImageBinds			= imageBinds;
        vkBindSparseInfo->signalSemaphoreCount	= numberOfSignalSemaphores;
        vkBindSparseInfo->pSignalSemaphores		= signalSemaphores;
    }
}
