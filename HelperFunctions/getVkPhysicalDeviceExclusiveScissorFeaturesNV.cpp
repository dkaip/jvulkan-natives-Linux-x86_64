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
 * getVkPhysicalDeviceExclusiveScissorFeaturesNV.cpp
 *
 *  Created on: May 17, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceExclusiveScissorFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceExclusiveScissorFeaturesNVObject,
			VkPhysicalDeviceExclusiveScissorFeaturesNV *vkPhysicalDeviceExclusiveScissorFeaturesNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceExclusiveScissorFeaturesNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceExclusiveScissorFeaturesNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDeviceExclusiveScissorFeaturesNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceExclusiveScissorFeaturesNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isExclusiveScissor", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isExclusiveScissor");
            return;
        }

        jboolean exclusiveScissor = env->CallBooleanMethod(jVkPhysicalDeviceExclusiveScissorFeaturesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkPhysicalDeviceExclusiveScissorFeaturesNV->sType = sTypeValue;
        vkPhysicalDeviceExclusiveScissorFeaturesNV->pNext = pNext;
        vkPhysicalDeviceExclusiveScissorFeaturesNV->exclusiveScissor = exclusiveScissor;
    }
}