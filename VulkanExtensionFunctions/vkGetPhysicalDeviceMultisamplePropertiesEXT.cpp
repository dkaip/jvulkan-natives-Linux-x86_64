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
 * vkGetPhysicalDeviceMultisamplePropertiesEXT.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceMultisamplePropertiesEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkMultisamplePropertiesEXT;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceMultisamplePropertiesEXT
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkSampleCountFlagBits, jobject jVkMultisamplePropertiesEXTObject)
{
	VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not retrieve VkPhysicalDevice handle");
		return;
	}

    jclass vkSampleCountFlagBitsEnumClass = env->GetObjectClass(jVkSampleCountFlagBits);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error getting class for jVkSampleCountFlagBits");
        return;
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id for valueOf");
        return;
    }

    VkSampleCountFlagBits samplesEnumValue = (VkSampleCountFlagBits)env->CallIntMethod(jVkSampleCountFlagBits, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
        return;
    }

    VkMultisamplePropertiesEXT vkMultisamplePropertiesEXT = {};
    vkMultisamplePropertiesEXT.sType = VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT;
    vkMultisamplePropertiesEXT.pNext = nullptr;

    vkGetPhysicalDeviceMultisamplePropertiesEXT(
    		physicalDeviceHandle,
			samplesEnumValue,
			&vkMultisamplePropertiesEXT);

    jvulkan::populateVkMultisamplePropertiesEXT(
    		env,
			jVkMultisamplePropertiesEXTObject,
			&vkMultisamplePropertiesEXT);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkMultisamplePropertiesEXT.");
        return;
    }
}
