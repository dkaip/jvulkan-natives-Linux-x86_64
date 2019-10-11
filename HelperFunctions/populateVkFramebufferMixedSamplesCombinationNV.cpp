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
 * populateVkFramebufferMixedSamplesCombinationNV.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkFramebufferMixedSamplesCombinationNV(
			JNIEnv *env,
			jobject jVkFramebufferMixedSamplesCombinationNVObject,
			VkFramebufferMixedSamplesCombinationNV const *vkFramebufferMixedSamplesCombinationNV)
	{
        jclass theClass = env->GetObjectClass(jVkFramebufferMixedSamplesCombinationNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkFramebufferMixedSamplesCombinationNV");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject theEnum = createEnumFromValue(
        		env,
        		"com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkCoverageReductionModeNV",
				vkFramebufferMixedSamplesCombinationNV->coverageReductionMode);
        if (env->ExceptionOccurred() || theEnum == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue");
            return;
        }


        jmethodID methodId = env->GetMethodID(theClass, "setCoverageReductionMode", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkCoverageReductionModeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCoverageReductionMode");
            return;
        }

        env->CallVoidMethod(jVkFramebufferMixedSamplesCombinationNVObject, methodId, theEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        theEnum = createEnumFromValue(
        		env,
        		"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits",
				vkFramebufferMixedSamplesCombinationNV->rasterizationSamples);
        if (env->ExceptionOccurred() || theEnum == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue");
            return;
        }


        methodId = env->GetMethodID(theClass, "setRasterizationSamples", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRasterizationSamples");
            return;
        }

        env->CallVoidMethod(jVkFramebufferMixedSamplesCombinationNVObject, methodId, theEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDepthStencilSamples", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDepthStencilSamples");
            return;
        }

        jobject jflags = createVkSampleCountFlagBitsAsEnumSet(env, vkFramebufferMixedSamplesCombinationNV->depthStencilSamples);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSampleCountFlagBitsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkFramebufferMixedSamplesCombinationNVObject, methodId, jflags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setColorSamples", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setColorSamples");
            return;
        }

        jflags = createVkSampleCountFlagBitsAsEnumSet(env, vkFramebufferMixedSamplesCombinationNV->colorSamples);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSampleCountFlagBitsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkFramebufferMixedSamplesCombinationNVObject, methodId, jflags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
