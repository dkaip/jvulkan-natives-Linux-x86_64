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
 * getVkImportMemoryHostPointerInfoEXT.cpp
 *
 *  Created on: May 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImportMemoryHostPointerInfoEXT(
            JNIEnv *env,
            const jobject jVkImportMemoryHostPointerInfoEXTObject,
			VkImportMemoryHostPointerInfoEXT *vkImportMemoryHostPointerInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImportMemoryHostPointerInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImportMemoryHostPointerInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkImportMemoryHostPointerInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImportMemoryHostPointerInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getHandleType", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkExternalMemoryHandleTypeFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getHandleType methodId");
            return;
        }

        jobject jVkExternalMemoryHandleTypeFlagBitsObject = env->CallObjectMethod(jVkImportMemoryHostPointerInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getTemplateType");
            return;
        }

        jclass vkExternalMemoryHandleTypeFlagBitsEnumClass = env->GetObjectClass(jVkExternalMemoryHandleTypeFlagBitsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkExternalMemoryHandleTypeFlagBitsObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkExternalMemoryHandleTypeFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkExternalMemoryHandleTypeFlagBits vkExternalMemoryHandleTypeFlagBitsEnumValue = (VkExternalMemoryHandleTypeFlagBits)env->CallIntMethod(jVkExternalMemoryHandleTypeFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getHostPointer", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VulkanHandle;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getHostPointer method Id");
            return;
        }

        jobject jHostPointerObject = env->CallObjectMethod(jVkImportMemoryHostPointerInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getHostPointer");
            return;
        }

        void *hostPointer = jvulkan::getHandleValue(env, jHostPointerObject);
        if (env->ExceptionOccurred())
        {
            return;
        }


        vkImportMemoryHostPointerInfoEXT->sType = sTypeValue;
        vkImportMemoryHostPointerInfoEXT->pNext = pNext;
        vkImportMemoryHostPointerInfoEXT->handleType = vkExternalMemoryHandleTypeFlagBitsEnumValue;
        vkImportMemoryHostPointerInfoEXT->pHostPointer = hostPointer;
    }
}
