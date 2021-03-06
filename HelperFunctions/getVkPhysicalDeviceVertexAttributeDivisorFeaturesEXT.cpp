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
 * getVkPhysicalDeviceVertexAttributeDivisorFeaturesEXT.cpp
 *
 *  Created on: May 19, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceVertexAttributeDivisorFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceVertexAttributeDivisorFeaturesEXTObject,
			VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT *vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceVertexAttributeDivisorFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceVertexAttributeDivisorFeaturesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceVertexAttributeDivisorFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceVertexAttributeDivisorFeaturesEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isVertexAttributeInstanceRateDivisor", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVertexAttributeInstanceRateDivisor");
            return;
        }

        jboolean vertexAttributeInstanceRateDivisor = env->CallBooleanMethod(jVkPhysicalDeviceVertexAttributeDivisorFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isVertexAttributeInstanceRateZeroDivisor", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVertexAttributeInstanceRateZeroDivisor");
            return;
        }

        jboolean vertexAttributeInstanceRateZeroDivisor = env->CallBooleanMethod(jVkPhysicalDeviceVertexAttributeDivisorFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT->sType = sTypeValue;
        vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT->pNext = pNext;
        vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT->vertexAttributeInstanceRateDivisor = vertexAttributeInstanceRateDivisor;
        vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT->vertexAttributeInstanceRateZeroDivisor = vertexAttributeInstanceRateZeroDivisor;
    }
}
