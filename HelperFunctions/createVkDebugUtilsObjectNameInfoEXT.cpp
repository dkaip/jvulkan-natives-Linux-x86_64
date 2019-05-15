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
 * createVkDebugUtilsObjectNameInfoEXT.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	jobject createVkDebugUtilsObjectNameInfoEXT(JNIEnv *env, const VkDebugUtilsObjectNameInfoEXT *objectNameInfo)
	{
		// Locate the VkDebugUtilsMessengerCallbackDataEXT class
		jclass vkDebugUtilsObjectNameInfoEXTclass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkDebugUtilsObjectNameInfoEXT");

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTclass, "<init>", "()V");

		// Create the Java vkDebugUtilsObjectNameInfoEXTObject object
		jobject vkDebugUtilsObjectNameInfoEXTObject =
				env->NewObject(vkDebugUtilsObjectNameInfoEXTclass, methodId);

		////////////////////////////////////////////////////////////////////////
		jclass theClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkObjectType");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class \"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkObjectType\"");
			return nullptr;
		}

		methodId = env->GetStaticMethodID(theClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkObjectType;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find static method fromValue");
			return nullptr;
		}

		jobject theObject =  env->CallStaticObjectMethod(theClass, methodId, objectNameInfo->objectType);

		methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTclass, "setObjectType", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkObjectType;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setObjectType");
			return nullptr;
		}

		env->CallVoidMethod(vkDebugUtilsObjectNameInfoEXTObject, methodId, theObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute methodId of setObjectType");
			return nullptr;
		}

		////////////////////////////////////////////////////////////////////////
		jobject jObjectHandle = createVulkanHandle(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VulkanHandle",
				(void *)objectNameInfo->objectHandle);

		methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTclass, "setObjectHandle", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VulkanHandle;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setObjectHandle");
			return nullptr;
		}

		env->CallVoidMethod(vkDebugUtilsObjectNameInfoEXTObject, methodId, jObjectHandle);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute methodId of setObjectHandle");
			return nullptr;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTclass, "setObjectName", "(Ljava/lang/String;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setObjectName");
			return nullptr;
		}

		jstring objectNameString = env->NewStringUTF(objectNameInfo->pObjectName);

		env->CallVoidMethod(vkDebugUtilsObjectNameInfoEXTObject, methodId, objectNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setObjectName");
			return nullptr;
		}

		env->DeleteLocalRef(objectNameString);


		return vkDebugUtilsObjectNameInfoEXTObject;
	}
}
