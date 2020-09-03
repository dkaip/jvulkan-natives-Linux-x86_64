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
 * getVkSampleLocationsInfoEXT.cpp
 *
 *  Created on: May 21, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSampleLocationsInfoEXT(
            JNIEnv *env,
            const jobject jVkSampleLocationsInfoEXTObject,
			VkSampleLocationsInfoEXT *vkSampleLocationsInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSampleLocationsInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkSampleLocationsInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkSampleLocationsInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSampleLocationsInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getSampleLocationsPerPixel", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSampleCountFlagBits;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSampleLocationsPerPixel");
            return;
        }

        jobject jSampleLocationsPerPixelObject = env->CallObjectMethod(jVkSampleLocationsInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkSampleCountFlagBitsObjectEnumClass = env->GetObjectClass(jSampleLocationsPerPixelObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jSampleLocationsPerPixelObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkSampleCountFlagBits vkSampleCountFlagBitsEnumValue = (VkSampleCountFlagBits)env->CallIntMethod(jSampleLocationsPerPixelObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSampleLocationGridSize", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent2D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSampleLocationGridSize");
            return;
        }

        jobject jSampleLocationGridSizeObject = env->CallObjectMethod(jVkSampleLocationsInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkExtent2D vkExtent2D = {};
        getVkExtent2D(
                env,
				jSampleLocationGridSizeObject,
                &vkExtent2D,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getVkExtent2D failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSampleLocations", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSampleLocations");
            return;
        }

        jobject jVkSampleLocationEXTs = env->CallObjectMethod(jVkSampleLocationsInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int numberOfVkSampleLocationEXTs = 0;
        VkSampleLocationEXT *vkSampleLocationEXTs = nullptr;
        getVkSampleLocationEXTCollection(
                env,
				jVkSampleLocationEXTs,
                &vkSampleLocationEXTs,
                &numberOfVkSampleLocationEXTs,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkSampleLocationEXTCollection");
            return;
        }


        vkSampleLocationsInfoEXT->sType = sTypeValue;
        vkSampleLocationsInfoEXT->pNext = pNext;
        vkSampleLocationsInfoEXT->sampleLocationsPerPixel = vkSampleCountFlagBitsEnumValue;
        vkSampleLocationsInfoEXT->sampleLocationGridSize.width = vkExtent2D.width;
        vkSampleLocationsInfoEXT->sampleLocationGridSize.height = vkExtent2D.height;
        vkSampleLocationsInfoEXT->sampleLocationsCount = numberOfVkSampleLocationEXTs;
        vkSampleLocationsInfoEXT->pSampleLocations = vkSampleLocationEXTs;
    }
}
