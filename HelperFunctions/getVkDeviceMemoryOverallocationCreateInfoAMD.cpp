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
 * getVkDeviceMemoryOverallocationCreateInfoAMD.cpp
 *
 *  Created on: May 16, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDeviceMemoryOverallocationCreateInfoAMD(
            JNIEnv *env,
            jobject jVkDeviceMemoryOverallocationCreateInfoAMDObject,
			VkDeviceMemoryOverallocationCreateInfoAMD *vkDeviceMemoryOverallocationCreateInfoAMD,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDeviceMemoryOverallocationCreateInfoAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkDeviceMemoryOverallocationCreateInfoAMDObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDeviceMemoryOverallocationCreateInfoAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDeviceMemoryOverallocationCreateInfoAMDObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getOverallocationBehavior", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkMemoryOverallocationBehaviorAMD;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getOverallocationBehavior.");
            return;
        }

        jobject jVkMemoryOverallocationBehaviorAMDObject = env->CallObjectMethod(jVkDeviceMemoryOverallocationCreateInfoAMDObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkMemoryOverallocationBehaviorAMDClass = env->GetObjectClass(jVkMemoryOverallocationBehaviorAMDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkMemoryOverallocationBehaviorAMDObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkMemoryOverallocationBehaviorAMDClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id valueOf.");
            return;
        }

        VkMemoryOverallocationBehaviorAMD vkMemoryOverallocationBehaviorAMDEnumValue = (VkMemoryOverallocationBehaviorAMD)env->CallIntMethod(jVkMemoryOverallocationBehaviorAMDObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }


        vkDeviceMemoryOverallocationCreateInfoAMD->sType 				= sTypeValue;
        vkDeviceMemoryOverallocationCreateInfoAMD->pNext 				= (void *)pNext;
        vkDeviceMemoryOverallocationCreateInfoAMD->overallocationBehavior = vkMemoryOverallocationBehaviorAMDEnumValue;
    }
}
