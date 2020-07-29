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
 * populateVkPhysicalDeviceGroupProperties.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkPhysicalDeviceGroupProperties(
    		JNIEnv *env,
			jobject jVkPhysicalDeviceGroupPropertiesObject,
			const VkPhysicalDeviceGroupProperties *vkPhysicalDeviceGroupProperties)
    {
		if (jVkPhysicalDeviceGroupPropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkPhysicalDeviceGroupPropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceGroupPropertiesObject == nullptr");
			return;
		}

		if (vkPhysicalDeviceGroupProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkPhysicalDeviceGroupProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceGroupProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceGroupPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceGroupProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setPhysicalDevices", "(Ljava/util/Collection;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPhysicalDevices");
            return;
        }

        jobject handleCollection = createVulkanHandleCollection(
        		env,
				"com/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice",
				vkPhysicalDeviceGroupProperties->physicalDeviceCount,
				(const void **)vkPhysicalDeviceGroupProperties->physicalDevices);

        env->CallVoidMethod(jVkPhysicalDeviceGroupPropertiesObject, methodId, handleCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubsetAllocation", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubsetAllocation");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceGroupPropertiesObject, methodId, vkPhysicalDeviceGroupProperties->subsetAllocation);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        return;
    }
}
