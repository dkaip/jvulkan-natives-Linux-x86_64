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
 * vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;ILcom/CIMthetics/jvulkan/VulkanCore/Structures/IntReturnValue;Ljava/util/Collection;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jint jQueueFamilyIndex, jobject jCounterCount, jobject jCountersCollectionObject, jobject jCounterDescriptionsCollectionObject)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	unsigned int queueFamilyIndex = (unsigned int)jQueueFamilyIndex;

	int desiredCounterCount = jvulkan::getIntReturnValue(env, jCounterCount);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getIntReturnValue.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    unsigned int actualCounterCount = 0;
	VkResult result = vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
			physicalDeviceHandle,
			queueFamilyIndex,
			&actualCounterCount,
			nullptr,
			nullptr);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (jCountersCollectionObject == nullptr && jCounterDescriptionsCollectionObject == nullptr)
    {
    	/*
    	 * All that is desired is the actual count so just set it
    	 * and return.
    	 */
    	jvulkan::setIntReturnValue(env, jCounterCount, actualCounterCount);
        return jvulkan::createVkResult(env, (jint)result);
    }

    /*
     * Set the max counter count to the smaller of
     * the actual number of counters or the number
     * requested.
     */
	int maxCounterCount = actualCounterCount;
	if (desiredCounterCount > 0)
	{
		maxCounterCount = std::min(maxCounterCount, desiredCounterCount);
	}

	/*
	 * Set the number counters that are having their data
	 * returned.
	 */
	jvulkan::setIntReturnValue(env, jCounterCount, maxCounterCount);

	VkPerformanceCounterKHR *counters = nullptr;
	VkPerformanceCounterDescriptionKHR *counterDescriptions = nullptr;

	if (jCountersCollectionObject != nullptr)
	{
		counters = (VkPerformanceCounterKHR *)calloc(maxCounterCount, sizeof(VkPerformanceCounterKHR));
		if (counters == nullptr)
		{
	    	LOGERROR(env, "%s", "Error trying to allocation memory for counters.");
	        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
		}
	}

	if (jCounterDescriptionsCollectionObject != nullptr)
	{
		counterDescriptions = (VkPerformanceCounterDescriptionKHR *)calloc(maxCounterCount, sizeof(VkPerformanceCounterDescriptionKHR));
    	LOGERROR(env, "%s", "Error trying to allocation memory for counterDescriptions.");
    	free(counters);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	result = vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
			physicalDeviceHandle,
			queueFamilyIndex,
			(unsigned int *)&maxCounterCount,
			counters,
			counterDescriptions);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR.");
    	free(counters);
    	free(counterDescriptions);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (counters != nullptr)
    {
    	jvulkan::populateVkPerformanceCounterKHRCollection(
    			env,
				jCountersCollectionObject,
				counters,
				maxCounterCount);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling populateVkPerformanceCounterKHRCollection");
        	free(counters);
        	free(counterDescriptions);
    		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    	}
    }

    if (counterDescriptions != nullptr)
    {
    	jvulkan::populateVkPerformanceCounterDescriptionKHRCollection(
    			env,
				jCounterDescriptionsCollectionObject,
				counterDescriptions,
				maxCounterCount);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling populateVkPerformanceCounterDescriptionKHRCollection");
        	free(counters);
        	free(counterDescriptions);
    		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    	}
    }

	free(counters);
	free(counterDescriptions);

	return jvulkan::createVkResult(env, (jint)result);
}
