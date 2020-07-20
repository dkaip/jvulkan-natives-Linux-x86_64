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
 * vkEnumerateDeviceLayerProperties.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include <vector>

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkEnumerateDeviceLayerProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkEnumerateDeviceLayerProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkLayerPropertiesCollection)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t propertyCount = 0;

    VkResult result = vkEnumerateDeviceLayerProperties(
    		vkPhysicalDeviceHandle,
			&propertyCount,
			nullptr);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Call to vkEnumerateDeviceLayerProperties failed.");
        return jvulkan::createVkResult(env, result);
    }

    if (propertyCount != 0)
    {
        std::vector<VkLayerProperties> properties(propertyCount);

        result = vkEnumerateDeviceLayerProperties(
				vkPhysicalDeviceHandle,
				&propertyCount,
				properties.data());

		if (result != VK_SUCCESS)
		{
			LOGERROR(env, "%s", "Call to vkEnumerateDeviceLayerProperties failed.");
			return jvulkan::createVkResult(env, result);
		}

		jclass vkLayerPropertiesClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Structures/VkLayerProperties");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkLayerProperties");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID constructorMethod = env->GetMethodID(vkLayerPropertiesClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jclass collectionClass = env->GetObjectClass(jVkLayerPropertiesCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkLayerPropertiesCollection");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        for (const auto& property : properties)
        {
            jobject newObject = env->NewObject(vkLayerPropertiesClass, constructorMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not create a new VkLayerProperties object");
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            jvulkan::populateVkLayerProperties(
            		env,
        			newObject,
					&property);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling populateVkLayerProperties");
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            bool addResult = env->CallBooleanMethod(jVkLayerPropertiesCollection, addMethodId, newObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Error VkLayerProperties element did not get added.");
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }
        }
    }

    return jvulkan::createVkResult(env, result);
}
