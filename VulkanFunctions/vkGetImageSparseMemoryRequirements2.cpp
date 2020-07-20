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
 * vkGetImageSparseMemoryRequirements2.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetImageSparseMemoryRequirements2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageSparseMemoryRequirementsInfo2;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetImageSparseMemoryRequirements2
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkImageSparseMemoryRequirementsInfo2, jobject jVkSparseImageMemoryRequirements2Collection)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkImageSparseMemoryRequirementsInfo2 vkImageSparseMemoryRequirementsInfo2 = {};
	jvulkan::getVkImageSparseMemoryRequirementsInfo2(
			env,
			jVkImageSparseMemoryRequirementsInfo2,
			&vkImageSparseMemoryRequirementsInfo2,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVkImageSparseMemoryRequirementsInfo2");
		return;
	}


    uint32_t numberOfVkSparseImageMemoryRequirements2s = 0;

    vkGetImageSparseMemoryRequirements2(
    		deviceHandle,
			&vkImageSparseMemoryRequirementsInfo2,
			&numberOfVkSparseImageMemoryRequirements2s,
			nullptr);

    VkSparseImageMemoryRequirements2 *vkSparseImageMemoryRequirements2s =
    		(VkSparseImageMemoryRequirements2 *)calloc(numberOfVkSparseImageMemoryRequirements2s, sizeof(VkSparseImageMemoryRequirements2));
    if (vkSparseImageMemoryRequirements2s == nullptr)
    {
    	LOGERROR(env, "Could allocate memory for %d VkSparseImageMemoryRequirements2 elements", numberOfVkSparseImageMemoryRequirements2s);
        return;
    }

    vkGetImageSparseMemoryRequirements2(
    		deviceHandle,
			&vkImageSparseMemoryRequirementsInfo2,
			&numberOfVkSparseImageMemoryRequirements2s,
			vkSparseImageMemoryRequirements2s);

    jvulkan::populateVkSparseImageMemoryRequirements2Collection(
    		env,
			jVkSparseImageMemoryRequirements2Collection,
			vkSparseImageMemoryRequirements2s,
			numberOfVkSparseImageMemoryRequirements2s);
    if (env->ExceptionOccurred())
    {
        free(vkSparseImageMemoryRequirements2s);
    	LOGERROR(env, "%s", "Error calling populateVkSparseImageMemoryRequirements2Collection.");
        return;
    }

    free(vkSparseImageMemoryRequirements2s);

    jvulkan::freeMemory(&memoryToFree);
}
