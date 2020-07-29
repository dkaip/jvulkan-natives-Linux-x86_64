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
 * getVkSamplerYcbcrConversionCreateInfo.cpp
 *
 *  Created on: Oct 25, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSamplerYcbcrConversionCreateInfo(
			JNIEnv *env,
			jobject jVkSamplerYcbcrConversionCreateInfoObject,
			VkSamplerYcbcrConversionCreateInfo *vkSamplerYcbcrConversionCreateInfo,
			std::vector<void *> *memoryToFree)
	{
		jclass theClass = env->GetObjectClass(jVkSamplerYcbcrConversionCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get class for jVkSamplerYcbcrConversionCreateInfoObject");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkSamplerYcbcrConversionCreateInfoObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSamplerYcbcrConversionCreateInfoObject);
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

        jobject jVkFormatObject = env->CallObjectMethod(jVkSamplerYcbcrConversionCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkFormatObjectEnumClass = env->GetObjectClass(jVkFormatObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkFormatObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkFormatObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkFormat formatEnumValue = (VkFormat)env->CallIntMethod(jVkFormatObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getYcbcrModel", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSamplerYcbcrModelConversion;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getYcbcrModel");
            return;
        }

        jobject jVkSamplerYcbcrModelConversionObject = env->CallObjectMethod(jVkSamplerYcbcrConversionCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkSamplerYcbcrModelConversionObjectEnumClass = env->GetObjectClass(jVkSamplerYcbcrModelConversionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkSamplerYcbcrModelConversionObject.");
            return;
        }


        valueOfMethodId = env->GetMethodID(vkSamplerYcbcrModelConversionObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkSamplerYcbcrModelConversion ycbcrModelEnumValue = (VkSamplerYcbcrModelConversion)env->CallIntMethod(jVkSamplerYcbcrModelConversionObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getYcbcrModel", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSamplerYcbcrRange;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getYcbcrModel");
            return;
        }

        jobject jVkSamplerYcbcrRangeObject = env->CallObjectMethod(jVkSamplerYcbcrConversionCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkSamplerYcbcrRangeObjectEnumClass = env->GetObjectClass(jVkSamplerYcbcrRangeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkSamplerYcbcrRangeObject.");
            return;
        }


        valueOfMethodId = env->GetMethodID(vkSamplerYcbcrModelConversionObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkSamplerYcbcrRange ycbcrRangeEnumValue = (VkSamplerYcbcrRange)env->CallIntMethod(jVkSamplerYcbcrRangeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getComponents", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkComponentMapping;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getComponents");
            return;
        }

        jobject jVkComponentMappingObject = env->CallObjectMethod(jVkSamplerYcbcrConversionCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

    	getVkComponentMapping(
    			env,
    			jVkComponentMappingObject,
    			&vkSamplerYcbcrConversionCreateInfo->components,
    			memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkComponentMapping");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getxChromaOffset", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkChromaLocation;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getxChromaOffset");
            return;
        }

        jobject jVkChromaLocationObject = env->CallObjectMethod(jVkSamplerYcbcrConversionCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkChromaLocationEnumClass = env->GetObjectClass(jVkChromaLocationObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkChromaLocationObject.");
            return;
        }


        valueOfMethodId = env->GetMethodID(vkChromaLocationEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkChromaLocation xChromaOffsetEnumValue = (VkChromaLocation)env->CallIntMethod(jVkChromaLocationObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getyChromaOffset", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkChromaLocation;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getyChromaOffset");
            return;
        }

        jVkChromaLocationObject = env->CallObjectMethod(jVkSamplerYcbcrConversionCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkChromaLocation yChromaOffsetEnumValue = (VkChromaLocation)env->CallIntMethod(jVkChromaLocationObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getChromaFilter", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFilter;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getChromaFilter");
            return;
        }

        jobject jVkFilterObject = env->CallObjectMethod(jVkSamplerYcbcrConversionCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkFilterEnumClass = env->GetObjectClass(jVkFilterObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkChromaLocationObject.");
            return;
        }


        valueOfMethodId = env->GetMethodID(vkFilterEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkFilter chromaFilterEnumValue = (VkFilter)env->CallIntMethod(jVkChromaLocationObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isForceExplicitReconstruction", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isForceExplicitReconstruction");
            return;
        }

        jboolean forceExplicitReconstruction = env->CallBooleanMethod(jVkSamplerYcbcrConversionCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
        	return;
        }

        vkSamplerYcbcrConversionCreateInfo->sType 	= (VkStructureType)sTypeValue;
        vkSamplerYcbcrConversionCreateInfo->pNext	= (void *)pNext;
        vkSamplerYcbcrConversionCreateInfo->format  = formatEnumValue;
        vkSamplerYcbcrConversionCreateInfo->ycbcrModel = ycbcrModelEnumValue;
        vkSamplerYcbcrConversionCreateInfo->ycbcrRange = ycbcrRangeEnumValue;
        vkSamplerYcbcrConversionCreateInfo->xChromaOffset = xChromaOffsetEnumValue;
        vkSamplerYcbcrConversionCreateInfo->yChromaOffset = yChromaOffsetEnumValue;
        vkSamplerYcbcrConversionCreateInfo->chromaFilter  = chromaFilterEnumValue;
        vkSamplerYcbcrConversionCreateInfo->forceExplicitReconstruction = forceExplicitReconstruction;
	}
}
