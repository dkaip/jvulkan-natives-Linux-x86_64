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
 * getVkPhysicalDeviceShaderSMBuiltinsFeaturesNV.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceShaderSMBuiltinsFeaturesNV(
            JNIEnv *env,
            jobject jVkPhysicalDeviceShaderSMBuiltinsFeaturesNVObject,
			VkPhysicalDeviceShaderSMBuiltinsFeaturesNV *vkPhysicalDeviceShaderSMBuiltinsFeaturesNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceShaderSMBuiltinsFeaturesNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDeviceShaderSMBuiltinsFeaturesNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceShaderSMBuiltinsFeaturesNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceShaderSMBuiltinsFeaturesNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isShaderSMBuiltins", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSMBuiltins.");
            return;
        }

        VkBool32 shaderSMBuiltins = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderSMBuiltinsFeaturesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkPhysicalDeviceShaderSMBuiltinsFeaturesNV->sType 	= sTypeValue;
        vkPhysicalDeviceShaderSMBuiltinsFeaturesNV->pNext 	= (void *)pNext;
        vkPhysicalDeviceShaderSMBuiltinsFeaturesNV->shaderSMBuiltins = shaderSMBuiltins;
    }
}
