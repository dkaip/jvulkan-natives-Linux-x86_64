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
 * getVkPipelineRepresentativeFragmentTestStateCreateInfoNV.cpp
 *
 *  Created on: May 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineRepresentativeFragmentTestStateCreateInfoNV(
            JNIEnv *env,
            const jobject jVkPipelineRepresentativeFragmentTestStateCreateInfoNVObject,
			VkPipelineRepresentativeFragmentTestStateCreateInfoNV *vkPipelineRepresentativeFragmentTestStateCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineRepresentativeFragmentTestStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineRepresentativeFragmentTestStateCreateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineRepresentativeFragmentTestStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineRepresentativeFragmentTestStateCreateInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isRepresentativeFragmentTestEnable", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isRepresentativeFragmentTestEnable");
            return;
        }

        jboolean representativeFragmentTestEnable = env->CallBooleanMethod(jVkPipelineRepresentativeFragmentTestStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkPipelineRepresentativeFragmentTestStateCreateInfoNV->sType = sTypeValue;
        vkPipelineRepresentativeFragmentTestStateCreateInfoNV->pNext = pNext;
        vkPipelineRepresentativeFragmentTestStateCreateInfoNV->representativeFragmentTestEnable = representativeFragmentTestEnable;
    }
}
