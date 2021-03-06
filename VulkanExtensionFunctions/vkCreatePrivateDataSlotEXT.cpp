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
 * vkCreatePrivateDataSlotEXT.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCreatePrivateDataSlotEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkPrivateDataSlotCreateInfoEXT;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkPrivateDataSlotEXT;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCreatePrivateDataSlotEXT
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPrivateDataSlotCreateInfoEXTObject, jobject jAlternateAllocator, jobject jVkPrivateDataSlotEXTObject)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    std::vector<void *> memoryToFree(5);
    VkPrivateDataSlotCreateInfoEXT vkPrivateDataSlotCreateInfoEXT = {};
    jvulkan::getVkPrivateDataSlotCreateInfoEXT(
            env,
			jVkPrivateDataSlotCreateInfoEXTObject,
			&vkPrivateDataSlotCreateInfoEXT,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkPrivateDataSlotCreateInfoEXT.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPrivateDataSlotEXT_T *privateDataSlot = nullptr;
    VkResult result = vkCreatePrivateDataSlotEXT(
    		deviceHandle,
			&vkPrivateDataSlotCreateInfoEXT,
			allocatorCallbacks,
			&privateDataSlot);

    if (result != VK_SUCCESS)
    {
    	jvulkan::freeMemory(&memoryToFree);
    	LOGERROR(env, "%s", "Error calling vkCreatePrivateDataSlotEXT.");
        return jvulkan::createVkResult(env, result);
    }

    jvulkan::setHandleValue(env, jVkPrivateDataSlotEXTObject, privateDataSlot);
    if (env->ExceptionOccurred())
    {
    	jvulkan::freeMemory(&memoryToFree);
    	LOGERROR(env, "%s", "Error calling setHandleValue.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	jvulkan::freeMemory(&memoryToFree);

	return jvulkan::createVkResult(env, result);
}
