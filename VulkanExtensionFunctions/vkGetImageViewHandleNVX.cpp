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
 * vkGetImageViewHandleNVX.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetImageViewHandleNVX
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkImageViewHandleInfoNVX;)I
 */
JNIEXPORT jint JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetImageViewHandleNVX
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkImageViewHandleInfoNVX)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return -1;
    }

    VkImageViewHandleInfoNVX vkImageViewHandleInfoNVX = {};

    int result = vkGetImageViewHandleNVX(
    		deviceHandle,
			&vkImageViewHandleInfoNVX);

    jvulkan::populateVkImageViewHandleInfoNVX(
    		env,
			jVkImageViewHandleInfoNVX,
			&vkImageViewHandleInfoNVX);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkImageViewHandleInfoNVX.");
        return -1;
    }

    return result;
}
