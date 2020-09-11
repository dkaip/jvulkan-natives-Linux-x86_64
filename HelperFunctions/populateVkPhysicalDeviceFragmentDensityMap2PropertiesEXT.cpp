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
 * populateVkPhysicalDeviceFragmentDensityMap2PropertiesEXT.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceFragmentDensityMap2PropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceFragmentDensityMap2PropertiesEXTObject,
			const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT *vkPhysicalDeviceFragmentDensityMap2PropertiesEXT)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceFragmentDensityMap2PropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceFragmentDensityMap2PropertiesEXTObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setSubsampledLoads", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubsampledLoads");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFragmentDensityMap2PropertiesEXTObject, methodId, vkPhysicalDeviceFragmentDensityMap2PropertiesEXT->subsampledLoads);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubsampledCoarseReconstructionEarlyAccess", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubsampledCoarseReconstructionEarlyAccess");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFragmentDensityMap2PropertiesEXTObject, methodId, vkPhysicalDeviceFragmentDensityMap2PropertiesEXT->subsampledCoarseReconstructionEarlyAccess);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxSubsampledArrayLayers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSubsampledArrayLayers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFragmentDensityMap2PropertiesEXTObject, methodId, vkPhysicalDeviceFragmentDensityMap2PropertiesEXT->maxSubsampledArrayLayers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetSubsampledSamplers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetSubsampledSamplers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFragmentDensityMap2PropertiesEXTObject, methodId, vkPhysicalDeviceFragmentDensityMap2PropertiesEXT->maxDescriptorSetSubsampledSamplers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
