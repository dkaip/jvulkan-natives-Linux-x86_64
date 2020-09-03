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
 * getVkValidationFlagsEXT.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkValidationFlagsEXT(
		JNIEnv *env,
		const jobject jVkValidationFlagsEXTObject,
		VkValidationFlagsEXT *vkValidationFlagsEXT,
		std::vector<void *> *memoryToFree)
	{
        jclass vkValidationFlagsEXTClass = env->GetObjectClass(jVkValidationFlagsEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error getting class for jVkValidationFlagsEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkValidationFlagsEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkValidationFlagsEXTObject);
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
        jmethodID methodId = env->GetMethodID(vkValidationFlagsEXTClass, "getDisabledValidationChecks", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDisabledValidationChecks");
            return;
        }

        jobject jVkValidationFeatureEnableEXTCollection = env->CallObjectMethod(jVkValidationFlagsEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on getDisabledValidationChecks.");
            return;
        }

        int numberOfValidationFlags = 0;
        VkValidationCheckEXT *validationFlags = nullptr;

        if (jVkValidationFeatureEnableEXTCollection != nullptr)
        {
            getVkValidationCheckEXTCollection(
                    env,
					jVkValidationFeatureEnableEXTCollection,
                    &validationFlags,
                    &numberOfValidationFlags,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkValidationFlagsEXTCollection.");
                return;
            }
        }


        vkValidationFlagsEXT->sType 						= sTypeValue;
        vkValidationFlagsEXT->pNext							= pNext;
        vkValidationFlagsEXT->disabledValidationCheckCount	= numberOfValidationFlags;
		vkValidationFlagsEXT->pDisabledValidationChecks		= validationFlags;
	}
}
