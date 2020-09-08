/*
 * Copyright 2020 Douglas Kaip
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
 * createVkPerformanceCounterKHR.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkPerformanceCounterKHR(JNIEnv *env, const VkPerformanceCounterKHR *vkPerformanceCounterKHR)
	{
		if (vkPerformanceCounterKHR == nullptr)
		{
			LOGERROR(env, "%s", "vkPerformanceCounterKHR == nullptr");
			return nullptr;
		}

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPerformanceCounterKHR",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject theEnum = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPerformanceCounterUnitKHR",
				vkPerformanceCounterKHR->unit);
        if (env->ExceptionOccurred() || theEnum == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue");
            return nullptr;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setUnit", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPerformanceCounterKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setUnit");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, theEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setDriverId");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        theEnum = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPerformanceCounterScopeKHR",
				vkPerformanceCounterKHR->scope);
        if (env->ExceptionOccurred() || theEnum == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue");
            return nullptr;
        }

        methodId = env->GetMethodID(theClass, "setScope", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPerformanceCounterScopeKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setScope");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, theEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method CallVoidMethod");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        theEnum = createEnumFromValue(
        		env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPerformanceCounterStorageKHR",
				vkPerformanceCounterKHR->storage);
        if (env->ExceptionOccurred() || theEnum == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue");
            return nullptr;
        }

        methodId = env->GetMethodID(theClass, "setStorage", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPerformanceCounterStorageKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setStorage");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, theEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method CallVoidMethod");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setUuid", "([L)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setUuid");
            return nullptr;
        }

        jlongArray uuid = env->NewLongArray(VK_UUID_SIZE);
        if (uuid == 0)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for uuid");
            return nullptr;
        }

        env->SetLongArrayRegion(uuid, 0, VK_UUID_SIZE, (const jlong *)vkPerformanceCounterKHR->uuid);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetLongArrayRegion");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, uuid);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

		return theObject;
	}
}
