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
 * vkMergePipelineCaches.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkMergePipelineCaches
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineCache;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkMergePipelineCaches
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jDstVkPipelineCache, jobject jSrcVkPipelineCacheCollection)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPipelineCache_T *dstPipelineCacheHandle = (VkPipelineCache_T *)jvulkan::getHandleValue(env, jDstVkPipelineCache);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jDstVkPipelineCache handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkPipelineCaches = 0;
    VkPipelineCache *vkPipelineCaches = nullptr;
	jvulkan::getVulkanHandleCollection(
			env,
			jSrcVkPipelineCacheCollection,
			(void **)&vkPipelineCaches,
			&numberOfVkPipelineCaches,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getVulkanHandleCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    VkResult result = vkMergePipelineCaches(
    		deviceHandle,
			dstPipelineCacheHandle,
			numberOfVkPipelineCaches,
			vkPipelineCaches);

	jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
