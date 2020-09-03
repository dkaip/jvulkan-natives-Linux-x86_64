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
 * getVkPhysicalDeviceComputeShaderDerivativesFeaturesNV.cpp
 *
 *  Created on: May 17, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceComputeShaderDerivativesFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceComputeShaderDerivativesFeaturesNVObject,
			VkPhysicalDeviceComputeShaderDerivativesFeaturesNV *vkPhysicalDeviceComputeShaderDerivativesFeaturesNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceComputeShaderDerivativesFeaturesNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceComputeShaderDerivativesFeaturesNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkPhysicalDeviceComputeShaderDerivativesFeaturesNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceComputeShaderDerivativesFeaturesNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isComputeDerivativeGroupQuads", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isComputeDerivativeGroupQuads");
            return;
        }

        jboolean computeDerivativeGroupQuads = env->CallBooleanMethod(jVkPhysicalDeviceComputeShaderDerivativesFeaturesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isComputeDerivativeGroupLinear", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isComputeDerivativeGroupLinear");
            return;
        }

        jboolean computeDerivativeGroupLinear = env->CallBooleanMethod(jVkPhysicalDeviceComputeShaderDerivativesFeaturesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkPhysicalDeviceComputeShaderDerivativesFeaturesNV->sType = sTypeValue;
        vkPhysicalDeviceComputeShaderDerivativesFeaturesNV->pNext = pNext;
        vkPhysicalDeviceComputeShaderDerivativesFeaturesNV->computeDerivativeGroupQuads = computeDerivativeGroupQuads;
        vkPhysicalDeviceComputeShaderDerivativesFeaturesNV->computeDerivativeGroupLinear = computeDerivativeGroupLinear;
    }
}
