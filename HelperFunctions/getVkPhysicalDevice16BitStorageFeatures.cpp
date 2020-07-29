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
 * getVkPhysicalDevice16BitStorageFeatures.cpp
 *
 *  Created on: May 16, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDevice16BitStorageFeatures(
            JNIEnv *env,
            const jobject jVkPhysicalDevice16BitStorageFeaturesObject,
			VkPhysicalDevice16BitStorageFeatures *vkPhysicalDevice16BitStorageFeatures,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDevice16BitStorageFeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDevice16BitStorageFeaturesObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDevice16BitStorageFeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDevice16BitStorageFeaturesObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isStorageBuffer16BitAccess", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStorageBuffer16BitAccess");
            return;
        }

        jboolean storageBuffer16BitAccess = env->CallBooleanMethod(jVkPhysicalDevice16BitStorageFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isUniformAndStorageBuffer16BitAccess", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isUniformAndStorageBuffer16BitAccess");
            return;
        }

        jboolean uniformAndStorageBuffer16BitAccess = env->CallBooleanMethod(jVkPhysicalDevice16BitStorageFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isStoragePushConstant16", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStoragePushConstant16");
            return;
        }

        jboolean storagePushConstant16 = env->CallBooleanMethod(jVkPhysicalDevice16BitStorageFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isStorageInputOutput16", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStorageInputOutput16");
            return;
        }

        jboolean storageInputOutput16 = env->CallBooleanMethod(jVkPhysicalDevice16BitStorageFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkPhysicalDevice16BitStorageFeatures->sType = sTypeValue;
        vkPhysicalDevice16BitStorageFeatures->pNext = pNext;
        vkPhysicalDevice16BitStorageFeatures->storageBuffer16BitAccess = storageBuffer16BitAccess;
        vkPhysicalDevice16BitStorageFeatures->uniformAndStorageBuffer16BitAccess = uniformAndStorageBuffer16BitAccess;
        vkPhysicalDevice16BitStorageFeatures->storagePushConstant16 = storagePushConstant16;
        vkPhysicalDevice16BitStorageFeatures->storageInputOutput16 = storageInputOutput16;
    }
}
