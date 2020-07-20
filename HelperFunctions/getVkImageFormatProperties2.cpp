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
 * getVkImageFormatProperties2.cpp
 *
 *  Created on: May 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImageFormatProperties2(
            JNIEnv *env,
            const jobject jVkImageFormatProperties2Object,
			VkImageFormatProperties2 *vkImageFormatProperties2,
            std::vector<void *> *memoryToFree)
    {
		if (jVkImageFormatProperties2Object == nullptr)
		{
			LOGERROR(env, "%s", "jVkImageFormatProperties2Object == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkImageFormatProperties2Object == nullptr");
			return;
		}

		if (vkImageFormatProperties2 == nullptr)
		{
			LOGERROR(env, "%s", "vkImageFormatProperties2 == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkImageFormatProperties2 == nullptr");
			return;
		}

        jclass theClass = env->GetObjectClass(jVkImageFormatProperties2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageFormatProperties2Object");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkImageFormatProperties2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImageFormatProperties2Object);
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
        jmethodID methodId = env->GetMethodID(theClass, "getImageFormatProperties", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageFormatProperties;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getImageFormatProperties");
            return;
        }

        jobject jVkImageFormatPropertiesObject = env->CallObjectMethod(jVkImageFormatProperties2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkImageFormatProperties *vkImageFormatProperties = (VkImageFormatProperties *)calloc(1, sizeof(VkImageFormatProperties));
        if(vkImageFormatProperties == nullptr)
        {
        	LOGERROR(env, "%s", "Error trying to allocate memory for VkImageFormatProperties.");
        	return;
        }

        memoryToFree->push_back(vkImageFormatProperties);

        jvulkan::getVkImageFormatProperties(
                env,
                jVkImageFormatPropertiesObject,
				vkImageFormatProperties,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkImageFormatProperties");
        	return;
        }


        vkImageFormatProperties2->sType = sTypeValue;
        vkImageFormatProperties2->pNext = pNext;
        memcpy(&vkImageFormatProperties2->imageFormatProperties, vkImageFormatProperties, sizeof(vkImageFormatProperties2->imageFormatProperties));
    }
}
