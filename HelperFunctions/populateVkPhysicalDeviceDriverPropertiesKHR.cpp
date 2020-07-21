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
 * populateVkPhysicalDeviceDriverPropertiesKHR.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceDriverPropertiesKHR(
		JNIEnv *env,
		jobject jVkPhysicalDeviceDriverPropertiesKHRObject,
		const VkPhysicalDeviceDriverPropertiesKHR *vkPhysicalDeviceDriverPropertiesKHR,
		std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDeviceDriverPropertiesKHRObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceDriverPropertiesKHR");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jclass vkDriverIdClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Enums/VkDriverId");
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "com/CIMthetics/jvulkan/VulkanCore/Enums/VkDriverId");
            return;
        }

        jmethodID methodId = env->GetStaticMethodID(vkDriverIdClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkDriverId;");
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Could not find static method id fromValue");
            return;
        }

        jobject vkDriverIdEnum = env->CallStaticObjectMethod(vkDriverIdClass, methodId, vkPhysicalDeviceDriverPropertiesKHR->driverID);

        methodId = env->GetMethodID(theClass, "setDriverId", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkDriverId;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setDriverId");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDriverPropertiesKHRObject, methodId, vkDriverIdEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setDriverId");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDriverName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setDriverName");
            return;
        }

        jstring driverNameString = env->NewStringUTF(vkPhysicalDeviceDriverPropertiesKHR->driverName);

        env->CallVoidMethod(jVkPhysicalDeviceDriverPropertiesKHRObject, methodId, driverNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setDriverName");
            return;
        }

        env->DeleteLocalRef(driverNameString);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDriverInfo", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setDriverInfo");
            return;
        }

        jstring driverInfoString = env->NewStringUTF(vkPhysicalDeviceDriverPropertiesKHR->driverInfo);

        env->CallVoidMethod(jVkPhysicalDeviceDriverPropertiesKHRObject, methodId, driverInfoString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setDriverInfo");
            return;
        }

        env->DeleteLocalRef(driverInfoString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setConformanceVersion", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkConformanceVersionKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setConformanceVersion");
            return;
        }

        jobject jVkConformanceVersionKHR = createVkConformanceVersionKHR(env, &(vkPhysicalDeviceDriverPropertiesKHR->conformanceVersion));

    	env->CallVoidMethod(jVkPhysicalDeviceDriverPropertiesKHRObject, methodId, jVkConformanceVersionKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}
