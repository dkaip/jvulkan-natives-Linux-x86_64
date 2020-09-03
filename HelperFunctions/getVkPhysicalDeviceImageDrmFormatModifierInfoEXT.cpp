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
 * getVkPhysicalDeviceImageDrmFormatModifierInfoEXT.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceImageDrmFormatModifierInfoEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject,
			VkPhysicalDeviceImageDrmFormatModifierInfoEXT *vkPhysicalDeviceImageDrmFormatModifierInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getDrmFormatModifier", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDrmFormatModifier");
            return;
        }

        jlong drmFormatModifier = env->CallLongMethod(jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSharingMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSharingMode;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSharingMode");
            return;
        }

        jobject jVkSharingModeObject = env->CallObjectMethod(jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkSharingModeEnumClass = env->GetObjectClass(jVkSharingModeObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkSharingModeObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkSharingModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkSharingMode sharingModeEnumValue = (VkSharingMode)env->CallIntMethod(jVkSharingModeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
        	return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getQueueFamilyIndices", "()[I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jQueueFamilyIndices = (jintArray)env->CallObjectMethod(jVkPhysicalDeviceImageDrmFormatModifierInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int *queueFamilyIndicesArray = nullptr;
        jsize arrayLength = 0;
        if (jQueueFamilyIndices != nullptr)
        {
            arrayLength = env->GetArrayLength(jQueueFamilyIndices);

            queueFamilyIndicesArray = (int *)calloc(arrayLength, sizeof(int));
            memoryToFree->push_back(queueFamilyIndicesArray);

            env->GetIntArrayRegion(jQueueFamilyIndices, 0, arrayLength, queueFamilyIndicesArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }


        vkPhysicalDeviceImageDrmFormatModifierInfoEXT->sType = sTypeValue;
        vkPhysicalDeviceImageDrmFormatModifierInfoEXT->pNext = pNext;
        vkPhysicalDeviceImageDrmFormatModifierInfoEXT->drmFormatModifier = drmFormatModifier;
        vkPhysicalDeviceImageDrmFormatModifierInfoEXT->sharingMode = sharingModeEnumValue;
        vkPhysicalDeviceImageDrmFormatModifierInfoEXT->queueFamilyIndexCount = arrayLength;
		vkPhysicalDeviceImageDrmFormatModifierInfoEXT->pQueueFamilyIndices = (uint32_t *)queueFamilyIndicesArray;
    }
}
