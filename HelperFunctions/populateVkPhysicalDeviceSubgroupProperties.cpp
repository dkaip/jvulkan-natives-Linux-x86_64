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
 * populateVkPhysicalDeviceSubgroupProperties.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceSubgroupProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceSubgroupPropertiesObject,
			const VkPhysicalDeviceSubgroupProperties *vkPhysicalDeviceSubgroupProperties,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDeviceSubgroupPropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceSubgroupProperties");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setSubgroupSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubgroupSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSubgroupPropertiesObject, methodId, vkPhysicalDeviceSubgroupProperties->subgroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSupportedStages", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedStages");
            return;
        }

        jobject jsupportedStages = createVkShaderStageFlagsAsEnumSet(env, vkPhysicalDeviceSubgroupProperties->supportedStages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkShaderStageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSubgroupPropertiesObject, methodId, jsupportedStages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSupportedOperations", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedOperations");
            return;
        }

        jobject jsupportedOperations = createVkSubgroupFeatureFlagsAsEnumSet(env, vkPhysicalDeviceSubgroupProperties->supportedOperations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkSubgroupFeatureFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSubgroupPropertiesObject, methodId, jsupportedOperations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setQuadOperationsInAllStages", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setQuadOperationsInAllStages");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSubgroupPropertiesObject, methodId, vkPhysicalDeviceSubgroupProperties->quadOperationsInAllStages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
