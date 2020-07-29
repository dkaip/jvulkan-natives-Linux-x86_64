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
 * populateVkPhysicalDeviceProperties.cpp
 *
 *  Created on: May 12, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	static jobject getdeviceLimits(JNIEnv *env, const VkPhysicalDeviceLimits *deviceLimits);
	static jobject getSparseProperties(JNIEnv *env, const VkPhysicalDeviceSparseProperties *sparseProperties);

    void populateVkPhysicalDeviceProperties(
    		JNIEnv *env,
			jobject jVkPhysicalDevicePropertiesObject,
			const VkPhysicalDeviceProperties *vkPhysicalDeviceProperties)
    {
        // Locate the VkPhysicalDeviceProperties class
        jclass vkPhysicalDevicePropertiesClass = env->GetObjectClass(jVkPhysicalDevicePropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "setApiVersion", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setApiVersion");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePropertiesObject, methodId, vkPhysicalDeviceProperties->apiVersion);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "setDriverVersion", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDriverVersion");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePropertiesObject, methodId, vkPhysicalDeviceProperties->driverVersion);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "setVendorID", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setVendorID");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePropertiesObject, methodId, vkPhysicalDeviceProperties->vendorID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "setDeviceID", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceID");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePropertiesObject, methodId, vkPhysicalDeviceProperties->deviceID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        char deviceTypeName[64];
        deviceTypeName[0] = '\0';

        switch(vkPhysicalDeviceProperties->deviceType)
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
            	LOGERROR(env, "ERROR: Unhandled deviceProperties.deviceType of %d", vkPhysicalDeviceProperties->deviceType);
                return;
        }

        jclass enumClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Enums/VkPhysicalDeviceType");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Enums/VkPhysicalDeviceType");
            return;
        }

        jfieldID fieldId = env->GetStaticFieldID(enumClass, deviceTypeName, "Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPhysicalDeviceType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetStaticFieldID");
            return;
        }

        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetStaticObjectField");
            return;
        }

        methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "setDeviceType", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPhysicalDeviceType;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceType");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePropertiesObject, methodId, theEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "setDeviceName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceName");
            return;
        }

        jstring deviceNameString = env->NewStringUTF(vkPhysicalDeviceProperties->deviceName);

        env->CallVoidMethod(jVkPhysicalDevicePropertiesObject, methodId, deviceNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(deviceNameString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "setPipelineCacheUUID", "([B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPipelineCacheUUID");
            return;
        }

        jbyteArray uuid = env->NewByteArray(sizeof(vkPhysicalDeviceProperties->pipelineCacheUUID));
        if (uuid == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for pipelineCacheUUID");
            return;
        }

        env->SetByteArrayRegion(uuid, 0, sizeof(vkPhysicalDeviceProperties->pipelineCacheUUID), (const jbyte *)vkPhysicalDeviceProperties->pipelineCacheUUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetByteArrayRegion");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePropertiesObject, methodId, uuid);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "setLimits", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceLimits;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setLimits");
            return;
        }

        jobject deviceLimitsObject = getdeviceLimits(env, &(vkPhysicalDeviceProperties->limits));
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getdeviceLimits");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePropertiesObject, methodId, deviceLimitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "setSparseProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceSparseProperties;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSparseProperties");
            return;
        }

        jobject sparsePropertiesObject = getSparseProperties(env, &(vkPhysicalDeviceProperties->sparseProperties));
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSparseProperties");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePropertiesObject, methodId, sparsePropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        return;
    }

    static jobject getSparseProperties(JNIEnv *env, const VkPhysicalDeviceSparseProperties *sparseProperties)
    {
        jclass sparsePropertiesClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceSparseProperties");
        jmethodID constructorMethod = env->GetMethodID(sparsePropertiesClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init>");
            return nullptr;
        }

        jobject sparsePropertiesObject = env->NewObject(sparsePropertiesClass, constructorMethod);

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyStandard2DBlockShape", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setResidencyStandard2DBlockShape");
            return nullptr;
        }

        env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyStandard2DBlockShape);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyStandard2DMultisampleBlockShape", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setResidencyStandard2DMultisampleBlockShape");
            return nullptr;
        }

        env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyStandard2DMultisampleBlockShape);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyStandard3DBlockShape", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setResidencyStandard3DBlockShape");
            return nullptr;
        }

        env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyStandard3DBlockShape);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyAlignedMipSize", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setResidencyAlignedMipSize");
            return nullptr;
        }

        env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyAlignedMipSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(sparsePropertiesClass, "setResidencyNonResidentStrict", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setResidencyAlignedMipSize");
            return nullptr;
        }

        env->CallVoidMethod(sparsePropertiesObject, methodId, sparseProperties->residencyNonResidentStrict);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return sparsePropertiesObject;
    }

    static jobject getdeviceLimits(JNIEnv *env, const VkPhysicalDeviceLimits *deviceLimits)
    {
        jclass deviceLimitsClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceLimits");
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
        	LOGERROR(env, "%s", "Could not find method id setMaxImageDimension1D");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageDimension1D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxImageDimension2D", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageDimension2D");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageDimension2D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxImageDimension3D", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageDimension3D");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageDimension3D);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxImageDimensionCube", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageDimensionCube");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageDimensionCube);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxImageArrayLayers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxImageArrayLayers");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxImageArrayLayers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTexelBufferElements", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTexelBufferElements");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTexelBufferElements);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxUniformBufferRange", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxUniformBufferRange");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxUniformBufferRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxStorageBufferRange", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxStorageBufferRange");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxStorageBufferRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxPushConstantsSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPushConstantsSize");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPushConstantsSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxMemoryAllocationCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMemoryAllocationCount");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxMemoryAllocationCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxSamplerAllocationCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSamplerAllocationCount");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxSamplerAllocationCount);
        if (env->ExceptionOccurred())
        {
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setBufferImageGranularity", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setBufferImageGranularity");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->bufferImageGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setSparseAddressSpaceSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSparseAddressSpaceSize");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->sparseAddressSpaceSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxBoundDescriptorSets", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxBoundDescriptorSets");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxBoundDescriptorSets);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorSamplers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorSamplers");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorSamplers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorUniformBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorUniformBuffers");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorUniformBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorStorageBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorStorageBuffers");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorStorageBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorSampledImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorSampledImages");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorSampledImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorStorageImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorStorageImages");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorStorageImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageDescriptorInputAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorInputAttachments");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageDescriptorInputAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxPerStageResources", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageResources");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxPerStageResources);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetSamplers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetSamplers");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetSamplers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetUniformBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUniformBuffers");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetUniformBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetUniformBuffersDynamic", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUniformBuffersDynamic");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetUniformBuffersDynamic);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetStorageBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetStorageBuffers");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetStorageBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetStorageBuffersDynamic", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetStorageBuffersDynamic");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetStorageBuffersDynamic);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetSampledImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetSampledImages");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetSampledImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetStorageImages", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetStorageImages");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetStorageImages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDescriptorSetInputAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetInputAttachments");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDescriptorSetInputAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexInputAttributes", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexInputAttributes");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexInputAttributes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexInputBindings", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexInputBindings");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexInputBindings);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexInputAttributeOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexInputAttributeOffset");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexInputAttributeOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexInputBindingStride", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexInputBindingStride");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexInputBindingStride);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxVertexOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxVertexOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxVertexOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationGenerationLevel", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationGenerationLevel");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationGenerationLevel);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationPatchSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationPatchSize");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationPatchSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationControlPerVertexInputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationControlPerVertexInputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationControlPerVertexInputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationControlPerVertexOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationControlPerVertexOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationControlPerVertexOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationControlPerPatchOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationControlPerPatchOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationControlPerPatchOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationControlTotalOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationControlTotalOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationControlTotalOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationEvaluationInputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationEvaluationInputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationEvaluationInputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTessellationEvaluationOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTessellationEvaluationOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTessellationEvaluationOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryShaderInvocations", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryShaderInvocations");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryShaderInvocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryInputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryInputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryInputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryOutputVertices", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryOutputVertices");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryOutputVertices);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxGeometryTotalOutputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryTotalOutputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxGeometryTotalOutputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxFragmentInputComponents", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFragmentInputComponents");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFragmentInputComponents);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxFragmentOutputAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFragmentOutputAttachments");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFragmentOutputAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxFragmentDualSrcAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFragmentDualSrcAttachments");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFragmentDualSrcAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxFragmentCombinedOutputResources", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFragmentCombinedOutputResources");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFragmentCombinedOutputResources);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxComputeSharedMemorySize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxComputeSharedMemorySize");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxComputeSharedMemorySize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxComputeWorkGroupCount", "([I)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, maxComputeWorkGroupCount);
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
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxComputeWorkGroupInvocations", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxComputeWorkGroupInvocations");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxComputeWorkGroupInvocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxComputeWorkGroupSize", "([I)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, maxComputeWorkGroupSize);
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
        methodId = env->GetMethodID(deviceLimitsClass, "setSubPixelPrecisionBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubPixelPrecisionBits");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->subPixelPrecisionBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setSubTexelPrecisionBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubTexelPrecisionBits");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->subTexelPrecisionBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMipmapPrecisionBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMipmapPrecisionBits");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->mipmapPrecisionBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDrawIndexedIndexValue", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDrawIndexedIndexValue");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDrawIndexedIndexValue);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxDrawIndirectCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDrawIndirectCount");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxDrawIndirectCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxSamplerLodBias", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSamplerLodBias");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxSamplerLodBias);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxSamplerAnisotropy", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSamplerAnisotropy");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxSamplerAnisotropy);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxViewports", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxViewports");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxViewports);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxViewportDimensions", "([I)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, maxViewportDimensions);
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
        methodId = env->GetMethodID(deviceLimitsClass, "setViewportBoundsRange", "([F)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, viewportBoundsRange);
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
        methodId = env->GetMethodID(deviceLimitsClass, "setViewportSubPixelBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setViewportSubPixelBits");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->viewportSubPixelBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMinMemoryMapAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinMemoryMapAlignment");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minMemoryMapAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMinTexelBufferOffsetAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinTexelBufferOffsetAlignment");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minTexelBufferOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMinUniformBufferOffsetAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinUniformBufferOffsetAlignment");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minUniformBufferOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMinStorageBufferOffsetAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinStorageBufferOffsetAlignment");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minStorageBufferOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMinTexelOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinTexelOffset");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minTexelOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTexelOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTexelOffset");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTexelOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMinTexelGatherOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinTexelGatherOffset");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minTexelGatherOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxTexelGatherOffset", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTexelGatherOffset");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxTexelGatherOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMinInterpolationOffset", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMinInterpolationOffset");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->minInterpolationOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxInterpolationOffset", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxInterpolationOffset");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxInterpolationOffset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setSubPixelInterpolationOffsetBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubPixelInterpolationOffsetBits");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->subPixelInterpolationOffsetBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxFramebufferWidth", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFramebufferWidth");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFramebufferWidth);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxFramebufferHeight", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFramebufferHeight");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFramebufferHeight);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxFramebufferLayers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFramebufferLayers");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFramebufferLayers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxFramebufferLayers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxFramebufferLayers");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxFramebufferLayers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setFramebufferColorSampleCounts", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setFramebufferDepthSampleCounts", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setFramebufferStencilSampleCounts", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////

        methodId = env->GetMethodID(deviceLimitsClass, "setFramebufferNoAttachmentsSampleCounts", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxColorAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxColorAttachments");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxColorAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setSampledImageColorSampleCounts", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setSampledImageIntegerSampleCounts", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setSampledImageDepthSampleCounts", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setSampledImageStencilSampleCounts", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setStorageImageSampleCounts", "(Ljava/util/EnumSet;)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, vkSampleCountFlagBitsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxSampleMaskWords", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSampleMaskWords");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxSampleMaskWords);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setTimestampComputeAndGraphics", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTimestampComputeAndGraphics");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->timestampComputeAndGraphics);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setTimestampPeriod", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTimestampPeriod");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->timestampPeriod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxClipDistances", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxClipDistances");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxClipDistances);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxCullDistances", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxCullDistances");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxCullDistances);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setMaxCombinedClipAndCullDistances", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxCombinedClipAndCullDistances");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->maxCombinedClipAndCullDistances);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setDiscreteQueuePriorities", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDiscreteQueuePriorities");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->discreteQueuePriorities);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setPointSizeRange", "([F)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, pointSizeRange);
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
        methodId = env->GetMethodID(deviceLimitsClass, "setLineWidthRange", "([F)V");
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

        env->CallVoidMethod(deviceLimitsObject, methodId, lineWidthRange);
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
        methodId = env->GetMethodID(deviceLimitsClass, "setPointSizeGranularity", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPointSizeGranularity");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->pointSizeGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setLineWidthGranularity", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setLineWidthGranularity");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->lineWidthGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setStrictLines", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setStrictLines");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->strictLines);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setStandardSampleLocations", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setStandardSampleLocations");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->standardSampleLocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setOptimalBufferCopyOffsetAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setOptimalBufferCopyOffsetAlignment");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->optimalBufferCopyOffsetAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setOptimalBufferCopyRowPitchAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setOptimalBufferCopyRowPitchAlignment");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->optimalBufferCopyRowPitchAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(deviceLimitsClass, "setNonCoherentAtomSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setNonCoherentAtomSize");
            return nullptr;
        }

        env->CallVoidMethod(deviceLimitsObject, methodId, deviceLimits->nonCoherentAtomSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return deviceLimitsObject;
    }
}
