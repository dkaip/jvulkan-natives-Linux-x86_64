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
    void getVkPhysicalDevice8BitStorageFeatures(
            JNIEnv *env,
            const jobject jVkPhysicalDevice8BitStorageFeaturesObject,
			VkPhysicalDevice8BitStorageFeatures *vkPhysicalDevice8BitStorageFeatures,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDevice8BitStorageFeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDevice8BitStorageFeaturesObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDevice8BitStorageFeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDevice8BitStorageFeaturesObject);
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

        jboolean storageBuffer8BitAccess = env->CallBooleanMethod(jVkPhysicalDevice8BitStorageFeaturesObject, methodId);
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

        jboolean uniformAndStorageBuffer8BitAccess = env->CallBooleanMethod(jVkPhysicalDevice8BitStorageFeaturesObject, methodId);
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

        jboolean storagePushConstant8 = env->CallBooleanMethod(jVkPhysicalDevice8BitStorageFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkPhysicalDevice8BitStorageFeatures->sType = sTypeValue;
        vkPhysicalDevice8BitStorageFeatures->pNext = pNext;
        vkPhysicalDevice8BitStorageFeatures->storageBuffer8BitAccess = storageBuffer8BitAccess;
        vkPhysicalDevice8BitStorageFeatures->uniformAndStorageBuffer8BitAccess = uniformAndStorageBuffer8BitAccess;
        vkPhysicalDevice8BitStorageFeatures->storagePushConstant8 = storagePushConstant8;
    }
}
