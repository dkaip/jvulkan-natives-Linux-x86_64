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

        jobject deviceLimitsObject = createVkPhysicalDeviceLimits(env, &(vkPhysicalDeviceProperties->limits));
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

        jobject sparsePropertiesObject = createVkPhysicalDeviceSparseProperties(env, &(vkPhysicalDeviceProperties->sparseProperties));
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
}
