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
 * getVkPipelineDiscardRectangleStateCreateInfoEXT.cpp
 *
 *  Created on: May 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineDiscardRectangleStateCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkPipelineDiscardRectangleStateCreateInfoEXTObject,
			VkPipelineDiscardRectangleStateCreateInfoEXT *vkPipelineDiscardRectangleStateCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineDiscardRectangleStateCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineDiscardRectangleStateCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineDiscardRectangleStateCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineDiscardRectangleStateCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for java/util/EnumSet");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineDiscardRectangleStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getFlags");
            return;
        }

        VkPipelineDiscardRectangleStateCreateFlagsEXT flags = (VkPipelineDiscardRectangleStateCreateFlagsEXT)getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineDiscardRectangleStateCreateFlagBitsEXT");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDiscardRectangleMode", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDiscardRectangleModeEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDiscardRectangleMode methodId");
            return;
        }

        jobject jVkDiscardRectangleModeEXTObject = env->CallObjectMethod(jVkPipelineDiscardRectangleStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getTemplateType");
            return;
        }

        jclass vkDiscardRectangleModeEXTObjectEnumClass = env->GetObjectClass(jVkDiscardRectangleModeEXTObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkDiscardRectangleModeEXTObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkDiscardRectangleModeEXT vkDiscardRectangleModeEXTEnumValue = (VkDiscardRectangleModeEXT)env->CallIntMethod(jVkDiscardRectangleModeEXTObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDiscardRectangles", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDiscardRectangles");
            return;
        }

        jobject jDiscardRectangles = env->CallObjectMethod(jVkPipelineDiscardRectangleStateCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int discardRectangleCount = 0;
        VkRect2D *vkRect2Ds = nullptr;
        getVkRect2DCollection(
                env,
				jDiscardRectangles,
                &vkRect2Ds,
                &discardRectangleCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkPipelineCreationFeedbackEXTCollection");
            return;
        }


        vkPipelineDiscardRectangleStateCreateInfoEXT->sType = sTypeValue;
        vkPipelineDiscardRectangleStateCreateInfoEXT->pNext = pNext;
        vkPipelineDiscardRectangleStateCreateInfoEXT->flags = flags;
        vkPipelineDiscardRectangleStateCreateInfoEXT->discardRectangleMode = vkDiscardRectangleModeEXTEnumValue;
        vkPipelineDiscardRectangleStateCreateInfoEXT->discardRectangleCount = discardRectangleCount;
		vkPipelineDiscardRectangleStateCreateInfoEXT->pDiscardRectangles = vkRect2Ds;
    }
}
