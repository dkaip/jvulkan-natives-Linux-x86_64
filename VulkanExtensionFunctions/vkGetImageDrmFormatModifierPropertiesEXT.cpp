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
 * vkGetImageDrmFormatModifierPropertiesEXT.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetImageDrmFormatModifierPropertiesEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetImageDrmFormatModifierPropertiesEXT
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkImage, jobject jVkImageDrmFormatModifierPropertiesEXT)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkImage_T *imageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jVkImage);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkImage handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkImageDrmFormatModifierPropertiesEXT vkImageDrmFormatModifierPropertiesEXT = {};
	vkImageDrmFormatModifierPropertiesEXT.sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT;
	vkImageDrmFormatModifierPropertiesEXT.pNext = nullptr;

	VkResult result = vkGetImageDrmFormatModifierPropertiesEXT(
			deviceHandle,
			imageHandle,
			&vkImageDrmFormatModifierPropertiesEXT);

    std::vector<void *> memoryToFree(5);
	jvulkan::populateVkImageDrmFormatModifierPropertiesEXT(
		env,
		jVkImageDrmFormatModifierPropertiesEXT,
		&vkImageDrmFormatModifierPropertiesEXT,
		&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling populateVkImageDrmFormatModifierPropertiesEXT.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    jvulkan::freeMemory(&memoryToFree);

	return jvulkan::createVkResult(env, result);
}
