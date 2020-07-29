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
 * getVkValidationFeaturesEXT.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkValidationFeaturesEXT(
		JNIEnv *env,
		const jobject jVkValidationFeaturesEXTObject,
		VkValidationFeaturesEXT *vkValidationFeaturesEXT,
		std::vector<void *> *memoryToFree)
	{
        jclass vkValidationFeaturesEXTClass = env->GetObjectClass(jVkValidationFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error getting class for jVkValidationFeaturesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkValidationFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkValidationFeaturesEXTObject);
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
        jmethodID methodId = env->GetMethodID(vkValidationFeaturesEXTClass, "getEnabledValidationFeatures", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getEnabledValidationFeatures");
            return;
        }

        jobject jVkValidationFeatureEnableEXTCollection = env->CallObjectMethod(jVkValidationFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on getEnabledValidationFeatures.");
            return;
        }

        int numberOfEnabledValidationFeatures = 0;
        VkValidationFeatureEnableEXT *enabledValidationFeatures = nullptr;

        if (jVkValidationFeatureEnableEXTCollection != nullptr)
        {
            getVkValidationFeatureEnableEXTCollection(
                    env,
					jVkValidationFeatureEnableEXTCollection,
                    &enabledValidationFeatures,
                    &numberOfEnabledValidationFeatures,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkValidationFeatureEnableEXTCollection.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkValidationFeaturesEXTClass, "getDisabledValidationFeatures", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDisabledValidationFeatures");
            return;
        }

        jobject jVkValidationFeatureDisableEXTCollection = env->CallObjectMethod(jVkValidationFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on getDisabledValidationFeatures.");
            return;
        }

        int numberOfDisabledValidationFeatures = 0;
        VkValidationFeatureDisableEXT *disabledValidationFeatures = nullptr;

        if (jVkValidationFeatureDisableEXTCollection != nullptr)
        {
            getVkValidationFeatureDisableEXTCollection(
                    env,
					jVkValidationFeatureDisableEXTCollection,
                    &disabledValidationFeatures,
                    &numberOfDisabledValidationFeatures,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkValidationFeatureDisableEXTCollection.");
                return;
            }
        }


        vkValidationFeaturesEXT->sType 							= sTypeValue;
        vkValidationFeaturesEXT->pNext							= pNext;
        vkValidationFeaturesEXT->enabledValidationFeatureCount 	= numberOfEnabledValidationFeatures;
		vkValidationFeaturesEXT->pEnabledValidationFeatures 	= enabledValidationFeatures;
		vkValidationFeaturesEXT->disabledValidationFeatureCount = numberOfDisabledValidationFeatures;
		vkValidationFeaturesEXT->pDisabledValidationFeatures 	= disabledValidationFeatures;
	}
}
