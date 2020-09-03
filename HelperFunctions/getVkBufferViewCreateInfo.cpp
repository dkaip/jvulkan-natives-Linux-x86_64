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
 * getVkBufferViewCreateInfo.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: Douglas Kaip
 */


#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBufferViewCreateInfo(
            JNIEnv *env,
            jobject jVkBufferViewCreateInfoObject,
            VkBufferViewCreateInfo *vkBufferViewCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferViewCreateInfoClass = env->GetObjectClass(jVkBufferViewCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkBufferViewCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkBufferViewCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkBufferViewCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkBufferViewCreateInfoObject, methodId);
        VkBufferViewCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkBufferViewCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferViewCreateInfoClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBufferObject = env->CallObjectMethod(jVkBufferViewCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *vkBufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferViewCreateInfoClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFormatObject = env->CallObjectMethod(jVkBufferViewCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFormatEnumClass = env->GetObjectClass(jVkFormatObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkFormatEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFormat vkFormatEnumValue = (VkFormat)env->CallIntMethod(jVkFormatObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferViewCreateInfoClass, "getOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong jOffset = env->CallLongMethod(jVkBufferViewCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferViewCreateInfoClass, "getRange", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong jRange = env->CallLongMethod(jVkBufferViewCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkBufferViewCreateInfo->sType   = sTypeValue;
        vkBufferViewCreateInfo->pNext   = (void *)pNext;
        vkBufferViewCreateInfo->flags   = flags;
        vkBufferViewCreateInfo->buffer  = vkBufferHandle;
        vkBufferViewCreateInfo->format  = vkFormatEnumValue;
        vkBufferViewCreateInfo->offset  = jOffset;
        vkBufferViewCreateInfo->range   = jRange;
    }
}
