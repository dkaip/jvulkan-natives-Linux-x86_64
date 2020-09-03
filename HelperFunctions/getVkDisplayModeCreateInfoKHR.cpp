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
 * getVkDisplayModeCreateInfoKHR.cpp
 *
 *  Created on: May 8, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

namespace jvulkan
{
    void getVkDisplayModeCreateInfoKHR(
            JNIEnv *env,
            const jobject jVkDisplayModeCreateInfoKHRObject,
			VkDisplayModeCreateInfoKHR *vkDisplayModeCreateInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDisplayModeCreateInfoKHRClass = env->GetObjectClass(jVkDisplayModeCreateInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get the class for jVkDisplayModeCreateInfoKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDisplayModeCreateInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "getSTypeAsInt failed");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkDisplayModeCreateInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDisplayModeCreateInfoKHRClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFlags");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDisplayModeCreateInfoKHRObject, methodId);
        VkDisplayModeCreateFlagsKHR flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulka/VulkanExtensions/Enums/VkDisplayModeCreateFlagBitsKHR");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplayModeCreateInfoKHRClass, "getParameters", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDisplayModeParametersKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getParameters");
            return;
        }

        jobject jVkDisplayModeParametersKHR = env->CallObjectMethod(jVkDisplayModeCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallObjectMethod failed for getParameters");
            return;
        }

        VkDisplayModeParametersKHR *vkDisplayModeParametersKHR = (VkDisplayModeParametersKHR *)calloc(1, sizeof(VkDisplayModeParametersKHR));
        memoryToFree->push_back(vkDisplayModeParametersKHR);

        jvulkan::getVkDisplayModeParametersKHR(env, jVkDisplayModeParametersKHR, vkDisplayModeParametersKHR, memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "getVkDisplayModeParametersKHR failed for jVkDisplayModeParametersKHR");
            return;
        }


        vkDisplayModeCreateInfoKHR->sType = sTypeValue;
        vkDisplayModeCreateInfoKHR->pNext = (void *)pNext;
        vkDisplayModeCreateInfoKHR->flags = flags;
        vkDisplayModeCreateInfoKHR->parameters.visibleRegion.height = vkDisplayModeParametersKHR->visibleRegion.height;
        vkDisplayModeCreateInfoKHR->parameters.visibleRegion.width = vkDisplayModeParametersKHR->visibleRegion.width;
        vkDisplayModeCreateInfoKHR->parameters.refreshRate = vkDisplayModeParametersKHR->refreshRate;
    }
}
