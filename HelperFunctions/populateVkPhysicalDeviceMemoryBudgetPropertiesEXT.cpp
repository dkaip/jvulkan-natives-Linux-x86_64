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
 * populateVkPhysicalDeviceMemoryBudgetPropertiesEXT.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceMemoryBudgetPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject,
			const VkPhysicalDeviceMemoryBudgetPropertiesEXT *vkPhysicalDeviceMemoryBudgetPropertiesEXT,
			std::vector<void *> *memoryToFree)
	{
		if (jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject == nullptr");
			return;
		}

		if (vkPhysicalDeviceMemoryBudgetPropertiesEXT == nullptr)
		{
			LOGERROR(env, "%s", "vkPhysicalDeviceMemoryBudgetPropertiesEXT == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceMemoryBudgetPropertiesEXT == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceMemoryBudgetPropertiesEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setHeapBudget", "([J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setHeapBudget");
            return;
        }

        jlongArray heapBudgetObject = env->NewLongArray(VK_MAX_MEMORY_HEAPS);
        if (heapBudgetObject == nullptr)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for setHeapBudget");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject, methodId, heapBudgetObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->SetLongArrayRegion(heapBudgetObject, 0, VK_MAX_MEMORY_HEAPS, (const jlong *)vkPhysicalDeviceMemoryBudgetPropertiesEXT->heapBudget);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetLongArrayRegion");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setHeapUsage", "([J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setHeapUsage");
            return;
        }

        jlongArray heapUsageObject = env->NewLongArray(VK_MAX_MEMORY_HEAPS);
        if (heapUsageObject == nullptr)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for setHeapUsage");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMemoryBudgetPropertiesEXTObject, methodId, heapUsageObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->SetLongArrayRegion(heapUsageObject, 0, VK_MAX_MEMORY_HEAPS, (const jlong *)vkPhysicalDeviceMemoryBudgetPropertiesEXT->heapUsage);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetLongArrayRegion");
            return;
        }

	}
}
