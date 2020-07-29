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
 * getVkDisplayModeParametersKHR.cpp
 *
 *  Created on: May 8, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
void getVkDisplayModeParametersKHR(
        JNIEnv *env,
        const jobject jVkDisplayModeParametersKHRObject,
		VkDisplayModeParametersKHR *vkDisplayModeParametersKHR,
        std::vector<void *> *memoryToFree)
    {
        jclass vkDisplayModeParametersKHRClass = env->GetObjectClass(jVkDisplayModeParametersKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not class for jVkDisplayModeParametersKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDisplayModeParametersKHRClass, "getVisibleRegion", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getVisibleRegion");
            return;
        }

        jobject jVkExtent2DObject = env->CallObjectMethod(jVkDisplayModeParametersKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallObjectMethod failed for getVisibleRegion");
            return;
        }

        VkExtent2D vkExtent2D = {};
        getVkExtent2D(
                env,
                jVkExtent2DObject,
                &vkExtent2D,
                memoryToFree);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplayModeParametersKHRClass, "getRefreshRate", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getRefreshRate");
            return;
        }

        jint refreshRate = env->CallIntMethod(jVkDisplayModeParametersKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallIntMethod failed for getRefreshRate");
            return;
        }

        vkDisplayModeParametersKHR->visibleRegion.height = vkExtent2D.height;
        vkDisplayModeParametersKHR->visibleRegion.width = vkExtent2D.width;
        vkDisplayModeParametersKHR->refreshRate = refreshRate;
    }
}
