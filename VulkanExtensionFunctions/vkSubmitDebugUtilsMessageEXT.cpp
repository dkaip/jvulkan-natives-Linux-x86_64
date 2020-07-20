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
 * vkSubmitDebugUtilsMessageEXT.cpp
 *
 *  Created on: Apr 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "slf4j.hh"

extern PFN_vkSubmitDebugUtilsMessageEXT	vkSubmitDebugUtilsMessageEXTFunc;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkSubmitDebugUtilsMessageEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugUtilsMessageSeverityFlagBitsEXT;Ljava/util/EnumSet;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDebugUtilsMessengerCallbackDataEXT;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkSubmitDebugUtilsMessageEXT
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkDebugUtilsMessageSeverityFlagBitsEXT, jobject jVkDebugUtilsMessageTypeFlagsEXT, jobject jVkDebugUtilsMessengerCallbackDataEXT)
{
    VkInstance_T *vkInstanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to get the value of jVkInstance");
    	return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkDebugUtilsMessageSeverityFlagBitsEXTEnumClass = env->GetObjectClass(jVkDebugUtilsMessageSeverityFlagBitsEXT);

    jmethodID valueOfMethodId = env->GetMethodID(vkDebugUtilsMessageSeverityFlagBitsEXTEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
        return;
    }

    VkDebugUtilsMessageSeverityFlagBitsEXT vkDebugUtilsMessageSeverityFlagBitsEXTEnumValue = (VkDebugUtilsMessageSeverityFlagBitsEXT)env->CallIntMethod(jVkDebugUtilsMessageSeverityFlagBitsEXT, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod for VkDebugUtilsMessageSeverityFlagBitsEXT enum value");
        return;
    }

    ////////////////////////////////////////////////////////////////////////
    VkDebugUtilsMessageTypeFlagsEXT vkDebugUtilsMessageTypeFlags = jvulkan::getEnumSetValue(
			env,
			jVkDebugUtilsMessageTypeFlagsEXT,
			"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugUtilsMessageTypeFlagBitsEXT");

	VkDebugUtilsMessengerCallbackDataEXT vkDebugUtilsMessengerCallbackDataEXT = {};
    std::vector<void *> memoryToFree(5);

    jvulkan::getvkDebugUtilsMessengerCallbackDataEXT(env, jVkDebugUtilsMessengerCallbackDataEXT, &vkDebugUtilsMessengerCallbackDataEXT, &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to extract jVkDebugUtilsObjectNameInfoEXT");
        return;
    }

	vkSubmitDebugUtilsMessageEXTFunc(
    		vkInstanceHandle,
    		vkDebugUtilsMessageSeverityFlagBitsEXTEnumValue,
			vkDebugUtilsMessageTypeFlags,
			&vkDebugUtilsMessengerCallbackDataEXT);

    jvulkan::freeMemory(&memoryToFree);
}
