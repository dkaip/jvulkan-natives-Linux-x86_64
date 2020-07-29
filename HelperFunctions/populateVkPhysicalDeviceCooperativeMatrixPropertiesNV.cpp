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
 * populateVkPhysicalDeviceCooperativeMatrixPropertiesNV.cpp
 *
 *  Created on: May 13, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceCooperativeMatrixPropertiesNV(
		JNIEnv *env,
		jobject jVkPhysicalDeviceCooperativeMatrixPropertiesNVObject,
		const VkPhysicalDeviceCooperativeMatrixPropertiesNV* vkPhysicalDeviceCooperativeMatrixPropertiesNV,
		std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceCooperativeMatrixPropertiesNVClass = env->GetObjectClass(
				jVkPhysicalDeviceCooperativeMatrixPropertiesNVObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceCooperativeMatrixPropertiesNV");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceCooperativeMatrixPropertiesNVClass, "setCooperativeMatrixSupportedStages", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCooperativeMatrixSupportedStages");
            return;
        }

        jobject jCooperativeMatrixSupportedStages = createVkShaderStageFlagsAsEnumSet(env, vkPhysicalDeviceCooperativeMatrixPropertiesNV->cooperativeMatrixSupportedStages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkShaderStageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceCooperativeMatrixPropertiesNVObject, methodId, jCooperativeMatrixSupportedStages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}

