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
 * getVkPipelineRasterizationLineStateCreateInfoEXT.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineRasterizationLineStateCreateInfoEXT(
            JNIEnv *env,
            jobject jVkPipelineRasterizationLineStateCreateInfoEXTObject,
			VkPipelineRasterizationLineStateCreateInfoEXT *vkPipelineRasterizationLineStateCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineRasterizationLineStateCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPipelineRasterizationLineStateCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineRasterizationLineStateCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineRasterizationLineStateCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getLineRasterizationMode", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkLineRasterizationModeEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to find method id for getLineRasterizationMode");
            return;
        }

        jobject jVkLineRasterizationModeEXTObject = env->CallObjectMethod(jVkPipelineRasterizationLineStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getLineRasterizationMode");
            return;
        }

        jclass vkLineRasterizationModeEXTEnumClass = env->GetObjectClass(jVkLineRasterizationModeEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkQueryPoolSamplingModeINTELObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkLineRasterizationModeEXTEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkLineRasterizationModeEXT lineRasterizationMode = (VkLineRasterizationModeEXT)env->CallIntMethod(jVkLineRasterizationModeEXTObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isStippledLineEnable", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id isStippledLineEnable.");
            return;
        }

        VkBool32 stippledLineEnable = (VkBool32)env->CallBooleanMethod(jVkPipelineRasterizationLineStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getLineStippleFactor", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getLineStippleFactor.");
            return;
        }

        uint32_t lineStippleFactor = (uint32_t)env->CallIntMethod(jVkPipelineRasterizationLineStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getLineStipplePattern", "()S");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getLineStipplePattern.");
            return;
        }

        uint16_t lineStipplePattern = (uint16_t)env->CallShortMethod(jVkPipelineRasterizationLineStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallShortMethod.");
            return;
        }


        vkPipelineRasterizationLineStateCreateInfoEXT->sType 	= sTypeValue;
        vkPipelineRasterizationLineStateCreateInfoEXT->pNext 	= (void *)pNext;
        vkPipelineRasterizationLineStateCreateInfoEXT->lineRasterizationMode = lineRasterizationMode;
        vkPipelineRasterizationLineStateCreateInfoEXT->stippledLineEnable = stippledLineEnable;
        vkPipelineRasterizationLineStateCreateInfoEXT->lineStippleFactor = lineStippleFactor;
		vkPipelineRasterizationLineStateCreateInfoEXT->lineStipplePattern = lineStipplePattern;
    }
}
