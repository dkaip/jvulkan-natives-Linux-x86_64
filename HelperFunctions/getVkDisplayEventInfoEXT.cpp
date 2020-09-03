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
 * getVkDisplayEventInfoEXT.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDisplayEventInfoEXT(
            JNIEnv *env,
            const jobject jVkDisplayEventInfoEXTObject,
			VkDisplayEventInfoEXT *vkDisplayEventInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDisplayEventInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDisplayEventInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkDisplayEventInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDisplayEventInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getDisplayEvent", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDisplayEventTypeEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType getDisplayEvent");
            return;
        }

        jobject jVkDisplayEventTypeEXTObject = env->CallObjectMethod(jVkDisplayEventInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getDisplayEvent");
            return;
        }

        jclass vkDisplayEventTypeEXTEnumClass = env->GetObjectClass(jVkDisplayEventTypeEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkDisplayEventTypeEXTObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkDisplayEventTypeEXTEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkDisplayEventTypeEXT vkDisplayEventTypeEXTEnumValue = (VkDisplayEventTypeEXT)env->CallIntMethod(jVkDisplayEventTypeEXTObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }


        vkDisplayEventInfoEXT->sType 		= sTypeValue;
        vkDisplayEventInfoEXT->pNext 		= pNext;
        vkDisplayEventInfoEXT->displayEvent	= vkDisplayEventTypeEXTEnumValue;
    }
}
