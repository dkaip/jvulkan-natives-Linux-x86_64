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
 * getVkPhysicalDevice8BitStorageFeaturesKHR.cpp
 *
 *  Created on: May 16, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDevice8BitStorageFeaturesKHR(
            JNIEnv *env,
            const jobject jVkPhysicalDevice8BitStorageFeaturesKHRObject,
			VkPhysicalDevice8BitStorageFeaturesKHR *vkPhysicalDevice8BitStorageFeaturesKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDevice8BitStorageFeaturesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDevice8BitStorageFeaturesKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDevice8BitStorageFeaturesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDevice8BitStorageFeaturesKHRObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isStorageBuffer8BitAccess", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStorageBuffer8BitAccess");
            return;
        }

        jboolean storageBuffer8BitAccess = env->CallBooleanMethod(jVkPhysicalDevice8BitStorageFeaturesKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isUniformAndStorageBuffer8BitAccess", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isUniformAndStorageBuffer8BitAccess");
            return;
        }

        jboolean uniformAndStorageBuffer8BitAccess = env->CallBooleanMethod(jVkPhysicalDevice8BitStorageFeaturesKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isStoragePushConstant8", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStoragePushConstant8");
            return;
        }

        jboolean storagePushConstant8 = env->CallBooleanMethod(jVkPhysicalDevice8BitStorageFeaturesKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkPhysicalDevice8BitStorageFeaturesKHR->sType = sTypeValue;
        vkPhysicalDevice8BitStorageFeaturesKHR->pNext = pNext;
        vkPhysicalDevice8BitStorageFeaturesKHR->storageBuffer8BitAccess = storageBuffer8BitAccess;
        vkPhysicalDevice8BitStorageFeaturesKHR->uniformAndStorageBuffer8BitAccess = uniformAndStorageBuffer8BitAccess;
        vkPhysicalDevice8BitStorageFeaturesKHR->storagePushConstant8 = storagePushConstant8;
    }
}
