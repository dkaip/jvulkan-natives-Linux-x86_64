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
 * vkGetPhysicalDeviceFormatProperties2.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceFormatProperties2
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkFormatProperties2;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceFormatProperties2
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkFormat, jobject jVkFormatProperties2Object)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get handle for jVkPhysicalDevice");
        return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkFormatEnumClass = env->GetObjectClass(jVkFormat);

    jmethodID valueOfMethodId = env->GetMethodID(vkFormatEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkFormat vkFormatEnumValue = (VkFormat)env->CallIntMethod(jVkFormat, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
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
    jobject jpNextObject = jvulkan::getpNextObject(env, jVkFormatProperties2Object);
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

    VkFormatProperties2 vkFormatProperties2 = {};
    /*
     * This needs to be done because the above line does not
     * properly init the object.  In other cases a "get"
     * helper function is called which does the job or it is
     * taken care of in getpNextChain
     */
    vkFormatProperties2.sType = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2;
    vkFormatProperties2.pNext = headOfpNextChain;

    vkGetPhysicalDeviceFormatProperties2(
    		vkPhysicalDeviceHandle,
			vkFormatEnumValue,
			&vkFormatProperties2);

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
     * Now populate the properties attribute of the jVkFormatProperties2Object
     * object
     */
	jclass vkFormatPropertiesClass = env->FindClass(
			"com/CIMthetics/jvulkan/VulkanCore/Structures/VkFormatProperties");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkFormatProperties");
			return;
		}

	// Locate the constructor
	jmethodID methodId = env->GetMethodID(vkFormatPropertiesClass, "<init>", "()V");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id <init> for class com/CIMthetics/jvulkan/VulkanCore/Structures/VkFormatProperties");
		return;
	}

	// Create the Java VkFormatProperties object
	jobject jVkFormatPropertiesObject =
			env->NewObject(vkFormatPropertiesClass, methodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could construct class com/CIMthetics/jvulkan/VulkanCore/Structures/VkFormatProperties");
		return;
	}

    jvulkan::populateVkFormatProperties(
    		env,
			jVkFormatPropertiesObject,
			&vkFormatProperties2.formatProperties);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkFormatProperties");
        return;
    }

    jclass vkFormatProperties2ObjectClass = env->GetObjectClass(jVkFormatProperties2Object);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find class of jVkFormatProperties2Object");
        return;
    }

    methodId = env->GetMethodID(vkFormatProperties2ObjectClass, "setFormatProperties", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkFormatProperties;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id setProperties for class setFormatProperties");
        return;
    }

    env->CallVoidMethod(jVkFormatProperties2Object, methodId, jVkFormatPropertiesObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", voidMethodErrorText);
        return;
    }

    jvulkan::freeMemory(&memoryToFree);
}
