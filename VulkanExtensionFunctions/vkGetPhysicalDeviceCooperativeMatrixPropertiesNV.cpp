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
 * vkGetPhysicalDeviceCooperativeMatrixPropertiesNV.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceCooperativeMatrixPropertiesNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkCooperativeMatrixPropertiesNVCollection)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	uint32_t propertiesCount = 0;

    VkResult result = vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    		physicalDeviceHandle,
			&propertiesCount,
			nullptr);

    if (result != VK_SUCCESS)
    {
		LOGERROR(env, "%s", "First call to vkGetPhysicalDeviceCooperativeMatrixPropertiesNV failed.");
		return jvulkan::createVkResult(env, result);
    }
    else
    {
    	if (propertiesCount == 0)
    	{
    		return jvulkan::createVkResult(env, result);
    	}
    }

    VkCooperativeMatrixPropertiesNV *VkCooperativeMatrixPropertiesNVs =
    		(VkCooperativeMatrixPropertiesNV *)calloc(propertiesCount, sizeof(VkCooperativeMatrixPropertiesNV));
    if (VkCooperativeMatrixPropertiesNVs == nullptr)
    {
		LOGERROR(env, "%s", "Could allocate memory for VkCooperativeMatrixPropertiesNVs,");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    for(int i = 0; i < propertiesCount; i++)
    {
    	VkCooperativeMatrixPropertiesNVs[i].sType = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV;
    	VkCooperativeMatrixPropertiesNVs[i].pNext = nullptr;  // This line is not really needed because of the calloc above
    }

    result = vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    		physicalDeviceHandle,
			&propertiesCount,
			VkCooperativeMatrixPropertiesNVs);

    if (result != VK_SUCCESS)
    {
		LOGERROR(env, "%s", "First call to vkGetPhysicalDeviceCooperativeMatrixPropertiesNV failed.");
		return jvulkan::createVkResult(env, result);
    }

    jvulkan::populateVkCooperativeMatrixPropertiesNVCollection(
			env,
			jVkCooperativeMatrixPropertiesNVCollection,
			VkCooperativeMatrixPropertiesNVs,
			propertiesCount);


    free(VkCooperativeMatrixPropertiesNVs);

	if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkCooperativeMatrixPropertiesNVCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
}
