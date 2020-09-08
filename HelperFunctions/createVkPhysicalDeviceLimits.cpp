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
 * createVkPhysicalDeviceLimits.cpp
 *
 *  Created on: Sep 7, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkPhysicalDeviceLimits(JNIEnv *env, const VkPhysicalDeviceLimits *deviceLimits)
	{
		if (deviceLimits == nullptr)
		{
			LOGERROR(env, "%s", "deviceLimits == nullptr");
			return nullptr;
		}

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceLimits",
				&theClass,
				&theObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor.");
			return nullptr;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setMaxImageDimension1D", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageDimension1D");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxImageDimension1D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxImageDimension2D", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageDimension2D");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxImageDimension2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxImageDimension3D", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageDimension3D");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxImageDimension3D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxImageDimensionCube", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageDimensionCube");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxImageDimensionCube);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxImageArrayLayers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageArrayLayers");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxImageArrayLayers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTexelBufferElements", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTexelBufferElements");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTexelBufferElements);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxUniformBufferRange", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxUniformBufferRange");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxUniformBufferRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxStorageBufferRange", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxStorageBufferRange");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxStorageBufferRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPushConstantsSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPushConstantsSize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxPushConstantsSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxMemoryAllocationCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMemoryAllocationCount");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxMemoryAllocationCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxSamplerAllocationCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSamplerAllocationCount");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxSamplerAllocationCount);
        if (env->ExceptionOccurred())
        {
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setBufferImageGranularity", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setBufferImageGranularity");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->bufferImageGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSparseAddressSpaceSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSparseAddressSpaceSize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->sparseAddressSpaceSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxBoundDescriptorSets", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxBoundDescriptorSets");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxBoundDescriptorSets);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorSamplers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorSamplers");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxPerStageDescriptorSamplers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorUniformBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorUniformBuffers");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxPerStageDescriptorUniformBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorStorageBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorStorageBuffers");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxPerStageDescriptorStorageBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorSampledImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorSampledImages");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxPerStageDescriptorSampledImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorStorageImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorStorageImages");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxPerStageDescriptorStorageImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorInputAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorInputAttachments");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxPerStageDescriptorInputAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageResources", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageResources");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxPerStageResources);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetSamplers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetSamplers");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDescriptorSetSamplers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUniformBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUniformBuffers");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDescriptorSetUniformBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUniformBuffersDynamic", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUniformBuffersDynamic");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDescriptorSetUniformBuffersDynamic);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetStorageBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetStorageBuffers");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDescriptorSetStorageBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetStorageBuffersDynamic", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetStorageBuffersDynamic");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDescriptorSetStorageBuffersDynamic);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetSampledImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetSampledImages");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDescriptorSetSampledImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetStorageImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetStorageImages");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDescriptorSetStorageImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetInputAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetInputAttachments");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDescriptorSetInputAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxVertexInputAttributes", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexInputAttributes");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxVertexInputAttributes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxVertexInputBindings", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexInputBindings");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxVertexInputBindings);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxVertexInputAttributeOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexInputAttributeOffset");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxVertexInputAttributeOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxVertexInputBindingStride", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexInputBindingStride");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxVertexInputBindingStride);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxVertexOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxVertexOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTessellationGenerationLevel", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationGenerationLevel");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTessellationGenerationLevel);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTessellationPatchSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationPatchSize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTessellationPatchSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTessellationControlPerVertexInputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationControlPerVertexInputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTessellationControlPerVertexInputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTessellationControlPerVertexOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationControlPerVertexOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTessellationControlPerVertexOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTessellationControlPerPatchOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationControlPerPatchOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTessellationControlPerPatchOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTessellationControlTotalOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationControlTotalOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTessellationControlTotalOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTessellationEvaluationInputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationEvaluationInputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTessellationEvaluationInputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTessellationEvaluationOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationEvaluationOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTessellationEvaluationOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxGeometryShaderInvocations", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryShaderInvocations");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxGeometryShaderInvocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxGeometryInputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryInputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxGeometryInputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxGeometryOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxGeometryOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxGeometryOutputVertices", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryOutputVertices");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxGeometryOutputVertices);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxGeometryTotalOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryTotalOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxGeometryTotalOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxFragmentInputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFragmentInputComponents");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxFragmentInputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxFragmentOutputAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFragmentOutputAttachments");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxFragmentOutputAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxFragmentDualSrcAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFragmentDualSrcAttachments");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxFragmentDualSrcAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxFragmentCombinedOutputResources", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFragmentCombinedOutputResources");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxFragmentCombinedOutputResources);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxComputeSharedMemorySize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxComputeSharedMemorySize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxComputeSharedMemorySize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxComputeWorkGroupCount", "([I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxComputeWorkGroupCount");
            return nullptr;
        }

        jintArray maxComputeWorkGroupCount = env->NewIntArray(sizeof(deviceLimits->maxComputeWorkGroupCount)/sizeof(jint));
        if (maxComputeWorkGroupCount == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for MaxComputeWorkGroupCount");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, maxComputeWorkGroupCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        env->SetIntArrayRegion(maxComputeWorkGroupCount, 0, sizeof(deviceLimits->maxComputeWorkGroupCount)/sizeof(jint), (const jint *)deviceLimits->maxComputeWorkGroupCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetIntArrayRegion");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxComputeWorkGroupInvocations", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxComputeWorkGroupInvocations");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxComputeWorkGroupInvocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxComputeWorkGroupSize", "([I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxComputeWorkGroupSize");
            return nullptr;
        }

        jintArray maxComputeWorkGroupSize = env->NewIntArray(sizeof(deviceLimits->maxComputeWorkGroupSize)/sizeof(jint));
        if (maxComputeWorkGroupSize == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for maxComputeWorkGroupSize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, maxComputeWorkGroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        env->SetIntArrayRegion(maxComputeWorkGroupSize, 0, sizeof(deviceLimits->maxComputeWorkGroupSize)/sizeof(jint), (const jint *)deviceLimits->maxComputeWorkGroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetIntArrayRegion");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubPixelPrecisionBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubPixelPrecisionBits");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->subPixelPrecisionBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubTexelPrecisionBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubTexelPrecisionBits");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->subTexelPrecisionBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMipmapPrecisionBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMipmapPrecisionBits");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->mipmapPrecisionBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDrawIndexedIndexValue", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDrawIndexedIndexValue");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDrawIndexedIndexValue);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDrawIndirectCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDrawIndirectCount");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxDrawIndirectCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxSamplerLodBias", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSamplerLodBias");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxSamplerLodBias);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxSamplerAnisotropy", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSamplerAnisotropy");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxSamplerAnisotropy);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxViewports", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxViewports");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxViewports);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxViewportDimensions", "([I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxViewportDimensions");
            return nullptr;
        }

        jintArray maxViewportDimensions = env->NewIntArray(sizeof(deviceLimits->maxViewportDimensions)/sizeof(jint));
        if (maxViewportDimensions == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for maxViewportDimensions");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, maxViewportDimensions);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        env->SetIntArrayRegion(maxViewportDimensions, 0, sizeof(deviceLimits->maxViewportDimensions)/sizeof(jint), (const jint *)deviceLimits->maxViewportDimensions);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetIntArrayRegion");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setViewportBoundsRange", "([F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setViewportBoundsRange");
            return nullptr;
        }

        jfloatArray viewportBoundsRange = env->NewFloatArray(sizeof(deviceLimits->viewportBoundsRange)/sizeof(jfloat));
        if (viewportBoundsRange == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for viewportBoundsRange");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, viewportBoundsRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        env->SetFloatArrayRegion(viewportBoundsRange, 0, sizeof(deviceLimits->viewportBoundsRange)/sizeof(jfloat), (const jfloat *)deviceLimits->viewportBoundsRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetFloatArrayRegion");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setViewportSubPixelBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setViewportSubPixelBits");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->viewportSubPixelBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinMemoryMapAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinMemoryMapAlignment");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->minMemoryMapAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinTexelBufferOffsetAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinTexelBufferOffsetAlignment");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->minTexelBufferOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinUniformBufferOffsetAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinUniformBufferOffsetAlignment");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->minUniformBufferOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinStorageBufferOffsetAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinStorageBufferOffsetAlignment");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->minStorageBufferOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinTexelOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinTexelOffset");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->minTexelOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTexelOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTexelOffset");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTexelOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinTexelGatherOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinTexelGatherOffset");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->minTexelGatherOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTexelGatherOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTexelGatherOffset");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxTexelGatherOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMinInterpolationOffset", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinInterpolationOffset");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->minInterpolationOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxInterpolationOffset", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxInterpolationOffset");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxInterpolationOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubPixelInterpolationOffsetBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubPixelInterpolationOffsetBits");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->subPixelInterpolationOffsetBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxFramebufferWidth", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFramebufferWidth");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxFramebufferWidth);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxFramebufferHeight", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFramebufferHeight");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxFramebufferHeight);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxFramebufferLayers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFramebufferLayers");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxFramebufferLayers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxFramebufferLayers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFramebufferLayers");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxFramebufferLayers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setFramebufferColorSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFramebufferColorSampleCounts");
            return nullptr;
        }

        jobject vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, deviceLimits->sampledImageColorSampleCounts);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setFramebufferDepthSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFramebufferDepthSampleCounts");
            return nullptr;
        }

        vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, deviceLimits->framebufferDepthSampleCounts);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setFramebufferStencilSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFramebufferStencilSampleCounts");
            return nullptr;
        }

        vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, deviceLimits->framebufferStencilSampleCounts);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////

        methodId = env->GetMethodID(theClass, "setFramebufferNoAttachmentsSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFramebufferNoAttachmentsSampleCounts");
            return nullptr;
        }

        vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, deviceLimits->framebufferNoAttachmentsSampleCounts);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxColorAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxColorAttachments");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxColorAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSampledImageColorSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSampledImageColorSampleCounts");
            return nullptr;
        }

        vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, deviceLimits->sampledImageColorSampleCounts);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSampledImageIntegerSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSampledImageIntegerSampleCounts");
            return nullptr;
        }

        vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, deviceLimits->sampledImageIntegerSampleCounts);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSampledImageDepthSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSampledImageDepthSampleCounts");
            return nullptr;
        }

        vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, deviceLimits->sampledImageDepthSampleCounts);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSampledImageStencilSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSampledImageStencilSampleCounts");
            return nullptr;
        }

        vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, deviceLimits->sampledImageStencilSampleCounts);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setStorageImageSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setStorageImageSampleCounts");
            return nullptr;
        }

        vkSampleCountFlagBitsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, deviceLimits->storageImageSampleCounts);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        if (vkSampleCountFlagBitsEnumSet == nullptr)
        {
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxSampleMaskWords", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSampleMaskWords");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxSampleMaskWords);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setTimestampComputeAndGraphics", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTimestampComputeAndGraphics");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->timestampComputeAndGraphics);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setTimestampPeriod", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTimestampPeriod");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->timestampPeriod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxClipDistances", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxClipDistances");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxClipDistances);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxCullDistances", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxCullDistances");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxCullDistances);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxCombinedClipAndCullDistances", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxCombinedClipAndCullDistances");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->maxCombinedClipAndCullDistances);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDiscreteQueuePriorities", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDiscreteQueuePriorities");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->discreteQueuePriorities);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setPointSizeRange", "([F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPointSizeRange");
            return nullptr;
        }

        jfloatArray pointSizeRange = env->NewFloatArray(sizeof(deviceLimits->pointSizeRange)/sizeof(jfloat));
        if (pointSizeRange == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for pointSizeRange");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, pointSizeRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        env->SetFloatArrayRegion(pointSizeRange, 0, sizeof(deviceLimits->pointSizeRange)/sizeof(jfloat), (const jfloat *)deviceLimits->pointSizeRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetFloatArrayRegion");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setLineWidthRange", "([F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setLineWidthRange");
            return nullptr;
        }

        jfloatArray lineWidthRange = env->NewFloatArray(sizeof(deviceLimits->lineWidthRange)/sizeof(jfloat));
        if (lineWidthRange == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for lineWidthRange");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, lineWidthRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        env->SetFloatArrayRegion(lineWidthRange, 0, sizeof(deviceLimits->lineWidthRange)/sizeof(jfloat), (const jfloat *)deviceLimits->lineWidthRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetFloatArrayRegion");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setPointSizeGranularity", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPointSizeGranularity");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->pointSizeGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setLineWidthGranularity", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setLineWidthGranularity");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->lineWidthGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setStrictLines", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setStrictLines");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->strictLines);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setStandardSampleLocations", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setStandardSampleLocations");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->standardSampleLocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setOptimalBufferCopyOffsetAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setOptimalBufferCopyOffsetAlignment");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->optimalBufferCopyOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setOptimalBufferCopyRowPitchAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setOptimalBufferCopyRowPitchAlignment");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->optimalBufferCopyRowPitchAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setNonCoherentAtomSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setNonCoherentAtomSize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, deviceLimits->nonCoherentAtomSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
