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
 * getVkPipelineViewportShadingRateImageStateCreateInfoNV.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineViewportShadingRateImageStateCreateInfoNV(
            JNIEnv *env,
            const jobject jVkPipelineViewportShadingRateImageStateCreateInfoNVObject,
			VkPipelineViewportShadingRateImageStateCreateInfoNV *vkPipelineViewportShadingRateImageStateCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineViewportShadingRateImageStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineViewportShadingRateImageStateCreateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPipelineViewportShadingRateImageStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineViewportShadingRateImageStateCreateInfoNVObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isShadingRateImageEnable", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShadingRateImageEnable");
            return;
        }

        jboolean shadingRateImageEnable = env->CallBooleanMethod(jVkPipelineViewportShadingRateImageStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getShadingRatePalettes", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getShadingRatePalettes");
            return;
        }

        jobject jShadingRatePalettes = env->CallObjectMethod(jVkPipelineViewportShadingRateImageStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int viewportCount = 0;
        VkShadingRatePaletteNV *shadingRatePalettes = nullptr;
        getVkShadingRatePaletteNVCollection(
                env,
				jShadingRatePalettes,
                &shadingRatePalettes,
                &viewportCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkShadingRatePaletteNVCollection");
            return;
        }


        vkPipelineViewportShadingRateImageStateCreateInfoNV->sType = sTypeValue;
        vkPipelineViewportShadingRateImageStateCreateInfoNV->pNext = pNext;
        vkPipelineViewportShadingRateImageStateCreateInfoNV->shadingRateImageEnable = shadingRateImageEnable;
        vkPipelineViewportShadingRateImageStateCreateInfoNV->viewportCount = viewportCount;
        vkPipelineViewportShadingRateImageStateCreateInfoNV->pShadingRatePalettes = shadingRatePalettes;
    }
}
