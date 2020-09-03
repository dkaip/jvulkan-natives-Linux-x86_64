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
 * getVkPrivateDataSlotCreateInfoEXT.cpp
 *
 *  Created on: Aug 30, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPrivateDataSlotCreateInfoEXT(
            JNIEnv *env,
            jobject jVkPrivateDataSlotCreateInfoEXTObject,
			VkPrivateDataSlotCreateInfoEXT *vkPrivateDataSlotCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPrivateDataSlotCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPrivateDataSlotCreateInfoEXTObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPrivateDataSlotCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkPrivateDataSlotCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPrivateDataSlotCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
            return;
        }

        VkPrivateDataSlotCreateFlagsEXT vkPrivateDataSlotCreateFlagsEXT = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPrivateDataSlotCreateFlagBitsEXT");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getEnumSetValue failed.");
            return;
        }


        vkPrivateDataSlotCreateInfoEXT->sType = sTypeValue;
        vkPrivateDataSlotCreateInfoEXT->pNext = pNext;
        vkPrivateDataSlotCreateInfoEXT->flags = vkPrivateDataSlotCreateFlagsEXT;
    }
}
