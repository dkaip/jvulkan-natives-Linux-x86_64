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
 * getVkSharedPresentSurfaceCapabilitiesKHR.cpp
 *
 *  Created on: May 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSharedPresentSurfaceCapabilitiesKHR(
            JNIEnv *env,
            const jobject jVkSharedPresentSurfaceCapabilitiesKHRObject,
			VkSharedPresentSurfaceCapabilitiesKHR *vkSharedPresentSurfaceCapabilitiesKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSharedPresentSurfaceCapabilitiesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkSharedPresentSurfaceCapabilitiesKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkSharedPresentSurfaceCapabilitiesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSharedPresentSurfaceCapabilitiesKHRObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getSharedPresentSupportedUsageFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSharedPresentSupportedUsageFlags.");
            return;
        }

        jobject sharedPresentSupportedUsageFlagsObject = env->CallObjectMethod(jVkSharedPresentSurfaceCapabilitiesKHRObject, methodId);
        VkImageUsageFlags flags = (VkImageUsageFlags)getEnumSetValue(
                env,
				sharedPresentSupportedUsageFlagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageUsageFlagBits");


        vkSharedPresentSurfaceCapabilitiesKHR->sType = sTypeValue;
        vkSharedPresentSurfaceCapabilitiesKHR->pNext = pNext;
        vkSharedPresentSurfaceCapabilitiesKHR->sharedPresentSupportedUsageFlags = flags;
    }
}
