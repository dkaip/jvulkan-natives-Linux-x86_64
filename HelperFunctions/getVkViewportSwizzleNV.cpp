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
 * getvkViewportSwizzleNV.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkViewportSwizzleNV(
            JNIEnv *env,
            const jobject jVkViewportSwizzleNVObject,
			VkViewportSwizzleNV *vkViewportSwizzleNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkViewportSwizzleNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkViewportSwizzleNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getX", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkViewportCoordinateSwizzleNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getX");
            return;
        }

        jobject jVkViewportCoordinateSwizzleNVObject = env->CallObjectMethod(jVkViewportSwizzleNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getX");
            return;
        }

        jclass vkViewportCoordinateSwizzleNVEnumClass = env->GetObjectClass(jVkViewportCoordinateSwizzleNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkViewportCoordinateSwizzleNVObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkViewportCoordinateSwizzleNVEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkViewportCoordinateSwizzleNV x = (VkViewportCoordinateSwizzleNV)env->CallIntMethod(jVkViewportCoordinateSwizzleNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getY", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkViewportCoordinateSwizzleNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getY");
            return;
        }

        jVkViewportCoordinateSwizzleNVObject = env->CallObjectMethod(jVkViewportSwizzleNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getY");
            return;
        }

        VkViewportCoordinateSwizzleNV y = (VkViewportCoordinateSwizzleNV)env->CallIntMethod(jVkViewportCoordinateSwizzleNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getZ", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkViewportCoordinateSwizzleNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getZ");
            return;
        }

        jVkViewportCoordinateSwizzleNVObject = env->CallObjectMethod(jVkViewportSwizzleNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getZ");
            return;
        }

        VkViewportCoordinateSwizzleNV z = (VkViewportCoordinateSwizzleNV)env->CallIntMethod(jVkViewportCoordinateSwizzleNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getW", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkViewportCoordinateSwizzleNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getW");
            return;
        }

        jVkViewportCoordinateSwizzleNVObject = env->CallObjectMethod(jVkViewportSwizzleNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getW");
            return;
        }

        VkViewportCoordinateSwizzleNV w = (VkViewportCoordinateSwizzleNV)env->CallIntMethod(jVkViewportCoordinateSwizzleNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }


        vkViewportSwizzleNV->x = x;
        vkViewportSwizzleNV->y = y;
        vkViewportSwizzleNV->z = z;
        vkViewportSwizzleNV->w = w;
    }
}
