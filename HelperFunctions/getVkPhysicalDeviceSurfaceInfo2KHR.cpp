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
 * getVkPhysicalDeviceSurfaceInfo2KHR.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceSurfaceInfo2KHR(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceSurfaceInfo2KHRObject,
			VkPhysicalDeviceSurfaceInfo2KHR *vkPhysicalDeviceSurfaceInfo2KHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceSurfaceInfo2KHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceSurfaceInfo2KHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkPhysicalDeviceSurfaceInfo2KHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceSurfaceInfo2KHRObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getSurface", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkSurfaceKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method if for getSurface");
            return;
        }

        jobject jVkSurfaceKHRObject = env->CallObjectMethod(jVkPhysicalDeviceSurfaceInfo2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getSurface");
            return;
        }

        VkSurfaceKHR surface = (VkSurfaceKHR)getHandleValue(env, jVkSurfaceKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue");
            return;
        }


        vkPhysicalDeviceSurfaceInfo2KHR->sType = sTypeValue;
        vkPhysicalDeviceSurfaceInfo2KHR->pNext = pNext;
        vkPhysicalDeviceSurfaceInfo2KHR->surface = surface;
    }
}
