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
 * getVkBindImagePlaneMemoryInfo.cpp
 *
 *  Created on: May 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBindImagePlaneMemoryInfo(
            JNIEnv *env,
            const jobject jVkBindImagePlaneMemoryInfoObject,
			VkBindImagePlaneMemoryInfo *vkBindImagePlaneMemoryInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkBindImagePlaneMemoryInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkBindImagePlaneMemoryInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkBindImagePlaneMemoryInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkBindImagePlaneMemoryInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getPlaneAspect", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageAspectFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDecodeMode");
            return;
        }

        jobject jVkImageAspectFlagBitsObject = env->CallObjectMethod(jVkBindImagePlaneMemoryInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkImageAspectFlagBitsEnumClass = env->GetObjectClass(jVkImageAspectFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageAspectFlagBitsObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkImageAspectFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkImageAspectFlagBits vkImageAspectFlagBitsEnumValue = (VkImageAspectFlagBits)env->CallIntMethod(jVkImageAspectFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }


        vkBindImagePlaneMemoryInfo->sType = sTypeValue;
        vkBindImagePlaneMemoryInfo->pNext = pNext;
        vkBindImagePlaneMemoryInfo->planeAspect = vkImageAspectFlagBitsEnumValue;
    }
}