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
 * getVkDeviceGroupRenderPassBeginInfo.cpp
 *
 *  Created on: May 21, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDeviceGroupRenderPassBeginInfo(
            JNIEnv *env,
            const jobject jVkDeviceGroupRenderPassBeginInfoObject,
			VkDeviceGroupRenderPassBeginInfo *vkDeviceGroupRenderPassBeginInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDeviceGroupRenderPassBeginInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDeviceGroupRenderPassBeginInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkDeviceGroupRenderPassBeginInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDeviceGroupRenderPassBeginInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getDeviceMask", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDeviceMask");
            return;
        }

        jint deviceMask = env->CallIntMethod(jVkDeviceGroupRenderPassBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDeviceRenderAreas", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDeviceRenderAreas");
            return;
        }

        jobject jVkRect2Ds = env->CallObjectMethod(jVkDeviceGroupRenderPassBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int numberOfVkRect2Ds = 0;
        VkRect2D *vkRect2Ds = nullptr;
        getVkRect2DCollection(
                env,
                jVkRect2Ds,
                &vkRect2Ds,
                &numberOfVkRect2Ds,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkRect2DCollection");
            return;
        }


        vkDeviceGroupRenderPassBeginInfo->sType = sTypeValue;
        vkDeviceGroupRenderPassBeginInfo->pNext = pNext;
        vkDeviceGroupRenderPassBeginInfo->deviceMask = deviceMask;
        vkDeviceGroupRenderPassBeginInfo->deviceRenderAreaCount = numberOfVkRect2Ds;
		vkDeviceGroupRenderPassBeginInfo->pDeviceRenderAreas = vkRect2Ds;
    }
}
