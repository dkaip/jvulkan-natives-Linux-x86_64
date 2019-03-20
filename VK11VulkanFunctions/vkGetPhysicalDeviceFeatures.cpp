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
#include <iostream>

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceFeatures
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkPhysicalDeviceFeatures;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceFeatures
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jPhysicalDeviceFeatures)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)hwjvi::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkPhysicalDeviceFeatures deviceFeatures;
    vkGetPhysicalDeviceFeatures(vkPhysicalDeviceHandle, &deviceFeatures);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass physicalDeviceFeaturesClass = env->FindClass("com/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkPhysicalDeviceFeatures");
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.robustBufferAccess);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.fullDrawIndexUint32);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.imageCubeArray);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.independentBlend);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.geometryShader);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.tessellationShader);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sampleRateShading);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.dualSrcBlend);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.logicOp);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.multiDrawIndirect);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.drawIndirectFirstInstance);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.depthClamp);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.depthBiasClamp);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.fillModeNonSolid);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.depthBounds);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.wideLines);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.largePoints);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.alphaToOne);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.multiViewport);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.samplerAnisotropy);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.textureCompressionETC2);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.textureCompressionASTC_LDR);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.textureCompressionBC);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.occlusionQueryPrecise);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.pipelineStatisticsQuery);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.vertexPipelineStoresAndAtomics);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.fragmentStoresAndAtomics);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderTessellationAndGeometryPointSize);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderImageGatherExtended);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderStorageImageExtendedFormats);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderStorageImageMultisample);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderStorageImageReadWithoutFormat);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderStorageImageWriteWithoutFormat);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderUniformBufferArrayDynamicIndexing);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderSampledImageArrayDynamicIndexing);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderStorageBufferArrayDynamicIndexing);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderStorageImageArrayDynamicIndexing);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderClipDistance);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderCullDistance);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderFloat64);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderInt64);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderInt16);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderResourceResidency);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.shaderResourceMinLod);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sparseBinding);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sparseResidencyBuffer);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sparseResidencyImage2D);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sparseResidencyImage3D);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sparseResidency2Samples);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sparseResidency4Samples);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sparseResidency8Samples);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sparseResidency16Samples);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.sparseResidencyAliased);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.variableMultisampleRate);
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

    env->CallVoidMethod(jPhysicalDeviceFeatures, methodId, deviceFeatures.inheritedQueries);
    if (env->ExceptionOccurred())
    {
        return;
    }

}

void jobjectToVkPhysicalDeviceFeatures(JNIEnv *env, jobject jPhysicalDeviceFeatures, VkPhysicalDeviceFeatures *vkPDF)
{
    jclass physicalDeviceFeaturesClass = env->GetObjectClass(jPhysicalDeviceFeatures);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ///////////////////////////////////////////////////////////////////////////

    jmethodID methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isRobustBufferAccess", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jboolean value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->robustBufferAccess = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isFullDrawIndexUint32", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->fullDrawIndexUint32 = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isImageCubeArray", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->imageCubeArray = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isIndependentBlend", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->independentBlend = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isGeometryShader", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->geometryShader = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isTessellationShader", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->tessellationShader = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSampleRateShading", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sampleRateShading = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDualSrcBlend", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->dualSrcBlend = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isLogicOp", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->logicOp = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isMultiDrawIndirect", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->multiDrawIndirect = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDrawIndirectFirstInstance", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->drawIndirectFirstInstance = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDepthClamp", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->depthClamp = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDepthBiasClamp", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->depthBiasClamp = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isFillModeNonSolid", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->fillModeNonSolid = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isDepthBounds", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->depthBounds = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isWideLines", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->wideLines = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isLargePoints", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->largePoints = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isAlphaToOne", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->alphaToOne = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isMultiViewport", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->multiViewport = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSamplerAnisotropy", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->samplerAnisotropy = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isTextureCompressionETC2", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->textureCompressionETC2 = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isTextureCompressionASTC_LDR", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->textureCompressionASTC_LDR = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isTextureCompressionBC", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->textureCompressionBC = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isOcclusionQueryPrecise", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->occlusionQueryPrecise = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isPipelineStatisticsQuery", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->pipelineStatisticsQuery = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isVertexPipelineStoresAndAtomics", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->vertexPipelineStoresAndAtomics = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isFragmentStoresAndAtomics", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->fragmentStoresAndAtomics = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderTessellationAndGeometryPointSize", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderTessellationAndGeometryPointSize = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderImageGatherExtended", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderImageGatherExtended = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageExtendedFormats", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderStorageImageExtendedFormats = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageMultisample", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderStorageImageMultisample = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageReadWithoutFormat", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderStorageImageReadWithoutFormat = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageWriteWithoutFormat", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderStorageImageWriteWithoutFormat = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderUniformBufferArrayDynamicIndexing", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderUniformBufferArrayDynamicIndexing = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderSampledImageArrayDynamicIndexing", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderSampledImageArrayDynamicIndexing = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageBufferArrayDynamicIndexing", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderStorageBufferArrayDynamicIndexing = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderStorageImageArrayDynamicIndexing", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderStorageImageArrayDynamicIndexing = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderClipDistance", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderClipDistance = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderCullDistance", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderCullDistance = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderFloat64", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderFloat64 = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderInt64", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderInt64 = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderInt16", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderInt16 = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderResourceResidency", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderResourceResidency = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isShaderResourceMinLod", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->shaderResourceMinLod = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseBinding", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sparseBinding = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidencyBuffer", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sparseResidencyBuffer = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidencyImage2D", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sparseResidencyImage2D = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidencyImage3D", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sparseResidencyImage3D = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidency2Samples", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sparseResidency2Samples = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidency4Samples", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sparseResidency4Samples = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidency8Samples", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sparseResidency8Samples = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidency16Samples", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sparseResidency16Samples = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isSparseResidencyAliased", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->sparseResidencyAliased = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isVariableMultisampleRate", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->variableMultisampleRate = value;

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDeviceFeaturesClass, "isInheritedQueries", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    value = env->CallBooleanMethod(jPhysicalDeviceFeatures, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkPDF->inheritedQueries = value;
}
