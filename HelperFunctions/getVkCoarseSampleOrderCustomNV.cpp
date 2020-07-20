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
 * getVkCoarseSampleOrderCustomNV.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkCoarseSampleOrderCustomNV(
            JNIEnv *env,
            const jobject jVkCoarseSampleOrderCustomNVObject,
			VkCoarseSampleOrderCustomNV *vkCoarseSampleOrderCustomNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkCoarseSampleOrderCustomNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkCoarseSampleOrderCustomNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getShadingRate", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkShadingRatePaletteEntryNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType getShadingRate");
            return;
        }

        jobject jVkShadingRatePaletteEntryNVObject = env->CallObjectMethod(jVkCoarseSampleOrderCustomNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getShadingRate");
            return;
        }

        jclass vkShadingRatePaletteEntryNVObjectEnumClass = env->GetObjectClass(jVkShadingRatePaletteEntryNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for VkShadingRatePaletteEntryNV");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkShadingRatePaletteEntryNVObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkShadingRatePaletteEntryNV vkShadingRatePaletteEntryNVEnumValue = (VkShadingRatePaletteEntryNV)env->CallIntMethod(jVkShadingRatePaletteEntryNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSampleCount", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSampleCount");
            return;
        }

        jint sampleCount = env->CallIntMethod(jVkCoarseSampleOrderCustomNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getCustomSampleOrders", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getCustomSampleOrders");
            return;
        }

        jobject jSampleLocationsObject = env->CallObjectMethod(jVkCoarseSampleOrderCustomNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int sampleLocationCount = 0;
        VkCoarseSampleLocationNV *sampleLocations = nullptr;
        getVkCoarseSampleLocationNVCollection(
                env,
				jSampleLocationsObject,
                &sampleLocations,
                &sampleLocationCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkCoarseSampleLocationNVCollection");
            return;
        }


        vkCoarseSampleOrderCustomNV->shadingRate = vkShadingRatePaletteEntryNVEnumValue;
        vkCoarseSampleOrderCustomNV->sampleCount = sampleCount;
        vkCoarseSampleOrderCustomNV->sampleLocationCount = sampleLocationCount;
        vkCoarseSampleOrderCustomNV->pSampleLocations = sampleLocations;
    }
}
