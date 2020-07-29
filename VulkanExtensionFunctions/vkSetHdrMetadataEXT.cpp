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
 * vkSetHdrMetadataEXT.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkSetHdrMetadataEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Ljava/util/Collection;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkSetHdrMetadataEXT
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSwapchainKHRCollection, jobject jVkHdrMetadataEXTCollection)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkSwapchainKHRs = 0;
    VkSwapchainKHR *vkSwapchainKHRs = nullptr;
	jvulkan::getVkSwapchainKHRCollection(
			env,
			jVkSwapchainKHRCollection,
			&vkSwapchainKHRs,
			&numberOfVkSwapchainKHRs,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkSwapchainKHRCollection");
		return;
	}

    int numberOfVkHdrMetadataEXTs = 0;
    VkHdrMetadataEXT *vkHdrMetadataEXTs = nullptr;
	jvulkan::getVkHdrMetadataEXTCollection(
			env,
			jVkHdrMetadataEXTCollection,
			&vkHdrMetadataEXTs,
			&numberOfVkHdrMetadataEXTs,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkHdrMetadataEXTCollection");
		return;
	}

	if (numberOfVkSwapchainKHRs != numberOfVkHdrMetadataEXTs)
	{
	    jvulkan::freeMemory(&memoryToFree);
		LOGERROR(env, "%s", "jVkSwapchainKHRCollection and jVkHdrMetadataEXTCollection MUST have the same number of elements.");
		return;
	}

	vkSetHdrMetadataEXT(
			deviceHandle,
			numberOfVkSwapchainKHRs,
			vkSwapchainKHRs,
			vkHdrMetadataEXTs);

    jvulkan::freeMemory(&memoryToFree);
}
