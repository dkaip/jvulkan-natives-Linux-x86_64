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
 * getVkDeviceCreateInfo.cpp
 *
 *  Created on: May 16, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkDeviceCreateInfo(
			JNIEnv *env,
			const jobject jVkDeviceCreateInfo,
			VkDeviceCreateInfo *deviceCreateInfo,
			std::vector<void *> *memoryToFree)
	{
		jclass vkDeviceCreateInfoClass = env->GetObjectClass(jVkDeviceCreateInfo);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkDeviceCreateInfo");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		int sTypeValue = getSTypeAsInt(env, jVkDeviceCreateInfo);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		jobject jpNextObject = getpNextObject(env, jVkDeviceCreateInfo);
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
		jmethodID methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id getFlags.");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
		int32_t flags = getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkDeviceCreateFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getEnumSetValue failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getQueueCreateInfos", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getQueueCreateInfos methodId");
            return;
        }

        jobject jVkDeviceQueueCreateInfoCollection = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getQueueCreateInfos");
            return;
        }

        int numberOfVkDeviceQueueCreateInfos = 0;
        VkDeviceQueueCreateInfo *vkDeviceQueueCreateInfos = nullptr;

        if (jVkDeviceQueueCreateInfoCollection != nullptr)
        {
            jvulkan::getVkDeviceQueueCreateInfoCollection(
                    env,
					jVkDeviceQueueCreateInfoCollection,
                    &vkDeviceQueueCreateInfos,
                    &numberOfVkDeviceQueueCreateInfos,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkDeviceQueueCreateInfoCollection");
                return;
            }
        }

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getEnabledLayerNames", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id getEnabledLayerNames.");
			return;
		}

		jobject layerNamesObject = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkDeviceCreateInfo");
			return;
		}

		char **arrayOfPointersToLayerNames = nullptr;
		int numberOfLayerNames = 0;

		if (layerNamesObject != nullptr)
		{
			getStringCollection(env, layerNamesObject, &arrayOfPointersToLayerNames, &numberOfLayerNames, memoryToFree);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Error calling getStringCollection");
				return;
			}
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getEnabledExtensionNames", "()Ljava/util/Collection;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id getEnabledExtensionNames.");
			return;
		}

		jobject extensionNamesObject = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkDeviceCreateInfo");
			return;
		}

		char **arrayOfPointersToExtensionNames = nullptr;
		int numberOfExtensionNames = 0;
		if (extensionNamesObject != nullptr)
		{
			getStringCollection(env, extensionNamesObject, &arrayOfPointersToExtensionNames, &numberOfExtensionNames, memoryToFree);
			if (env->ExceptionOccurred())
			{
	        	LOGERROR(env, "%s", "Error calling getStringCollection");
				return;
			}
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getEnabledFeatures", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceFeatures;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id getEnabledFeatures.");
			return;
		}

		jobject physicalDeviceFeaturesObject = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkDeviceCreateInfo");
			return;
		}

		VkPhysicalDeviceFeatures *physicalDeviceFeatures = (VkPhysicalDeviceFeatures *)calloc(1, sizeof(VkPhysicalDeviceFeatures));
		memoryToFree->push_back(physicalDeviceFeatures);

		getVkPhysicalDeviceFeatures(
			env,
			physicalDeviceFeaturesObject,
			physicalDeviceFeatures,
			memoryToFree);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceFeatures");
			return;
		}

		deviceCreateInfo->sType = (VkStructureType)sTypeValue;
		deviceCreateInfo->pNext = (void *)pNext;
		deviceCreateInfo->flags = flags;
		deviceCreateInfo->queueCreateInfoCount = numberOfVkDeviceQueueCreateInfos;
		deviceCreateInfo->pQueueCreateInfos = vkDeviceQueueCreateInfos;
		deviceCreateInfo->enabledLayerCount = numberOfLayerNames;
		deviceCreateInfo->ppEnabledLayerNames = arrayOfPointersToLayerNames;
		deviceCreateInfo->enabledExtensionCount = numberOfExtensionNames;
		deviceCreateInfo->ppEnabledExtensionNames = arrayOfPointersToExtensionNames;
		deviceCreateInfo->pEnabledFeatures = physicalDeviceFeatures;
	}

}
