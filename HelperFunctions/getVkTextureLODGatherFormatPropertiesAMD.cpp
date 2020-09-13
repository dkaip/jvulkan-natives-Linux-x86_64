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
 * getVkTextureLODGatherFormatPropertiesAMD.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkTextureLODGatherFormatPropertiesAMD(
        JNIEnv *env,
        const jobject jVkTextureLODGatherFormatPropertiesAMDObject,
		VkTextureLODGatherFormatPropertiesAMD *vkTextureLODGatherFormatPropertiesAMD,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkTextureLODGatherFormatPropertiesAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error getting class for jVkTextureLODGatherFormatPropertiesAMDObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkTextureLODGatherFormatPropertiesAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkTextureLODGatherFormatPropertiesAMDObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isSupportsTextureGatherLODBiasAMD", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id isSupportsTextureGatherLODBiasAMD.");
            return;
        }

        VkBool32 supportsTextureGatherLODBiasAMD = (VkBool32)env->CallBooleanMethod(jVkTextureLODGatherFormatPropertiesAMDObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on CallBooleanMethod");
            return;
        }


        vkTextureLODGatherFormatPropertiesAMD->sType = sTypeValue;
        vkTextureLODGatherFormatPropertiesAMD->pNext = (void *)pNext;
        vkTextureLODGatherFormatPropertiesAMD->supportsTextureGatherLODBiasAMD = supportsTextureGatherLODBiasAMD;
    }
}
