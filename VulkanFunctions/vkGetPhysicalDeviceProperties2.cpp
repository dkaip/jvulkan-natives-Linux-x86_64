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
 * vkGetPhysicalDeviceProperties2.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "slf4j.hh"

using namespace std;

extern const char *voidMethodErrorText;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceProperties2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceProperties2;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceProperties2
  (JNIEnv *env , jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceProperties2Object)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get handle for jVkPhysicalDevice");
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
    jobject jpNextObject = jvulkan::getpNextObject(env, jVkPhysicalDeviceProperties2Object);
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

    VkPhysicalDeviceProperties2 vkPhysicalDeviceProperties2 = {};
    /*
     * This needs to be done because the above line does not
     * properly init the object.  In other cases a "get"
     * helper function is called which does the job or it is
     * taken care of in getpNextChain
     */
    vkPhysicalDeviceProperties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
    vkPhysicalDeviceProperties2.pNext = headOfpNextChain;

    vkGetPhysicalDeviceProperties2(
    		vkPhysicalDeviceHandle,
			&vkPhysicalDeviceProperties2);

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
     * Now populate the properties attribute of the VkPhysicalDeviceProperties2
     * object
     */
	jclass vkPhysicalDevicePropertiesClass = nullptr;
	jobject jVkPhysicalDevicePropertiesObject = nullptr;
	jvulkan::createJavaObjectUsingDefaultConstructor(
			env,
			"com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceProperties",
			&vkPhysicalDevicePropertiesClass,
			&jVkPhysicalDevicePropertiesObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor.");
        return;
    }

    jvulkan::populateVkPhysicalDeviceProperties(
    		env,
			jVkPhysicalDevicePropertiesObject,
			&vkPhysicalDeviceProperties2.properties);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceProperties");
        return;
    }

    jclass vkPhysicalDeviceProperties2Class = env->GetObjectClass(jVkPhysicalDeviceProperties2Object);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find class of jVkPhysicalDeviceProperties2");
        return;
    }

    jmethodID methodId = env->GetMethodID(vkPhysicalDeviceProperties2Class, "setProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceProperties;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id setProperties for class jVkPhysicalDeviceProperties2");
        return;
    }

    env->CallVoidMethod(jVkPhysicalDeviceProperties2Object, methodId, jVkPhysicalDevicePropertiesObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", voidMethodErrorText);
        return;
    }

    jvulkan::freeMemory(&memoryToFree);
}
