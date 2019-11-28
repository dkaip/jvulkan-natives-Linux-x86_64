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
 * populateVkPhysicalDeviceFloatControlsPropertiesKHR.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceFloatControlsPropertiesKHR(
			JNIEnv *env,
			jobject jVkPhysicalDeviceFloatControlsPropertiesKHRObject,
			const VkPhysicalDeviceFloatControlsPropertiesKHR *vkPhysicalDeviceFloatControlsPropertiesKHR,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceFloatControlsPropertiesKHRClass = env->GetObjectClass(
				jVkPhysicalDeviceFloatControlsPropertiesKHRObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceFloatControlsPropertiesKHR");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jclass vkShaderFloatControlsIndependenceKHRClass = env->FindClass("com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkShaderFloatControlsIndependenceKHR");
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkShaderFloatControlsIndependenceKHR");
            return;
        }

        jmethodID fromValueMethodId = env->GetStaticMethodID(vkShaderFloatControlsIndependenceKHRClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkShaderFloatControlsIndependenceKHR;");
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Could not find static method id fromValue");
            return;
        }

        jobject denormBehaviorIndependenceEnum = env->CallStaticObjectMethod(vkShaderFloatControlsIndependenceKHRClass, fromValueMethodId, vkPhysicalDeviceFloatControlsPropertiesKHR->denormBehaviorIndependence);

        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setDenormBehaviorIndependence", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkShaderFloatControlsIndependenceKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSeparateDenormSettings");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, denormBehaviorIndependenceEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setDriverId");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject roundingModeIndependenceEnum = env->CallStaticObjectMethod(vkShaderFloatControlsIndependenceKHRClass, fromValueMethodId, vkPhysicalDeviceFloatControlsPropertiesKHR->roundingModeIndependence);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method CallStaticObjectMethod");
            return;
        }

        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setRoundingModeIndependence", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkShaderFloatControlsIndependenceKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRoundingModeIndependence");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, roundingModeIndependenceEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setDriverId");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderSignedZeroInfNanPreserveFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSignedZeroInfNanPreserveFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderSignedZeroInfNanPreserveFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderSignedZeroInfNanPreserveFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSignedZeroInfNanPreserveFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderSignedZeroInfNanPreserveFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderSignedZeroInfNanPreserveFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderSignedZeroInfNanPreserveFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderSignedZeroInfNanPreserveFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderDenormPreserveFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormPreserveFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderDenormPreserveFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderDenormPreserveFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormPreserveFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderDenormPreserveFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderDenormPreserveFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormPreserveFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderDenormPreserveFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderDenormFlushToZeroFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormFlushToZeroFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderDenormFlushToZeroFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderDenormFlushToZeroFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormFlushToZeroFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderDenormFlushToZeroFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderDenormFlushToZeroFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderDenormFlushToZeroFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderDenormFlushToZeroFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderRoundingModeRTEFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTEFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderRoundingModeRTEFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderRoundingModeRTEFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTEFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderRoundingModeRTEFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderRoundingModeRTEFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTEFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderRoundingModeRTEFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderRoundingModeRTZFloat16", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTZFloat16");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderRoundingModeRTZFloat16);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderRoundingModeRTZFloat32", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTZFloat32");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderRoundingModeRTZFloat32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceFloatControlsPropertiesKHRClass, "setShaderRoundingModeRTZFloat64", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderRoundingModeRTZFloat64");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceFloatControlsPropertiesKHRObject, methodId, vkPhysicalDeviceFloatControlsPropertiesKHR->shaderRoundingModeRTZFloat64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
