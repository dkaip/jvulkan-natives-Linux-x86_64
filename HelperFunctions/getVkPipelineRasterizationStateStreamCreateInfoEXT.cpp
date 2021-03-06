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
 * getVkPipelineRasterizationStateStreamCreateInfoEXT.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineRasterizationStateStreamCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkPipelineRasterizationStateStreamCreateInfoEXTObject,
			VkPipelineRasterizationStateStreamCreateInfoEXT *vkPipelineRasterizationStateStreamCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineRasterizationStateStreamCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineRasterizationStateStreamCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineRasterizationStateStreamCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineRasterizationStateStreamCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get methodId for getFlags");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkPipelineRasterizationStateStreamCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkPipelineRasterizationStateStreamCreateFlagsEXT flags = (VkPipelineRasterizationStateStreamCreateFlagsEXT)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineRasterizationStateStreamCreateFlagsEXT");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getRasterizationStream", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getRasterizationStream.");
            return;
        }

        jint  rasterizationStream = env->CallIntMethod(jVkPipelineRasterizationStateStreamCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkPipelineRasterizationStateStreamCreateInfoEXT->sType = sTypeValue;
        vkPipelineRasterizationStateStreamCreateInfoEXT->pNext = pNext;
        vkPipelineRasterizationStateStreamCreateInfoEXT->flags = flags;
        vkPipelineRasterizationStateStreamCreateInfoEXT->rasterizationStream = rasterizationStream;
    }
}
