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
 * populateVkPhysicalDeviceDriverProperties.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceDriverProperties(
		JNIEnv *env,
		jobject jVkPhysicalDeviceDriverPropertiesObject,
		const VkPhysicalDeviceDriverProperties *vkPhysicalDeviceDriverProperties,
		std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDeviceDriverPropertiesObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkPhysicalDeviceDriverProperties");
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

        jobject vkDriverIdEnum = env->CallStaticObjectMethod(vkDriverIdClass, methodId, vkPhysicalDeviceDriverProperties->driverID);

        methodId = env->GetMethodID(theClass, "setDriverId", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkDriverId;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setDriverId");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceDriverPropertiesObject, methodId, vkDriverIdEnum);
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

        jstring driverNameString = env->NewStringUTF(vkPhysicalDeviceDriverProperties->driverName);

        env->CallVoidMethod(jVkPhysicalDeviceDriverPropertiesObject, methodId, driverNameString);
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

        jstring driverInfoString = env->NewStringUTF(vkPhysicalDeviceDriverProperties->driverInfo);

        env->CallVoidMethod(jVkPhysicalDeviceDriverPropertiesObject, methodId, driverInfoString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setDriverInfo");
            return;
        }

        env->DeleteLocalRef(driverInfoString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setConformanceVersion", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkConformanceVersion;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setConformanceVersion");
            return;
        }

        jobject jVkConformanceVersion = createVkConformanceVersion(env, &(vkPhysicalDeviceDriverProperties->conformanceVersion));

    	env->CallVoidMethod(jVkPhysicalDeviceDriverPropertiesObject, methodId, jVkConformanceVersion);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

	}
}
