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
 * createVkDebugUtilsObjectNameInfoEXT.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	jobject createVkDebugUtilsObjectNameInfoEXT(JNIEnv *env, const VkDebugUtilsObjectNameInfoEXT *objectNameInfo)
	{
		jclass vkDebugUtilsObjectNameInfoEXTclass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDebugUtilsObjectNameInfoEXT",
				&vkDebugUtilsObjectNameInfoEXTclass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

		////////////////////////////////////////////////////////////////////////
		jclass theClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Enums/VkObjectType");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class \"com/CIMthetics/jvulkan/VulkanCore/Enums/VkObjectType\"");
			return nullptr;
		}

		jmethodID methodId = env->GetStaticMethodID(theClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkObjectType;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find static method fromValue");
			return nullptr;
		}

		jobject vkObjectTypeObject =  env->CallStaticObjectMethod(theClass, methodId, objectNameInfo->objectType);

		methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTclass, "setObjectType", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkObjectType;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setObjectType");
			return nullptr;
		}

		env->CallVoidMethod(theObject, methodId, vkObjectTypeObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute methodId of setObjectType");
			return nullptr;
		}

		////////////////////////////////////////////////////////////////////////
		jobject jObjectHandle = createVulkanHandle(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Handles/VulkanHandle",
				(void *)objectNameInfo->objectHandle);

		methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTclass, "setObjectHandle", "(Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VulkanHandle;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setObjectHandle");
			return nullptr;
		}

		env->CallVoidMethod(theObject, methodId, jObjectHandle);
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

		env->CallVoidMethod(theObject, methodId, objectNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setObjectName");
			return nullptr;
		}

		env->DeleteLocalRef(objectNameString);

		return theObject;
	}
}
