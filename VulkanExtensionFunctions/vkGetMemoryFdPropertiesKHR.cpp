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
 * vkGetMemoryFdPropertiesKHR.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetMemoryFdPropertiesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalMemoryHandleTypeFlagBits;ILcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkMemoryFdPropertiesKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetMemoryFdPropertiesKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkExternalMemoryHandleTypeFlagBits, jint JFd, jobject jVkMemoryFdPropertiesKHR)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

    jclass handleTypeEnumClass = env->GetObjectClass(jVkExternalMemoryHandleTypeFlagBits);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error getting class for jVkExternalMemoryHandleTypeFlagBits");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID valueOfMethodId = env->GetMethodID(handleTypeEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id for valueOf");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkExternalMemoryHandleTypeFlagBits handleTypeEnumValue = (VkExternalMemoryHandleTypeFlagBits)env->CallIntMethod(jVkExternalMemoryHandleTypeFlagBits, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkMemoryFdPropertiesKHR vkMemoryFdPropertiesKHR = {} ;
    VkResult result = vkGetMemoryFdPropertiesKHR(
    		deviceHandle,
			handleTypeEnumValue,
			JFd,
			&vkMemoryFdPropertiesKHR);


    jvulkan::populateVkMemoryFdPropertiesKHR(
			env,
			jVkMemoryFdPropertiesKHR,
			&vkMemoryFdPropertiesKHR);
	if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkMemoryFdPropertiesKHR");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    return jvulkan::createVkResult(env, result);
}
