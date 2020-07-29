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
 * getVkPipelineRasterizationStateRasterizationOrderAMD.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineRasterizationStateRasterizationOrderAMD(
            JNIEnv *env,
            const jobject jVkPipelineRasterizationStateRasterizationOrderAMDObject,
			VkPipelineRasterizationStateRasterizationOrderAMD *vkPipelineRasterizationStateRasterizationOrderAMD,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineRasterizationStateRasterizationOrderAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineRasterizationStateRasterizationOrderAMDObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPipelineRasterizationStateRasterizationOrderAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineRasterizationStateRasterizationOrderAMDObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getRasterizationOrder", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkRasterizationOrderAMD;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getRasterizationOrder.");
            return;
        }

        jobject jVkRasterizationOrderAMDObject = env->CallObjectMethod(jVkPipelineRasterizationStateRasterizationOrderAMDObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkRasterizationOrderAMDEnumClass = env->GetObjectClass(jVkRasterizationOrderAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkRasterizationOrderAMDObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkRasterizationOrderAMDEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf.");
            return;
        }

        VkRasterizationOrderAMD vkRasterizationOrderAMDEnumValue = (VkRasterizationOrderAMD)env->CallIntMethod(jVkRasterizationOrderAMDObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkPipelineRasterizationStateRasterizationOrderAMD->sType = sTypeValue;
        vkPipelineRasterizationStateRasterizationOrderAMD->pNext = pNext;
        vkPipelineRasterizationStateRasterizationOrderAMD->rasterizationOrder = vkRasterizationOrderAMDEnumValue;
    }
}
