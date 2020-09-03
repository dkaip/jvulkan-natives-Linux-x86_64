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
 * getVkBufferMemoryRequirementsInfo2.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */


#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBufferMemoryRequirementsInfo2(
            JNIEnv *env,
            const jobject jVkBufferMemoryRequirementsInfo2Object,
			VkBufferMemoryRequirementsInfo2 *vkBufferMemoryRequirementsInfo2,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkBufferMemoryRequirementsInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkBufferMemoryRequirementsInfo2Object");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkBufferMemoryRequirementsInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkBufferMemoryRequirementsInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getBuffer");
            return;
        }

        jobject jVkBufferHandle = env->CallObjectMethod(jVkBufferMemoryRequirementsInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferHandle);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkFence handle");
    		return;
    	}


    	vkBufferMemoryRequirementsInfo2->sType 		= sTypeValue;
    	vkBufferMemoryRequirementsInfo2->pNext 		= pNext;
    	vkBufferMemoryRequirementsInfo2->buffer		= bufferHandle;
    }
}
