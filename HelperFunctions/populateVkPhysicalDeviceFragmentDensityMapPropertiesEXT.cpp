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
 * populateVkPhysicalDeviceFragmentDensityMapPropertiesEXT.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceFragmentDensityMapPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceFragmentDensityMapPropertiesEXTObject,
			const VkPhysicalDeviceFragmentDensityMapPropertiesEXT *vkPhysicalDeviceFragmentDensityMapPropertiesEXT,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceFragmentDensityMapPropertiesEXTClass = env->GetObjectClass(
				jVkPhysicalDeviceFragmentDensityMapPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceFragmentDensityMapPropertiesEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceFragmentDensityMapPropertiesEXTClass, "setMinFragmentDensityTexelSize", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinFragmentDensityTexelSize");
            return;
        }

	    jobject extent2DObject = createVkExtent2D(env, &(vkPhysicalDeviceFragmentDensityMapPropertiesEXT->minFragmentDensityTexelSize));
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFragmentDensityMapPropertiesEXTObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFragmentDensityMapPropertiesEXTClass, "setMaxFragmentDensityTexelSize", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFragmentDensityTexelSize");
            return;
        }

	    extent2DObject = createVkExtent2D(env, &(vkPhysicalDeviceFragmentDensityMapPropertiesEXT->maxFragmentDensityTexelSize));
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFragmentDensityMapPropertiesEXTObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFragmentDensityMapPropertiesEXTClass, "setFragmentDensityInvocations", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFragmentDensityInvocations");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFragmentDensityMapPropertiesEXTObject, methodId, vkPhysicalDeviceFragmentDensityMapPropertiesEXT->fragmentDensityInvocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFragmentDensityMapPropertiesEXTClass, "setFragmentDensityInvocations", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFragmentDensityInvocations");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFragmentDensityMapPropertiesEXTObject, methodId, vkPhysicalDeviceFragmentDensityMapPropertiesEXT->fragmentDensityInvocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}
