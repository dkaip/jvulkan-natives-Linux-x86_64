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
 * getVkPhysicalDeviceImageViewImageFormatInfoEXT.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceImageViewImageFormatInfoEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceImageViewImageFormatInfoEXTObject,
			VkPhysicalDeviceImageViewImageFormatInfoEXT *vkPhysicalDeviceImageViewImageFormatInfoEXT,
            std::vector<void *> *memoryToFree)
    {
		if (jVkPhysicalDeviceImageViewImageFormatInfoEXTObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkPhysicalDeviceImageViewImageFormatInfoEXTObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkPhysicalDeviceImageViewImageFormatInfoEXTObject == nullptr");
			return;
		}

		if (vkPhysicalDeviceImageViewImageFormatInfoEXT == nullptr)
		{
			LOGERROR(env, "%s", "vkPhysicalDeviceImageViewImageFormatInfoEXT == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkPhysicalDeviceImageViewImageFormatInfoEXT == nullptr");
			return;
		}

        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceImageViewImageFormatInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceImageViewImageFormatInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDeviceImageViewImageFormatInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceImageViewImageFormatInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getImageViewType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageViewType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getImageViewType");
            return;
        }

        jobject jVkImageViewTypeObject = env->CallObjectMethod(jVkPhysicalDeviceImageViewImageFormatInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkImageViewTypeEnumClass = env->GetObjectClass(jVkImageViewTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageViewTypeObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkImageViewTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkImageViewType imageViewTypeEnumValue = (VkImageViewType)env->CallIntMethod(jVkImageViewTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }


        vkPhysicalDeviceImageViewImageFormatInfoEXT->sType = sTypeValue;
        vkPhysicalDeviceImageViewImageFormatInfoEXT->pNext = pNext;
        vkPhysicalDeviceImageViewImageFormatInfoEXT->imageViewType = imageViewTypeEnumValue;
    }
}
