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
 * getVkRayTracingShaderGroupCreateInfoNV.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkRayTracingShaderGroupCreateInfoNV(
            JNIEnv *env,
            jobject jVkRayTracingShaderGroupCreateInfoNVObject,
			VkRayTracingShaderGroupCreateInfoNV *vkRayTracingShaderGroupCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRayTracingShaderGroupCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkRayTracingShaderGroupCreateInfoNVObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkRayTracingShaderGroupCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkRayTracingShaderGroupCreateInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkRayTracingShaderGroupTypeKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getType.");
            return;
        }

        jobject jVkRayTracingShaderGroupTypeKHRObject = env->CallObjectMethod(jVkRayTracingShaderGroupCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkAccelerationStructureTypeNVClass = env->GetObjectClass(jVkRayTracingShaderGroupTypeKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkRayTracingShaderGroupTypeKHRObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkAccelerationStructureTypeNVClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkRayTracingShaderGroupTypeKHR typeEnumValue = (VkRayTracingShaderGroupTypeKHR)env->CallIntMethod(jVkRayTracingShaderGroupTypeKHRObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getGeneralShader", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getGeneralShader.");
            return;
        }

        uint32_t generalShader = (uint32_t)env->CallIntMethod(jVkRayTracingShaderGroupCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getClosestHitShader", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getClosestHitShader.");
            return;
        }

        uint32_t closestHitShader = (uint32_t)env->CallIntMethod(jVkRayTracingShaderGroupCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getAnyHitShader", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getAnyHitShader.");
            return;
        }

        uint32_t anyHitShader = (uint32_t)env->CallIntMethod(jVkRayTracingShaderGroupCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getIntersectionShader", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getIntersectionShader.");
            return;
        }

        uint32_t intersectionShader = (uint32_t)env->CallIntMethod(jVkRayTracingShaderGroupCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkRayTracingShaderGroupCreateInfoNV->sType = sTypeValue;
        vkRayTracingShaderGroupCreateInfoNV->pNext = pNext;
        vkRayTracingShaderGroupCreateInfoNV->type = typeEnumValue;
        vkRayTracingShaderGroupCreateInfoNV->generalShader = generalShader;
        vkRayTracingShaderGroupCreateInfoNV->closestHitShader = closestHitShader;
        vkRayTracingShaderGroupCreateInfoNV->anyHitShader = anyHitShader;
        vkRayTracingShaderGroupCreateInfoNV->intersectionShader = intersectionShader;
    }
}
