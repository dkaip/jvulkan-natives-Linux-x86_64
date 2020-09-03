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
 * getVkImageMemoryRequirementsInfo2.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImageMemoryRequirementsInfo2(
            JNIEnv *env,
            const jobject jVkImageMemoryRequirementsInfo2Object,
			VkImageMemoryRequirementsInfo2 *vkImageMemoryRequirementsInfo2,
            std::vector<void *> *memoryToFree)
    {
		if (jVkImageMemoryRequirementsInfo2Object == nullptr)
		{
			LOGERROR(env, "%s", "jVkImageMemoryRequirementsInfo2Object == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkImageMemoryRequirementsInfo2Object == nullptr");
			return;
		}

		if (vkImageMemoryRequirementsInfo2 == nullptr)
		{
			LOGERROR(env, "%s", "vkImageMemoryRequirementsInfo2 == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkImageMemoryRequirementsInfo2 == nullptr");
			return;
		}

        jclass theClass = env->GetObjectClass(jVkImageMemoryRequirementsInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageMemoryRequirementsInfo2Object");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkImageMemoryRequirementsInfo2Object);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImageMemoryRequirementsInfo2Object);
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
        jmethodID methodId = env->GetMethodID(theClass, "getImage", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImage;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getImage");
            return;
        }

        jobject jVkImageObject = env->CallObjectMethod(jVkImageMemoryRequirementsInfo2Object, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkImage_T *imageHandle = (VkImage_T *)jvulkan::getHandleValue(env, jVkImageObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
            return;
        }


        vkImageMemoryRequirementsInfo2->sType = sTypeValue;
        vkImageMemoryRequirementsInfo2->pNext = pNext;
        vkImageMemoryRequirementsInfo2->image = imageHandle;
    }
}
