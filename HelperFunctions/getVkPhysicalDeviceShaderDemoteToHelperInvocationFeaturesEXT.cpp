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
 * getVkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT(
            JNIEnv *env,
            jobject jVkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXTObject,
			VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT *vkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isShaderDemoteToHelperInvocation", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderDemoteToHelperInvocation.");
            return;
        }

        VkBool32 shaderDemoteToHelperInvocation = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT->sType 	= sTypeValue;
        vkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT->pNext 	= (void *)pNext;
        vkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT->shaderDemoteToHelperInvocation	= shaderDemoteToHelperInvocation;
    }
}
