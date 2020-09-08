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
		jobject vkDebugUtilsObjectNameInfoEXTObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDebugUtilsObjectNameInfoEXT",
				&vkDebugUtilsObjectNameInfoEXTclass,
				&vkDebugUtilsObjectNameInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor.");
            return nullptr;
        }

		////////////////////////////////////////////////////////////////////////
        jobject vkObjectTypeObject = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkObjectType",
				objectNameInfo->objectType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		jmethodID methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTclass, "setObjectType", "(Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkObjectType;)V");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying to get methodId of setObjectType");
			return nullptr;
		}

		env->CallVoidMethod(vkDebugUtilsObjectNameInfoEXTObject, methodId, vkObjectTypeObject);
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
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTclass, "setObjectHandle", "(Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VulkanHandle;)V");
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
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling NewStringUTF.");
            return nullptr;
        }

		env->CallVoidMethod(vkDebugUtilsObjectNameInfoEXTObject, methodId, objectNameString);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of setObjectName");
			return nullptr;
		}

		env->DeleteLocalRef(objectNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling DeleteLocalRef.");
            return nullptr;
        }

		return vkDebugUtilsObjectNameInfoEXTObject;
	}
}
