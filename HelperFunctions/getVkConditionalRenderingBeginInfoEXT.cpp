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
 * getVkConditionalRenderingBeginInfoEXT.cpp
 *
 *  Created on: Aug 30, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkConditionalRenderingBeginInfoEXT(
            JNIEnv *env,
            jobject jVkConditionalRenderingBeginInfoEXTObject,
			VkConditionalRenderingBeginInfoEXT *vkConditionalRenderingBeginInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkConditionalRenderingBeginInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkConditionalRenderingBeginInfoEXTObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkConditionalRenderingBeginInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkConditionalRenderingBeginInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getBuffer.");
            return;
        }

        jobject jVkBufferObject = env->CallObjectMethod(jVkConditionalRenderingBeginInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
            return;
        }

        VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getHandleValue failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getOffset", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getOffset.");
            return;
        }

        VkDeviceSize offset = (VkDeviceSize)env->CallLongMethod(jVkConditionalRenderingBeginInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallLongMethod failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkConditionalRenderingBeginInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
            return;
        }

        VkConditionalRenderingFlagsEXT vkConditionalRenderingFlagsEXT = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkConditionalRenderingFlagBitsEXT");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getEnumSetValue failed.");
            return;
        }


        vkConditionalRenderingBeginInfoEXT->sType = sTypeValue;
        vkConditionalRenderingBeginInfoEXT->pNext = pNext;
        vkConditionalRenderingBeginInfoEXT->buffer = bufferHandle;
        vkConditionalRenderingBeginInfoEXT->offset = offset;
        vkConditionalRenderingBeginInfoEXT->flags = vkConditionalRenderingFlagsEXT;
    }
}
