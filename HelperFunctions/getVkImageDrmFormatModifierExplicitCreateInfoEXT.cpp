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
 * getVkImageDrmFormatModifierExplicitCreateInfoEXT.cpp
 *
 *  Created on: May 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkImageDrmFormatModifierExplicitCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkImageDrmFormatModifierExplicitCreateInfoEXTObject,
			VkImageDrmFormatModifierExplicitCreateInfoEXT *vkImageDrmFormatModifierExplicitCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkImageDrmFormatModifierExplicitCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkImageDrmFormatModifierExplicitCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkImageDrmFormatModifierExplicitCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkImageDrmFormatModifierExplicitCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getDrmFormatModifier", "()J;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDrmFormatModifier");
            return;
        }

        jlong drmFormatModifier = env->CallLongMethod(jVkImageDrmFormatModifierExplicitCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPlaneLayouts", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPlaneLayouts");
            return;
        }

        jobject jPipelineStageCreationFeedbacks = env->CallObjectMethod(jVkImageDrmFormatModifierExplicitCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int planeLayoutCount = 0;
        VkSubresourceLayout *vkSubresourceLayouts = nullptr;
        getVkSubresourceLayoutCollection(
                env,
				jPipelineStageCreationFeedbacks,
                &vkSubresourceLayouts,
                &planeLayoutCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkSubresourceLayoutCollection");
            return;
        }


        vkImageDrmFormatModifierExplicitCreateInfoEXT->sType = sTypeValue;
        vkImageDrmFormatModifierExplicitCreateInfoEXT->pNext = pNext;
        vkImageDrmFormatModifierExplicitCreateInfoEXT->drmFormatModifier = drmFormatModifier;
        vkImageDrmFormatModifierExplicitCreateInfoEXT->drmFormatModifierPlaneCount = planeLayoutCount;
        vkImageDrmFormatModifierExplicitCreateInfoEXT->pPlaneLayouts = vkSubresourceLayouts;
    }
}