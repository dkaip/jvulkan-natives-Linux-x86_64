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
 * populateVkPhysicalDeviceVulkan12Properties.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceVulkan12Properties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceVulkan12PropertiesObject,
			const VkPhysicalDeviceVulkan12Properties *vkPhysicalDeviceVulkan12Properties)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceVulkan12PropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceVulkan12PropertiesObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jobject jVkDriverIdObject = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkDriverId",
				vkPhysicalDeviceVulkan12Properties->driverID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setDriverID", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkDriverId;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDriverID");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, jVkDriverIdObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDriverName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDriverName");
            return;
        }

        jstring driverNameString = env->NewStringUTF(vkPhysicalDeviceVulkan12Properties->driverName);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling NewStringUTF.");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, driverNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(driverNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling DeleteLocalRef.");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDriverInfo", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDriverInfo");
            return;
        }

        jstring driverInfoString = env->NewStringUTF(vkPhysicalDeviceVulkan12Properties->driverInfo);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling NewStringUTF.");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, driverInfoString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(driverInfoString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling DeleteLocalRef.");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setConformanceVersion", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkConformanceVersion;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setConformanceVersion");
            return;
        }

        jobject jVkConformanceVersion = createVkConformanceVersion(env, &(vkPhysicalDeviceVulkan12Properties->conformanceVersion));
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkConformanceVersion.");
            return;
        }

    	env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, jVkConformanceVersion);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject denormBehaviorIndependenceObject = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderFloatControlsIndependence",
				vkPhysicalDeviceVulkan12Properties->denormBehaviorIndependence);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setDenormBehaviorIndependence", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderFloatControlsIndependence;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDenormBehaviorIndependence");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, denormBehaviorIndependenceObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject roundingModeIndependenceObject = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderFloatControlsIndependence",
				vkPhysicalDeviceVulkan12Properties->roundingModeIndependence);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setRoundingModeIndependence", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderFloatControlsIndependence;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRoundingModeIndependence");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, roundingModeIndependenceObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderSignedZeroInfNanPreserveFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSignedZeroInfNanPreserveFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderSignedZeroInfNanPreserveFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSignedZeroInfNanPreserveFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderSignedZeroInfNanPreserveFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSignedZeroInfNanPreserveFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderDenormPreserveFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormPreserveFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderDenormPreserveFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderDenormPreserveFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormPreserveFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderDenormPreserveFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderDenormPreserveFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormPreserveFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderDenormPreserveFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderDenormFlushToZeroFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormFlushToZeroFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderDenormFlushToZeroFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderDenormFlushToZeroFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormFlushToZeroFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderDenormFlushToZeroFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderDenormFlushToZeroFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormFlushToZeroFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderDenormFlushToZeroFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderRoundingModeRTEFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTEFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderRoundingModeRTEFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTEFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderRoundingModeRTEFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTEFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderRoundingModeRTZFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTZFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTZFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderRoundingModeRTZFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTZFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTZFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderRoundingModeRTZFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTZFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTZFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxUpdateAfterBindDescriptorsInAllPools", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxUpdateAfterBindDescriptorsInAllPools");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxUpdateAfterBindDescriptorsInAllPools);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderUniformBufferArrayNonUniformIndexingNative);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderSampledImageArrayNonUniformIndexingNative);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderStorageBufferArrayNonUniformIndexingNative);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderStorageImageArrayNonUniformIndexingNative);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->shaderInputAttachmentArrayNonUniformIndexingNative);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->robustBufferAccessUpdateAfterBind);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->quadDivergentImplicitLod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerStageDescriptorUpdateAfterBindSamplers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerStageDescriptorUpdateAfterBindSamplers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSamplers);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindUniformBuffers);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageBuffers);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSampledImages);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageImages);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindInputAttachments);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxPerStageUpdateAfterBindResources);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSamplers);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffers);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetUpdateAfterBindStorageBuffersDynamic", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetUpdateAfterBindStorageBuffersDynamic");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSampledImages);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageImages);
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

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindInputAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSupportedDepthResolveModes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedDepthResolveModes");
            return;
        }

        jobject vkResolveModeFlagsEnumSet = createVkResolveModeFlagsAsEnumSet(env, vkPhysicalDeviceVulkan12Properties->supportedDepthResolveModes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkResolveModeFlagsAsEnumSet");
            return;
        }

        if (vkResolveModeFlagsEnumSet == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createVkResolveModeFlagsAsEnumSet, setSupportedDepthResolveModes was nullptr");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkResolveModeFlagsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSupportedStencilResolveModes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSupportedStencilResolveModes");
            return;
        }

        vkResolveModeFlagsEnumSet = createVkResolveModeFlagsAsEnumSet(env, vkPhysicalDeviceVulkan12Properties->supportedStencilResolveModes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkResolveModeFlagsAsEnumSet");
            return;
        }

        if (vkResolveModeFlagsEnumSet == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createVkResolveModeFlagsAsEnumSet, setSupportedStencilResolveModes was nullptr");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkResolveModeFlagsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setIndependentResolveNone", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setIndependentResolveNone");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->independentResolveNone);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setIndependentResolve", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setIndependentResolve");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->independentResolve);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setFilterMinmaxSingleComponentFormats", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFilterMinmaxSingleComponentFormats");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->filterMinmaxSingleComponentFormats);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setFilterMinmaxImageComponentMapping", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFilterMinmaxImageComponentMapping");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->filterMinmaxImageComponentMapping);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTimelineSemaphoreValueDifference", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTimelineSemaphoreValueDifference");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkPhysicalDeviceVulkan12Properties->maxTimelineSemaphoreValueDifference);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setFramebufferIntegerColorSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFramebufferIntegerColorSampleCounts");
            return;
        }

        jobject vkSampleCountFlagsEnumSet = createVkSampleCountFlagBitsAsEnumSet(env, vkPhysicalDeviceVulkan12Properties->framebufferIntegerColorSampleCounts);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSampleCountFlagBitsAsEnumSet");
            return;
        }

        if (vkResolveModeFlagsEnumSet == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createVkSampleCountFlagsAsEnumSet, setFramebufferIntegerColorSampleCounts was nullptr");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan12PropertiesObject, methodId, vkSampleCountFlagsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
