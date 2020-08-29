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
 * vkGetPhysicalDeviceToolPropertiesEXT.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceToolPropertiesEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceToolPropertiesEXT
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceToolPropertiesEXTCollectionObject)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkPhysicalDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t toolCount = 0;
    VkResult result = vkGetPhysicalDeviceToolPropertiesEXT(
    		physicalDeviceHandle,
			&toolCount,
			nullptr);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "Error calling vkGetPhysicalDeviceToolPropertiesEXT:%d", result);
        return jvulkan::createVkResult(env, result);
    }

    if (toolCount == 0)
    {
        return jvulkan::createVkResult(env, result);
    }

    VkPhysicalDeviceToolPropertiesEXT *toolProperties = (VkPhysicalDeviceToolPropertiesEXT *)calloc(toolCount, sizeof(VkPhysicalDeviceToolPropertiesEXT));
    if (toolProperties == nullptr)
    {
    	LOGERROR(env, "Could not allocate memory for %d VkPhysicalDeviceToolPropertiesEXTs.", toolCount);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jvulkan::populateVkPhysicalDeviceToolPropertiesEXTCollection(
			env,
			jVkPhysicalDeviceToolPropertiesEXTCollectionObject,
			toolProperties,
			toolCount);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Error calling populateVkPipelineExecutablePropertiesKHRCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    free(toolProperties);

    return jvulkan::createVkResult(env, result);

}
