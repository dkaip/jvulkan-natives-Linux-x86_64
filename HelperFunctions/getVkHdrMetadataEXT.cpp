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
 * getVkHdrMetadataEXT.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkHdrMetadataEXT(
			JNIEnv *env,
			jobject jVkHdrMetadataEXTObject,
			VkHdrMetadataEXT *vkHdrMetadataEXT,
			std::vector<void *> *memoryToFree)
	{
		jclass theClass = env->GetObjectClass(jVkHdrMetadataEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get class for jVkDisplayPowerInfoEXTObject");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		VkStructureType sTypeValue = getSType(env, jVkHdrMetadataEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getSType failed.");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkHdrMetadataEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getDisplayPrimaryRed", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkXYColorEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDisplayPrimaryRed");
            return;
        }

        jobject jVkXYColorEXTObject = env->CallObjectMethod(jVkHdrMetadataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkXYColorEXT displayPrimaryRed = {};
        getVkXYColorEXT(
                env,
				jVkXYColorEXTObject,
                &displayPrimaryRed,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling method getVkXYColorEXT");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDisplayPrimaryGreen", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkXYColorEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDisplayPrimaryGreen");
            return;
        }

        jVkXYColorEXTObject = env->CallObjectMethod(jVkHdrMetadataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkXYColorEXT displayPrimaryGreen = {};
        getVkXYColorEXT(
                env,
				jVkXYColorEXTObject,
                &displayPrimaryGreen,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling method getVkXYColorEXT");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDisplayPrimaryBlue", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkXYColorEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDisplayPrimaryBlue");
            return;
        }

        jVkXYColorEXTObject = env->CallObjectMethod(jVkHdrMetadataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkXYColorEXT displayPrimaryBlue = {};
        getVkXYColorEXT(
                env,
				jVkXYColorEXTObject,
                &displayPrimaryBlue,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling method getVkXYColorEXT");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getWhitePoint", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkXYColorEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getWhitePoint");
            return;
        }

        jVkXYColorEXTObject = env->CallObjectMethod(jVkHdrMetadataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkXYColorEXT whitePoint = {};
        getVkXYColorEXT(
                env,
				jVkXYColorEXTObject,
                &whitePoint,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling method getVkXYColorEXT");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMaxLuminance", "()F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMaxLuminance");
            return;
        }

        jfloat maxLuminance = env->CallFloatMethod(jVkHdrMetadataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallFloatMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMinLuminance", "()F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMinLuminance");
            return;
        }

        jfloat minLuminance = env->CallFloatMethod(jVkHdrMetadataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallFloatMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMaxContentLightLevel", "()F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMaxContentLightLevel");
            return;
        }

        jfloat maxContentLightLevel = env->CallFloatMethod(jVkHdrMetadataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallFloatMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMaxFrameAverageLightLevel", "()F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMaxFrameAverageLightLevel");
            return;
        }

        jfloat maxFrameAverageLightLevel = env->CallFloatMethod(jVkHdrMetadataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallFloatMethod");
            return;
        }


        vkHdrMetadataEXT->sType 		= sTypeValue;
        vkHdrMetadataEXT->pNext		= (void *)pNext;
        (void)std::memcpy(&vkHdrMetadataEXT->displayPrimaryRed, &displayPrimaryRed, sizeof(vkHdrMetadataEXT->displayPrimaryRed));
        (void)std::memcpy( &vkHdrMetadataEXT->displayPrimaryGreen, &displayPrimaryGreen, sizeof(vkHdrMetadataEXT->displayPrimaryGreen));
        (void)std::memcpy( &vkHdrMetadataEXT->displayPrimaryBlue, &displayPrimaryBlue, sizeof(vkHdrMetadataEXT->displayPrimaryBlue));
        (void)std::memcpy( &vkHdrMetadataEXT->whitePoint, &whitePoint, sizeof(vkHdrMetadataEXT->whitePoint));
        vkHdrMetadataEXT->maxLuminance				= maxLuminance;
        vkHdrMetadataEXT->minLuminance				= minLuminance;
        vkHdrMetadataEXT->maxContentLightLevel		= maxContentLightLevel;
        vkHdrMetadataEXT->maxFrameAverageLightLevel	= maxFrameAverageLightLevel;
	}
}
