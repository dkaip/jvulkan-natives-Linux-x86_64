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
 * populateVkPhysicalDeviceConservativeRasterizationPropertiesEXT.cpp
 *
 *  Created on: May 13, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceConservativeRasterizationPropertiesEXT(
		JNIEnv *env,
		jobject jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject,
		const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* vkPhysicalDeviceConservativeRasterizationPropertiesEXT,
		std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass = env->GetObjectClass(
				jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceConservativeRasterizationPropertiesEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass, "setPrimitiveOverestimationSize", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPrimitiveOverestimationSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceConservativeRasterizationPropertiesEXT->primitiveOverestimationSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass, "setMaxExtraPrimitiveOverestimationSize", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxExtraPrimitiveOverestimationSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceConservativeRasterizationPropertiesEXT->maxExtraPrimitiveOverestimationSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass, "setExtraPrimitiveOverestimationSizeGranularity", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExtraPrimitiveOverestimationSizeGranularity");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceConservativeRasterizationPropertiesEXT->extraPrimitiveOverestimationSizeGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass, "setPrimitiveUnderestimation", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPrimitiveUnderestimation");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceConservativeRasterizationPropertiesEXT->primitiveUnderestimation);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass, "setConservativePointAndLineRasterization", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setConservativePointAndLineRasterization");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceConservativeRasterizationPropertiesEXT->conservativePointAndLineRasterization);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass, "setDegenerateTrianglesRasterized", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDegenerateTrianglesRasterized");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceConservativeRasterizationPropertiesEXT->degenerateTrianglesRasterized);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass, "setDegenerateLinesRasterized", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDegenerateLinesRasterized");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceConservativeRasterizationPropertiesEXT->degenerateLinesRasterized);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass, "setFullyCoveredFragmentShaderInputVariable", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFullyCoveredFragmentShaderInputVariable");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceConservativeRasterizationPropertiesEXT->fullyCoveredFragmentShaderInputVariable);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceConservativeRasterizationPropertiesEXTClass, "setConservativeRasterizationPostDepthCoverage", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setConservativeRasterizationPostDepthCoverage");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceConservativeRasterizationPropertiesEXT->conservativeRasterizationPostDepthCoverage);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
