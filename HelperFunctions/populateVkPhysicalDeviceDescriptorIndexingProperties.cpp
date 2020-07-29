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
 * populateVkPhysicalDeviceDescriptorIndexingProperties.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceDescriptorIndexingProperties(
		JNIEnv *env,
		jobject jVkPhysicalDeviceDescriptorIndexingPropertiesObject,
		const VkPhysicalDeviceDescriptorIndexingProperties *vkPhysicalDeviceDescriptorIndexingProperties,
		std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceDescriptorIndexingPropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceDescriptorIndexingPropertiesObject.");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setMaxUpdateAfterBindDescriptorsInAllPools", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxUpdateAfterBindDescriptorsInAllPools");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxUpdateAfterBindDescriptorsInAllPools);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderUniformBufferArrayNonUniformIndexingNative", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderUniformBufferArrayNonUniformIndexingNative");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->shaderUniformBufferArrayNonUniformIndexingNative);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderSampledImageArrayNonUniformIndexingNative", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSampledImageArrayNonUniformIndexingNative");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->shaderSampledImageArrayNonUniformIndexingNative);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderStorageBufferArrayNonUniformIndexingNative", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderStorageBufferArrayNonUniformIndexingNative");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->shaderStorageBufferArrayNonUniformIndexingNative);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderStorageImageArrayNonUniformIndexingNative", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderStorageImageArrayNonUniformIndexingNative");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->shaderStorageImageArrayNonUniformIndexingNative);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderInputAttachmentArrayNonUniformIndexingNative", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderInputAttachmentArrayNonUniformIndexingNative");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->shaderInputAttachmentArrayNonUniformIndexingNative);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setRobustBufferAccessUpdateAfterBind", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRobustBufferAccessUpdateAfterBind");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->robustBufferAccessUpdateAfterBind);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setQuadDivergentImplicitLod", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setQuadDivergentImplicitLod");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->quadDivergentImplicitLod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorUpdateAfterBindSamplers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "setMaxPerStageDescriptorUpdateAfterBindSamplers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxPerStageDescriptorUpdateAfterBindSamplers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorUpdateAfterBindUniformBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorUpdateAfterBindUniformBuffers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxPerStageDescriptorUpdateAfterBindUniformBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorUpdateAfterBindStorageBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorUpdateAfterBindStorageBuffers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxPerStageDescriptorUpdateAfterBindStorageBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorUpdateAfterBindSampledImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorUpdateAfterBindSampledImages");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxPerStageDescriptorUpdateAfterBindSampledImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorUpdateAfterBindStorageImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorUpdateAfterBindStorageImages");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxPerStageDescriptorUpdateAfterBindStorageImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorUpdateAfterBindInputAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorUpdateAfterBindInputAttachments");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxPerStageDescriptorUpdateAfterBindInputAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageUpdateAfterBindResources", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageUpdateAfterBindResources");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxPerStageUpdateAfterBindResources);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUpdateAfterBindSamplers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUpdateAfterBindSamplers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxDescriptorSetUpdateAfterBindSamplers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUpdateAfterBindUniformBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUpdateAfterBindUniformBuffers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxDescriptorSetUpdateAfterBindUniformBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUpdateAfterBindUniformBuffersDynamic", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUpdateAfterBindUniformBuffersDynamic");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUpdateAfterBindStorageBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUpdateAfterBindStorageBuffers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxDescriptorSetUpdateAfterBindStorageBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUpdateAfterBindStorageBuffersDynamic", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "setMaxDescriptorSetUpdateAfterBindStorageBuffersDynamic");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUpdateAfterBindSampledImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUpdateAfterBindSampledImages");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxDescriptorSetUpdateAfterBindSampledImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUpdateAfterBindStorageImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUpdateAfterBindStorageImages");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxDescriptorSetUpdateAfterBindStorageImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUpdateAfterBindInputAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUpdateAfterBindInputAttachments");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDescriptorIndexingPropertiesObject, methodId, vkPhysicalDeviceDescriptorIndexingProperties->maxDescriptorSetUpdateAfterBindInputAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}
