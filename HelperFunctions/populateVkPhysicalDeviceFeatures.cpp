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
 * populateVkPhysicalvkPhysicalDeviceFeatures->cpp
 *
 *  Created on: May 16, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkPhysicalDeviceFeatures(
		JNIEnv *env,
		jobject jVkPhysicalDeviceFeaturesObject,
		const VkPhysicalDeviceFeatures *vkPhysicalDeviceFeatures,
		std::vector<void *> *memoryToFree)
	{
		jclass physicalDeviceFeaturesClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceFeatures");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    jmethodID methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setRobustBufferAccess", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->robustBufferAccess);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setFullDrawIndexUint32", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->fullDrawIndexUint32);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setImageCubeArray", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->imageCubeArray);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setIndependentBlend", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->independentBlend);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setGeometryShader", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->geometryShader);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setTessellationShader", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->tessellationShader);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSampleRateShading", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sampleRateShading);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setDualSrcBlend", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->dualSrcBlend);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setLogicOp", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->logicOp);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setMultiDrawIndirect", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->multiDrawIndirect);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setDrawIndirectFirstInstance", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->drawIndirectFirstInstance);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setDepthClamp", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->depthClamp);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setDepthBiasClamp", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->depthBiasClamp);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setFillModeNonSolid", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->fillModeNonSolid);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setDepthBounds", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->depthBounds);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setWideLines", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->wideLines);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setLargePoints", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->largePoints);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setAlphaToOne", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->alphaToOne);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setMultiViewport", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->multiViewport);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSamplerAnisotropy", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->samplerAnisotropy);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setTextureCompressionETC2", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->textureCompressionETC2);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setTextureCompressionASTC_LDR", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->textureCompressionASTC_LDR);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setTextureCompressionBC", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->textureCompressionBC);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setOcclusionQueryPrecise", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->occlusionQueryPrecise);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setPipelineStatisticsQuery", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->pipelineStatisticsQuery);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setVertexPipelineStoresAndAtomics", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->vertexPipelineStoresAndAtomics);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setFragmentStoresAndAtomics", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->fragmentStoresAndAtomics);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderTessellationAndGeometryPointSize", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderTessellationAndGeometryPointSize);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderImageGatherExtended", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderImageGatherExtended);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderStorageImageExtendedFormats", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderStorageImageExtendedFormats);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderStorageImageMultisample", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderStorageImageMultisample);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderStorageImageReadWithoutFormat", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderStorageImageReadWithoutFormat);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderStorageImageWriteWithoutFormat", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderStorageImageWriteWithoutFormat);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderUniformBufferArrayDynamicIndexing", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderUniformBufferArrayDynamicIndexing);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderSampledImageArrayDynamicIndexing", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderSampledImageArrayDynamicIndexing);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderStorageBufferArrayDynamicIndexing", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderStorageBufferArrayDynamicIndexing);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderStorageImageArrayDynamicIndexing", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderStorageImageArrayDynamicIndexing);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderClipDistance", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderClipDistance);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderCullDistance", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderCullDistance);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderFloat64", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderFloat64);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderInt64", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderInt64);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderInt16", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderInt16);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderResourceResidency", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderResourceResidency);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setShaderResourceMinLod", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->shaderResourceMinLod);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSparseBinding", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sparseBinding);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSparseResidencyBuffer", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sparseResidencyBuffer);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSparseResidencyImage2D", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sparseResidencyImage2D);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSparseResidencyImage3D", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sparseResidencyImage3D);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSparseResidency2Samples", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sparseResidency2Samples);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSparseResidency4Samples", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sparseResidency4Samples);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSparseResidency8Samples", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sparseResidency8Samples);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSparseResidency16Samples", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sparseResidency16Samples);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setSparseResidencyAliased", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->sparseResidencyAliased);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setVariableMultisampleRate", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->variableMultisampleRate);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "setInheritedQueries", "(Z)V");
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }

	    env->CallVoidMethod(jVkPhysicalDeviceFeaturesObject, methodId, vkPhysicalDeviceFeatures->inheritedQueries);
	    if (env->ExceptionOccurred())
	    {
	        return;
	    }
	}
}
