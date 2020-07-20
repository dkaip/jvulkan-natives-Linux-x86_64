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
 * getVkPhysicalDeviceFeatures2.cpp
 *
 *  Created on: May 17, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceFeatures2(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceFeatures2Object,
			VkPhysicalDeviceFeatures2 *vkPhysicalDeviceFeatures2,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceFeatures2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceFeatures2Object");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDeviceFeatures2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceFeatures2Object);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFeatures", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceFeatures;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFeatures");
            return;
        }

        jobject vkPhysicalDeviceFeaturesObject = env->CallObjectMethod(jVkPhysicalDeviceFeatures2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkPhysicalDeviceFeatures vkPhysicalDeviceFeatures = {};

        getVkPhysicalDeviceFeatures(
                env,
                vkPhysicalDeviceFeaturesObject,
    			&vkPhysicalDeviceFeatures,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkPhysicalDeviceFeatures");
            return;
        }


        vkPhysicalDeviceFeatures2->sType = sTypeValue;
        vkPhysicalDeviceFeatures2->pNext = pNext;
        memcpy(&vkPhysicalDeviceFeatures2->features, &vkPhysicalDeviceFeatures, sizeof(vkPhysicalDeviceFeatures2->features));
    }
}
