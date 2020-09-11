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
 * getVkPipelineCoverageReductionStateCreateInfoNV.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineCoverageReductionStateCreateInfoNV(
            JNIEnv *env,
            jobject jVkPipelineCoverageReductionStateCreateInfoNVObject,
			VkPipelineCoverageReductionStateCreateInfoNV *vkPipelineCoverageReductionStateCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineCoverageReductionStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPipelineCoverageReductionStateCreateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineCoverageReductionStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineCoverageReductionStateCreateInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineCoverageReductionStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineCoverageReductionStateCreateFlagsNV flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineCoverageReductionStateCreateFlagBitsNV");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getCoverageReductionMode", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkCoverageReductionModeNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to find method id for getCoverageReductionMode");
            return;
        }

        jobject jVkCoverageReductionModeNVObject = env->CallObjectMethod(jVkPipelineCoverageReductionStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getHandleType");
            return;
        }

        jclass vkCoverageReductionModeNVEnumClass = env->GetObjectClass(jVkCoverageReductionModeNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkExternalSemaphoreHandleTypeFlagBitsObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkCoverageReductionModeNVEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkCoverageReductionModeNV coverageReductionMode = (VkCoverageReductionModeNV)env->CallIntMethod(jVkCoverageReductionModeNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }


        vkPipelineCoverageReductionStateCreateInfoNV->sType 	= sTypeValue;
        vkPipelineCoverageReductionStateCreateInfoNV->pNext 	= (void *)pNext;
        vkPipelineCoverageReductionStateCreateInfoNV->flags	= flags;
        vkPipelineCoverageReductionStateCreateInfoNV->coverageReductionMode = coverageReductionMode;
    }
}
