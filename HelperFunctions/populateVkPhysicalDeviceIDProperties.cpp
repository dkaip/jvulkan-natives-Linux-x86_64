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
 * populateVkPhysicalDeviceIDProperties.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceIDProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceIDPropertiesObject,
			const VkPhysicalDeviceIDProperties *vkPhysicalDeviceIDProperties,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceIDPropertiesClass = env->GetObjectClass(
				jVkPhysicalDeviceIDPropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceIDProperties");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(vkPhysicalDeviceIDPropertiesClass, "setDeviceUUID", "([B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceUUID");
            return;
        }

        jbyteArray deviceUUID = env->NewByteArray(sizeof(vkPhysicalDeviceIDProperties->deviceUUID));
        if (deviceUUID == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for deviceUUID");
            return;
        }

        env->SetByteArrayRegion(deviceUUID, 0, sizeof(vkPhysicalDeviceIDProperties->deviceUUID), (const jbyte *)vkPhysicalDeviceIDProperties->deviceUUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetByteArrayRegion");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceIDPropertiesObject, methodId, deviceUUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceIDPropertiesClass, "setDriverUUID", "([B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDriverUUID");
            return;
        }

        jbyteArray driverUUID = env->NewByteArray(sizeof(vkPhysicalDeviceIDProperties->driverUUID));
        if (driverUUID == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for driverUUID");
            return;
        }

        env->SetByteArrayRegion(driverUUID, 0, sizeof(vkPhysicalDeviceIDProperties->driverUUID), (const jbyte *)vkPhysicalDeviceIDProperties->driverUUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetByteArrayRegion");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceIDPropertiesObject, methodId, driverUUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceIDPropertiesClass, "setDeviceLUID", "([B)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceLUID");
            return;
        }

        jbyteArray deviceLUID = env->NewByteArray(sizeof(vkPhysicalDeviceIDProperties->deviceLUID));
        if (deviceLUID == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for deviceLUID");
            return;
        }

        env->SetByteArrayRegion(deviceLUID, 0, sizeof(vkPhysicalDeviceIDProperties->deviceLUID), (const jbyte *)vkPhysicalDeviceIDProperties->deviceLUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetByteArrayRegion");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceIDPropertiesObject, methodId, deviceLUID);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceIDPropertiesClass, "setDeviceNodeMask", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceNodeMask");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceIDPropertiesObject, methodId, vkPhysicalDeviceIDProperties->deviceNodeMask);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceIDPropertiesClass, "setDeviceLUIDValid", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDeviceLUIDValid");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceIDPropertiesObject, methodId, vkPhysicalDeviceIDProperties->deviceLUIDValid);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}
