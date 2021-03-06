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
 * getVkPipelineViewportSwizzleStateCreateInfoNV.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineViewportSwizzleStateCreateInfoNV(
            JNIEnv *env,
            const jobject jVkPipelineViewportSwizzleStateCreateInfoNVObject,
			VkPipelineViewportSwizzleStateCreateInfoNV *vkPipelineViewportSwizzleStateCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineViewportSwizzleStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineViewportSwizzleStateCreateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineViewportSwizzleStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineViewportSwizzleStateCreateInfoNVObject);
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

		jobject flagsObject = env->CallObjectMethod(jVkPipelineViewportSwizzleStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkPipelineViewportSwizzleStateCreateFlagsNV flags = (VkPipelineViewportSwizzleStateCreateFlagsNV)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineViewportSwizzleStateCreateFlagBitsNV");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getViewportSwizzles", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getViewportSwizzles");
            return;
        }

        jobject jViewportSwizzles = env->CallObjectMethod(jVkPipelineViewportSwizzleStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int viewportCount = 0;
        VkViewportSwizzleNV *viewportSwizzles = nullptr;
        getVkViewportSwizzleNVCollection(
                env,
				jViewportSwizzles,
                &viewportSwizzles,
                &viewportCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkViewportSwizzleNVCollection");
            return;
        }


        vkPipelineViewportSwizzleStateCreateInfoNV->sType = sTypeValue;
        vkPipelineViewportSwizzleStateCreateInfoNV->pNext = pNext;
        vkPipelineViewportSwizzleStateCreateInfoNV->flags = flags;
        vkPipelineViewportSwizzleStateCreateInfoNV->viewportCount = viewportCount;
        vkPipelineViewportSwizzleStateCreateInfoNV->pViewportSwizzles = viewportSwizzles;
    }
}
