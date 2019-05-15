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
 * getpNext.cpp
 *
 *  Created on: May 9, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	jobject getpNextObject(
        JNIEnv *env,
        const jobject jVulkanCreateInfoStructureObject)
    {
        ////////////////////////////////////////////////////////////////////////
        jclass vulkanCreateInfoStructureClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "Could not find class:%s", "com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure");
            return nullptr;
        }

        jmethodID methodId = env->GetMethodID(vulkanCreateInfoStructureClass, "getpNext", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getpNext");
            return nullptr;
        }

        jobject pNextObject = env->CallObjectMethod(jVulkanCreateInfoStructureObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod to get pNext.");
            return nullptr;
        }

        return pNextObject;
    }
}
