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
 * getVkPipelineCoverageModulationStateCreateInfoNV.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineCoverageModulationStateCreateInfoNV(
            JNIEnv *env,
            const jobject jVkPipelineCoverageModulationStateCreateInfoNVObject,
			VkPipelineCoverageModulationStateCreateInfoNV *vkPipelineCoverageModulationStateCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineCoverageModulationStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineCoverageModulationStateCreateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPipelineCoverageModulationStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineCoverageModulationStateCreateInfoNVObject);
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

        jobject flagsObject = env->CallObjectMethod(jVkPipelineCoverageModulationStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkPipelineCoverageModulationStateCreateFlagsNV flags = (VkPipelineCoverageModulationStateCreateFlagsNV)getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineCoverageModulationStateCreateFlagBitsNV");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getCoverageModulationMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkCoverageModulationModeNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getCoverageModulationMode.");
            return;
        }

        jobject jVkCoverageModulationModeNVObject = env->CallObjectMethod(jVkPipelineCoverageModulationStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkCoverageModulationModeNVEnumClass = env->GetObjectClass(jVkCoverageModulationModeNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkCoverageModulationModeNVObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkCoverageModulationModeNVEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf.");
            return;
        }

        VkCoverageModulationModeNV vkCoverageModulationModeNVEnumValue = (VkCoverageModulationModeNV)env->CallIntMethod(jVkCoverageModulationModeNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isCoverageModulationTableEnable", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isCoverageModulationTableEnable.");
            return;
        }

        jboolean  coverageModulationTableEnable = env->CallBooleanMethod(jVkPipelineCoverageModulationStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getCoverageModulationTable", "()[F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getCoverageModulationTable.");
            return;
        }

        jfloatArray jCoverageModulationTable = (jfloatArray)env->CallObjectMethod(jVkPipelineCoverageModulationStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        float *coverageModulationTable = nullptr;
        jsize arrayLength = 0;
        if (jCoverageModulationTable != nullptr)
        {
            arrayLength = env->GetArrayLength(jCoverageModulationTable);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength.");
                return;
            }

            coverageModulationTable = (float *)calloc(arrayLength, sizeof(float));
            if (coverageModulationTable == nullptr)
            {
            	LOGERROR(env, "%s", "Error trying to allocate memory for coverageModulationTable.");
                return;
            }
            memoryToFree->push_back(coverageModulationTable);

            env->GetFloatArrayRegion(jCoverageModulationTable, 0, arrayLength, coverageModulationTable);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetFloatArrayRegion.");
                return;
            }
        }


        vkPipelineCoverageModulationStateCreateInfoNV->sType = sTypeValue;
        vkPipelineCoverageModulationStateCreateInfoNV->pNext = pNext;
        vkPipelineCoverageModulationStateCreateInfoNV->flags = flags;
        vkPipelineCoverageModulationStateCreateInfoNV->coverageModulationMode = vkCoverageModulationModeNVEnumValue;
        vkPipelineCoverageModulationStateCreateInfoNV->coverageModulationTableEnable = coverageModulationTableEnable;
        vkPipelineCoverageModulationStateCreateInfoNV->coverageModulationTableCount = arrayLength;
        vkPipelineCoverageModulationStateCreateInfoNV->pCoverageModulationTable = coverageModulationTable;
    }
}
