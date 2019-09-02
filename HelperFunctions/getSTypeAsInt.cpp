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
 * getSTypeAsInt.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

namespace jvulkan
{
	VkStructureType getSTypeAsInt(
            JNIEnv *env,
            const jobject vulkanStructureObject)
    {
        jclass vulkanStructureClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure");
            return (VkStructureType)0x7FFFFFFF;
        }

        jmethodID methodId = env->GetMethodID(vulkanStructureClass, "getSType", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkStructureType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getSType in class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure");
            return (VkStructureType)0x7FFFFFFF;
        }

        jobject sTypeObject = env->CallObjectMethod(vulkanStructureObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return (VkStructureType)0x7FFFFFFF;
        }

        jclass enumClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkStructureType");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkStructureType");
            return (VkStructureType)0x7FFFFFFF;
        }

        methodId = env->GetMethodID(enumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id valueOf in class com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkStructureType");
            return (VkStructureType)0x7FFFFFFF;
        }

        jint result = env->CallIntMethod(sTypeObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for valueOf");
            return (VkStructureType)0x7FFFFFFF;
        }

        return (VkStructureType)result;
    }
}
