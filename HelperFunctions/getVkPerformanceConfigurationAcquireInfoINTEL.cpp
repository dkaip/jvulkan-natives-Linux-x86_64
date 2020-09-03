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
 * getVkPerformanceConfigurationAcquireInfoINTEL.cpp
 *
 *  Created on: Sep 1, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPerformanceConfigurationAcquireInfoINTEL(
            JNIEnv *env,
            jobject jVkPerformanceConfigurationAcquireInfoINTELObject,
			VkPerformanceConfigurationAcquireInfoINTEL *vkPerformanceConfigurationAcquireInfoINTEL,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPerformanceConfigurationAcquireInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPerformanceConfigurationAcquireInfoINTELObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPerformanceConfigurationAcquireInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPerformanceConfigurationAcquireInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (jpNextObject != nullptr)
        {
			LOGERROR(env, "%s", "pNext must be null.");
			return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPerformanceConfigurationTypeINTEL;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getType.");
            return;
        }

        jobject jVkPerformanceConfigurationTypeINTELObject = env->CallObjectMethod(jVkPerformanceConfigurationAcquireInfoINTELObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkPerformanceConfigurationTypeINTELClass = env->GetObjectClass(jVkPerformanceConfigurationTypeINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPipelineBindPointObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkPerformanceConfigurationTypeINTELClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf.");
            return;
        }

        VkPerformanceConfigurationTypeINTEL typeEnumValue = (VkPerformanceConfigurationTypeINTEL)env->CallIntMethod(jVkPerformanceConfigurationTypeINTELObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkPerformanceConfigurationAcquireInfoINTEL->sType = sTypeValue;
        vkPerformanceConfigurationAcquireInfoINTEL->pNext = pNext;
        vkPerformanceConfigurationAcquireInfoINTEL->type = typeEnumValue;
    }
}
