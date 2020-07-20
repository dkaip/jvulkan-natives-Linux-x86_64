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
 * getVkBindImageMemorySwapchainInfoKHR.cpp
 *
 *  Created on: May 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBindImageMemorySwapchainInfoKHR(
            JNIEnv *env,
            const jobject jVkBindImageMemorySwapchainInfoKHRObject,
			VkBindImageMemorySwapchainInfoKHR *vkBindImageMemorySwapchainInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkBindImageMemorySwapchainInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkBindImageMemorySwapchainInfoKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkBindImageMemorySwapchainInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkBindImageMemorySwapchainInfoKHRObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getSwapchain", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkDeviceAddress;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for getSwapchain");
            return;
        }

        jobject jVkSwapchainKHRObject = env->CallObjectMethod(jVkBindImageMemorySwapchainInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getSwapchain");
            return;
        }

        VkSwapchainKHR swapchainHandle = (VkSwapchainKHR)getHandleValue(env, jVkSwapchainKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getImageIndex", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for getImageIndex");
            return;
        }

        jint imageIndex = env->CallIntMethod(jVkBindImageMemorySwapchainInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for getImageIndex");
            return;
        }


        vkBindImageMemorySwapchainInfoKHR->sType = sTypeValue;
        vkBindImageMemorySwapchainInfoKHR->pNext = pNext;
        vkBindImageMemorySwapchainInfoKHR->swapchain = swapchainHandle;
        vkBindImageMemorySwapchainInfoKHR->imageIndex = imageIndex;
    }
}
