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
 * getVkDebugUtilsMessengerCreateInfoEXT.cpp
 *
 *  Created on: Apr 21, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

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
        VkStructureType sTypeValue = getSType(env, jVkDebugUtilsMessengerCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDebugUtilsMessengerCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDebugUtilsMessengerCreateInfoEXTClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDebugUtilsMessengerCreateInfoEXTObject, methodId);
        VkDebugUtilsMessengerCreateFlagsEXT flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugUtilsMessengerCreateFlagBitsEXT");

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
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugUtilsMessageSeverityFlagBitsEXT");

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
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugUtilsMessageTypeFlagBitsEXT");



        vkDebugUtilsMessengerCreateInfoEXT->sType = sTypeValue;
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



