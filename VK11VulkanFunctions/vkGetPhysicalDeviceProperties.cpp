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
#include <cstring>

using namespace std;

//#include <vulkan/vulkan.h>
//#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

static jobject getdeviceLimits(JNIEnv *env, VkPhysicalDeviceLimits *deviceLimits);
static jobject getVkSampleCountFlagBits(JNIEnv *env, VkSampleCountFlags vkSampleCountFlags);
static jobject getSparseProperties(JNIEnv *env, VkPhysicalDeviceSparseProperties *sparseProperties);

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceProperties;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jPhysicalDeviceProperties)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

//    jclass vkInstanceClass = env->GetObjectClass(jVkPhysicalDevice);
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
//    jmethodID methodId = env->GetMethodID(vkInstanceClass, "getHandle", "()J");
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
//    jlong physicalDeviceHandle = env->CallLongMethod(jVkPhysicalDevice, methodId);
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
    VkPhysicalDeviceProperties deviceProperties;
    vkGetPhysicalDeviceProperties(vkPhysicalDeviceHandle, &deviceProperties);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass physicalDevicePropertiesClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceProperties");
    if (env->ExceptionOccurred())
    {
        return;
    }

    ///////////////////////////////////////////////////////////////////////////

    jmethodID methodId = env->GetMethodID(physicalDevicePropertiesClass, "setApiVersion", "(I)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jPhysicalDeviceProperties, methodId, deviceProperties.apiVersion);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDevicePropertiesClass, "setDriverVersion", "(I)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jPhysicalDeviceProperties, methodId, deviceProperties.driverVersion);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDevicePropertiesClass, "setVendorID", "(I)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jPhysicalDeviceProperties, methodId, deviceProperties.vendorID);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDevicePropertiesClass, "setDeviceID", "(I)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jPhysicalDeviceProperties, methodId, deviceProperties.deviceID);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ///////////////////////////////////////////////////////////////////////////

    char deviceTypeName[64];
    deviceTypeName[0] = '\0';

    switch(deviceProperties.deviceType)
    {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER:
            (void)strcpy(deviceTypeName, "VK_PHYSICAL_DEVICE_TYPE_OTHER");
            break;
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
            (void)strcpy(deviceTypeName, "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU");
            break;
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            (void)strcpy(deviceTypeName, "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU");
            break;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            (void)strcpy(deviceTypeName, "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU");
            break;
        case VK_PHYSICAL_DEVICE_TYPE_CPU:
            (void)strcpy(deviceTypeName, "VK_PHYSICAL_DEVICE_TYPE_CPU");
            break;
        default:
            cout << "ERROR: Unhandled deviceProperties.deviceType of " << deviceProperties.deviceType << endl;
            return;
    }

    jclass enumClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPhysicalDeviceType");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jfieldID fieldId = env->GetStaticFieldID(enumClass, deviceTypeName, "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPhysicalDeviceType;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    methodId = env->GetMethodID(physicalDevicePropertiesClass, "setDeviceType", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPhysicalDeviceType;)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jPhysicalDeviceProperties, methodId, theEnum);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDevicePropertiesClass, "setDeviceName", "(Ljava/lang/String;)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jstring deviceNameString = env->NewStringUTF(deviceProperties.deviceName);

    env->CallVoidMethod(jPhysicalDeviceProperties, methodId, deviceNameString);
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->DeleteLocalRef(deviceNameString);

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDevicePropertiesClass, "setPipelineCacheUUID", "([B)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jbyteArray uuid = env->NewByteArray(sizeof(deviceProperties.pipelineCacheUUID));
    if (uuid == 0)
    {
        cout << "ERROR: out of memory trying to allocate array for pipelineCacheUUID" << endl;
        return;
    }

    env->SetByteArrayRegion(uuid, 0, sizeof(deviceProperties.pipelineCacheUUID), (const jbyte *)deviceProperties.pipelineCacheUUID);
    env->CallVoidMethod(jPhysicalDeviceProperties, methodId, uuid);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDevicePropertiesClass, "setLimits", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceLimits;)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject deviceLimitsObject = getdeviceLimits(env, &deviceProperties.limits);
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jPhysicalDeviceProperties, methodId, deviceLimitsObject);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(physicalDevicePropertiesClass, "setSparseProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceSparseProperties;)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject sparsePropertiesObject = getSparseProperties(env, &deviceProperties.sparseProperties);
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jPhysicalDeviceProperties, methodId, sparsePropertiesObject);
    if (env->ExceptionOccurred())
    {
        return;
    }
}

static jobject getSparseProperties(JNIEnv *env, VkPhysicalDeviceSparseProperties *sparseProperties)
{
    jclass sparsePropertiesClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceSparseProperties");
    jmethodID constructorMethod = env->GetMethodID(sparsePropertiesClass, "<init>", "()V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jobject sparsePropertiesObject = env->NewObject(sparsePropertiesClass, constructorMethod);

    ///////////////////////////////////////////////////////////////////////////

    jmethodID methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyStandard2DBlockShape", "(Z)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyStandard2DBlockShape);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyStandard2DMultisampleBlockShape", "(Z)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyStandard2DMultisampleBlockShape);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyStandard3DBlockShape", "(Z)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyStandard3DBlockShape);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyAlignedMipSize", "(Z)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyAlignedMipSize);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyNonResidentStrict", "(Z)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyNonResidentStrict);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    return sparsePropertiesObject;
}

static jobject getdeviceLimits(JNIEnv *env, VkPhysicalDeviceLimits *deviceLimits)
{
    jclass deviceLimitsClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceLimits");
    jmethodID constructorMethod = env->GetMethodID(deviceLimitsClass, "<init>", "()V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jobject deviceLimitsObject = env->NewObject(deviceLimitsClass, constructorMethod);

    ///////////////////////////////////////////////////////////////////////////

    jmethodID methodId = env->GetMethodID(deviceLimitsClass, "setMaxImageDimension1D", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageDimension1D);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxImageDimension2D", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageDimension2D);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxImageDimension3D", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageDimension3D);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxImageDimensionCube", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageDimensionCube);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxImageArrayLayers", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageArrayLayers);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTexelBufferElements", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTexelBufferElements);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxUniformBufferRange", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxUniformBufferRange);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxStorageBufferRange", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxStorageBufferRange);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxPushConstantsSize", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPushConstantsSize);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxMemoryAllocationCount", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxMemoryAllocationCount);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxSamplerAllocationCount", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxSamplerAllocationCount);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setBufferImageGranularity", "(J)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->bufferImageGranularity);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setSparseAddressSpaceSize", "(J)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->sparseAddressSpaceSize);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxBoundDescriptorSets", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxBoundDescriptorSets);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorSamplers", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorSamplers);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorUniformBuffers", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorUniformBuffers);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorStorageBuffers", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorStorageBuffers);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorSampledImages", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorSampledImages);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorStorageImages", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorStorageImages);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorInputAttachments", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorInputAttachments);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageResources", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageResources);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetSamplers", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetSamplers);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetUniformBuffers", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetUniformBuffers);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetUniformBuffersDynamic", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetUniformBuffersDynamic);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetStorageBuffers", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetStorageBuffers);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetStorageBuffersDynamic", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetStorageBuffersDynamic);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetSampledImages", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetSampledImages);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetStorageImages", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetStorageImages);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetInputAttachments", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetInputAttachments);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexInputAttributes", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexInputAttributes);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexInputBindings", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexInputBindings);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexInputAttributeOffset", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexInputAttributeOffset);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexInputBindingStride", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexInputBindingStride);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexOutputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexOutputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationGenerationLevel", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationGenerationLevel);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationPatchSize", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationPatchSize);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationControlPerVertexInputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationControlPerVertexInputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationControlPerVertexOutputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationControlPerVertexOutputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationControlPerPatchOutputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationControlPerPatchOutputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationControlTotalOutputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationControlTotalOutputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationEvaluationInputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationEvaluationInputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationEvaluationOutputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationEvaluationOutputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryShaderInvocations", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryShaderInvocations);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryInputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryInputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryOutputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryOutputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryOutputVertices", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryOutputVertices);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryTotalOutputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryTotalOutputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxFragmentInputComponents", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFragmentInputComponents);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxFragmentOutputAttachments", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFragmentOutputAttachments);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxFragmentDualSrcAttachments", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFragmentDualSrcAttachments);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxFragmentCombinedOutputResources", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFragmentCombinedOutputResources);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxComputeSharedMemorySize", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxComputeSharedMemorySize);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxComputeWorkGroupCount", "([I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jintArray maxComputeWorkGroupCount = env->NewIntArray(sizeof(deviceLimits->maxComputeWorkGroupCount)/sizeof(jint));
    if (maxComputeWorkGroupCount == 0)
    {
        cout << "ERROR: out of memory trying to allocate array for MaxComputeWorkGroupCount" << endl;
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, maxComputeWorkGroupCount);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->SetIntArrayRegion(maxComputeWorkGroupCount, 0, sizeof(deviceLimits->maxComputeWorkGroupCount)/sizeof(jint), (const jint *)deviceLimits->maxComputeWorkGroupCount);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxComputeWorkGroupInvocations", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxComputeWorkGroupInvocations);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxComputeWorkGroupSize", "([I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jintArray maxComputeWorkGroupSize = env->NewIntArray(sizeof(deviceLimits->maxComputeWorkGroupSize)/sizeof(jint));
    if (maxComputeWorkGroupSize == 0)
    {
        cout << "ERROR: out of memory trying to allocate array for maxComputeWorkGroupSize" << endl;
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, maxComputeWorkGroupSize);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->SetIntArrayRegion(maxComputeWorkGroupSize, 0, sizeof(deviceLimits->maxComputeWorkGroupSize)/sizeof(jint), (const jint *)deviceLimits->maxComputeWorkGroupSize);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setSubPixelPrecisionBits", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->subPixelPrecisionBits);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setSubTexelPrecisionBits", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->subTexelPrecisionBits);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMipmapPrecisionBits", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->mipmapPrecisionBits);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDrawIndexedIndexValue", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDrawIndexedIndexValue);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxDrawIndirectCount", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDrawIndirectCount);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxSamplerLodBias", "(F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxSamplerLodBias);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxSamplerAnisotropy", "(F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxSamplerAnisotropy);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxViewports", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxViewports);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxViewportDimensions", "([I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jintArray maxViewportDimensions = env->NewIntArray(sizeof(deviceLimits->maxViewportDimensions)/sizeof(jint));
    if (maxViewportDimensions == 0)
    {
        cout << "ERROR: out of memory trying to allocate array for maxViewportDimensions" << endl;
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, maxViewportDimensions);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->SetIntArrayRegion(maxViewportDimensions, 0, sizeof(deviceLimits->maxViewportDimensions)/sizeof(jint), (const jint *)deviceLimits->maxViewportDimensions);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setViewportBoundsRange", "([F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jfloatArray viewportBoundsRange = env->NewFloatArray(sizeof(deviceLimits->viewportBoundsRange)/sizeof(jfloat));
    if (viewportBoundsRange == 0)
    {
        cout << "ERROR: out of memory trying to allocate array for viewportBoundsRange" << endl;
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, viewportBoundsRange);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->SetFloatArrayRegion(viewportBoundsRange, 0, sizeof(deviceLimits->viewportBoundsRange)/sizeof(jfloat), (const jfloat *)deviceLimits->viewportBoundsRange);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setViewportSubPixelBits", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->viewportSubPixelBits);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMinMemoryMapAlignment", "(J)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minMemoryMapAlignment);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMinTexelBufferOffsetAlignment", "(J)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minTexelBufferOffsetAlignment);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMinUniformBufferOffsetAlignment", "(J)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minUniformBufferOffsetAlignment);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMinStorageBufferOffsetAlignment", "(J)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minStorageBufferOffsetAlignment);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMinTexelOffset", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minTexelOffset);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTexelOffset", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTexelOffset);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMinTexelGatherOffset", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minTexelGatherOffset);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxTexelGatherOffset", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTexelGatherOffset);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMinInterpolationOffset", "(F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minInterpolationOffset);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxInterpolationOffset", "(F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxInterpolationOffset);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setSubPixelInterpolationOffsetBits", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->subPixelInterpolationOffsetBits);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxFramebufferWidth", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFramebufferWidth);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxFramebufferHeight", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFramebufferHeight);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxFramebufferLayers", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFramebufferLayers);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxFramebufferLayers", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFramebufferLayers);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setFramebufferColorSampleCounts", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jobject vkSampleCountFlagBitsEnumSet = getVkSampleCountFlagBits(env, deviceLimits->sampledImageColorSampleCounts);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    if (vkSampleCountFlagBitsEnumSet == nullptr)
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setFramebufferDepthSampleCounts", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    vkSampleCountFlagBitsEnumSet = getVkSampleCountFlagBits(env, deviceLimits->framebufferDepthSampleCounts);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    if (vkSampleCountFlagBitsEnumSet == nullptr)
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setFramebufferStencilSampleCounts", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    vkSampleCountFlagBitsEnumSet = getVkSampleCountFlagBits(env, deviceLimits->framebufferStencilSampleCounts);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    if (vkSampleCountFlagBitsEnumSet == nullptr)
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setFramebufferNoAttachmentsSampleCounts", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    vkSampleCountFlagBitsEnumSet = getVkSampleCountFlagBits(env, deviceLimits->framebufferNoAttachmentsSampleCounts);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    if (vkSampleCountFlagBitsEnumSet == nullptr)
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxColorAttachments", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxColorAttachments);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setSampledImageColorSampleCounts", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    vkSampleCountFlagBitsEnumSet = getVkSampleCountFlagBits(env, deviceLimits->sampledImageColorSampleCounts);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    if (vkSampleCountFlagBitsEnumSet == nullptr)
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setSampledImageIntegerSampleCounts", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    vkSampleCountFlagBitsEnumSet = getVkSampleCountFlagBits(env, deviceLimits->sampledImageIntegerSampleCounts);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    if (vkSampleCountFlagBitsEnumSet == nullptr)
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setSampledImageDepthSampleCounts", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    vkSampleCountFlagBitsEnumSet = getVkSampleCountFlagBits(env, deviceLimits->sampledImageDepthSampleCounts);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    if (vkSampleCountFlagBitsEnumSet == nullptr)
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setSampledImageStencilSampleCounts", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    vkSampleCountFlagBitsEnumSet = getVkSampleCountFlagBits(env, deviceLimits->sampledImageStencilSampleCounts);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    if (vkSampleCountFlagBitsEnumSet == nullptr)
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setStorageImageSampleCounts", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    vkSampleCountFlagBitsEnumSet = getVkSampleCountFlagBits(env, deviceLimits->storageImageSampleCounts);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    if (vkSampleCountFlagBitsEnumSet == nullptr)
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxSampleMaskWords", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxSampleMaskWords);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setTimestampComputeAndGraphics", "(Z)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->timestampComputeAndGraphics);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setTimestampPeriod", "(F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->timestampPeriod);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxClipDistances", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxClipDistances);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxCullDistances", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxCullDistances);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setMaxCombinedClipAndCullDistances", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxCombinedClipAndCullDistances);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setDiscreteQueuePriorities", "(I)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->discreteQueuePriorities);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setPointSizeRange", "([F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jfloatArray pointSizeRange = env->NewFloatArray(sizeof(deviceLimits->pointSizeRange)/sizeof(jfloat));
    if (pointSizeRange == 0)
    {
        cout << "ERROR: out of memory trying to allocate array for pointSizeRange" << endl;
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, pointSizeRange);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->SetFloatArrayRegion(pointSizeRange, 0, sizeof(deviceLimits->pointSizeRange)/sizeof(jfloat), (const jfloat *)deviceLimits->pointSizeRange);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setLineWidthRange", "([F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jfloatArray lineWidthRange = env->NewFloatArray(sizeof(deviceLimits->lineWidthRange)/sizeof(jfloat));
    if (lineWidthRange == 0)
    {
        cout << "ERROR: out of memory trying to allocate array for lineWidthRange" << endl;
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, lineWidthRange);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->SetFloatArrayRegion(lineWidthRange, 0, sizeof(deviceLimits->lineWidthRange)/sizeof(jfloat), (const jfloat *)deviceLimits->lineWidthRange);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setPointSizeGranularity", "(F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->pointSizeGranularity);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setLineWidthGranularity", "(F)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->lineWidthGranularity);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setStrictLines", "(Z)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->strictLines);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setStandardSampleLocations", "(Z)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->standardSampleLocations);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setOptimalBufferCopyOffsetAlignment", "(J)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->optimalBufferCopyOffsetAlignment);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setOptimalBufferCopyRowPitchAlignment", "(J)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->optimalBufferCopyRowPitchAlignment);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(deviceLimitsClass, "setNonCoherentAtomSize", "(J)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->nonCoherentAtomSize);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }


    return deviceLimitsObject;
}

static jobject getVkSampleCountFlagBits(JNIEnv *env, VkSampleCountFlags vkSampleCountFlags)
{
    char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits";
    char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits;";
    /*
     * Create the EnumSet for the flags.
     */
    jclass enumSetClass = env->FindClass("java/util/EnumSet");
    if (env->ExceptionOccurred())
    {
        cout << "Error finding EnumSet class ... returning" << endl;
        return nullptr;
    }
//    cout << "Found EnumSet class" << endl;

    jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
    if (env->ExceptionOccurred() != 0)
    {
        cout << "Error getting noneOf ... returning" << endl;
        return nullptr;
    }

//    cout << "Got noneOfMethod" << endl;

    jclass enumClass = env->FindClass(enumClassString);

    jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
    if (env->ExceptionOccurred())
    {
        cout << "Error CallStaticObjectMethod on enumset object class ... returning" << endl;
        return nullptr;
    }

//    cout << "Made the empty EnumSet flags is " << vkSampleCountFlags << endl;

    jclass setClass = env->FindClass("java/util/Set");
    jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
        cout << "Error getting add method on EnumSet ... returning" << endl;
        return nullptr;
    }

    /*
     * Make sure that flags does not have an unexpected value.  This would
     * indicate that this code is out of sync with the LunarG Vulkan SDK.
     */
    if ((vkSampleCountFlags &
         !(VK_SAMPLE_COUNT_1_BIT |
           VK_SAMPLE_COUNT_2_BIT |
           VK_SAMPLE_COUNT_4_BIT |
           VK_SAMPLE_COUNT_8_BIT |
           VK_SAMPLE_COUNT_16_BIT |
           VK_SAMPLE_COUNT_32_BIT |
           VK_SAMPLE_COUNT_64_BIT)) != 0)
    {
        cout << "ERROR: Unhandled case for vkSampleCountFlags...value is " << vkSampleCountFlags << endl;
        return nullptr;
    }

    if (vkSampleCountFlags & VK_SAMPLE_COUNT_1_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_1_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_SAMPLE_COUNT_1_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkSampleCountFlags & VK_SAMPLE_COUNT_2_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_2_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_SAMPLE_COUNT_2_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkSampleCountFlags & VK_SAMPLE_COUNT_4_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_4_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_SAMPLE_COUNT_4_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkSampleCountFlags & VK_SAMPLE_COUNT_8_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_8_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_SAMPLE_COUNT_8_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkSampleCountFlags & VK_SAMPLE_COUNT_16_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_16_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_SAMPLE_COUNT_16_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkSampleCountFlags & VK_SAMPLE_COUNT_32_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_32_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_SAMPLE_COUNT_32_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkSampleCountFlags & VK_SAMPLE_COUNT_64_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SAMPLE_COUNT_64_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_SAMPLE_COUNT_64_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    return enumSetObject;
}
