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
 * getVkSamplerYcbcrConversionImageFormatProperties.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSamplerYcbcrConversionImageFormatProperties(
        JNIEnv *env,
        const jobject jVkSamplerYcbcrConversionImageFormatPropertiesObject,
		VkSamplerYcbcrConversionImageFormatProperties *vkSamplerYcbcrConversionImageFormatProperties,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSamplerYcbcrConversionImageFormatPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error getting class for jVkSamplerYcbcrConversionImageFormatPropertiesObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkSamplerYcbcrConversionImageFormatPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSamplerYcbcrConversionImageFormatPropertiesObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getCombinedImageSamplerDescriptorCount", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getCombinedImageSamplerDescriptorCount.");
            return;
        }

        uint32_t combinedImageSamplerDescriptorCount = (uint32_t)env->CallIntMethod(jVkSamplerYcbcrConversionImageFormatPropertiesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on CallIntMethod");
            return;
        }


        vkSamplerYcbcrConversionImageFormatProperties->sType = sTypeValue;
        vkSamplerYcbcrConversionImageFormatProperties->pNext = (void *)pNext;
        vkSamplerYcbcrConversionImageFormatProperties->combinedImageSamplerDescriptorCount = combinedImageSamplerDescriptorCount;
    }
}
