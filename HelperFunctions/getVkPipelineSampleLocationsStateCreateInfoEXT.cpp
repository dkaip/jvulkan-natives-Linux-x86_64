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
 * getVkPipelineSampleLocationsStateCreateInfoEXT.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineSampleLocationsStateCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkPipelineSampleLocationsStateCreateInfoEXTObject,
			VkPipelineSampleLocationsStateCreateInfoEXT *vkPipelineSampleLocationsStateCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineSampleLocationsStateCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineSampleLocationsStateCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPipelineSampleLocationsStateCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineSampleLocationsStateCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isSampleLocationsEnable", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isSampleLocationsEnable.");
            return;
        }

        jboolean sampleLocationsEnable = env->CallBooleanMethod(jVkPipelineSampleLocationsStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getInfo", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkSampleLocationsInfoEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getInfo.");
            return;
        }

        jobject jSampleLocationsInfo = env->CallObjectMethod(jVkPipelineSampleLocationsStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }


        vkPipelineSampleLocationsStateCreateInfoEXT->sType = sTypeValue;
        vkPipelineSampleLocationsStateCreateInfoEXT->pNext = pNext;
        vkPipelineSampleLocationsStateCreateInfoEXT->sampleLocationsEnable = sampleLocationsEnable;

        getVkSampleLocationsInfoEXT(
                env,
                jSampleLocationsInfo,
				&(vkPipelineSampleLocationsStateCreateInfoEXT->sampleLocationsInfo),
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkSampleLocationsInfoEXT.");
            return;
        }
    }
}
