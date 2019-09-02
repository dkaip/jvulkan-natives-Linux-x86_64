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
 * getVkBufferDeviceAddressCreateInfoEXT.cpp
 *
 *  Created on: May 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBufferDeviceAddressCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkBufferDeviceAddressCreateInfoEXTObject,
			VkBufferDeviceAddressCreateInfoEXT *vkBufferDeviceAddressCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkBufferDeviceAddressCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkBufferDeviceAddressCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkBufferDeviceAddressCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkBufferDeviceAddressCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getDeviceAddress", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkDeviceAddress;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDeviceAddress method Id");
            return;
        }

        jobject jVkDeviceAddressObject = env->CallObjectMethod(jVkBufferDeviceAddressCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getDeviceAddress");
            return;
        }

        VkDeviceAddress *deviceAddressHandle = (VkDeviceAddress *)jvulkan::getHandleValue(env, jVkDeviceAddressObject);
        if (env->ExceptionOccurred())
        {
            return;
        }


        vkBufferDeviceAddressCreateInfoEXT->sType = sTypeValue;
        vkBufferDeviceAddressCreateInfoEXT->pNext = pNext;
        vkBufferDeviceAddressCreateInfoEXT->deviceAddress = (VkDeviceSize)deviceAddressHandle; // hmmm
    }
}
