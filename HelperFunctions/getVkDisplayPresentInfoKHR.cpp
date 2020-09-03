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
 * getVkDisplayPresentInfoKHR.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDisplayPresentInfoKHR(
            JNIEnv *env,
            const jobject jVkDisplayPresentInfoKHRObject,
			VkDisplayPresentInfoKHR *vkDisplayPresentInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDisplayPresentInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDisplayPresentInfoKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkDisplayPresentInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDisplayPresentInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getSrcRect", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkRect2D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSrcRect.");
            return;
        }

        jobject jVkRect2DObject = env->CallObjectMethod(jVkDisplayPresentInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkRect2D srcVkRect2D = {};
		getVkRect2D(
				env,
				jVkRect2DObject,
				&srcVkRect2D,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getVkRect2D.");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDstRect", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkRect2D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDstRect.");
            return;
        }

        jVkRect2DObject = env->CallObjectMethod(jVkDisplayPresentInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkRect2D dstVkRect2D = {};
		getVkRect2D(
				env,
				jVkRect2DObject,
				&dstVkRect2D,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getVkRect2D.");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isPersistent", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isPersistent.");
            return;
        }

        jboolean persistent = env->CallBooleanMethod(jVkDisplayPresentInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkDisplayPresentInfoKHR->sType = sTypeValue;
        vkDisplayPresentInfoKHR->pNext = pNext;
        vkDisplayPresentInfoKHR->srcRect.extent.width = srcVkRect2D.extent.width;
        vkDisplayPresentInfoKHR->srcRect.extent.height = srcVkRect2D.extent.height;
        vkDisplayPresentInfoKHR->srcRect.offset.x = srcVkRect2D.offset.x;
        vkDisplayPresentInfoKHR->srcRect.offset.y= srcVkRect2D.offset.y;
        vkDisplayPresentInfoKHR->dstRect.extent.width = dstVkRect2D.extent.width;
        vkDisplayPresentInfoKHR->dstRect.extent.height = dstVkRect2D.extent.height;
        vkDisplayPresentInfoKHR->dstRect.offset.x = dstVkRect2D.offset.x;
        vkDisplayPresentInfoKHR->dstRect.offset.y= dstVkRect2D.offset.y;
		vkDisplayPresentInfoKHR->persistent = persistent;
    }
}
