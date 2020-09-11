/*
 * Copyright 2020 Douglas Kaip
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
 * getVkPhysicalDeviceRobustness2FeaturesEXT.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceRobustness2FeaturesEXT(
            JNIEnv *env,
            jobject jVkPhysicalDeviceRobustness2FeaturesEXTObject,
			VkPhysicalDeviceRobustness2FeaturesEXT *vkPhysicalDeviceRobustness2FeaturesEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceRobustness2FeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDeviceRobustness2FeaturesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceRobustness2FeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceRobustness2FeaturesEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isRobustBufferAccess2", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isRobustBufferAccess2.");
            return;
        }

        VkBool32 robustBufferAccess2 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRobustness2FeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isRobustImageAccess2", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isRobustImageAccess2.");
            return;
        }

        VkBool32 robustImageAccess2 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRobustness2FeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isNullDescriptor", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isNullDescriptor.");
            return;
        }

        VkBool32 nullDescriptor = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRobustness2FeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkPhysicalDeviceRobustness2FeaturesEXT->sType 	= sTypeValue;
        vkPhysicalDeviceRobustness2FeaturesEXT->pNext 	= (void *)pNext;
        vkPhysicalDeviceRobustness2FeaturesEXT->robustBufferAccess2	= robustBufferAccess2;
        vkPhysicalDeviceRobustness2FeaturesEXT->robustImageAccess2	= robustImageAccess2;
        vkPhysicalDeviceRobustness2FeaturesEXT->nullDescriptor	= nullDescriptor;
    }
}
