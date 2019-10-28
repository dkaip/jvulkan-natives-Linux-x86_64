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
 * getVkValidationCacheCreateInfoEXT.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkValidationCacheCreateInfoEXT(
            JNIEnv *env,
            jobject jVkValidationCacheCreateInfoEXTObject,
			VkValidationCacheCreateInfoEXT *vkValidationCacheCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkValidationCacheCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "jVkValidationCacheCreateInfoEXTObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkValidationCacheCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkValidationCacheCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkValidationCacheCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkValidationCacheCreateFlagsEXT flags = (VkValidationCacheCreateFlagsEXT)getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkValidationCacheCreateFlagBitsEXT");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
        	return;
        }


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getInitialDataSize", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getInitialDataSize.");
            return;
        }

        jlong initialDataSize = env->CallLongMethod(jVkValidationCacheCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getInitialData", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkValidationCacheEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getInitialData.");
            return;
        }

        jobject jVkValidationCacheEXTHandle = env->CallObjectMethod(jVkValidationCacheCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

    	void *initialData = (void *)jvulkan::getHandleValue(env, jVkValidationCacheEXTHandle);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not retrieve jVkValidationCacheEXTHandle handle");
            return;
        }


        vkValidationCacheCreateInfoEXT->sType = (VkStructureType)sTypeValue;
        vkValidationCacheCreateInfoEXT->pNext = (void *)pNext;
        vkValidationCacheCreateInfoEXT->flags = flags;
        vkValidationCacheCreateInfoEXT->initialDataSize = initialDataSize;
        vkValidationCacheCreateInfoEXT->pInitialData = initialData;
    }
}
