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
 * vkEnumeratePhysicalDeviceGroups.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include <vector>

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkEnumeratePhysicalDeviceGroups
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkInstance;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkEnumeratePhysicalDeviceGroups
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkPhysicalDeviceGroupPropertiesCollection)
{
	VkInstance_T *instanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkInstance handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t physicalDeviceGroupCount = 0;

    VkResult result = vkEnumeratePhysicalDeviceGroups(
    		instanceHandle,
			&physicalDeviceGroupCount,
			nullptr);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Call to vkEnumeratePhysicalDeviceGroups failed.");
        return jvulkan::createVkResult(env, result);
    }

    if (physicalDeviceGroupCount != 0)
    {
        std::vector<VkPhysicalDeviceGroupProperties> properties(physicalDeviceGroupCount);

        result = vkEnumeratePhysicalDeviceGroups(
        		instanceHandle,
				&physicalDeviceGroupCount,
				properties.data());

		if (result != VK_SUCCESS)
		{
			LOGERROR(env, "%s", "Call to vkEnumeratePhysicalDeviceGroups failed.");
			return jvulkan::createVkResult(env, result);
		}

		jclass vkPhysicalDeviceGroupPropertiesClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceGroupProperties");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceGroupProperties");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID constructorMethod = env->GetMethodID(vkPhysicalDeviceGroupPropertiesClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jclass collectionClass = env->GetObjectClass(jVkPhysicalDeviceGroupPropertiesCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceGroupPropertiesCollection");
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
            jobject newObject = env->NewObject(vkPhysicalDeviceGroupPropertiesClass, constructorMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not create a new VkPhysicalDeviceGroupProperties object");
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            jvulkan::populateVkPhysicalDeviceGroupProperties(
            		env,
        			newObject,
					&property);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceGroupProperties");
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            bool addResult = env->CallBooleanMethod(jVkPhysicalDeviceGroupPropertiesCollection, addMethodId, newObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Error VkPhysicalDeviceGroupProperties element did not get added.");
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }
        }
    }

    return jvulkan::createVkResult(env, result);

}
