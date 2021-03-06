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
 * populateVkPhysicalDeviceImageViewImageFormatInfoEXT.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceImageViewImageFormatInfoEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceImageViewImageFormatInfoEXTObject,
			const VkPhysicalDeviceImageViewImageFormatInfoEXT *vkPhysicalDeviceImageViewImageFormatInfoEXT,
			std::vector<void *> *memoryToFree)
	{
		if (jVkPhysicalDeviceImageViewImageFormatInfoEXTObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkPhysicalDeviceImageViewImageFormatInfoEXTObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceImageViewImageFormatInfoEXTObject == nullptr");
			return;
		}

		if (vkPhysicalDeviceImageViewImageFormatInfoEXT == nullptr)
		{
			LOGERROR(env, "%s", "vkPhysicalDeviceImageViewImageFormatInfoEXT == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceImageViewImageFormatInfoEXT == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceImageViewImageFormatInfoEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceImageViewImageFormatInfoEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jobject jimageViewTypeObject = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageViewType",
				vkPhysicalDeviceImageViewImageFormatInfoEXT->imageViewType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setImageViewType", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageViewType;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImageViewType");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceImageViewImageFormatInfoEXTObject, methodId, jimageViewTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
