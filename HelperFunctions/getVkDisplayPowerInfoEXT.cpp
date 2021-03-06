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
 * getVkDisplayPowerInfoEXT.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkDisplayPowerInfoEXT(
			JNIEnv *env,
			jobject jVkDisplayPowerInfoEXTObject,
			VkDisplayPowerInfoEXT *vkDisplayPowerInfoEXT,
			std::vector<void *> *memoryToFree)
	{
		jclass theClass = env->GetObjectClass(jVkDisplayPowerInfoEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get class for jVkDisplayPowerInfoEXTObject");
			return;
		}

		////////////////////////////////////////////////////////////////////////
		VkStructureType sTypeValue = getSType(env, jVkDisplayPowerInfoEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Call to getSType failed.");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDisplayPowerInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (jpNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getPowerState", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDisplayPowerStateEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPowerState");
            return;
        }

        jobject jVkDisplayPowerStateEXTObject = env->CallObjectMethod(jVkDisplayPowerInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkDisplayPowerStateEXTObjectObjectEnumClass = env->GetObjectClass(jVkDisplayPowerStateEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkDisplayPowerStateEXTObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkDisplayPowerStateEXTObjectObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkDisplayPowerStateEXT vkDisplayPowerStateEXTEnumValue = (VkDisplayPowerStateEXT)env->CallIntMethod(jVkDisplayPowerStateEXTObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }


        vkDisplayPowerInfoEXT->sType 		= sTypeValue;
        vkDisplayPowerInfoEXT->pNext		= (void *)pNext;
        vkDisplayPowerInfoEXT->powerState 	= vkDisplayPowerStateEXTEnumValue;
	}
}
