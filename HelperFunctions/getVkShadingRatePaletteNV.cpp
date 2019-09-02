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
 * getVkShadingRatePaletteNV.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkShadingRatePaletteNV(
            JNIEnv *env,
            const jobject jVkShadingRatePaletteNVObject,
			VkShadingRatePaletteNV *vkShadingRatePaletteNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkShadingRatePaletteNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineCreationFeedbackCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getShadingRatePaletteEntries", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getShadingRatePaletteEntries");
            return;
        }

        jobject jShadingRatePaletteEntries = env->CallObjectMethod(jVkShadingRatePaletteNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int shadingRatePaletteEntryCount = 0;
        VkShadingRatePaletteEntryNV *shadingRatePaletteEntries = nullptr;
        getVkShadingRatePaletteEntryNVCollection(
                env,
				jShadingRatePaletteEntries,
                &shadingRatePaletteEntries,
                &shadingRatePaletteEntryCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkShadingRatePaletteEntryNVCollection");
            return;
        }

        vkShadingRatePaletteNV->shadingRatePaletteEntryCount = shadingRatePaletteEntryCount;
        vkShadingRatePaletteNV->pShadingRatePaletteEntries = shadingRatePaletteEntries;
    }
}
