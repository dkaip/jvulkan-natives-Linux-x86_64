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
 * getVkImageSparseMemoryRequirementsInfo2.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImageSparseMemoryRequirementsInfo2(
            JNIEnv *env,
            const jobject jVkImageSparseMemoryRequirementsInfo2Object,
			VkImageSparseMemoryRequirementsInfo2 *vkImageSparseMemoryRequirementsInfo2,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImageSparseMemoryRequirementsInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageSparseMemoryRequirementsInfo2Object");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkImageSparseMemoryRequirementsInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImageSparseMemoryRequirementsInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (jpNextObject != nullptr)
        {
			LOGERROR(env, "%s", "pNext must be null.");
			return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getImage", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getImage");
            return;
        }

        jobject jVkImage = env->CallObjectMethod(jVkImageSparseMemoryRequirementsInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkImage_T *imageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jVkImage);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not retrieve VkDVkImageevice handle");
            return;
        }


        vkImageSparseMemoryRequirementsInfo2->sType = sTypeValue;
        vkImageSparseMemoryRequirementsInfo2->pNext = pNext;
        vkImageSparseMemoryRequirementsInfo2->image = imageHandle;
    }
}
