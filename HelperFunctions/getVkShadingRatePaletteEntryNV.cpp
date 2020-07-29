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
 * getVkShadingRatePaletteEntryNV.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkShadingRatePaletteEntryNV(
            JNIEnv *env,
            const jobject jVkShadingRatePaletteEntryNVObject,
			VkShadingRatePaletteEntryNV *vkShadingRatePaletteEntryNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkShadingRatePaletteEntryNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkShadingRatePaletteEntryNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID valueOfMethodId = env->GetMethodID(theClass, "valueOf", "()I");
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

        *vkShadingRatePaletteEntryNV = vkShadingRatePaletteEntryNVEnumValue;
    }
}
