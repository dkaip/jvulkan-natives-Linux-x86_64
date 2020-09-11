/*
 * Copyright 2020 Douglas Kaip
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
 * getVkRenderPassTransformBeginInfoQCOM.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkRenderPassTransformBeginInfoQCOM(
            JNIEnv *env,
            jobject jVkRenderPassTransformBeginInfoQCOMObject,
			VkRenderPassTransformBeginInfoQCOM *vkRenderPassTransformBeginInfoQCOM,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRenderPassTransformBeginInfoQCOMObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkRenderPassTransformBeginInfoQCOMObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkRenderPassTransformBeginInfoQCOMObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkRenderPassTransformBeginInfoQCOMObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getTransform", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSurfaceTransformFlagBitsKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType getTransform");
            return;
        }

        jobject jVkSurfaceTransformFlagBitsKHRObject = env->CallObjectMethod(jVkRenderPassTransformBeginInfoQCOMObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getShadingRate");
            return;
        }

        jclass vkSurfaceTransformFlagBitsKHRObjectEnumClass = env->GetObjectClass(jVkSurfaceTransformFlagBitsKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for vkSurfaceTransformFlagBitsKHRObjectEnumClass");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkSurfaceTransformFlagBitsKHRObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkSurfaceTransformFlagBitsKHR transform = (VkSurfaceTransformFlagBitsKHR)env->CallIntMethod(jVkSurfaceTransformFlagBitsKHRObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }


        vkRenderPassTransformBeginInfoQCOM->sType 	= sTypeValue;
        vkRenderPassTransformBeginInfoQCOM->pNext 	= (void *)pNext;
        vkRenderPassTransformBeginInfoQCOM->transform = transform;
    }
}
