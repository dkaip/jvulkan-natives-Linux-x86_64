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
 * getVkImageDrmFormatModifierListCreateInfoEXT.cpp
 *
 *  Created on: May 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImageDrmFormatModifierListCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkImageDrmFormatModifierListCreateInfoEXTObject,
			VkImageDrmFormatModifierListCreateInfoEXT *vkImageDrmFormatModifierListCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImageDrmFormatModifierListCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageDrmFormatModifierListCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkImageDrmFormatModifierListCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImageDrmFormatModifierListCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getDrmFormatModifiers", "()[J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDrmFormatModifiers");
            return;
        }

        jlongArray jDrmFormatModifiersArrayObject = (jlongArray)env->CallObjectMethod(jVkImageDrmFormatModifierListCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        uint64_t *pDrmFormatModifiers = nullptr;
        jsize arrayLength = 0;
        if (jDrmFormatModifiersArrayObject != nullptr)
        {
            arrayLength = env->GetArrayLength(jDrmFormatModifiersArrayObject);

            pDrmFormatModifiers = (uint64_t *)calloc(arrayLength, sizeof(uint64_t));
            memoryToFree->push_back(pDrmFormatModifiers);

            env->GetLongArrayRegion(jDrmFormatModifiersArrayObject, 0, arrayLength, (long int *)pDrmFormatModifiers);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }


        vkImageDrmFormatModifierListCreateInfoEXT->sType = sTypeValue;
        vkImageDrmFormatModifierListCreateInfoEXT->pNext = pNext;
        vkImageDrmFormatModifierListCreateInfoEXT->drmFormatModifierCount = (uint32_t)arrayLength;
        vkImageDrmFormatModifierListCreateInfoEXT->pDrmFormatModifiers = pDrmFormatModifiers;
    }
}
