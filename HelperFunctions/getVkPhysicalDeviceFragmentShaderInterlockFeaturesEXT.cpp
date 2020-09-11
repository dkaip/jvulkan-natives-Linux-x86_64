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
 * getVkPhysicalDeviceFragmentShaderInterlockFeaturesEXT.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(
            JNIEnv *env,
            jobject jVkPhysicalDeviceFragmentShaderInterlockFeaturesEXTObject,
			VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *vkPhysicalDeviceFragmentShaderInterlockFeaturesEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceFragmentShaderInterlockFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDeviceFragmentShaderInterlockFeaturesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceFragmentShaderInterlockFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceFragmentShaderInterlockFeaturesEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isFragmentShaderSampleInterlock", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isFragmentShaderSampleInterlock.");
            return;
        }

        VkBool32 fragmentShaderSampleInterlock = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceFragmentShaderInterlockFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isFragmentShaderPixelInterlock", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isFragmentShaderPixelInterlock.");
            return;
        }

        VkBool32 fragmentShaderPixelInterlock = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceFragmentShaderInterlockFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isFragmentShaderShadingRateInterlock", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isFragmentShaderShadingRateInterlock.");
            return;
        }

        VkBool32 fragmentShaderShadingRateInterlock = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceFragmentShaderInterlockFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkPhysicalDeviceFragmentShaderInterlockFeaturesEXT->sType 	= sTypeValue;
        vkPhysicalDeviceFragmentShaderInterlockFeaturesEXT->pNext 	= (void *)pNext;
        vkPhysicalDeviceFragmentShaderInterlockFeaturesEXT->fragmentShaderSampleInterlock	= fragmentShaderSampleInterlock;
        vkPhysicalDeviceFragmentShaderInterlockFeaturesEXT->fragmentShaderPixelInterlock	= fragmentShaderPixelInterlock;
        vkPhysicalDeviceFragmentShaderInterlockFeaturesEXT->fragmentShaderShadingRateInterlock	= fragmentShaderShadingRateInterlock;
    }
}
