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
 * populateVkPhysicalDeviceShadingRateImagePropertiesNV.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceShadingRateImagePropertiesNV(
			JNIEnv *env,
			jobject jVkPhysicalDeviceShadingRateImagePropertiesNVObject,
			const VkPhysicalDeviceShadingRateImagePropertiesNV *vkPhysicalDeviceShadingRateImagePropertiesNV,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDeviceShadingRateImagePropertiesNVObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceShadingRateImagePropertiesNV");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setShadingRateTexelSize", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShadingRateTexelSize");
            return;
        }

	    jobject extent2DObject = createVkExtent2D(env, &(vkPhysicalDeviceShadingRateImagePropertiesNV->shadingRateTexelSize));
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShadingRateImagePropertiesNVObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShadingRatePaletteSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShadingRatePaletteSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShadingRateImagePropertiesNVObject, methodId, vkPhysicalDeviceShadingRateImagePropertiesNV->shadingRatePaletteSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShadingRateMaxCoarseSamples", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShadingRateMaxCoarseSamples");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceShadingRateImagePropertiesNVObject, methodId, vkPhysicalDeviceShadingRateImagePropertiesNV->shadingRateMaxCoarseSamples);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
