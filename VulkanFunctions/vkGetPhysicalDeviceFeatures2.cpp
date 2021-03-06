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
 * vkGetPhysicalDeviceFeatures2.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceFeatures2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceFeatures2;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceFeatures2
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceFeatures2Object)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return;
	}

    std::vector<void *> memoryToFree(20);

    /*
     * For "output" data we need to crawl the pNext chain "first" so that all of
     * the pNext structures are already in place before the API call.  For "input"
     * items their pNext has already been crawled in the "get" functions (in this
     * case NA) before the API call.
     */
    void *headOfpNextChain = nullptr;
    ////////////////////////////////////////////////////////////////////////
    jobject jpNextObject = jvulkan::getpNextObject(env, jVkPhysicalDeviceFeatures2Object);
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

    VkPhysicalDeviceFeatures2 vkPhysicalDeviceFeatures2 = {};
    /*
     * This needs to be done because the above line does not
     * properly init the object.  In other cases a "get"
     * helper function is called which does the job or it is
     * taken care of in getpNextChain
     */
    vkPhysicalDeviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
    vkPhysicalDeviceFeatures2.pNext = headOfpNextChain;

    vkGetPhysicalDeviceFeatures2(
    		physicalDeviceHandle,
			&vkPhysicalDeviceFeatures2);

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

    /*
     * Now populate the properties attribute of the VkPhysicalDeviceFeatures2
     * object
     */
	jclass vkPhysicalDeviceFeaturesClass = nullptr;
	jobject jVkPhysicalDeviceFeaturesObject = nullptr;
	jvulkan::createJavaObjectUsingDefaultConstructor(
			env,
			"com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceFeatures",
			&vkPhysicalDeviceFeaturesClass,
			&jVkPhysicalDeviceFeaturesObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor.");
        return;
    }

    jvulkan::populateVkPhysicalDeviceFeatures(
    		env,
			jVkPhysicalDeviceFeaturesObject,
			&vkPhysicalDeviceFeatures2.features,
			nullptr);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceFeatures");
        return;
    }

    jclass vkPhysicalDeviceFeatures2Class = env->GetObjectClass(jVkPhysicalDeviceFeatures2Object);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find class of jVkPhysicalDeviceFeatures2Object");
        return;
    }

    jmethodID methodId = env->GetMethodID(vkPhysicalDeviceFeatures2Class, "setFeatures", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceFeatures;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id setFeatures for class jVkPhysicalDeviceFeatures2Object");
        return;
    }

    env->CallVoidMethod(jVkPhysicalDeviceFeatures2Object, methodId, jVkPhysicalDeviceFeaturesObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallVoidMethod.");
        return;
    }

    jvulkan::freeMemory(&memoryToFree);
}
