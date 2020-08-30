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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetAccelerationStructureMemoryRequirementsNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkAccelerationStructureMemoryRequirementsInfoNV;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkMemoryRequirements2KHR;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetAccelerationStructureMemoryRequirementsNV
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkAccelerationStructureMemoryRequirementsInfoNV, jobject jVkMemoryRequirements2KHR)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get jVkDevice.");
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkAccelerationStructureMemoryRequirementsInfoNV vkAccelerationStructureMemoryRequirementsInfoNV = {};
    jvulkan::getVkAccelerationStructureMemoryRequirementsInfoNV(
            env,
			jVkAccelerationStructureMemoryRequirementsInfoNV,
			&vkAccelerationStructureMemoryRequirementsInfoNV,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkAccelerationStructureMemoryRequirementsInfoNV.");
        return;
    }

    VkMemoryRequirements2KHR vkMemoryRequirements2KHR = {};
    vkMemoryRequirements2KHR.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV;
    vkMemoryRequirements2KHR.pNext = nullptr;

    vkGetAccelerationStructureMemoryRequirementsNV(
    		logicalDeviceHandle,
			&vkAccelerationStructureMemoryRequirementsInfoNV,
			&vkMemoryRequirements2KHR);


	jvulkan::populateVkMemoryRequirements2(env, jVkMemoryRequirements2KHR, &vkMemoryRequirements2KHR);
	if (env->ExceptionOccurred())
	{
		jvulkan::freeMemory(&memoryToFree);
		LOGERROR(env, "%s", "Error calling populateVkMemoryRequirements2.");
		return;
	}

	jvulkan::freeMemory(&memoryToFree);
}
