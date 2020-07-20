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
 * populateVkPhysicalDevicePointClippingProperties.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkPhysicalDevicePointClippingProperties(
		JNIEnv *env,
		jobject jVkPhysicalDevicePointClippingPropertiesObject,
		const VkPhysicalDevicePointClippingProperties *vkPhysicalDevicePointClippingProperties,
		std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDevicePointClippingPropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDevicePointClippingProperties");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jclass vkPointClippingBehaviorClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Enums/VkPointClippingBehavior");
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPointClippingBehavior");
            return;
        }

        jmethodID methodId = env->GetStaticMethodID(vkPointClippingBehaviorClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPointClippingBehavior;");
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Could not find static method id fromValue");
            return;
        }

        jobject vkPointClippingBehaviorEnum = env->CallStaticObjectMethod(vkPointClippingBehaviorClass, methodId, vkPhysicalDevicePointClippingProperties->pointClippingBehavior);

        methodId = env->GetMethodID(theClass, "setPointClippingBehavior", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPointClippingBehavior;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setPointClippingBehavior");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePointClippingPropertiesObject, methodId, vkPointClippingBehaviorEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setPointClippingBehavior");
            return;
        }

	}
}
