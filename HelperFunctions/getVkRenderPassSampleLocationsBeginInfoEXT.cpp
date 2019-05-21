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
 * getVkRenderPassSampleLocationsBeginInfoEXT.cpp
 *
 *  Created on: May 21, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkRenderPassSampleLocationsBeginInfoEXT(
            JNIEnv *env,
            const jobject jVkRenderPassSampleLocationsBeginInfoEXTObject,
			VkRenderPassSampleLocationsBeginInfoEXT *vkRenderPassSampleLocationsBeginInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRenderPassSampleLocationsBeginInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkRenderPassSampleLocationsBeginInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkRenderPassSampleLocationsBeginInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkRenderPassSampleLocationsBeginInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getAttachmentInitialSampleLocations", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAttachmentInitialSampleLocations");
            return;
        }

        jobject jAttachmentInitialSampleLocations = env->CallObjectMethod(jVkRenderPassSampleLocationsBeginInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int attachmentInitialSampleLocationsCount = 0;
        VkAttachmentSampleLocationsEXT *vkAttachmentSampleLocationsEXTs = nullptr;
        getVkAttachmentSampleLocationsEXTCollection(
                env,
				jAttachmentInitialSampleLocations,
                &vkAttachmentSampleLocationsEXTs,
                &attachmentInitialSampleLocationsCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkAttachmentSampleLocationsEXTCollection");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPostSubpassSampleLocations", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getPostSubpassSampleLocations");
            return;
        }

        jobject jPostSubpassSampleLocations = env->CallObjectMethod(jVkRenderPassSampleLocationsBeginInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int postSubpassSampleLocationsCount = 0;
        VkSubpassSampleLocationsEXT *vkSubpassSampleLocationsEXTs = nullptr;
        getVkSubpassSampleLocationsEXTCollection(
                env,
				jPostSubpassSampleLocations,
                &vkSubpassSampleLocationsEXTs,
                &postSubpassSampleLocationsCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkSubpassSampleLocationsEXT");
            return;
        }


        vkRenderPassSampleLocationsBeginInfoEXT->sType = sTypeValue;
        vkRenderPassSampleLocationsBeginInfoEXT->pNext = pNext;
        vkRenderPassSampleLocationsBeginInfoEXT->attachmentInitialSampleLocationsCount = attachmentInitialSampleLocationsCount;
        vkRenderPassSampleLocationsBeginInfoEXT->pAttachmentInitialSampleLocations = vkAttachmentSampleLocationsEXTs;
        vkRenderPassSampleLocationsBeginInfoEXT->postSubpassSampleLocationsCount = postSubpassSampleLocationsCount;
        vkRenderPassSampleLocationsBeginInfoEXT->pPostSubpassSampleLocations = vkSubpassSampleLocationsEXTs;
    }
}
