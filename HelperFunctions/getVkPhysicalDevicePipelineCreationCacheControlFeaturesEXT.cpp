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
 * getVkPhysicalDevicePipelineCreationCacheControlFeaturesEXT.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDevicePipelineCreationCacheControlFeaturesEXT(
            JNIEnv *env,
            jobject jVkPhysicalDevicePipelineCreationCacheControlFeaturesEXTObject,
			VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT *vkPhysicalDevicePipelineCreationCacheControlFeaturesEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDevicePipelineCreationCacheControlFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDevicePipelineCreationCacheControlFeaturesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDevicePipelineCreationCacheControlFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDevicePipelineCreationCacheControlFeaturesEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isPipelineCreationCacheControl", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isPipelineCreationCacheControl.");
            return;
        }

        VkBool32 pipelineCreationCacheControl = (VkBool32)env->CallBooleanMethod(jVkPhysicalDevicePipelineCreationCacheControlFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkPhysicalDevicePipelineCreationCacheControlFeaturesEXT->sType 	= sTypeValue;
        vkPhysicalDevicePipelineCreationCacheControlFeaturesEXT->pNext 	= (void *)pNext;
        vkPhysicalDevicePipelineCreationCacheControlFeaturesEXT->pipelineCreationCacheControl	= pipelineCreationCacheControl;
    }
}
