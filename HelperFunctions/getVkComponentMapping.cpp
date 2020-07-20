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
 * VkComponentMapping.cpp
 *
 *  Created on: Oct 25, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkComponentMapping(
			JNIEnv *env,
			jobject jVkComponentMappingObject,
			VkComponentMapping *vkComponentMapping,
			std::vector<void *> *memoryToFree)
	{
		jclass theClass = env->GetObjectClass(jVkComponentMappingObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get class for jVkComponentMappingObject");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getR", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkComponentSwizzle;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getR");
            return;
        }

        jobject jVkComponentSwizzleObject = env->CallObjectMethod(jVkComponentMappingObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkComponentSwizzleObjectEnumClass = env->GetObjectClass(jVkComponentSwizzleObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkComponentSwizzleObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkComponentSwizzleObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkComponentSwizzle rEnumValue = (VkComponentSwizzle)env->CallIntMethod(jVkComponentSwizzleObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getG", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkComponentSwizzle;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getG");
            return;
        }

        jVkComponentSwizzleObject = env->CallObjectMethod(jVkComponentMappingObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkComponentSwizzle gEnumValue = (VkComponentSwizzle)env->CallIntMethod(jVkComponentSwizzleObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getB", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkComponentSwizzle;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getB");
            return;
        }

        jVkComponentSwizzleObject = env->CallObjectMethod(jVkComponentMappingObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkComponentSwizzle bEnumValue = (VkComponentSwizzle)env->CallIntMethod(jVkComponentSwizzleObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getA", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkComponentSwizzle;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getA");
            return;
        }

        jVkComponentSwizzleObject = env->CallObjectMethod(jVkComponentMappingObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkComponentSwizzle aEnumValue = (VkComponentSwizzle)env->CallIntMethod(jVkComponentSwizzleObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }


        vkComponentMapping->r = rEnumValue;
        vkComponentMapping->g = gEnumValue;
        vkComponentMapping->b = bEnumValue;
        vkComponentMapping->a = aEnumValue;
	}
}
