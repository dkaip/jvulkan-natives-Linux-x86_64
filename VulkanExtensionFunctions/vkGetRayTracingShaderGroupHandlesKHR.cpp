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
 * vkGetRayTracingShaderGroupHandlesKHR.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetRayTracingShaderGroupHandlesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipeline;IILjava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetRayTracingShaderGroupHandlesKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPipeline, jint jFirstGroup, jint jGroupCount, jobject jVulkanHandleCollectionObject)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPipeline_T *pipelineHandle = (VkPipeline_T *)jvulkan::getHandleValue(env, jVkPipeline);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for VkPipeline");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    uint32_t firstGroup = (uint32_t)jFirstGroup;
    uint32_t groupCount = (uint32_t)jGroupCount;

    size_t dataArraySize = sizeof(void *) * groupCount;
    void **dataArray = (void **)calloc(groupCount, sizeof(void *));
    if (dataArray == nullptr)
    {
    	LOGERROR(env, "Could not allocate %d bytes for an array of %d void pointers.", (int)dataArraySize, (int)groupCount);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkResult result = vkGetRayTracingShaderGroupHandlesKHR(
    		deviceHandle,
			pipelineHandle,
			firstGroup,
			groupCount,
			dataArraySize,
			dataArray);
    if (result != VK_SUCCESS)
    {
    	free(dataArray);
    	LOGERROR(env, "Call to vkGetRayTracingShaderGroupHandlesKHR failed with a result of %d.", result);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass collectionClass = env->GetObjectClass(jVulkanHandleCollectionObject);
    if (env->ExceptionOccurred())
    {
    	free(dataArray);
    	LOGERROR(env, "%s", "Could not get class for jVulkanHandleCollectionObject.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
    	free(dataArray);
    	LOGERROR(env, "%s", "Could not find method id for add.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    for (uint32_t i = 0; i < groupCount; i++)
    {
        jobject vulkanHandle = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/VulkanCore/Handles/VulkanHandle", dataArray[i]);
        if (env->ExceptionOccurred())
        {
        	free(dataArray);
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jboolean addResult = env->CallBooleanMethod(jVulkanHandleCollectionObject, addMethodId, vulkanHandle);
        if (env->ExceptionOccurred())
        {
        	free(dataArray);
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        if (addResult == false)
        {
        	LOGERROR(env, "Handle %d was not added to collection.", i);
        }
    }

    free(dataArray);

    return jvulkan::createVkResult(env, result);
}
