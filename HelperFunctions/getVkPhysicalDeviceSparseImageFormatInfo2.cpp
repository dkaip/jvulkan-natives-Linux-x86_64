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
 * getVkPhysicalDeviceSparseImageFormatInfo2.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceSparseImageFormatInfo2(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceSparseImageFormatInfo2Object,
			VkPhysicalDeviceSparseImageFormatInfo2 *vkPhysicalDeviceSparseImageFormatInfo2,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceSparseImageFormatInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceSparseImageFormatInfo2Object");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDeviceSparseImageFormatInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceSparseImageFormatInfo2Object);
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

        jobject jDecodeMode = env->CallObjectMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId);
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
        	LOGERROR(env, "%s", "Error trying to get getType getType");
            return;
        }

        jobject jVkImageTypeObject = env->CallObjectMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId);
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
        methodId = env->GetMethodID(theClass, "getSamples", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getType getSamples");
            return;
        }

        jobject jVkSampleCountFlagBitsObject = env->CallObjectMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getType");
            return;
        }

        jclass vkSampleCountFlagBitsEnumClass = env->GetObjectClass(jVkImageTypeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for VkImageType");
            return;
        }

        valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkSampleCountFlagBits vkSampleCountFlagBitsEnumValue = (VkSampleCountFlagBits)env->CallIntMethod(jVkImageTypeObject, valueOfMethodId);
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

        jobject vkImageUsageFlagsObject = env->CallObjectMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId);
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
        methodId = env->GetMethodID(theClass, "getTiling", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageTiling;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType getTiling");
            return;
        }

        jobject jVkImageTilingObject = env->CallObjectMethod(jVkPhysicalDeviceSparseImageFormatInfo2Object, methodId);
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


        vkPhysicalDeviceSparseImageFormatInfo2->sType 	= sTypeValue;
        vkPhysicalDeviceSparseImageFormatInfo2->pNext 	= pNext;
        vkPhysicalDeviceSparseImageFormatInfo2->format 	= vkFormat;
        vkPhysicalDeviceSparseImageFormatInfo2->type 	= vkImageTypeEnumValue;
        vkPhysicalDeviceSparseImageFormatInfo2->samples = vkSampleCountFlagBitsEnumValue;
        vkPhysicalDeviceSparseImageFormatInfo2->usage 	= usage;
        vkPhysicalDeviceSparseImageFormatInfo2->tiling	= vkImageTilingEnumValue;
    }
}
