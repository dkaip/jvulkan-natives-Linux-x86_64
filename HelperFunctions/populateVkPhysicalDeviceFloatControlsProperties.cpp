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
 * populateVkPhysicalDeviceFloatControlsProperties.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceFloatControlsProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceFloatControlsPropertiesObject,
			const VkPhysicalDeviceFloatControlsProperties *vkPhysicalDeviceFloatControlsProperties,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceFloatControlsPropertiesClass = env->GetObjectClass(
				jVkPhysicalDeviceFloatControlsPropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceFloatControlsProperties");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jclass vkShaderFloatControlsIndependenceClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderFloatControlsIndependence");
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderFloatControlsIndependence");
            return;
        }

        jmethodID fromValueMethodId = env->GetStaticMethodID(vkShaderFloatControlsIndependenceClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderFloatControlsIndependence;");
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Could not find static method id fromValue");
            return;
        }

        jobject denormBehaviorIndependenceEnum = env->CallStaticObjectMethod(vkShaderFloatControlsIndependenceClass, fromValueMethodId, vkPhysicalDeviceFloatControlsProperties->denormBehaviorIndependence);

        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setDenormBehaviorIndependence", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderFloatControlsIndependence;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSeparateDenormSettings");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, denormBehaviorIndependenceEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setDriverId");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject roundingModeIndependenceEnum = env->CallStaticObjectMethod(vkShaderFloatControlsIndependenceClass, fromValueMethodId, vkPhysicalDeviceFloatControlsProperties->roundingModeIndependence);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method CallStaticObjectMethod");
            return;
        }

        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setRoundingModeIndependence", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkShaderFloatControlsIndependence;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRoundingModeIndependence");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, roundingModeIndependenceEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setDriverId");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderSignedZeroInfNanPreserveFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSignedZeroInfNanPreserveFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderSignedZeroInfNanPreserveFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderSignedZeroInfNanPreserveFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSignedZeroInfNanPreserveFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderSignedZeroInfNanPreserveFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderSignedZeroInfNanPreserveFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSignedZeroInfNanPreserveFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderSignedZeroInfNanPreserveFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderDenormPreserveFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormPreserveFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderDenormPreserveFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderDenormPreserveFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormPreserveFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderDenormPreserveFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderDenormPreserveFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormPreserveFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderDenormPreserveFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderDenormFlushToZeroFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormFlushToZeroFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderDenormFlushToZeroFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderDenormFlushToZeroFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormFlushToZeroFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderDenormFlushToZeroFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderDenormFlushToZeroFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormFlushToZeroFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderDenormFlushToZeroFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderRoundingModeRTEFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTEFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderRoundingModeRTEFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderRoundingModeRTEFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTEFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderRoundingModeRTEFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderRoundingModeRTEFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTEFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderRoundingModeRTEFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderRoundingModeRTZFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTZFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderRoundingModeRTZFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderRoundingModeRTZFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTZFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderRoundingModeRTZFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesClass, "setShaderRoundingModeRTZFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTZFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesObject, methodId, vkPhysicalDeviceFloatControlsProperties->shaderRoundingModeRTZFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
