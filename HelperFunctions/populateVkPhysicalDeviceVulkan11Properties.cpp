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
 * populateVkPhysicalDeviceVulkan11Properties.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceVulkan11Properties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceVulkan11PropertiesObject,
			const VkPhysicalDeviceVulkan11Properties *vkPhysicalDeviceVulkan11Properties)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceVulkan11PropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceVulkan11PropertiesObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jbyteArray deviceUUID = env->NewByteArray(sizeof(vkPhysicalDeviceVulkan11Properties->deviceUUID));
        if (deviceUUID == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for deviceUUID");
            return;
        }

        env->SetByteArrayRegion(deviceUUID, 0, sizeof(vkPhysicalDeviceVulkan11Properties->deviceUUID), (const jbyte *)vkPhysicalDeviceVulkan11Properties->deviceUUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetByteArrayRegion");
            return;
        }

		jmethodID methodId = env->GetMethodID(theClass, "setDeviceUUID", "([B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceUUID");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, deviceUUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jbyteArray driverUUID = env->NewByteArray(sizeof(vkPhysicalDeviceVulkan11Properties->driverUUID));
        if (driverUUID == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for driverUUID");
            return;
        }

        env->SetByteArrayRegion(driverUUID, 0, sizeof(vkPhysicalDeviceVulkan11Properties->driverUUID), (const jbyte *)vkPhysicalDeviceVulkan11Properties->driverUUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetByteArrayRegion");
            return;
        }

		methodId = env->GetMethodID(theClass, "setDriverUUID", "([B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDriverUUID");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, driverUUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jbyteArray deviceLUID = env->NewByteArray(sizeof(vkPhysicalDeviceVulkan11Properties->deviceLUID));
        if (deviceLUID == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for deviceLUID");
            return;
        }

        env->SetByteArrayRegion(deviceLUID, 0, sizeof(vkPhysicalDeviceVulkan11Properties->deviceLUID), (const jbyte *)vkPhysicalDeviceVulkan11Properties->deviceLUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetByteArrayRegion");
            return;
        }

		methodId = env->GetMethodID(theClass, "setDeviceLUID", "([B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceLUID");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, deviceLUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDeviceNodeMask", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceNodeMask");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkPhysicalDeviceVulkan11Properties->deviceNodeMask);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDeviceLUIDValid", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceLUIDValid");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkPhysicalDeviceVulkan11Properties->deviceLUIDValid);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubgroupSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubgroupSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkPhysicalDeviceVulkan11Properties->subgroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubgroupSupportedStages", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubgroupSupportedStages");
            return;
        }

        jobject vkShaderStageFlagsEnumSet = createVkShaderStageFlagsAsEnumSet(env, vkPhysicalDeviceVulkan11Properties->subgroupSupportedStages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSampleCountFlagBitsAsEnumSet");
            return;
        }

        if (vkShaderStageFlagsEnumSet == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createVkShaderStageFlagsAsEnumSet, setSubgroupSupportedStages was nullptr");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkShaderStageFlagsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubgroupSupportedOperations", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubgroupSupportedOperations");
            return;
        }

        jobject vkSubgroupFeatureFlagsEnumSet = createVkSubgroupFeatureFlagsAsEnumSet(env, vkPhysicalDeviceVulkan11Properties->subgroupSupportedOperations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkSubgroupFeatureFlagsAsEnumSet");
            return;
        }

        if (vkShaderStageFlagsEnumSet == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createVkSubgroupFeatureFlagsAsEnumSet, setSubgroupSupportedOperations was nullptr");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkSubgroupFeatureFlagsEnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubgroupQuadOperationsInAllStages", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubgroupQuadOperationsInAllStages");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkPhysicalDeviceVulkan11Properties->subgroupQuadOperationsInAllStages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject jVkPointClippingBehaviorObject = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkPointClippingBehavior",
				vkPhysicalDeviceVulkan11Properties->pointClippingBehavior);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setPointClippingBehavior", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPointClippingBehavior;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPointClippingBehavior");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, jVkPointClippingBehaviorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxMultiviewViewCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMultiviewViewCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkPhysicalDeviceVulkan11Properties->maxMultiviewViewCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxMultiviewInstanceIndex", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMultiviewInstanceIndex");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkPhysicalDeviceVulkan11Properties->maxMultiviewInstanceIndex);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setProtectedNoFault", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setProtectedNoFault");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkPhysicalDeviceVulkan11Properties->protectedNoFault);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxPerSetDescriptors", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxPerSetDescriptors");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkPhysicalDeviceVulkan11Properties->maxPerSetDescriptors);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxMemoryAllocationSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMemoryAllocationSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceVulkan11PropertiesObject, methodId, vkPhysicalDeviceVulkan11Properties->maxMemoryAllocationSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
