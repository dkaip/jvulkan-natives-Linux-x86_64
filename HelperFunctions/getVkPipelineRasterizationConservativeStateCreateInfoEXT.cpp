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
 * getVkPipelineRasterizationConservativeStateCreateInfoEXT.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineRasterizationConservativeStateCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkPipelineRasterizationConservativeStateCreateInfoEXTObject,
			VkPipelineRasterizationConservativeStateCreateInfoEXT *vkPipelineRasterizationConservativeStateCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineRasterizationConservativeStateCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineRasterizationConservativeStateCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineRasterizationConservativeStateCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineRasterizationConservativeStateCreateInfoEXTObject);
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

        jobject flagsObject = env->CallObjectMethod(jVkPipelineRasterizationConservativeStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineRasterizationConservativeStateCreateFlagsEXT flags = (VkPipelineRasterizationConservativeStateCreateFlagsEXT)getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineRasterizationConservativeStateCreateFlagBitsEXT");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getConservativeRasterizationMode", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkConservativeRasterizationModeEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getConservativeRasterizationMode.");
            return;
        }

        jobject jVkConservativeRasterizationModeEXTObject = env->CallObjectMethod(jVkPipelineRasterizationConservativeStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkConservativeRasterizationModeEXTEnumClass = env->GetObjectClass(jVkConservativeRasterizationModeEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkConservativeRasterizationModeEXTObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkConservativeRasterizationModeEXTEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf.");
            return;
        }

        VkConservativeRasterizationModeEXT vkConservativeRasterizationModeEXTEnumValue = (VkConservativeRasterizationModeEXT)env->CallIntMethod(jVkConservativeRasterizationModeEXTObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getExtraPrimitiveOverestimationSize", "()F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getExtraPrimitiveOverestimationSize.");
            return;
        }

        jfloat  extraPrimitiveOverestimationSize = env->CallFloatMethod(jVkPipelineRasterizationConservativeStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallFloatMethod.");
            return;
        }


        vkPipelineRasterizationConservativeStateCreateInfoEXT->sType = sTypeValue;
        vkPipelineRasterizationConservativeStateCreateInfoEXT->pNext = pNext;
        vkPipelineRasterizationConservativeStateCreateInfoEXT->flags = flags;
        vkPipelineRasterizationConservativeStateCreateInfoEXT->conservativeRasterizationMode = vkConservativeRasterizationModeEXTEnumValue;
        vkPipelineRasterizationConservativeStateCreateInfoEXT->extraPrimitiveOverestimationSize = extraPrimitiveOverestimationSize;
    }
}
