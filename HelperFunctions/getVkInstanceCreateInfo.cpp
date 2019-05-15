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
 * getVkInstanceCreateInfo.cpp
 *
 *  Created on: May 9, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkInstanceCreateInfo(
        JNIEnv *env,
        const jobject jVkInstanceCreateInfoObject,
		VkInstanceCreateInfo *vkInstanceCreateInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass vkInstanceCreateInfoClass = env->GetObjectClass(jVkInstanceCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error getting class for jVkInstanceCreateInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkInstanceCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkInstanceCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        LOGINFO(env, "pNext is:", jpNextObject);
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
        jmethodID methodId = env->GetMethodID(vkInstanceCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkInstanceCreateInfoObject, methodId);
        VkInstanceCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkInstanceCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        VkApplicationInfo *vkApplicationInfo = (VkApplicationInfo *)calloc(1, sizeof(VkApplicationInfo));
        memoryToFree->push_back(vkApplicationInfo);

        methodId = env->GetMethodID(vkInstanceCreateInfoClass, "getApplicationInfo", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkApplicationInfo;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getApplicationInfo.");
            return;
        }

        jobject jVkApplicationInfoObject = env->CallObjectMethod(jVkInstanceCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkApplicationInfoObject");
            return;
        }

    	getVkApplicationInfo(
            env,
			jVkApplicationInfoObject,
			vkApplicationInfo,
            memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkApplicationInfo");
            return;
        }


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkInstanceCreateInfoClass, "getEnabledLayerNames", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getEnabledLayerNames.");
            return;
        }

        jobject layerNamesObject = env->CallObjectMethod(jVkInstanceCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkInstanceCreateInfoObject");
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
        methodId = env->GetMethodID(vkInstanceCreateInfoClass, "getEnabledExtensionNames", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getEnabledExtensionNames.");
            return;
        }

        jobject enabledExtensionsObject = env->CallObjectMethod(jVkInstanceCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkInstanceCreateInfoObject");
            return;
        }

        char **arrayOfPointersToExtensionNames = nullptr;
        int numberOfExtensionNames = 0;
        if (layerNamesObject != nullptr)
        {
        	getStringCollection(env, enabledExtensionsObject, &arrayOfPointersToExtensionNames, &numberOfExtensionNames, memoryToFree);
            if (env->ExceptionOccurred())
            {
				LOGERROR(env, "%s", "Error calling getStringCollection");
                return;
            }
        }


        vkInstanceCreateInfo->sType   					= (VkStructureType)sTypeValue;
        vkInstanceCreateInfo->pNext   					= (void *)pNext;
        vkInstanceCreateInfo->flags   					= flags;
        vkInstanceCreateInfo->pApplicationInfo			= vkApplicationInfo;
        vkInstanceCreateInfo->enabledLayerCount   		= numberOfLayerNames;
		vkInstanceCreateInfo->ppEnabledLayerNames 		= arrayOfPointersToLayerNames;
		vkInstanceCreateInfo->enabledExtensionCount   	= numberOfExtensionNames;
		vkInstanceCreateInfo->ppEnabledExtensionNames	= arrayOfPointersToExtensionNames;
    }
}
