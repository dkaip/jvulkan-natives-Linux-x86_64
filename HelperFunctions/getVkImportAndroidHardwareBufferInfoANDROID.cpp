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
 * getVkImportAndroidHardwareBufferInfoANDROID.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImportAndroidHardwareBufferInfoANDROID(
            JNIEnv *env,
            jobject jVkImportAndroidHardwareBufferInfoANDROIDObject,
			VkImportAndroidHardwareBufferInfoANDROID *vkImportAndroidHardwareBufferInfoANDROID,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImportAndroidHardwareBufferInfoANDROIDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkImportAndroidHardwareBufferInfoANDROIDObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkImportAndroidHardwareBufferInfoANDROIDObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImportAndroidHardwareBufferInfoANDROIDObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getBuffer", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/AndroidHardwareBuffer;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find methodId for getBuffer");
            return;
        }

        jobject jVkDeferredOperationKHRObject = env->CallObjectMethod(jVkImportAndroidHardwareBufferInfoANDROIDObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        struct AHardwareBuffer *bufferHandle = (struct AHardwareBuffer *)jvulkan::getHandleValue(env, jVkDeferredOperationKHRObject);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Could not retrieve VkFence handle");
    		return;
    	}


    	vkImportAndroidHardwareBufferInfoANDROID->sType 	= sTypeValue;
    	vkImportAndroidHardwareBufferInfoANDROID->pNext 	= (void *)pNext;
    	vkImportAndroidHardwareBufferInfoANDROID->buffer	= bufferHandle;
    }
}
