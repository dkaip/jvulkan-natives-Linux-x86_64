/*
 * Copyright 2020 Douglas Kaip
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
 * getVkPhysicalDeviceVulkan12Features.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceVulkan12Features(
            JNIEnv *env,
            jobject jVkPhysicalDeviceVulkan12FeaturesObject,
			VkPhysicalDeviceVulkan12Features *vkPhysicalDeviceVulkan12Features,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceVulkan12FeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDeviceVulkan12FeaturesObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceVulkan12FeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceVulkan12FeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "isSamplerMirrorClampToEdge", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isSamplerMirrorClampToEdge.");
            return;
        }

        VkBool32 samplerMirrorClampToEdge = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDrawIndirectCount", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDrawIndirectCount.");
            return;
        }

        VkBool32 drawIndirectCount = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isStorageBuffer8BitAccess", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStorageBuffer8BitAccess.");
            return;
        }

        VkBool32 storageBuffer8BitAccess = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isUniformAndStorageBuffer8BitAccess", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isUniformAndStorageBuffer8BitAccess.");
            return;
        }

        VkBool32 uniformAndStorageBuffer8BitAccess = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isStoragePushConstant8", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStoragePushConstant8.");
            return;
        }

        VkBool32 storagePushConstant8 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderBufferInt64Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderBufferInt64Atomics.");
            return;
        }

        VkBool32 shaderBufferInt64Atomics = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSharedInt64Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSharedInt64Atomics.");
            return;
        }

        VkBool32 shaderSharedInt64Atomics = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderFloat16", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderFloat16.");
            return;
        }

        VkBool32 shaderFloat16 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderInt8", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderInt8.");
            return;
        }

        VkBool32 shaderInt8 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorIndexing.");
            return;
        }

        VkBool32 descriptorIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderInputAttachmentArrayDynamicIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderInputAttachmentArrayDynamicIndexing.");
            return;
        }

        VkBool32 shaderInputAttachmentArrayDynamicIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderUniformTexelBufferArrayDynamicIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderUniformTexelBufferArrayDynamicIndexing.");
            return;
        }

        VkBool32 shaderUniformTexelBufferArrayDynamicIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageTexelBufferArrayDynamicIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageTexelBufferArrayDynamicIndexing.");
            return;
        }

        VkBool32 shaderStorageTexelBufferArrayDynamicIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderUniformBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderUniformBufferArrayNonUniformIndexing.");
            return;
        }

        VkBool32 shaderUniformBufferArrayNonUniformIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSampledImageArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSampledImageArrayNonUniformIndexing.");
            return;
        }

        VkBool32 shaderSampledImageArrayNonUniformIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageBufferArrayNonUniformIndexing.");
            return;
        }

        VkBool32 shaderStorageBufferArrayNonUniformIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageImageArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageImageArrayNonUniformIndexing.");
            return;
        }

        VkBool32 shaderStorageImageArrayNonUniformIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderInputAttachmentArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderInputAttachmentArrayNonUniformIndexing.");
            return;
        }

        VkBool32 shaderInputAttachmentArrayNonUniformIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderUniformTexelBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderUniformTexelBufferArrayNonUniformIndexing.");
            return;
        }

        VkBool32 shaderUniformTexelBufferArrayNonUniformIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageTexelBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageTexelBufferArrayNonUniformIndexing.");
            return;
        }

        VkBool32 shaderStorageTexelBufferArrayNonUniformIndexing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingUniformBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingUniformBufferUpdateAfterBind.");
            return;
        }

        VkBool32 descriptorBindingUniformBufferUpdateAfterBind = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingSampledImageUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingSampledImageUpdateAfterBind.");
            return;
        }

        VkBool32 descriptorBindingSampledImageUpdateAfterBind = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingStorageImageUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingStorageImageUpdateAfterBind.");
            return;
        }

        VkBool32 descriptorBindingStorageImageUpdateAfterBind = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingStorageBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingStorageBufferUpdateAfterBind.");
            return;
        }

        VkBool32 descriptorBindingStorageBufferUpdateAfterBind = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingUniformTexelBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingUniformTexelBufferUpdateAfterBind.");
            return;
        }

        VkBool32 descriptorBindingUniformTexelBufferUpdateAfterBind = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingStorageTexelBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingStorageTexelBufferUpdateAfterBind.");
            return;
        }

        VkBool32 descriptorBindingStorageTexelBufferUpdateAfterBind = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingUpdateUnusedWhilePending", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingUpdateUnusedWhilePending.");
            return;
        }

        VkBool32 descriptorBindingUpdateUnusedWhilePending = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingPartiallyBound", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingPartiallyBound.");
            return;
        }

        VkBool32 descriptorBindingPartiallyBound = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingVariableDescriptorCount", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingVariableDescriptorCount.");
            return;
        }

        VkBool32 descriptorBindingVariableDescriptorCount = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isRuntimeDescriptorArray", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isRuntimeDescriptorArray.");
            return;
        }

        VkBool32 runtimeDescriptorArray = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isSamplerFilterMinmax", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isSamplerFilterMinmax.");
            return;
        }

        VkBool32 samplerFilterMinmax = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isScalarBlockLayout", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isScalarBlockLayout.");
            return;
        }

        VkBool32 scalarBlockLayout = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isImagelessFramebuffer", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isImagelessFramebuffer.");
            return;
        }

        VkBool32 imagelessFramebuffer = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isUniformBufferStandardLayout", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isUniformBufferStandardLayout.");
            return;
        }

        VkBool32 uniformBufferStandardLayout = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSubgroupExtendedTypes", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSubgroupExtendedTypes.");
            return;
        }

        VkBool32 shaderSubgroupExtendedTypes = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isSeparateDepthStencilLayouts", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isSeparateDepthStencilLayouts.");
            return;
        }

        VkBool32 separateDepthStencilLayouts = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isHostQueryReset", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isHostQueryReset.");
            return;
        }

        VkBool32 hostQueryReset = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isTimelineSemaphore", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isTimelineSemaphore.");
            return;
        }

        VkBool32 timelineSemaphore = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isBufferDeviceAddress", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isBufferDeviceAddress.");
            return;
        }

        VkBool32 bufferDeviceAddress = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isBufferDeviceAddressCaptureReplay", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isBufferDeviceAddressCaptureReplay.");
            return;
        }

        VkBool32 bufferDeviceAddressCaptureReplay = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isBufferDeviceAddressMultiDevice", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isBufferDeviceAddressMultiDevice.");
            return;
        }

        VkBool32 bufferDeviceAddressMultiDevice = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isVulkanMemoryModel", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVulkanMemoryModel.");
            return;
        }

        VkBool32 vulkanMemoryModel = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isVulkanMemoryModelDeviceScope", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVulkanMemoryModelDeviceScope.");
            return;
        }

        VkBool32 vulkanMemoryModelDeviceScope = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isVulkanMemoryModelAvailabilityVisibilityChains", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVulkanMemoryModelAvailabilityVisibilityChains.");
            return;
        }

        VkBool32 vulkanMemoryModelAvailabilityVisibilityChains = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderOutputViewportIndex", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderOutputViewportIndex.");
            return;
        }

        VkBool32 shaderOutputViewportIndex = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderOutputLayer", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderOutputLayer.");
            return;
        }

        VkBool32 shaderOutputLayer = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isSubgroupBroadcastDynamicId", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isSubgroupBroadcastDynamicId.");
            return;
        }

        VkBool32 subgroupBroadcastDynamicId = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan12FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkPhysicalDeviceVulkan12Features->sType 	= sTypeValue;
        vkPhysicalDeviceVulkan12Features->pNext 	= (void *)pNext;
        vkPhysicalDeviceVulkan12Features->samplerMirrorClampToEdge	= samplerMirrorClampToEdge;
        vkPhysicalDeviceVulkan12Features->drawIndirectCount	= drawIndirectCount;
        vkPhysicalDeviceVulkan12Features->storageBuffer8BitAccess	= storageBuffer8BitAccess;
        vkPhysicalDeviceVulkan12Features->uniformAndStorageBuffer8BitAccess	= uniformAndStorageBuffer8BitAccess;
        vkPhysicalDeviceVulkan12Features->storagePushConstant8	= storagePushConstant8;
        vkPhysicalDeviceVulkan12Features->shaderBufferInt64Atomics	= shaderBufferInt64Atomics;
        vkPhysicalDeviceVulkan12Features->shaderSharedInt64Atomics	= shaderSharedInt64Atomics;
        vkPhysicalDeviceVulkan12Features->shaderFloat16	= shaderFloat16;
        vkPhysicalDeviceVulkan12Features->shaderInt8	= shaderInt8;
        vkPhysicalDeviceVulkan12Features->descriptorIndexing	= descriptorIndexing;
        vkPhysicalDeviceVulkan12Features->shaderInputAttachmentArrayDynamicIndexing	= shaderInputAttachmentArrayDynamicIndexing;
        vkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayDynamicIndexing	= shaderUniformTexelBufferArrayDynamicIndexing;
        vkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayDynamicIndexing	= shaderStorageTexelBufferArrayDynamicIndexing;
        vkPhysicalDeviceVulkan12Features->shaderUniformBufferArrayNonUniformIndexing	= shaderUniformBufferArrayNonUniformIndexing;
        vkPhysicalDeviceVulkan12Features->shaderSampledImageArrayNonUniformIndexing	= shaderSampledImageArrayNonUniformIndexing;
        vkPhysicalDeviceVulkan12Features->shaderStorageBufferArrayNonUniformIndexing	= shaderStorageBufferArrayNonUniformIndexing;
        vkPhysicalDeviceVulkan12Features->shaderStorageImageArrayNonUniformIndexing	= shaderStorageImageArrayNonUniformIndexing;
        vkPhysicalDeviceVulkan12Features->shaderInputAttachmentArrayNonUniformIndexing	= shaderInputAttachmentArrayNonUniformIndexing;
        vkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayNonUniformIndexing	= shaderUniformTexelBufferArrayNonUniformIndexing;
        vkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayNonUniformIndexing	= shaderStorageTexelBufferArrayNonUniformIndexing;
        vkPhysicalDeviceVulkan12Features->descriptorBindingUniformBufferUpdateAfterBind	= descriptorBindingUniformBufferUpdateAfterBind;
        vkPhysicalDeviceVulkan12Features->descriptorBindingSampledImageUpdateAfterBind	= descriptorBindingSampledImageUpdateAfterBind;
        vkPhysicalDeviceVulkan12Features->descriptorBindingStorageImageUpdateAfterBind	= descriptorBindingStorageImageUpdateAfterBind;
        vkPhysicalDeviceVulkan12Features->descriptorBindingStorageBufferUpdateAfterBind	= descriptorBindingStorageBufferUpdateAfterBind;
        vkPhysicalDeviceVulkan12Features->descriptorBindingUniformTexelBufferUpdateAfterBind	= descriptorBindingUniformTexelBufferUpdateAfterBind;
        vkPhysicalDeviceVulkan12Features->descriptorBindingStorageTexelBufferUpdateAfterBind	= descriptorBindingStorageTexelBufferUpdateAfterBind;
        vkPhysicalDeviceVulkan12Features->descriptorBindingUpdateUnusedWhilePending	= descriptorBindingUpdateUnusedWhilePending;
        vkPhysicalDeviceVulkan12Features->descriptorBindingPartiallyBound	= descriptorBindingPartiallyBound;
        vkPhysicalDeviceVulkan12Features->descriptorBindingVariableDescriptorCount	= descriptorBindingVariableDescriptorCount;
        vkPhysicalDeviceVulkan12Features->runtimeDescriptorArray	= runtimeDescriptorArray;
        vkPhysicalDeviceVulkan12Features->samplerFilterMinmax	= samplerFilterMinmax;
        vkPhysicalDeviceVulkan12Features->scalarBlockLayout	= scalarBlockLayout;
        vkPhysicalDeviceVulkan12Features->imagelessFramebuffer	= imagelessFramebuffer;
        vkPhysicalDeviceVulkan12Features->uniformBufferStandardLayout	= uniformBufferStandardLayout;
        vkPhysicalDeviceVulkan12Features->shaderSubgroupExtendedTypes	= shaderSubgroupExtendedTypes;
        vkPhysicalDeviceVulkan12Features->separateDepthStencilLayouts	= separateDepthStencilLayouts;
        vkPhysicalDeviceVulkan12Features->hostQueryReset	= hostQueryReset;
        vkPhysicalDeviceVulkan12Features->timelineSemaphore	= timelineSemaphore;
        vkPhysicalDeviceVulkan12Features->bufferDeviceAddress	= bufferDeviceAddress;
        vkPhysicalDeviceVulkan12Features->bufferDeviceAddressCaptureReplay	= bufferDeviceAddressCaptureReplay;
        vkPhysicalDeviceVulkan12Features->bufferDeviceAddressMultiDevice	= bufferDeviceAddressMultiDevice;
        vkPhysicalDeviceVulkan12Features->vulkanMemoryModel	= vulkanMemoryModel;
        vkPhysicalDeviceVulkan12Features->vulkanMemoryModelDeviceScope	= vulkanMemoryModelDeviceScope;
        vkPhysicalDeviceVulkan12Features->vulkanMemoryModelAvailabilityVisibilityChains	= vulkanMemoryModelAvailabilityVisibilityChains;
        vkPhysicalDeviceVulkan12Features->shaderOutputViewportIndex	= shaderOutputViewportIndex;
        vkPhysicalDeviceVulkan12Features->shaderOutputLayer	= shaderOutputLayer;
        vkPhysicalDeviceVulkan12Features->subgroupBroadcastDynamicId	= subgroupBroadcastDynamicId;
    }
}
