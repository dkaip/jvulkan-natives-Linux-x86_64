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
 * getVkDeviceGroupDeviceCreateInfo.cpp
 *
 *  Created on: May 16, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDeviceGroupDeviceCreateInfo(
            JNIEnv *env,
            jobject jVkDeviceGroupDeviceCreateInfoObject,
			VkDeviceGroupDeviceCreateInfo *vkDeviceGroupDeviceCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDeviceGroupDeviceCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkDeviceGroupDeviceCreateInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDeviceGroupDeviceCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDeviceGroupDeviceCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getPhysicalDevices", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getPhysicalDevices methodId");
            return;
        }

        jobject jVkPhysicalDeviceCollection = env->CallObjectMethod(jVkDeviceGroupDeviceCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getPhysicalDevices");
            return;
        }

        int numberOfVkPhysicalDevices = 0;
        VkPhysicalDevice *vkPhysicalDevices = nullptr;

        if (jVkPhysicalDeviceCollection != nullptr)
        {
            jvulkan::getVkPhysicalDeviceCollection(
                    env,
					jVkPhysicalDeviceCollection,
                    &vkPhysicalDevices,
                    &numberOfVkPhysicalDevices,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPhysicalDeviceCollection");
                return;
            }
        }

        vkDeviceGroupDeviceCreateInfo->sType 				= sTypeValue;
        vkDeviceGroupDeviceCreateInfo->pNext 				= (void *)pNext;
        vkDeviceGroupDeviceCreateInfo->physicalDeviceCount 	= numberOfVkPhysicalDevices;
        vkDeviceGroupDeviceCreateInfo->pPhysicalDevices 	= vkPhysicalDevices;
    }
}
