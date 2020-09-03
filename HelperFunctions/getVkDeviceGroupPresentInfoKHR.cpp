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
 * getVkDeviceGroupPresentInfoKHR.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDeviceGroupPresentInfoKHR(
            JNIEnv *env,
            const jobject jVkDeviceGroupPresentInfoKHRObject,
			VkDeviceGroupPresentInfoKHR *vkDeviceGroupPresentInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDeviceGroupPresentInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDeviceGroupPresentInfoKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDeviceGroupPresentInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDeviceGroupPresentInfoKHRObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getDeviceMasks", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDeviceMasks.");
            return;
        }

        jintArray jDeviceMasksArray = (jintArray)env->CallObjectMethod(jVkDeviceGroupPresentInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int *deviceMasksArray = nullptr;
        jsize arrayLength = 0;
        if (jDeviceMasksArray != nullptr)
        {
            arrayLength = env->GetArrayLength(jDeviceMasksArray);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength.");
                return;
            }

            deviceMasksArray = (int *)calloc(arrayLength, sizeof(int));
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error trying to allocate memory for deviceMasksArray.");
                return;
            }

            memoryToFree->push_back(deviceMasksArray);

            env->GetIntArrayRegion(jDeviceMasksArray, 0, arrayLength, deviceMasksArray);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetIntArrayRegion.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMode", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDeviceGroupPresentModeFlagBitsKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getMode.");
            return;
        }

        jobject jVkDeviceGroupPresentModeFlagBitsKHRObject = env->CallObjectMethod(jVkDeviceGroupPresentInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkDeviceGroupPresentInfoKHRClass = env->GetObjectClass(jVkDeviceGroupPresentModeFlagBitsKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkDeviceGroupPresentModeFlagBitsKHRObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkDeviceGroupPresentInfoKHRClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id valueOf.");
            return;
        }

        VkDeviceGroupPresentModeFlagBitsKHR vkDeviceGroupPresentModeFlagBitsKHREnumValue = (VkDeviceGroupPresentModeFlagBitsKHR)env->CallIntMethod(jVkDeviceGroupPresentModeFlagBitsKHRObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }


        vkDeviceGroupPresentInfoKHR->sType = sTypeValue;
        vkDeviceGroupPresentInfoKHR->pNext = pNext;
        vkDeviceGroupPresentInfoKHR->swapchainCount = arrayLength;
        vkDeviceGroupPresentInfoKHR->pDeviceMasks = (uint32_t *)deviceMasksArray;
        vkDeviceGroupPresentInfoKHR->mode = vkDeviceGroupPresentModeFlagBitsKHREnumValue;
    }
}
