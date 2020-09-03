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
 * getVkFilterCubicImageViewImageFormatPropertiesEXT.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkFilterCubicImageViewImageFormatPropertiesEXT(
            JNIEnv *env,
            const jobject jVkFilterCubicImageViewImageFormatPropertiesEXTObject,
			VkFilterCubicImageViewImageFormatPropertiesEXT *vkFilterCubicImageViewImageFormatPropertiesEXT,
            std::vector<void *> *memoryToFree)
    {
		if (jVkFilterCubicImageViewImageFormatPropertiesEXTObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkFilterCubicImageViewImageFormatPropertiesEXTObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkFilterCubicImageViewImageFormatPropertiesEXTObject == nullptr");
			return;
		}

		if (vkFilterCubicImageViewImageFormatPropertiesEXT == nullptr)
		{
			LOGERROR(env, "%s", "vkFilterCubicImageViewImageFormatPropertiesEXT == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkFilterCubicImageViewImageFormatPropertiesEXT == nullptr");
			return;
		}

        jclass theClass = env->GetObjectClass(jVkFilterCubicImageViewImageFormatPropertiesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkFilterCubicImageViewImageFormatPropertiesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkFilterCubicImageViewImageFormatPropertiesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkFilterCubicImageViewImageFormatPropertiesEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isFilterCubic", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isFilterCubic");
            return;
        }

        jboolean filterCubic = env->CallBooleanMethod(jVkFilterCubicImageViewImageFormatPropertiesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isFilterCubicMinmax", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isFilterCubicMinmax");
            return;
        }

        jboolean filterCubicMinmax = env->CallBooleanMethod(jVkFilterCubicImageViewImageFormatPropertiesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkFilterCubicImageViewImageFormatPropertiesEXT->sType = sTypeValue;
        vkFilterCubicImageViewImageFormatPropertiesEXT->pNext = pNext;
        vkFilterCubicImageViewImageFormatPropertiesEXT->filterCubic = filterCubic;
		vkFilterCubicImageViewImageFormatPropertiesEXT->filterCubicMinmax = filterCubicMinmax;
    }
}
