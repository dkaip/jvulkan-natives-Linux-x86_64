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
 * getVkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(
            JNIEnv *env,
            jobject jVkPhysicalDeviceShaderIntegerFunctions2FeaturesINTELObject,
			VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL *vkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceShaderIntegerFunctions2FeaturesINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDeviceShaderIntegerFunctions2FeaturesINTELObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceShaderIntegerFunctions2FeaturesINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceShaderIntegerFunctions2FeaturesINTELObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isShaderIntegerFunctions2", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderIntegerFunctions2.");
            return;
        }

        VkBool32 shaderIntegerFunctions2 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderIntegerFunctions2FeaturesINTELObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL->sType 	= sTypeValue;
        vkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL->pNext 	= (void *)pNext;
        vkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL->shaderIntegerFunctions2 = shaderIntegerFunctions2;
    }
}
