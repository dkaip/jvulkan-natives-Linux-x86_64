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
 * vkGetPhysicalDeviceImageFormatProperties.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceImageFormatProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageType;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageTiling;Ljava/util/EnumSet;Ljava/util/EnumSet;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageFormatProperties;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceImageFormatProperties
  (JNIEnv *env , jobject, jobject jVkPhysicalDeviceObject, jobject jVkFormatObject, jobject jVkImageTypeObject, jobject jVkImageTilingObject, jobject jVkImageUsageFlagsObject, jobject jVkImageCreateFlagsObject, jobject jVkImageFormatPropertiesObject)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDeviceObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getHandleValue.");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    VkFormat vkFormat = (VkFormat)0;
    jvulkan::getVkFormat(
            env,
			jVkFormatObject,
			&vkFormat,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling method getVkFormat");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkImageTypeClass = env->GetObjectClass(jVkImageTypeObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get class for jVkImageTypeObject");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkImageTypeClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id valueOf.");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkImageType vkImageTypeEnumValue = (VkImageType)env->CallIntMethod(jVkImageTypeObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkImageTilingClass = env->GetObjectClass(jVkImageTilingObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get class for jVkImageTilingObject");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    valueOfMethodId = env->GetMethodID(vkImageTypeClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id valueOf.");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkImageTiling vkImageTilingEnumValue = (VkImageTiling)env->CallIntMethod(jVkImageTilingObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	////////////////////////////////////////////////////////////////////////
    VkImageUsageFlags vkImageUsageFlags = (VkImageUsageFlags)jvulkan::getEnumSetValue(
			env,
			jVkImageUsageFlagsObject,
			"com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageUsageFlagBits");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getEnumSetValue");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	////////////////////////////////////////////////////////////////////////
    VkImageCreateFlags vkImageCreateFlagsFlags = (VkImageCreateFlags)jvulkan::getEnumSetValue(
			env,
			jVkImageCreateFlagsObject,
			"com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageCreateFlagBits");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getEnumSetValue");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }


	////////////////////////////////////////////////////////////////////////
    VkImageFormatProperties vkImageFormatProperties = {};
    jvulkan::getVkImageFormatProperties(
            env,
            jVkImageFormatPropertiesObject,
			&vkImageFormatProperties,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getVkImageFormatProperties");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkResult result = vkGetPhysicalDeviceImageFormatProperties(
    		physicalDeviceHandle,
			vkFormat,
			vkImageTypeEnumValue,
			vkImageTilingEnumValue,
			vkImageUsageFlags,
			vkImageCreateFlagsFlags,
			&vkImageFormatProperties);

    if (result == VK_SUCCESS)
    {
		jvulkan::populateVkImageFormatProperties(
				env,
				jVkImageFormatPropertiesObject,
				&vkImageFormatProperties,
				&memoryToFree);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling jvulkan::populateVkImageFormatProperties");
			return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
		}
    }

	jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
