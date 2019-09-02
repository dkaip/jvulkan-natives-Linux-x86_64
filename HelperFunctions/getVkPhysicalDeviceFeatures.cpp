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
 * getVkPhysicalDeviceFeatures.cpp
 *
 *  Created on: May 16, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	static const char *booleanMethodError = "Error calling CallBooleanMethod";

    void getVkPhysicalDeviceFeatures(
            JNIEnv *env,
            const jobject jgetVkPhysicalDeviceFeaturesObject,
			VkPhysicalDeviceFeatures *vkPhysicalDeviceFeatures,
            std::vector<void *> *memoryToFree)
    {
		jclass physicalDeviceFeaturesClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceFeatures");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceFeatures");
	        return;
	    }

	    ///////////////////////////////////////////////////////////////////////////
	    jmethodID methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isRobustBufferAccess", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isRobustBufferAccess");
	        return;
	    }

	    jboolean theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->robustBufferAccess = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isFullDrawIndexUint32", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isFullDrawIndexUint32");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->fullDrawIndexUint32 = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isImageCubeArray", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isImageCubeArray");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->imageCubeArray = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isIndependentBlend", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isIndependentBlend");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->independentBlend = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isGeometryShader", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isGeometryShader");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->geometryShader = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isTessellationShader", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isTessellationShader");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->tessellationShader = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSampleRateShading", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSampleRateShading");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sampleRateShading = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDualSrcBlend", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isDualSrcBlend");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->dualSrcBlend = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isLogicOp", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isLogicOp");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->logicOp = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isMultiDrawIndirect", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isMultiDrawIndirect");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->multiDrawIndirect = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDrawIndirectFirstInstance", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isDrawIndirectFirstInstance");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->drawIndirectFirstInstance = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDepthClamp", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isDepthClamp");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->depthClamp = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDepthBiasClamp", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isDepthBiasClamp");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->depthBiasClamp = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isFillModeNonSolid", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isFillModeNonSolid");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->fillModeNonSolid = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDepthBounds", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isDepthBounds");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->depthBounds = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isWideLines", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isWideLines");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->wideLines = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isLargePoints", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isLargePoints");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->largePoints = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isAlphaToOne", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isAlphaToOne");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->alphaToOne = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isMultiViewport", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isMultiViewport");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->multiViewport = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSamplerAnisotropy", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSamplerAnisotropy");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->samplerAnisotropy = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isTextureCompressionETC2", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isTextureCompressionETC2");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->textureCompressionETC2 = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isTextureCompressionASTC_LDR", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isTextureCompressionASTC_LDR");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->textureCompressionASTC_LDR = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isTextureCompressionBC", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isTextureCompressionBC");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->textureCompressionBC = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isOcclusionQueryPrecise", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isOcclusionQueryPrecise");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->occlusionQueryPrecise = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isPipelineStatisticsQuery", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isPipelineStatisticsQuery");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->pipelineStatisticsQuery = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isVertexPipelineStoresAndAtomics", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isVertexPipelineStoresAndAtomics");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->vertexPipelineStoresAndAtomics = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isFragmentStoresAndAtomics", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isFragmentStoresAndAtomics");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->fragmentStoresAndAtomics = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderTessellationAndGeometryPointSize", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderTessellationAndGeometryPointSize");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderTessellationAndGeometryPointSize = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderImageGatherExtended", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderImageGatherExtended");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderImageGatherExtended = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageExtendedFormats", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderStorageImageExtendedFormats");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderStorageImageExtendedFormats = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageMultisample", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderStorageImageMultisample");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderStorageImageMultisample = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageReadWithoutFormat", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderStorageImageReadWithoutFormat");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderStorageImageReadWithoutFormat = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageWriteWithoutFormat", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderStorageImageWriteWithoutFormat");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderStorageImageWriteWithoutFormat = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderUniformBufferArrayDynamicIndexing", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderUniformBufferArrayDynamicIndexing");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderUniformBufferArrayDynamicIndexing = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderSampledImageArrayDynamicIndexing", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderSampledImageArrayDynamicIndexing");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderSampledImageArrayDynamicIndexing = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageBufferArrayDynamicIndexing", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderStorageBufferArrayDynamicIndexing");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderStorageBufferArrayDynamicIndexing = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageArrayDynamicIndexing", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderStorageImageArrayDynamicIndexing");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderStorageImageArrayDynamicIndexing = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderClipDistance", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderClipDistance");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderClipDistance = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderCullDistance", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderCullDistance");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderCullDistance = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderFloat64", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderFloat64");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderFloat64 = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderInt64", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderInt64");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderInt64 = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderInt16", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderInt16");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderInt16 = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderResourceResidency", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderResourceResidency");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderResourceResidency = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderResourceMinLod", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isShaderResourceMinLod");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->shaderResourceMinLod = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseBinding", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSparseBinding");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sparseBinding = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidencyBuffer", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSparseResidencyBuffer");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sparseResidencyBuffer = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidencyImage2D", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSparseResidencyImage2D");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sparseResidencyImage2D = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidencyImage3D", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSparseResidencyImage3D");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sparseResidencyImage3D = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidency2Samples", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSparseResidency2Samples");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sparseResidency2Samples = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidency4Samples", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSparseResidency4Samples");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sparseResidency4Samples = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidency8Samples", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSparseResidency8Samples");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sparseResidency8Samples = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidency16Samples", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSparseResidency16Samples");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sparseResidency16Samples = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidencyAliased", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isSparseResidencyAliased");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->sparseResidencyAliased = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isVariableMultisampleRate", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isVariableMultisampleRate");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->variableMultisampleRate = theValue;

	    ///////////////////////////////////////////////////////////////////////////
	    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isInheritedQueries", "()Z");
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", "Could not find method id isInheritedQueries");
	        return;
	    }

	    theValue = env->CallBooleanMethod(jgetVkPhysicalDeviceFeaturesObject, methodId);
	    if (env->ExceptionOccurred())
	    {
	    	LOGERROR(env, "%s", booleanMethodError);
	        return;
	    }

	    vkPhysicalDeviceFeatures->inheritedQueries = theValue;

    }
}
