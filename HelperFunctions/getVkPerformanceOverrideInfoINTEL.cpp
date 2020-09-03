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
 * getVkPerformanceOverrideInfoINTEL.cpp
 *
 *  Created on: Sep 1, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPerformanceOverrideInfoINTEL(
            JNIEnv *env,
            jobject jVkPerformanceOverrideInfoINTELObject,
			VkPerformanceOverrideInfoINTEL *vkPerformanceOverrideInfoINTEL,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPerformanceOverrideInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPerformanceOverrideInfoINTELObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPerformanceOverrideInfoINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPerformanceOverrideInfoINTELObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPerformanceOverrideTypeINTEL;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getType.");
            return;
        }

        jobject jVkPerformanceOverrideTypeINTELObject = env->CallObjectMethod(jVkPerformanceOverrideInfoINTELObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkPerformanceOverrideTypeINTELClass = env->GetObjectClass(jVkPerformanceOverrideTypeINTELObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPipelineBindPointObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkPerformanceOverrideTypeINTELClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf.");
            return;
        }

        VkPerformanceOverrideTypeINTEL typeEnumValue = (VkPerformanceOverrideTypeINTEL)env->CallIntMethod(jVkPerformanceOverrideTypeINTELObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isEnable", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for isEnable.");
            return;
        }

        VkBool32 enable = (VkBool32)env->CallBooleanMethod(jVkPerformanceOverrideInfoINTELObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getParameter", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getParameter.");
            return;
        }

        uint64_t parameter = (uint64_t)env->CallLongMethod(jVkPerformanceOverrideInfoINTELObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }


        vkPerformanceOverrideInfoINTEL->sType = sTypeValue;
        vkPerformanceOverrideInfoINTEL->pNext = pNext;
        vkPerformanceOverrideInfoINTEL->type = typeEnumValue;
        vkPerformanceOverrideInfoINTEL->enable = enable;
        vkPerformanceOverrideInfoINTEL->parameter = parameter;
    }
}
