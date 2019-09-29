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
 * getVkSamplerReductionModeCreateInfoEXT.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSamplerReductionModeCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkSamplerReductionModeCreateInfoEXTObject,
			VkSamplerReductionModeCreateInfoEXT *vkSamplerReductionModeCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSamplerReductionModeCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkSamplerReductionModeCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkSamplerReductionModeCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSamplerReductionModeCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getReductionMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkObjectType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getReductionMode method Id");
            return;
        }

        jobject jVkSamplerReductionModeEXTObject = env->CallObjectMethod(jVkSamplerReductionModeCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for objectType");
            return;
        }

        jclass vkSamplerReductionModeEXTEnumClass = env->GetObjectClass(jVkSamplerReductionModeEXTObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkSamplerReductionModeEXTEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkSamplerReductionModeEXT vkSamplerReductionModeEXTEnumValue = (VkSamplerReductionModeEXT)env->CallIntMethod(jVkSamplerReductionModeEXTObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }


        vkSamplerReductionModeCreateInfoEXT->sType = sTypeValue;
        vkSamplerReductionModeCreateInfoEXT->pNext = pNext;
        vkSamplerReductionModeCreateInfoEXT->reductionMode = vkSamplerReductionModeEXTEnumValue;
    }
}