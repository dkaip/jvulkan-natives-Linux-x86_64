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
 * populateVkPhysicalDeviceSubgroupSizeControlPropertiesEXT.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceSubgroupSizeControlPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceSubgroupSizeControlPropertiesEXTObject,
			const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT *vkPhysicalDeviceSubgroupSizeControlPropertiesEXT)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceSubgroupSizeControlPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceSubgroupSizeControlPropertiesEXTObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setMinSubgroupSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinSubgroupSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSubgroupSizeControlPropertiesEXTObject, methodId, vkPhysicalDeviceSubgroupSizeControlPropertiesEXT->minSubgroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxSubgroupSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSubgroupSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSubgroupSizeControlPropertiesEXTObject, methodId, vkPhysicalDeviceSubgroupSizeControlPropertiesEXT->maxSubgroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxComputeWorkgroupSubgroups", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxComputeWorkgroupSubgroups");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSubgroupSizeControlPropertiesEXTObject, methodId, vkPhysicalDeviceSubgroupSizeControlPropertiesEXT->maxComputeWorkgroupSubgroups);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setRequiredSubgroupSizeStages", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRequiredSubgroupSizeStages");
            return;
        }

        jobject vkShaderStageFlagsEnumSet = createVkShaderStageFlagsAsEnumSet(env, vkPhysicalDeviceSubgroupSizeControlPropertiesEXT->requiredSubgroupSizeStages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSampleCountFlagBitsAsEnumSet");
            return;
        }

        if (vkShaderStageFlagsEnumSet == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createVkShaderStageFlagsAsEnumSet, setRequiredSubgroupSizeStages was nullptr");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSubgroupSizeControlPropertiesEXTObject, methodId, vkShaderStageFlagsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
