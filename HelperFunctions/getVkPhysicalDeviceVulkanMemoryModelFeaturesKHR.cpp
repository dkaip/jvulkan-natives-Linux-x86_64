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
 * getVkPhysicalDeviceVulkanMemoryModelFeaturesKHR.cpp
 *
 *  Created on: May 19, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceVulkanMemoryModelFeaturesKHR(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceVulkanMemoryModelFeaturesKHRObject,
			VkPhysicalDeviceVulkanMemoryModelFeaturesKHR *vkPhysicalDeviceVulkanMemoryModelFeaturesKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceVulkanMemoryModelFeaturesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceVulkanMemoryModelFeaturesKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDeviceVulkanMemoryModelFeaturesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceVulkanMemoryModelFeaturesKHRObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isVulkanMemoryModel", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVulkanMemoryModel");
            return;
        }

        jboolean vulkanMemoryModel = env->CallBooleanMethod(jVkPhysicalDeviceVulkanMemoryModelFeaturesKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isVulkanMemoryModelDeviceScope", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVulkanMemoryModelDeviceScope");
            return;
        }

        jboolean vulkanMemoryModelDeviceScope = env->CallBooleanMethod(jVkPhysicalDeviceVulkanMemoryModelFeaturesKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isVulkanMemoryModelAvailabilityVisibilityChains", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVulkanMemoryModelAvailabilityVisibilityChains");
            return;
        }

        jboolean vulkanMemoryModelAvailabilityVisibilityChains = env->CallBooleanMethod(jVkPhysicalDeviceVulkanMemoryModelFeaturesKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkPhysicalDeviceVulkanMemoryModelFeaturesKHR->sType = sTypeValue;
        vkPhysicalDeviceVulkanMemoryModelFeaturesKHR->pNext = pNext;
        vkPhysicalDeviceVulkanMemoryModelFeaturesKHR->vulkanMemoryModel = vulkanMemoryModel;
        vkPhysicalDeviceVulkanMemoryModelFeaturesKHR->vulkanMemoryModelDeviceScope = vulkanMemoryModelDeviceScope;
        vkPhysicalDeviceVulkanMemoryModelFeaturesKHR->vulkanMemoryModelAvailabilityVisibilityChains = vulkanMemoryModelAvailabilityVisibilityChains;
    }
}
