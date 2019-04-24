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
 * getVkDebugUtilsMessengerCreateInfoEXT.cpp
 *
 *  Created on: Apr 21, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace jvulkan
{
	void getVkDebugUtilsMessengerCreateInfoEXT(
        JNIEnv *env,
        const jobject jVkDebugUtilsMessengerCreateInfoEXTObject,
		VkDebugUtilsMessengerCreateInfoEXT *vkDebugUtilsMessengerCreateInfoEXT,
        std::vector<void *> *memoryToFree)
    {
        jclass vkDebugUtilsMessengerCreateInfoEXTClass = env->GetObjectClass(jVkDebugUtilsMessengerCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDebugUtilsMessengerCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDebugUtilsMessengerCreateInfoEXTClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkDebugUtilsMessengerCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCreateInfoEXTClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDebugUtilsMessengerCreateInfoEXTObject, methodId);
        VkDebugUtilsMessengerCreateFlagsEXT flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessengerCreateFlagBitsEXT");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCreateInfoEXTClass, "getMessageSeverity", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject messageSeverityObject = env->CallObjectMethod(jVkDebugUtilsMessengerCreateInfoEXTObject, methodId);
        VkDebugUtilsMessageSeverityFlagsEXT messageSeverity = getEnumSetValue(
                env,
				messageSeverityObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessageSeverityFlagBitsEXT");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCreateInfoEXTClass, "getMessageType", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject messageTypeObject = env->CallObjectMethod(jVkDebugUtilsMessengerCreateInfoEXTObject, methodId);
        VkDebugUtilsMessengerCreateFlagsEXT messageType = getEnumSetValue(
                env,
				messageTypeObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessageTypeFlagBitsEXT");



        vkDebugUtilsMessengerCreateInfoEXT->sType = (VkStructureType)sTypeValue;
        vkDebugUtilsMessengerCreateInfoEXT->pNext = (void *)pNext;
        vkDebugUtilsMessengerCreateInfoEXT->flags = flags;
        vkDebugUtilsMessengerCreateInfoEXT->messageSeverity = messageSeverity;
		vkDebugUtilsMessengerCreateInfoEXT->messageType = messageType;

		/*
		 * Because of the Java to c++ interaction these next two attributes
		 * require special handling that will need to be performed by the
		 * caller;
		 */
		vkDebugUtilsMessengerCreateInfoEXT->pfnUserCallback = nullptr;
		vkDebugUtilsMessengerCreateInfoEXT->pUserData = nullptr;
    }
}



