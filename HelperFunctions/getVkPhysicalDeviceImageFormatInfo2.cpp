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
 * getVkPhysicalDeviceImageFormatInfo2.cpp
 *
 *  Created on: May 31, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceImageFormatInfo2(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceImageFormatInfo2Object,
			VkPhysicalDeviceImageFormatInfo2 *vkPhysicalDeviceImageFormatInfo2,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceImageFormatInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceImageFormatInfo2Object");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkPhysicalDeviceImageFormatInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceImageFormatInfo2Object);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFormat");
            return;
        }

        jobject jDecodeMode = env->CallObjectMethod(jVkPhysicalDeviceImageFormatInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkFormat vkFormat = (VkFormat)0;
        getVkFormat(
                env,
				jDecodeMode,
				&vkFormat,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling method getVkFormat");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType getType");
            return;
        }

        jobject jVkImageTypeObject = env->CallObjectMethod(jVkPhysicalDeviceImageFormatInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getType");
            return;
        }

        jclass vkImageTypeEnumClass = env->GetObjectClass(jVkImageTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for VkImageType");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkImageTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkImageType vkImageTypeEnumValue = (VkImageType)env->CallIntMethod(jVkImageTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getTiling", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageTiling;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType getTiling");
            return;
        }

        jobject jVkImageTilingObject = env->CallObjectMethod(jVkPhysicalDeviceImageFormatInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getTiling");
            return;
        }

        jclass vkImageTilingEnumClass = env->GetObjectClass(jVkImageTilingObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for VkImageTiling");
            return;
        }

        valueOfMethodId = env->GetMethodID(vkImageTilingEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkImageTiling vkImageTilingEnumValue = (VkImageTiling)env->CallIntMethod(jVkImageTilingObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getUsage", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getUsage.");
            return;
        }

        jobject vkImageUsageFlagsObject = env->CallObjectMethod(jVkPhysicalDeviceImageFormatInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkImageUsageFlags usage = (VkImageUsageFlags)getEnumSetValue(
                env,
				vkImageUsageFlagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageUsageFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getFlags.");
            return;
        }

        jobject vkImageCreateFlagsObject = env->CallObjectMethod(jVkPhysicalDeviceImageFormatInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkImageCreateFlags flags = (VkImageCreateFlags)getEnumSetValue(
                env,
				vkImageCreateFlagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkImageCreateFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }


        vkPhysicalDeviceImageFormatInfo2->sType = sTypeValue;
        vkPhysicalDeviceImageFormatInfo2->pNext = pNext;
        vkPhysicalDeviceImageFormatInfo2->format = vkFormat;
        vkPhysicalDeviceImageFormatInfo2->type = vkImageTypeEnumValue;
        vkPhysicalDeviceImageFormatInfo2->tiling = vkImageTilingEnumValue;
        vkPhysicalDeviceImageFormatInfo2->usage = usage;
        vkPhysicalDeviceImageFormatInfo2->flags = flags;
    }
}
