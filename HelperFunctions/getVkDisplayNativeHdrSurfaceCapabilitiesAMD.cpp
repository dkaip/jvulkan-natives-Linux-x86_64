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
 * getVkDisplayNativeHdrSurfaceCapabilitiesAMD.cpp
 *
 *  Created on: May 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDisplayNativeHdrSurfaceCapabilitiesAMD(
            JNIEnv *env,
            const jobject jVkDisplayNativeHdrSurfaceCapabilitiesAMDObject,
			VkDisplayNativeHdrSurfaceCapabilitiesAMD *vkDisplayNativeHdrSurfaceCapabilitiesAMD,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDisplayNativeHdrSurfaceCapabilitiesAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDisplayNativeHdrSurfaceCapabilitiesAMDObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDisplayNativeHdrSurfaceCapabilitiesAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDisplayNativeHdrSurfaceCapabilitiesAMDObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isLocalDimmingSupport", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isLocalDimmingSupport.");
            return;
        }

        jboolean localDimmingSupport = env->CallBooleanMethod(jVkDisplayNativeHdrSurfaceCapabilitiesAMDObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkDisplayNativeHdrSurfaceCapabilitiesAMD->sType = sTypeValue;
        vkDisplayNativeHdrSurfaceCapabilitiesAMD->pNext = pNext;
        vkDisplayNativeHdrSurfaceCapabilitiesAMD->localDimmingSupport = localDimmingSupport;
    }
}
