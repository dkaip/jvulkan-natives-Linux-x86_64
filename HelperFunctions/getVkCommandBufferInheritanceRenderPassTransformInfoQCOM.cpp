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
 * getVkCommandBufferInheritanceRenderPassTransformInfoQCOM.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkCommandBufferInheritanceRenderPassTransformInfoQCOM(
            JNIEnv *env,
            jobject jVkCommandBufferInheritanceRenderPassTransformInfoQCOMObject,
			VkCommandBufferInheritanceRenderPassTransformInfoQCOM *vkCommandBufferInheritanceRenderPassTransformInfoQCOM,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkCommandBufferInheritanceRenderPassTransformInfoQCOMObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkCommandBufferInheritanceRenderPassTransformInfoQCOMObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkCommandBufferInheritanceRenderPassTransformInfoQCOMObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkCommandBufferInheritanceRenderPassTransformInfoQCOMObject);
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
        	LOGERROR(env, "%s", "Could not find method id for getTransform.");
            return;
        }

        jobject jVkSurfaceTransformFlagBitsKHRObject = env->CallObjectMethod(jVkCommandBufferInheritanceRenderPassTransformInfoQCOMObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkSurfaceTransformFlagBitsKHRClass = env->GetObjectClass(jVkSurfaceTransformFlagBitsKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling GetObjectClass.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkSurfaceTransformFlagBitsKHRClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSurfaceTransformFlagBitsKHR transform = (VkSurfaceTransformFlagBitsKHR)env->CallIntMethod(jVkSurfaceTransformFlagBitsKHRObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getRenderArea", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkRect2D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getRenderArea.");
            return;
        }

        jobject jVkRect2DObject = env->CallObjectMethod(jVkCommandBufferInheritanceRenderPassTransformInfoQCOMObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkRect2D renderArea = {};
		getVkRect2D(
				env,
				jVkRect2DObject,
				&renderArea,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getVkRect2D.");
			return;
		}


        vkCommandBufferInheritanceRenderPassTransformInfoQCOM->sType 	= sTypeValue;
        vkCommandBufferInheritanceRenderPassTransformInfoQCOM->pNext 	= (void *)pNext;
        vkCommandBufferInheritanceRenderPassTransformInfoQCOM->transform = transform;
        vkCommandBufferInheritanceRenderPassTransformInfoQCOM->renderArea = renderArea;
    }
}
