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
 * getVkSamplerCustomBorderColorCreateInfoEXT.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSamplerCustomBorderColorCreateInfoEXT(
            JNIEnv *env,
            jobject jVkSamplerCustomBorderColorCreateInfoEXTObject,
			VkSamplerCustomBorderColorCreateInfoEXT *vkSamplerCustomBorderColorCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSamplerCustomBorderColorCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkSamplerCustomBorderColorCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkSamplerCustomBorderColorCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSamplerCustomBorderColorCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getCustomBorderColor", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkClearColorValue;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getCustomBorderColor.");
            return;
        }

        jobject jVkClearColorValueObject = env->CallObjectMethod(jVkSamplerCustomBorderColorCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkClearColorValue *vkClearColorValue = (VkClearColorValue *)calloc(1, sizeof (VkClearColorValue));
        if (vkClearColorValue == nullptr)
		{
        	LOGERROR(env, "%s", "Could not allocate memory for vkClearColorValue.");
            return;
		}

        memoryToFree->push_back(vkClearColorValue);

        getVkClearColorValue(
                env,
    			jVkClearColorValueObject,
    			vkClearColorValue,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkClearColorValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFormat.");
            return;
        }

        jobject jVkFormatObject = env->CallObjectMethod(jVkSamplerCustomBorderColorCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkImageLayoutTypeObjectEnumClass = env->GetObjectClass(jVkFormatObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkImageLayoutTypeObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkFormat format = (VkFormat)env->CallIntMethod(jVkFormatObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkSamplerCustomBorderColorCreateInfoEXT->sType 	= sTypeValue;
        vkSamplerCustomBorderColorCreateInfoEXT->pNext 	= (void *)pNext;
        (void)memcpy(&vkSamplerCustomBorderColorCreateInfoEXT->customBorderColor, &vkClearColorValue, sizeof(vkSamplerCustomBorderColorCreateInfoEXT->customBorderColor));
        vkSamplerCustomBorderColorCreateInfoEXT->format = format;
    }
}
