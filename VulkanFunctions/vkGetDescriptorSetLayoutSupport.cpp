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
 * vkGetDescriptorSetLayoutSupport.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetDescriptorSetLayoutSupport
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VkDescriptorSetLayoutCreateInfo;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkDescriptorSetLayoutSupport;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetDescriptorSetLayoutSupport
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDescriptorSetLayoutCreateInfo, jobject jVkDescriptorSetLayoutSupport)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkDescriptorSetLayoutCreateInfo vkDescriptorSetLayoutCreateInfo = {};
    jvulkan::getVkDescriptorSetLayoutCreateInfo(
            env,
			jVkDescriptorSetLayoutCreateInfo,
			&vkDescriptorSetLayoutCreateInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkDescriptorSetLayoutCreateInfo.");
        return;
    }

    /*
     * For "output" data we need to crawl the pNext chain "first" so that all of
     * the pNext structures are already in place before the API call.  For "input"
     * items their pNext has already been crawled in the "get" functions (in this
     * case getVkDescriptorSetLayoutCreateInfo) before the API call.
     */
    void *headOfpNextChain = nullptr;
    ////////////////////////////////////////////////////////////////////////
    jobject jpNextObject = jvulkan::getpNextObject(env, jVkDescriptorSetLayoutSupport);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getpNext failed.");
        return;
    }

    if (jpNextObject != nullptr)
    {
		/*
		 * Crawl the pNext chain and identify / create any needed elements.
		 */
		jvulkan::getpNextChain(
				env,
				jpNextObject,
				&headOfpNextChain,
				&memoryToFree);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error trying to crawl the pNext chain.");
			return;
		}
    }

    VkDescriptorSetLayoutSupport vkDescriptorSetLayoutSupport = {};
    vkDescriptorSetLayoutSupport.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT;
    vkDescriptorSetLayoutSupport.pNext = headOfpNextChain;

    vkGetDescriptorSetLayoutSupport(
    		deviceHandle,
			&vkDescriptorSetLayoutCreateInfo,
			&vkDescriptorSetLayoutSupport);

    /*
     * We have the data now we have some other work to do.
     *
     * First we need to crawl the pNext chain again and
     * populate the Java Object equivalents that may be
     * on it.  In this case the pNext chain data is out bound.
     */

    if (jpNextObject != nullptr)
    {
		jvulkan::populatepNextChain(
				env,
				jpNextObject,
				headOfpNextChain,
				&memoryToFree);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error trying to crawl the pNext chain.");
			return;
		}
    }

    jvulkan::populateVkDescriptorSetLayoutSupport(
    		env,
			jVkDescriptorSetLayoutSupport,
			&vkDescriptorSetLayoutSupport);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkDescriptorSetLayoutSupport");
        return;
    }

    jvulkan::freeMemory(&memoryToFree);
}
