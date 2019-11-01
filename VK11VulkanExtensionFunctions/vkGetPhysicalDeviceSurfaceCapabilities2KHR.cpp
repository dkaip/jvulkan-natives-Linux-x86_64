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
 * vkGetPhysicalDeviceSurfaceCapabilities2KHR.cpp
 *
 *  Created on: May 29, 2019
 *      Author: Douglas Kaip
 */

using namespace std;

extern const char *voidMethodErrorText;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceSurfaceCapabilities2KHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceSurfaceInfo2KHR;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkSurfaceCapabilities2KHR;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceSurfaceCapabilities2KHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceSurfaceInfo2KHR, jobject jVkSurfaceCapabilities2KHR)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getHandleValue.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(20);

    VkPhysicalDeviceSurfaceInfo2KHR vkPhysicalDeviceSurfaceInfo2KHR = {};
    jvulkan::getVkPhysicalDeviceSurfaceInfo2KHR(
            env,
			jVkPhysicalDeviceSurfaceInfo2KHR,
			&vkPhysicalDeviceSurfaceInfo2KHR,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling jvulkan::getVkPhysicalDeviceSurfaceInfo2KHR.");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (jVkSurfaceCapabilities2KHR == nullptr)
    {
    	LOGERROR(env, "%s", "jVkSurfaceCapabilities2KHR must be created before calling vkGetPhysicalDeviceSurfaceCapabilities2KHR.");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    /*
     * For "output" data we need to crawl the pNext chain "first" so that all of
     * the pNext structures are already in place before the API call.  For "input"
     * items their pNext has already been crawled in the "get" functions (in this
     * case getVkPhysicalDeviceSurfaceInfo2KHR) before the API call.
     */
    void *headOfpNextChain = nullptr;
    ////////////////////////////////////////////////////////////////////////
    jobject jpNextObject = jvulkan::getpNextObject(env, jVkSurfaceCapabilities2KHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getpNext failed.");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (jpNextObject != nullptr)
    {
//    	LOGERROR(env, "%s", "jpNextObject is not null");
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
			jvulkan::freeMemory(&memoryToFree);
			return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
		}
    }


    VkSurfaceCapabilities2KHR vkSurfaceCapabilities2KHR = {};
    /*
     * This needs to be done because the above line does not
     * properly init the object.  In other cases a "get"
     * helper function is called which does the job or it is
     * taken care of in getpNextChain
     */
    vkSurfaceCapabilities2KHR.sType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
    vkSurfaceCapabilities2KHR.pNext = headOfpNextChain;

//    LOGERROR(env, "%s:hpnc:%lx", "vkPhysicalDeviceSurfaceInfo2KHR", vkPhysicalDeviceSurfaceInfo2KHR.pNext);
//    LOGERROR(env, "%s:hpnc:%lx", "vkSurfaceCapabilities2KHR", headOfpNextChain);
//    LOGERROR(env, "pdh:%lx", physicalDeviceHandle);
//    LOGERROR(env, "vkPhysicalDeviceSurfaceInfo2KHR sType:%d surface:%lx", vkPhysicalDeviceSurfaceInfo2KHR.sType, vkPhysicalDeviceSurfaceInfo2KHR.surface);
//    LOGERROR(env, "vkSurfaceCapabilities2KHR sType:%d maxImageArrayLayers:%d", vkSurfaceCapabilities2KHR.sType, vkSurfaceCapabilities2KHR.surfaceCapabilities.maxImageArrayLayers);
//    VkResult result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDeviceHandle, vkPhysicalDeviceSurfaceInfo2KHR.surface, &vkSurfaceCapabilities2KHR.surfaceCapabilities);
    VkResult result = vkGetPhysicalDeviceSurfaceCapabilities2KHR(nullptr, &vkPhysicalDeviceSurfaceInfo2KHR, &vkSurfaceCapabilities2KHR);
    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "Error calling vkGetPhysicalDeviceSurfaceCapabilities2KHR:%d", result);
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, result);
    }

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
			LOGERROR(env, "%s", "Error trying to crawl the pNext chain for populate.");
			jvulkan::freeMemory(&memoryToFree);
			return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
		}
    }

    jclass vkSurfaceCapabilitiesKHRClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSurfaceCapabilitiesKHR");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSurfaceCapabilitiesKHR.");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID constructorMethodId = env->GetMethodID(vkSurfaceCapabilitiesKHRClass, "<init>", "()V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id <init>.");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	jobject jVkSurfaceCapabilitiesKHRObject = env->NewObject(vkSurfaceCapabilitiesKHRClass, constructorMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling NewObject");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	jvulkan::populateVkSurfaceCapabilitiesKHR(
			env,
			jVkSurfaceCapabilitiesKHRObject,
			&vkSurfaceCapabilities2KHR.surfaceCapabilities,
			&memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkSurfaceCapabilitiesKHR");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass vkSurfaceCapabilities2KHRClass = env->GetObjectClass(jVkSurfaceCapabilities2KHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find class for jVkSurfaceCapabilities2KHR.");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkSurfaceCapabilities2KHRClass, "setSurfaceCapabilities", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSurfaceCapabilitiesKHR;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id setSurfaceCapabilities");
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    env->CallVoidMethod(jVkSurfaceCapabilities2KHR, methodId, jVkSurfaceCapabilitiesKHRObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", voidMethodErrorText);
        jvulkan::freeMemory(&memoryToFree);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
