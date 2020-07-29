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
 * getVkCalibratedTimestampInfoEXT.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkCalibratedTimestampInfoEXT(
            JNIEnv *env,
            const jobject jVkCalibratedTimestampInfoEXTObject,
			VkCalibratedTimestampInfoEXT *vkCalibratedTimestampInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkCalibratedTimestampInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkCalibratedTimestampInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkCalibratedTimestampInfoEXTObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkCalibratedTimestampInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getTimeDomain", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkTimeDomainEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getTimeDomain");
            return;
        }

        jobject jVkTimeDomainEXTObject = env->CallObjectMethod(jVkCalibratedTimestampInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkTimeDomainEXTEnumClass = env->GetObjectClass(jVkTimeDomainEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkTimeDomainEXTObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkTimeDomainEXTEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkTimeDomainEXT timeDomainEnumValue = (VkTimeDomainEXT)env->CallIntMethod(jVkTimeDomainEXTObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }


        vkCalibratedTimestampInfoEXT->timeDomain = timeDomainEnumValue;
    }
}
