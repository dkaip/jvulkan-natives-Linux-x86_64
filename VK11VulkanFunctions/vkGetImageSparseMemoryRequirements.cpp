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
 * vkGetImageSparseMemoryRequirements.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetImageSparseMemoryRequirements
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkImage;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetImageSparseMemoryRequirements
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkImage, jobject jVkSparseImageMemoryRequirementsCollection)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return;
    }

    VkImage_T *imageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jVkImage);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkImage handle");
        return;
    }

    uint32_t numberOfVkSparseImageMemoryRequirements = 0;

    vkGetImageSparseMemoryRequirements(
    		deviceHandle,
			imageHandle,
			&numberOfVkSparseImageMemoryRequirements,
			nullptr);

    VkSparseImageMemoryRequirements *vkSparseImageMemoryRequirements =
    		(VkSparseImageMemoryRequirements *)calloc(numberOfVkSparseImageMemoryRequirements, sizeof(VkSparseImageMemoryRequirements));
    if (vkSparseImageMemoryRequirements == nullptr)
    {
    	LOGERROR(env, "Could allocate memory for %d VkSparseImageMemoryRequirements elements", numberOfVkSparseImageMemoryRequirements);
        return;
    }

    vkGetImageSparseMemoryRequirements(
    		deviceHandle,
			imageHandle,
			&numberOfVkSparseImageMemoryRequirements,
			vkSparseImageMemoryRequirements);

    jvulkan::populateVkSparseImageMemoryRequirementsCollection(
    		env,
			jVkSparseImageMemoryRequirementsCollection,
			vkSparseImageMemoryRequirements,
			numberOfVkSparseImageMemoryRequirements);
    if (env->ExceptionOccurred())
    {
        free(vkSparseImageMemoryRequirements);
    	LOGERROR(env, "%s", "Error calling populateVkSparseImageMemoryRequirementsCollection.");
        return;
    }

    free(vkSparseImageMemoryRequirements);
}
