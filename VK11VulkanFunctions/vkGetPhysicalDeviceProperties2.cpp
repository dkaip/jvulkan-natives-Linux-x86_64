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
 * vkGetPhysicalDeviceProperties2.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

extern const char *voidMethodErrorText;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceProperties2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceProperties2;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceProperties2
  (JNIEnv *env , jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceProperties2Object)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get handle for jVkPhysicalDevice");
        return;
    }

    std::vector<void *> memoryToFree(20);
    void *headOfpNextChain = nullptr;

    ////////////////////////////////////////////////////////////////////////
    jobject jpNextObject = jvulkan::getpNextObject(env, jVkPhysicalDeviceProperties2Object);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getpNext failed.");
        return;
    }

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

    VkPhysicalDeviceProperties2 vkPhysicalDeviceProperties2 = {};
    /*
     * TODO
     * Hmmm, I did not have to do this elsewhere...is there is bug or do I need
     * to go and fix all of the other references like this?
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
     * create the Java Object equivalents that may be
     * on it.
     */

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

    /*
     * Now populate the properties attribute of the VkPhysicalDeviceProperties2
     * object
     */
	jclass vkPhysicalDevicePropertiesClass = env->FindClass(
			"com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceProperties");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceProperties");
			return;
		}

	// Locate the constructor
	jmethodID methodId = env->GetMethodID(vkPhysicalDevicePropertiesClass, "<init>", "()V");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id <init> for class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceProperties");
		return;
	}

	// Create the Java vkPhysicalDeviceProperties object
	jobject jVkPhysicalDevicePropertiesObject =
			env->NewObject(vkPhysicalDevicePropertiesClass, methodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could construct class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceProperties");
		return;
	}

    jvulkan::createVkPhysicalDeviceProperties(
    		env,
			jVkPhysicalDevicePropertiesObject,
			&vkPhysicalDeviceProperties2.properties);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVkPhysicalDeviceProperties");
        return;
    }

    jclass vkPhysicalDeviceProperties2Class = env->GetObjectClass(jVkPhysicalDeviceProperties2Object);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find class of jVkPhysicalDeviceProperties2");
        return;
    }

    methodId = env->GetMethodID(vkPhysicalDeviceProperties2Class, "setProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceProperties;)V");
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
